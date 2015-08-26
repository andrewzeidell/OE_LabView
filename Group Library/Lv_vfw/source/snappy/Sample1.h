// Sample1.h
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
#ifndef _SAMPLE1_H
#define _SAMPLE1_H

//globals
extern HGLOBAL hDisplayDIB;
extern HWND hWndMain;
extern HGLOBAL hSnappedDIB;
extern BOOL SnapError;

// SnapVer.cpp Routines
extern DWORD GetSnappyVersion();

// UseSnap.cpp Routines
extern BOOL InitSnappy();
extern void EndSnappy();
extern void DoSnap();
extern void DoPreview();
extern void DoProcess(int width, int height);
extern void GetImageSize(WORD *width, WORD *height, WORD *depth);


#endif // _SAMPLE1_H