// snapcom.h
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

#ifndef _SNAPCOM_H
#define _SNAPCOM_H

	// define Notification class
class CSnappyNotify : public ISnappyAdviseSync
{
public:
    CSnappyNotify() : m_cRef(1) {};

	virtual ~CSnappyNotify() {};

	// IUnknown members
	STDMETHODIMP QueryInterface(REFIID riid, void** ppv)
	{
		*ppv=NULL;

		if (IsEqualGUID(riid,IID_IUnknown) ||
			IsEqualGUID(riid,IID_ISnappyAdviseSync))
			*ppv=this;

		if (*ppv==NULL)
			return ResultFromScode(E_NOINTERFACE);

		AddRef();
		return NOERROR;
	};

	STDMETHODIMP_(DWORD) AddRef(void) { return ++m_cRef; };
	STDMETHODIMP_(DWORD) Release(void)
	{
		if (--m_cRef != 0)
			return m_cRef;
		delete this;
		return 0;
	};


	// ISnappyAdvise members
public:
	virtual STDMETHODIMP OnDIBReady(
		/* [in] */ HGLOBAL hPackedDIB ) { return E_NOTIMPL; }

	virtual STDMETHODIMP OnDataReady( void ) { return E_NOTIMPL; }

	virtual STDMETHODIMP OnFieldSnapped( void ) { return E_NOTIMPL; }

	virtual STDMETHODIMP OnLineProcessed(
		/* [in] */ WORD nLine,
		/* [in] */ BYTE* pBits) { return E_NOTIMPL; }

	virtual STDMETHODIMP OnReadyToSnap( void ) { return E_NOTIMPL; }

	virtual STDMETHODIMP OnPowerChanged(
		/* [in] */ BOOL bPower ) { return E_NOTIMPL; }

	virtual STDMETHODIMP OnVideoThruChanged(
		/* [in] */ BOOL bTerminated ) { return E_NOTIMPL; }

	virtual STDMETHODIMP OnPreviewImageReady(
		/* [in] */ HGLOBAL hPackedDIB,
        /* [in] */ ISnappyPreview* pPreview) 
    {
        // if Preview is being used, it is assumed the notify class
        // was constructed with an ISnappyPreview*.
        if (pPreview) pPreview->UnlockPreviewImage();    
        return S_OK; 
    }

	virtual STDMETHODIMP OnLowBatteryChanged(
		/* [in] */ BOOL bLow ) { return E_NOTIMPL; }

	virtual STDMETHODIMP OnHotVideoChanged(
		/* [in] */ BOOL bHot ) { return E_NOTIMPL; }

	virtual STDMETHODIMP OnVideoAvailableChanged(
		/* [in] */ BOOL bVideoAvailable ) { return E_NOTIMPL; }

	virtual STDMETHODIMP OnWarning(
		/* [in] */ ESnappyWarning eWarningNum ) { return E_NOTIMPL; }

    virtual STDMETHODIMP OnError(
        /* [in] */ int nErrorNum, int nCheckpoint ) { return E_NOTIMPL; }

    virtual STDMETHODIMP OnStatusUpdate(
		/* [in] */ ESnappyPhase ePhase,
		/* [in] */ WORD nValue,
		/* [in] */ WORD nTotal ) { return E_NOTIMPL; }

private:
	DWORD m_cRef;
};

#endif // _SNAPCOM_H
