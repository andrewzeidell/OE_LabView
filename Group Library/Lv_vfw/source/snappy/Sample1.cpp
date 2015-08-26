// Sample1.cpp
/*
    This sample code is covered under the same disclaimers supplied in the
    Snappy Video Snapshot users manual.  These files may only be used by a
    Registered User of a Snappy Video Snapshot.  See users manual for complete
    licence information.

    Play Incorporated ("Play") is the "Licensor" of the Snappy Video Snapshot
    software program and accompanying documentation.

    LIMITATION OF LIABILITY.  IN NO EVENT WILL LICENSOR(S), PLAY OR ANYONE ELSE
    WHO HAS BEEN INVOLVED IN THE CREATION, PRODUCTION OR DELIVERY OF THE
    PROGRAMS, OR ANY OR ALL OF THE SNAPPY PRODUCT BE LIABLE TO YOU FOR ANY
    CONSEQUENTIAL, INCIDENTAL, INDIRECT OR SPECIAL DAMAGES, INCLUDING ANY LOST
    PROFITS OR LOST SAVINGS ARISING OUT OF THE USE OR INABILITY TO USE THE
    PROGRAMS, ACCOMPANYING DOCUMENTATION OR SNAPPY HARDWARE MODULE, EVEN IF
    LICENSOR(S), INCLUDING PLAY, HAVE BEEN ADVISED OF THE POSSIBILITY OF SUCH
    DAMAGES.  The foregoing limitations of liability shall apply notwithstanding
    any failure of essential purpose of any limited remedy or for any claim by
    any other party.  Play and Licensors' liability to You or any third party
    arising out of or related to this Agreement however caused and on any theory
    of liability, whether in contract, tort(including negligence), or otherwise
    will not exceed the fee paid by You for the Programs or the Snappy Hardware
    Module, as applicable.  The Programs and Snappy Hardware Module are not
    specifically developed or licensed for use in any nuclear, aviation,
    mass transit, life support or medical application, any other inherently
    dangerous applications and commercial applications.  SOME STATES DO
    NOT ALLOW THE LIMITATION OR EXCLUSION OF LIABILITY FOR INCIDENTAL OR
    CONSEQUENTIAL DAMAGES SO THE ABOVE LIMITATION OR EXCLUSION MAY NOT APPLY TO
    YOU.

    Copyright(c) 1996 Play Incorporated.
    All rights reserved.
*/
#include <windows.h>
#include "resource.h"

#include "Sample1.h"

// global vars
HWND hSample1Dlg = 0;
HGLOBAL hSample1DIB = NULL;

/*******************************************************************************
    function definitions
*******************************************************************************/

// The Dialog Procedure
BOOL CALLBACK TheDialogProc(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch(uMsg)
    {
    case WM_INITDIALOG:
        {
            hSample1Dlg = hwndDlg;
            DWORD dwSnappyVer = GetSnappyVersion();
            if (dwSnappyVer)
            {
                TCHAR szVer[128];
                wsprintf(szVer,"Snappy %d.%d Build %d Installed",
                    HIBYTE(HIWORD(dwSnappyVer)), // major ver
                    LOBYTE(HIWORD(dwSnappyVer)), // minor ver
                    LOWORD(dwSnappyVer)); // build num

                SetStatus(szVer);

                // Enable Snap & Preview Buttons
                EnableWindow(GetDlgItem(hwndDlg, IDC_SNAP), TRUE);
                EnableWindow(GetDlgItem(hwndDlg, IDC_PREVIEW), TRUE);
                InitSnappy();

            }
        }
        return TRUE;

    case WM_CLOSE:
        EndSnappy();
        EndDialog(hwndDlg, IDCANCEL);
        return TRUE;

    case WM_COMMAND:
        switch (wParam)
        {
        case IDOK:
            EndSnappy();
            EndDialog(hwndDlg, IDOK);
            return TRUE;

        case IDC_SNAP:
            DoSnap();
            return TRUE;

        case IDC_PREVIEW:
            DoPreview();
            return TRUE;

        case IDC_PROCESS_SMALL:
            DoProcess(64,48);
            return TRUE;

        case IDC_PROCESS_BIG:
            DoProcess(1024, 768);
            return TRUE;

        }
        break;

    case WM_CTLCOLORSTATIC:
        HDC hdc = (HDC) wParam;
        if (GetDlgCtrlID((HWND) lParam) != IDC_IMAGEFRAME)
            break;
        HWND hFrame = (HWND) lParam;
        if (hSample1DIB) // we have an image to paint
        {
            LPBITMAPINFO pDIB = (LPBITMAPINFO)GlobalLock(hSample1DIB);
		    RECT r; GetClientRect(hFrame, &r);

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
        }
        return TRUE;

    }
    return FALSE;
}

void SetStatus(LPSTR str)
{
    SetDlgItemText(hSample1Dlg, IDC_STATUS, str);
}

void SetImage(HGLOBAL hPackedDIB)
{
    hSample1DIB = hPackedDIB;
    HWND hFrame = GetDlgItem(hSample1Dlg, IDC_IMAGEFRAME);
    InvalidateRect(hFrame, NULL, FALSE);
    UpdateWindow(hFrame);
}

void ReadyToProcess()
{
    SetStatus("Ready to Process");
    EnableWindow(GetDlgItem(hSample1Dlg, IDC_PROCESS_SMALL), TRUE);
    EnableWindow(GetDlgItem(hSample1Dlg, IDC_PROCESS_BIG), TRUE);
}

// Mian entry point
int PASCAL WinMain(HINSTANCE hInst, HINSTANCE hPrev, LPSTR szCmdLine,
    int cmdShow)
{
    szCmdLine = szCmdLine; // not used, but some compilers like this
    return DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG), NULL, (DLGPROC)TheDialogProc);
}


