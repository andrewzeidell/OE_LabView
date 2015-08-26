// MyNotify.cpp
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

#include "snapcom.h"

class CSample1SnappyNotify : public CSnappyNotify
{
public:
    CSample1SnappyNotify() {};

    // overide CSnappyNotify member functions you want to use
	STDMETHODIMP OnDIBReady(
        /* [in] */ HGLOBAL hPackedDIB);
    
	STDMETHODIMP OnPreviewImageReady( 
        /* [in] */ HGLOBAL hPackedDIB,
        /* [in] */ ISnappyPreview __RPC_FAR *pPreview);

    STDMETHODIMP OnStatusUpdate(
		/* [in] */ ESnappyPhase ePhase,
		/* [in] */ WORD nValue,
		/* [in] */ WORD nTotal);

    STDMETHODIMP OnLineProcessed(
		/* [in] */ WORD nLine,
		/* [in] */ BYTE* pBits);

    STDMETHODIMP OnError(
        /* [in] */ int nErrorNum, 
        int nCheckpoint);

    STDMETHODIMP OnDataReady(void);
};