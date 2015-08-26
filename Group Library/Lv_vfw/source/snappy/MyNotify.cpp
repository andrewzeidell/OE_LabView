#include "snappy.h"
#include "MyNotify.h"
#include "Sample1.h"

STDMETHODIMP CSample1SnappyNotify::OnDIBReady(
        /* [in] */ HGLOBAL hPackedDIB)
{
	hSnappedDIB = hPackedDIB;
    return S_OK;
}

STDMETHODIMP CSample1SnappyNotify::OnPreviewImageReady( 
        /* [in] */ HGLOBAL hPackedDIB,
        /* [in] */ ISnappyPreview __RPC_FAR *pPreview)
{
	hDisplayDIB = hPackedDIB;
	InvalidateRect(hWndMain, NULL, FALSE);
	UpdateWindow(hWndMain);
    return CSnappyNotify::OnPreviewImageReady(hPackedDIB,pPreview);
}

STDMETHODIMP CSample1SnappyNotify::OnStatusUpdate(
		/* [in] */ ESnappyPhase ePhase,
		/* [in] */ WORD nValue,
		/* [in] */ WORD nTotal )
{
    return S_OK;
}

STDMETHODIMP CSample1SnappyNotify::OnLineProcessed(
		/* [in] */ WORD nLine,
		/* [in] */ BYTE* pBits) 
{
    return S_OK;
}

STDMETHODIMP CSample1SnappyNotify::OnError(
        /* [in] */ int nErrorNum, int nCheckpoint )
{
	MessageBox(NULL, "Error during frame capture.", "Error", MB_OK);
	SnapError = TRUE;
    return S_OK; 
}

STDMETHODIMP CSample1SnappyNotify::OnDataReady( void )
{
    return S_OK;
}