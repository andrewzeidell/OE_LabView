// capwind.dll
//
// Video capture window for use by LabView
//
// Eric Eilebrecht
// eilebrec@colorado.edu
//
// See dlltest.vi for sample usage.


#include <windows.h>
#include <vfw.h>
#include <stdio.h>
#include "resource.h"
#include "dib.h"


#define WINDOW_CLASS "EricsCaptureWindow"
#define WINDOW_STYLE_VISIBLE (WS_CAPTION | WS_POPUPWINDOW | WS_VISIBLE)
#define WINDOW_STYLE_HIDDEN (WS_CAPTION | WS_POPUPWINDOW)

#define WM_SNAP_DIB (WM_USER + 1)
#define WM_SNAP_DIB_QUICKLY (WM_USER + 2)


LRESULT APIENTRY CapWndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);


static HINSTANCE hInstance;
static CDIB dib;
static BOOL bQuickSnap = FALSE; //true if we're in "quick snap" mode


// External interfaces to capwind.dll
//
// These are suitable for calling using the LabView
// "Call library function.vi."


#define DllExport __declspec(dllexport)

// Initialize the frame capture process.  This should be the first function
// you call.
//
// returns the handle of the frame capture window.  This is used by all of the
// other functions in this library.

extern "C" DllExport long _cdecl CreateCaptureWindow(int show)
{
	HWND hwnd = CreateWindow(
		WINDOW_CLASS,
		"Video Preview",
		show ? WINDOW_STYLE_VISIBLE : WINDOW_STYLE_HIDDEN,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		NULL,
		LoadMenu(hInstance, MAKEINTRESOURCE(IDR_MAINMENU)),
		hInstance,
		NULL);

	return (long)hwnd;
}

// Cleans up after the frame capture process.  This should be the last function
// you call.  'hwnd' is the window handle obtained from CreateCaptureWindow().

extern "C" DllExport void _cdecl DestroyCaptureWindow(long hwnd)
{
	if (hwnd)
		DestroyWindow((HWND)hwnd);
}

// Capture the current frame of video.  'hwnd' is the window handle obtained 
// from CreateCaptureWindow().  'filename' is the full pathname of the
// file to save the frame in.  This file should have a ".BMP" extension.
// The file will be written in Windows' standard DIB format.  This is readable
// by Paintbrush and most other Windows programs.
//
// This must be called prior to calling GetData(), as that function makes use
// of the results of this function.

extern "C" DllExport void _cdecl SnapDIB(long hwnd, char* filename)
{
	if (hwnd && filename)
		SendMessage((HWND)hwnd, WM_SNAP_DIB, 0, (LPARAM)filename);
}

extern "C" DllExport void _cdecl SnapDIB_NoFile(long hwnd)
{
	if (hwnd)
		SendMessage((HWND)hwnd, WM_SNAP_DIB_QUICKLY, 0, 0);
}

// returns the width of a frame of video.

extern "C" DllExport long _cdecl GetWidth(long hwnd)
{
	return dib.DibWidth();
}

// returns the height of a frame of video.

extern "C" DllExport long _cdecl GetHeight(long hwnd)
{
	return dib.DibHeight();
}


// Retrieve the pixels of the captured data, in the form of an "intensity matrix"
// This function should only be called *after* SnapDIB().  This function uses
// the video frame that was capatured during the most recent call to SnapDIB().
//
// Parameters are as follows:
//
// hwnd
//    the handle of the video preview window
// 
// rWeight, gWeight, bWeight:
//    the weighting that will be applied to each color to form the final 
//    intensity value.  These only have meaning relative to each other.
//    Some examples:
//
//    rWeight gWeight bWeight  Result
//    --------------------------------------------------------------------------
//      1.0     1.0     1.0    RGB values are simply added
//      1.0      0       0     filter out all but red
//      .5       .5      1     weight red and green half as much as blue
//       0       0       0     ERROR.  This will produce a divide by zero error
//
// allWeight:
//    All intensity values are scaled with allWeight as the maximum value.
//    Setting this to 0 produces an matrix of 0's.
//
// data:
//    a pointer to a matrix of 'float's.  The size of the matrix should be 
//    w * h, where w is the width of the captured image, and h is the height.
//    These values may be obtained from GetWidth() and GetHeight().
//    This is the format that LabView uses to pass 2D arrays to a DLL.

