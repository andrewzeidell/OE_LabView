#include <windows.h>
#include "snappy.h"
#include "sample1.h"


#define WINDOW_CLASS "SnappyInterface"
#define WINDOW_STYLE_VISIBLE (WS_CAPTION | WS_THICKFRAME | WS_POPUPWINDOW | WS_VISIBLE)
#define WINDOW_STYLE_HIDDEN (WS_CAPTION | WS_THICKFRAME | WS_POPUPWINDOW)

static HINSTANCE hInstance;
HWND hWndMain = 0;
HGLOBAL hDisplayDIB = 0;
HGLOBAL hSnappedDIB = 0;
BOOL SnapError = FALSE;

#define DllExport __declspec(dllexport)


extern "C" DllExport long _cdecl CreateSnappyWindow(int show)
{
	DWORD dwSnappyVer = GetSnappyVersion();
	if (!dwSnappyVer)
	{
		MessageBox(NULL, "This program requires Snappy 2.0 or later", "Error", MB_OK);
		return 0;
	}
	else
	{
		HWND hwnd = CreateWindow(
			WINDOW_CLASS,
			"Snappy Preview",
			show ? WINDOW_STYLE_VISIBLE : WINDOW_STYLE_HIDDEN,
			10,
			10,
			200,
			200,
			NULL,
			NULL,
			hInstance,
			NULL);
		InitSnappy();
		DoPreview();
		return (long)hwnd;
	}
}

extern "C" DllExport void _cdecl DestroySnappyWindow(long hwnd)
{
	if (hwnd)
		DestroyWindow((HWND)hwnd);
}


extern "C" DllExport void _cdecl GetData(long hwnd, float rWeight, float gWeight, 
									     float bWeight, float allWeight, float* data)
{
	if (!hSnappedDIB || SnapError) return;

	//convert the DIB to something LabView can handle

	LPBITMAPINFO pDIB = (LPBITMAPINFO)GlobalLock(hSnappedDIB);
	LPBITMAPINFOHEADER pbmi = (LPBITMAPINFOHEADER)pDIB;

	BYTE* pBits = (BYTE*)pDIB + pbmi->biSize + (pbmi->biClrUsed * sizeof(RGBQUAD));
	
	float normalizer = rWeight + gWeight + bWeight;
	rWeight /= normalizer;
	gWeight /= normalizer;
	bWeight /= normalizer;

	rWeight *= allWeight;
	gWeight *= allWeight;
	bWeight *= allWeight;

	float r, g, b;

	int cPixelBits = pbmi->biBitCount;
	int cPixels = pbmi->biHeight * pbmi->biWidth;

	switch (cPixelBits)
	{
	case 32:
		{
			int cBytes = cPixels * 4;
			for (int i = 0; i < cBytes; i += 4)
			{
				b = ((float)pBits[i] / 255) * bWeight;
				g = ((float)pBits[i+1] / 255) * gWeight;
				r = ((float)pBits[i+2] / 255) * rWeight;

				*(data++) = r + g + b;
			}
		}
		break;

	case 24:
		{
			int cBytes = cPixels * 3;
			for (int i = 0; i < cBytes; i += 3)
			{
				b = ((float)pBits[i] / 255) * bWeight;
				g = ((float)pBits[i+1] / 255) * gWeight;
				r = ((float)pBits[i+2] / 255) * rWeight;

				*(data++) = r + g + b;
			}
		}
		break;

	case 16:
		{
			WORD word, tr, tg, tb;

			for (int i = 0; i < cPixels; i++)
			{
				word = ((WORD*)pBits)[i];
				tb = word & 0x1F;
				tg = (word & 0x3E0) >> 5;
				tr = (word & 0x7C00) >> 10;
				b = ((float)tb / 31) * bWeight;
				g = ((float)tg / 31) * gWeight;
				r = ((float)tr / 31) * rWeight;

				*(data++) = r + g + b;
			}
		}
		break;

	case 8:
		{
			RGBQUAD* table = (LPRGBQUAD)(((BYTE *)(pbmi)) + sizeof(BITMAPINFOHEADER));
			int index;
			
			for (int i = 0; i < cPixels; i++)
			{
				index = (int)pBits[i];
				b = ((float)table[index].rgbBlue / 255) * bWeight;
				g = ((float)table[index].rgbGreen / 255) * gWeight;
				r = ((float)table[index].rgbRed / 255) * rWeight;

				*(data++) = r + g + b;
			}
		}
		break;

	case 4:
		{
			RGBQUAD* table = (LPRGBQUAD)(((BYTE *)(pbmi)) + sizeof(BITMAPINFOHEADER));
			int index1, index2;
			cPixels /= 2;
			for (int i = 0; i < cPixels; i++)
			{
				index1 = (int)(pBits[i] >> 4);
				index2 = (int)(pBits[i] & 0x0F);

				b = ((float)table[index1].rgbBlue / 255) * bWeight;
				g = ((float)table[index1].rgbGreen / 255) * gWeight;
				r = ((float)table[index1].rgbRed / 255) * rWeight;

				*(data++) = r + g + b;

				b = ((float)table[index2].rgbBlue / 255) * bWeight;
				g = ((float)table[index2].rgbGreen / 255) * gWeight;
				r = ((float)table[index2].rgbRed / 255) * rWeight;

				*(data++) = r + g + b;
			}
		}
		break;

	default:
		MessageBox((HWND)hwnd, "Unsupported bit depth!", "GetData", MB_OK);
		break;
	}

	//free up the DIB
	if (GlobalFree(hSnappedDIB))
		MessageBox(NULL, "Error deleting the temporary bitmap object.", "Error", MB_OK); 
	hSnappedDIB = 0;

	DoPreview();
}

