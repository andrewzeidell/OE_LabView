// UseSnap.cpp
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
#include "Sample1.h"

#include "snappy.h"
#include "sCLSIDs.h"
#include "MyNotify.h"

// declare classes -- interfaces declared in snappy_i.c
DECLARE_CLSID_cSnappy;
DECLARE_PAL_CLSID_cSnappy;

ISnappy* pSnappy = NULL;
ISnappyHardware* pHardware = NULL;
ISnappyPreview* pPreview = NULL;
ISnappyProcess* pProcess = NULL;
HGLOBAL hDIB = NULL;


CSample1SnappyNotify* pSnappyNotify = NULL;

BOOL IsSnappyNTSC()
{
    DWORD dwLen = 255;
    TCHAR str[255];

    OSVERSIONINFO osversion;
    memset(&osversion, 0, sizeof(OSVERSIONINFO));
    osversion.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);
    GetVersionEx(&osversion);

    // if win32s use "playsnap.ini"
    if(VER_PLATFORM_WIN32s == osversion.dwPlatformId)
    {
        GetPrivateProfileString(TEXT("AcquireOptions"),
                TEXT("VideoFormat"), TEXT(""), str,
                dwLen, "PLAYSNAP.INI");
    }
    else
    {
        // look up VideoFormat in registry
        HKEY hKey;
        DWORD dwKeyType;
        if (RegOpenKeyEx(HKEY_LOCAL_MACHINE,
                TEXT("Software\\Play\\SnappyVideoSnapshot\\AcquireOptions"),
		        0, KEY_ALL_ACCESS, &hKey) == ERROR_SUCCESS)
        {
            RegQueryValueEx( hKey, TEXT("VideoFormat"),
  	            NULL, &dwKeyType, (LPBYTE)str, &dwLen);
            RegCloseKey(hKey);
        }
    }
    return (!lstrcmp(str,TEXT("NTSC")));
}

BOOL InitSnappy()
{
    HRESULT hr;

    if (pSnappy) return TRUE; // already initialized

    // initialize com
    CoInitialize(NULL);

    if (IsSnappyNTSC())
        hr = CoCreateInstance (CLSID_cSnappy, NULL, CLSCTX_INPROC_SERVER,
            IID_ISnappy, (LPVOID*)&pSnappy);
    else
        hr = CoCreateInstance (PAL_CLSID_cSnappy, NULL, CLSCTX_INPROC_SERVER,
            IID_ISnappy, (LPVOID*)&pSnappy);

    if (SUCCEEDED(hr))
    {
	    pSnappyNotify = new CSample1SnappyNotify();
	    pSnappy->SetAdvise(pSnappyNotify);
        if (SUCCEEDED(pSnappy->QueryInterface(IID_ISnappyHardware,
		    (LPVOID*)&pHardware)))
        {
            // Tell SnappyX.dll to use user's default LPT Port
            pHardware->SetLPTPort(0);

            if (SUCCEEDED(pSnappy->QueryInterface(IID_ISnappyProcess,
		        (LPVOID*)&pProcess)))
            return TRUE;
        }
    }
    return FALSE;
}

void EndSnappy()
{
    if (!pSnappy) return; // snappy wasn't initialized
    pSnappy->Abort();   // make sure everythig is stopped

	pSnappy->SetAdvise(NULL);
    if (pSnappyNotify)
        pSnappyNotify->Release();

    if (pHardware)
    {
        pHardware->Release();
        pHardware = NULL;
    }

    if (pPreview) 
    {
        pPreview->Release();
        pPreview = NULL;
    }

    if (pProcess) 
    {
        pProcess->Release();    // This will free the DIB that
                                // has been set with pProcess->SetProcessDIB()

        // alternately, 
        // pProcess->SetProcessDIB(NULL)
        // GlobalFree(hDIB)

        hDIB = NULL;

        pProcess = NULL;
    }

    pSnappy->Release();
    pSnappy = NULL;
    CoUninitialize();
}

void DoSnap()
{
//	pSnappy->Abort();
    HRESULT hr = pSnappy->Snap(NULL);
    if (FAILED(hr))
    {
        TCHAR str[256] = "Error Snapping: ";
        switch(hr)
        {
        case SNAPERR_BUSY:
            lstrcat(str, "Snappy Busy");
            break;
        case SNAPERR_NOT_FOUND:
            lstrcat(str, "No Snappy Found");
            break;                       
        case SNAPERR_NOT_INITIALIZED:
            lstrcat(str, "Not Initialized");
            break;
        case SNAPERR_LPT_PORT_NOT_AVAILABLE:
            lstrcat(str, "LPT Port Not Available");
            break;
        case SNAPERR_INVALID_POINTER:
            lstrcat(str, "Bad Parameter");
            break;
        case SNAPERR_BUSY_STARTING_PREVIEW:
            lstrcat(str, "Busy Starting Preview");
            break;
        }
        MessageBox(NULL, str, "Error", MB_OK);
		SnapError = TRUE;
    }
}

void DoPreview()
{
    if (!pSnappy) return; // call InitSnappy() first!

    if (!pPreview)
    {
        if (FAILED(pSnappy->QueryInterface(IID_ISnappyPreview,
		    (LPVOID*)&pPreview)))
        {
            pPreview = NULL;
            return;
        }
    }
    pPreview->StartPreviewing();
}

void GetImageSize(WORD *width, WORD *height, WORD *depth)
{
    pProcess->GetImageSize(width, height, depth);
}

void DoProcess(int width, int height)
{
    if (!pProcess) return; // call InitSnappy() first!

    pSnappy->Abort();   // stop Previewing or Snapping

    if (hDIB) pProcess->FreeProcessDIB(hDIB);

    pProcess->SetImageSize(width, height, 24);

    pProcess->AllocProcessDIB(&hDIB);    
    pProcess->SetProcessDIB(hDIB);

    pProcess->ProcessSnappyData();
}