//    extern "C" DllExport void _cdecl GetData(long hwnd, float rWeight, float gWeight, float bWeight, float allWeight, float* data)
extern "C" DllExport void _cdecl GetData(long hwnd, int* data)
{


	int cPixelBits = dib.GetBitsPerPixel();
	int cPixels = dib.DibHeight() * dib.DibWidth();
	BYTE* pBits = dib.GetBitsAddress();

	switch (cPixelBits)
	{
	case 32:
		{
			int cBytes = cPixels * 4;
			for (int i = 0; i < cBytes; i += 4)
			{
				*(data++) = (pBits[i+2] << 16) + (pBits[i+1] << 8)+ pBits[i];  //new
			}
		}
		break;

	case 24:
		{
			int cBytes = cPixels * 3;
		for (int i = 0; i < cBytes; i += 3)
			{
				*(data++) = (pBits[i+2] << 16) + (pBits[i+1] << 8)+ pBits[i];  //new
			}
		}
		break;

	case 16:
		{

			for (int i = 0; i < cPixels; i++)
			{
				*(data++) = (pBits[i+2] << 16) + (pBits[i+1] << 8)+ pBits[i];   //new
			}
		}
		break;

	case 8:
		{
			RGBQUAD* table = dib.GetClrTabAddress();
			int index;
			
			for (int i = 0; i < cPixels; i++)
			{
				index = (int)pBits[i];
				*(data++) = (table[index].rgbRed << 16) + (table[index].rgbGreen << 8 ) + table[index].rgbBlue  ;  //new
			}
		}
		break;

	case 4:
		{
			RGBQUAD* table = dib.GetClrTabAddress();
			int index1, index2;
			cPixels /= 2;
			for (int i = 0; i < cPixels; i++)
			{
				index1 = (int)(pBits[i] >> 4);
				index2 = (int)(pBits[i] & 0x0F);
				*(data++) = (table[index1].rgbRed << 16) + (table[index1].rgbGreen << 8 ) + table[index1].rgbBlue  ;  //new
				*(data++) = (table[index1].rgbRed << 16) + (table[index1].rgbGreen << 8 ) + table[index1].rgbBlue  ;  //new

			}
		}
		break;

	default:
		MessageBox((HWND)hwnd, "Unsupported bit depth!", "GetData", MB_OK);
		break;
	}
}


// utility function - gets the current size of a frame of video and
// resizes the preview window to fit it snugly

void UpdateSize(HWND hwndParent, HWND hwndCapture)
{
	CAPSTATUS status;
	capGetStatus(hwndCapture, &status, sizeof(status));

	RECT rect;
	rect.top = 0; 
	rect.left = 0;
	rect.bottom = status.uiImageHeight;
	rect.right = status.uiImageWidth;

	SetWindowPos(hwndCapture, HWND_TOP, 0, 0,
		rect.right - rect.left,
		rect.bottom - rect.top,
		SWP_NOZORDER);

	AdjustWindowRect(&rect, WINDOW_STYLE_VISIBLE, TRUE);

	SetWindowPos(hwndParent, HWND_TOP, 0, 0,
		rect.right - rect.left,
		rect.bottom - rect.top,
		SWP_NOMOVE | SWP_NOZORDER);
}


// utility function - fills the "Devices" menu with a list of the
// installed video capture devices

void BuildDriverMenu(HWND hwnd, HWND hwndCapture)
{
	HMENU popup = GetSubMenu(GetMenu(hwnd), 0);

	char name[255];
	int i = 0;
	while (capGetDriverDescription(i, name, 255, 0, 0))
	{
		AppendMenu(popup, MF_ENABLED | MF_STRING, IDM_DRIVER + i, name);
		i++;
	}
}


//"about" dialog procedure