extern "C" DllExport void _cdecl Snap(long hwnd)
{
	//capture a DIB

	hSnappedDIB = 0;
	SnapError = FALSE;

	DoSnap();
}

extern "C" DllExport int _cdecl IsDone()
{
	return (hSnappedDIB || SnapError);
}


extern "C" DllExport void _cdecl GetSize(WORD *width, WORD *height)
{
	WORD depth;
	GetImageSize(width, height, &depth);
}


LRESULT APIENTRY SnappyWndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_CREATE:
		hWndMain = hwnd;
		return 0;

	case WM_DESTROY:
		EndSnappy();
		return 0;

	case WM_PAINT:
		if (hDisplayDIB) // we have an image to paint
		{
			PAINTSTRUCT paint;
			HDC hdc = BeginPaint(hwnd, &paint);
			LPBITMAPINFO pDIB = (LPBITMAPINFO)GlobalLock(hDisplayDIB);
			RECT r; GetClientRect(hwnd, &r);

			SetStretchBltMode(hdc, COLORONCOLOR);

			LPBITMAPINFOHEADER pbmi = (LPBITMAPINFOHEADER)pDIB;
			BYTE* pBits = (BYTE*)pDIB + pbmi->biSize + (pbmi->biClrUsed * sizeof(RGBQUAD));

			StretchDIBits(
				hdc,	// handle of device context
				0,	// x-coordinate of upper-left corner of dest. rect.
				0,	// y-coordinate of upper-left corner of dest. rect.
				r.right- r.left,	// width of destination rectangle
				r.bottom - r.top,	// height of destination rectangle
				0,	// x-coordinate of upper-left corner of source rect.
				0,	// y-coordinate of upper-left corner of source rect.
				pbmi->biWidth,	// width of source rectangle
				pbmi->biHeight,	// height of source rectangle
				pBits,	// address of bitmap bits
				pDIB,	// address of bitmap data
				DIB_RGB_COLORS,	// usage
				SRCCOPY 	// raster operation code
			);

			EndPaint(hwnd, &paint);

			return 0;
		}
	}

	return DefWindowProc(hwnd, uMsg, wParam, lParam);
}





//prototype for c run-time initialization
extern "C" BOOL WINAPI _CRT_INIT( HINSTANCE hinstDLL, DWORD fdwReason, 
	LPVOID lpReserved );

//our DLL initialization code
BOOL WINAPI DllEntryPoint(HINSTANCE hInst, DWORD fdwReason, LPVOID lpReserved)
{
	if(!_CRT_INIT(hInst, fdwReason, lpReserved))
		return FALSE;

	switch (fdwReason)
	{
	case DLL_PROCESS_ATTACH:
		hInstance = hInst;

		static WNDCLASSEX wc;
	
		wc.cbSize = sizeof(WNDCLASSEX);
		wc.style = CS_BYTEALIGNCLIENT | CS_NOCLOSE;
		wc.lpfnWndProc = SnappyWndProc;
		wc.cbClsExtra = 0;
		wc.cbWndExtra = 0;
		wc.hInstance = hInst;
		wc.hIcon = NULL;
		wc.hCursor = LoadCursor(NULL, IDC_ARROW);
		wc.hbrBackground = NULL;
		wc.lpszMenuName = NULL;
		wc.lpszClassName = WINDOW_CLASS;
		wc.hIconSm = NULL;

		if (!RegisterClassEx(&wc))
			return FALSE;
		break;

	case DLL_PROCESS_DETACH:
		UnregisterClass(WINDOW_CLASS, hInst);
		break;
	}

	return TRUE;
}
