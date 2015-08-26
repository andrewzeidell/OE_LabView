// SnapVer.cpp
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
#include <string.h>
#include "Sample1.h"

// GetOcxPath - determines the path to the currently registered
//              Snappy 2.x Ole control (if any)
void GetOcxPath(LPTSTR szPath)
{
    DWORD dwSize = _MAX_PATH;
    HKEY hKey;
	DWORD dwKeyType;

    RegOpenKeyEx(HKEY_CLASSES_ROOT, 
                 TEXT("CLSID\\{99C49163-CAC8-11CF-B908-0000B4681EAD}\\InprocServer32"),
                 0, KEY_ALL_ACCESS, &hKey);

    if (ERROR_SUCCESS != RegQueryValueEx( hKey, TEXT(""),
      NULL, &dwKeyType, (LPBYTE)szPath, &dwSize))
    {
          // unable to locate Snappy OCX Path
          *szPath = '\0';
    }
    RegCloseKey(hKey);
}

// GetSnappy2Version - returns SnappyVer
// major version = HIBYTE(HIWORD(SnappyVer))
// minor version = LOBYTE(HIWORD(SnappyVer))
// build number  = LOWORD(SnappyVer)
DWORD GetSnappyVersion()
{            
    TCHAR szLongPathName[_MAX_PATH];
    GetOcxPath(szLongPathName);

    DWORD dwRtn = 0L;  // variable to recieve 0
    DWORD dwSize = GetFileVersionInfoSize(szLongPathName, &dwRtn);
    if ( dwSize )
    {
        LPTSTR pVerBlock = new TCHAR[dwSize];
        if (GetFileVersionInfo(szLongPathName, 0, dwSize, pVerBlock))
        {
            LPVOID pFileVersion = NULL;
            UINT nFileVersionLength = 0;
            if (VerQueryValue(pVerBlock, TEXT("\\"),
                (LPVOID*)&pFileVersion, &nFileVersionLength))
            {
                VS_FIXEDFILEINFO* vi = (VS_FIXEDFILEINFO*)pFileVersion;
                dwRtn |= (HIWORD(vi->dwProductVersionMS)) << 24;
                dwRtn |= (LOWORD(vi->dwProductVersionMS)) << 16;
                // if rev == 1 use PrivateBuild string for build num
                if (LOWORD(vi->dwProductVersionLS) == 1)
                {
                    if (VerQueryValue(pVerBlock,
                        TEXT("\\StringFileInfo\\040904b0\\PrivateBuild"),
                        (LPVOID*)&pFileVersion,
                        &nFileVersionLength))
                    {
                        dwRtn |= atoi((LPTSTR)pFileVersion) & 0xffff;
                    }
                }
                else // otherwise, just use rev # as build num
                    dwRtn |= LOWORD(vi->dwProductVersionLS);
            }
        delete [] pVerBlock;
        }
    }
    return dwRtn;
}