BOOL CALLBACK AboutProc (HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
{
	switch(msg)
	{
	case WM_COMMAND:
		switch (wparam)
		{
		case IDOK:
			EndDialog(hwnd, IDOK);
			break;
		}
		return 1;
	}

	return 0;
}


// frame capture callback function

LRESULT PASCAL FrameCallbackProc(HWND hwndCapture, LPVIDEOHDR lpVHdr)
{
	if (bQuickSnap)
	{
		DWORD cInfo = capGetVideoFormatSize(hwndCapture);
		BITMAPINFO *info = (BITMAPINFO*)malloc(cInfo);
		capGetVideoFormat(hwndCapture, info, cInfo);

		BYTE *bits = (BYTE*)malloc(lpVHdr->dwBytesUsed);
		memcpy(bits, lpVHdr->lpData, lpVHdr->dwBytesUsed);

		dib.ChangeTo(info, bits);

		bQuickSnap = FALSE;
	}

	return (LRESULT)TRUE;
}


// Implementation of the capwind window class

LRESULT APIENTRY CapWndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	static HWND hwndCapture = 0;
	static int driver = 0;
	static CAPDRIVERCAPS caps;
	FILE* file;

	switch (uMsg)
	{
	case WM_CREATE:
		hwndCapture = capCreateCaptureWindow("Capture Window", 
			WS_CHILD | WS_VISIBLE, 0, 0, 200, 200, hwnd, 13);
		
		BuildDriverMenu(hwnd, hwndCapture);

		capDriverConnect (hwndCapture, driver);
		capPreviewRate (hwndCapture, 1.0E3 / 30);
		capPreview (hwndCapture, TRUE);
		capDriverGetCaps(hwndCapture, &caps, sizeof(caps));
		capSetCallbackOnFrame(hwndCapture, FrameCallbackProc);
		
		UpdateSize(hwnd, hwndCapture);
		return 0;

	case WM_DESTROY:
		capDriverDisconnect(hwndCapture);
		DestroyWindow(hwndCapture);
		return 0;

	case WM_COMMAND:
		switch (wParam)
		{
		case IDM_FORMAT:
			capDlgVideoFormat(hwndCapture);
			UpdateSize(hwnd, hwndCapture);
			break;

		case IDM_SOURCE:
			capDlgVideoSource(hwndCapture);
			UpdateSize(hwnd, hwndCapture);
			break;

		case IDM_DISPLAY:
			capDlgVideoDisplay(hwndCapture);
			UpdateSize(hwnd, hwndCapture);
			break;

		case IDM_ABOUT:
			DialogBox(hInstance, MAKEINTRESOURCE(IDD_ABOUT), hwnd, (DLGPROC)AboutProc);
			break;

		default:
			if (wParam >= IDM_DRIVER && wParam <= IDM_DRIVER9)
			{
				capDriverDisconnect (hwndCapture);
				driver = wParam - IDM_DRIVER;
				capDriverConnect (hwndCapture, driver);
				capDriverGetCaps(hwndCapture, &caps, sizeof(caps));
				UpdateSize(hwnd, hwndCapture);
			}
		}
		return 0;

	case WM_INITMENUPOPUP:
		{
			HMENU menu = (HMENU)wParam;
			MENUITEMINFO info;
			info.cbSize = sizeof(info);
			info.fMask = MIIM_STATE;

			int count = GetMenuItemCount(menu);
			for (int i = 0; i < count; i++)
			{
				int id = GetMenuItemID(menu, i);
				if (id >= IDM_DRIVER && id <= IDM_DRIVER9)
				{
					if (id == (IDM_DRIVER + driver))
						info.fState = MFS_CHECKED;
					else
						info.fState = MFS_UNCHECKED;

					SetMenuItemInfo(menu, i, TRUE, &info);
				}
				else
				{
					switch (id)
					{
					case IDM_FORMAT:
						info.fState = caps.fHasDlgVideoFormat ? MFS_ENABLED : MFS_DISABLED;
						break;
					case IDM_SOURCE:
						info.fState = caps.fHasDlgVideoSource ? MFS_ENABLED : MFS_DISABLED;
						break;
					case IDM_DISPLAY:
						info.fState = caps.fHasDlgVideoDisplay ? MFS_ENABLED : MFS_DISABLED;
						break;
					}

					SetMenuItemInfo(menu, i, TRUE, &info);
				}
			}
		}
		return 0;

	case WM_SNAP_DIB:
		capGrabFrameNoStop(hwndCapture);
		capFileSaveDIB(hwndCapture, (char*)lParam);

		file = fopen((char*)lParam, "r");
		if (file)
		{
			if (!dib.Load(file))
				MessageBox(hwnd, "Error reading bitmap file.", "Video Capture", MB_OK);
			fclose(file);
		}
		else
			MessageBox(hwnd, "Error opening bitmap file.", "Video Capture", MB_OK);

		return 0;

	case WM_SNAP_DIB_QUICKLY:
		bQuickSnap = TRUE;
		capGrabFrameNoStop(hwndCapture);

		while (bQuickSnap) /*do nothing*/;

		return 0;
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
		wc.lpfnWndProc = CapWndProc;
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

