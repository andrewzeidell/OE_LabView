/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 2.00.0102 */
/* at Tue May 13 18:04:40 1997
 */
//@@MIDL_FILE_HEADING(  )
#include "rpc.h"
#include "rpcndr.h"
#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __snappy_h__
#define __snappy_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __ISnappy_FWD_DEFINED__
#define __ISnappy_FWD_DEFINED__
typedef interface ISnappy ISnappy;
#endif 	/* __ISnappy_FWD_DEFINED__ */


#ifndef __ISnappyAdviseSync_FWD_DEFINED__
#define __ISnappyAdviseSync_FWD_DEFINED__
typedef interface ISnappyAdviseSync ISnappyAdviseSync;
#endif 	/* __ISnappyAdviseSync_FWD_DEFINED__ */


#ifndef __ISnappyPreview_FWD_DEFINED__
#define __ISnappyPreview_FWD_DEFINED__
typedef interface ISnappyPreview ISnappyPreview;
#endif 	/* __ISnappyPreview_FWD_DEFINED__ */


#ifndef __ISnappyProcess_FWD_DEFINED__
#define __ISnappyProcess_FWD_DEFINED__
typedef interface ISnappyProcess ISnappyProcess;
#endif 	/* __ISnappyProcess_FWD_DEFINED__ */


#ifndef __ISnappyHardware_FWD_DEFINED__
#define __ISnappyHardware_FWD_DEFINED__
typedef interface ISnappyHardware ISnappyHardware;
#endif 	/* __ISnappyHardware_FWD_DEFINED__ */


/* header files for imported files */
#include "wtypes.h"
#include "unknwn.h"

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

/****************************************
 * Generated header for interface: __MIDL__intf_0000
 * at Tue May 13 18:04:40 1997
 * using MIDL 2.00.0102
 ****************************************/
/* [local] */ 


#define SNAPERR_BUSY                            0xE80A0001
#define SNAPERR_NOT_FOUND                       0xE80A0002
#define SNAPERR_INVALID_BUFFER                  0xE80A0003
#define SNAPERR_FILE_INVALID                    0xE80A0004
#define SNAPERR_NOT_INITIALIZED                 0xE80A0005
#define SNAPERR_LPT_PORT_NOT_AVAILABLE          0xE80A0006
#define SNAPERR_SETTINGS_CHANGED_WHILE_SNAPPING 0xE80A0007
#define SNAPERR_INVALID_POINTER                 0xE80A0008
#define SNAPERR_ABORT_CALLED_FROM_WORKER_THREAD 0xE80A0009
#define SNAPERR_PREVIEW_TIMEOUT                 0xE80A000A
#define SNAPERR_BUSY_STARTING_PREVIEW           0xE80A000B
			/* size is 0 */

			/* size is 0 */



extern RPC_IF_HANDLE __MIDL__intf_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL__intf_0000_v0_0_s_ifspec;

#ifndef __ISnappy_INTERFACE_DEFINED__
#define __ISnappy_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: ISnappy
 * at Tue May 13 18:04:40 1997
 * using MIDL 2.00.0102
 ****************************************/
/* [unique][uuid][local][object] */ 


			/* size is 2 */
typedef 
enum tagSnapMode
    {	Moving	= 0,
	Still	= Moving + 1,
	HighQuality	= Still + 1,
	HighestQuality	= HighQuality + 1
    }	ESnapMode;


EXTERN_C const IID IID_ISnappy;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface ISnappy : public IUnknown
    {
    public:
        virtual HRESULT __stdcall SetAdvise( 
            /* [in] */ ISnappyAdviseSync __RPC_FAR *pNotify) = 0;
        
        virtual HRESULT __stdcall Snap( 
            /* [in] */ HGLOBAL hPackedDIB) = 0;
        
        virtual HRESULT __stdcall SnapToUnprocessedData( void) = 0;
        
        virtual HRESULT __stdcall Abort( void) = 0;
        
        virtual HRESULT __stdcall GetSnapMode( 
            /* [out] */ ESnapMode __RPC_FAR *pSnapMode) = 0;
        
        virtual HRESULT __stdcall SetSnapMode( 
            /* [in] */ ESnapMode eSnapMode) = 0;
        
        virtual HRESULT __stdcall IsSourceCamera( 
            /* [out] */ BOOL __RPC_FAR *pbCamera) = 0;
        
        virtual HRESULT __stdcall SetInputSource( 
            /* [in] */ BOOL bCamera) = 0;
        
        virtual HRESULT __stdcall IsSourceColor( 
            /* [out] */ BOOL __RPC_FAR *pbColor) = 0;
        
        virtual HRESULT __stdcall SetSourceColor( 
            /* [in] */ BOOL bColor) = 0;
        
        virtual HRESULT __stdcall IsSourceNegative( 
            /* [out] */ BOOL __RPC_FAR *pbNegative) = 0;
        
        virtual HRESULT __stdcall SetSourceNegative( 
            /* [in] */ BOOL bNegative) = 0;
        
        virtual HRESULT __stdcall SaveCurrentSettingsAsDefault( void) = 0;
        
        virtual HRESULT __stdcall GetDefaultSettings( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ISnappyVtbl
    {
        
        HRESULT ( __stdcall __RPC_FAR *QueryInterface )( 
            ISnappy __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( __stdcall __RPC_FAR *AddRef )( 
            ISnappy __RPC_FAR * This);
        
        ULONG ( __stdcall __RPC_FAR *Release )( 
            ISnappy __RPC_FAR * This);
        
        HRESULT ( __stdcall __RPC_FAR *SetAdvise )( 
            ISnappy __RPC_FAR * This,
            /* [in] */ ISnappyAdviseSync __RPC_FAR *pNotify);
        
        HRESULT ( __stdcall __RPC_FAR *Snap )( 
            ISnappy __RPC_FAR * This,
            /* [in] */ HGLOBAL hPackedDIB);
        
        HRESULT ( __stdcall __RPC_FAR *SnapToUnprocessedData )( 
            ISnappy __RPC_FAR * This);
        
        HRESULT ( __stdcall __RPC_FAR *Abort )( 
            ISnappy __RPC_FAR * This);
        
        HRESULT ( __stdcall __RPC_FAR *GetSnapMode )( 
            ISnappy __RPC_FAR * This,
            /* [out] */ ESnapMode __RPC_FAR *pSnapMode);
        
        HRESULT ( __stdcall __RPC_FAR *SetSnapMode )( 
            ISnappy __RPC_FAR * This,
            /* [in] */ ESnapMode eSnapMode);
        
        HRESULT ( __stdcall __RPC_FAR *IsSourceCamera )( 
            ISnappy __RPC_FAR * This,
            /* [out] */ BOOL __RPC_FAR *pbCamera);
        
        HRESULT ( __stdcall __RPC_FAR *SetInputSource )( 
            ISnappy __RPC_FAR * This,
            /* [in] */ BOOL bCamera);
        
        HRESULT ( __stdcall __RPC_FAR *IsSourceColor )( 
            ISnappy __RPC_FAR * This,
            /* [out] */ BOOL __RPC_FAR *pbColor);
        
        HRESULT ( __stdcall __RPC_FAR *SetSourceColor )( 
            ISnappy __RPC_FAR * This,
            /* [in] */ BOOL bColor);
        
        HRESULT ( __stdcall __RPC_FAR *IsSourceNegative )( 
            ISnappy __RPC_FAR * This,
            /* [out] */ BOOL __RPC_FAR *pbNegative);
        
        HRESULT ( __stdcall __RPC_FAR *SetSourceNegative )( 
            ISnappy __RPC_FAR * This,
            /* [in] */ BOOL bNegative);
        
        HRESULT ( __stdcall __RPC_FAR *SaveCurrentSettingsAsDefault )( 
            ISnappy __RPC_FAR * This);
        
        HRESULT ( __stdcall __RPC_FAR *GetDefaultSettings )( 
            ISnappy __RPC_FAR * This);
        
    } ISnappyVtbl;

    interface ISnappy
    {
        CONST_VTBL struct ISnappyVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISnappy_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ISnappy_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ISnappy_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ISnappy_SetAdvise(This,pNotify)	\
    (This)->lpVtbl -> SetAdvise(This,pNotify)

#define ISnappy_Snap(This,hPackedDIB)	\
    (This)->lpVtbl -> Snap(This,hPackedDIB)

#define ISnappy_SnapToUnprocessedData(This)	\
    (This)->lpVtbl -> SnapToUnprocessedData(This)

#define ISnappy_Abort(This)	\
    (This)->lpVtbl -> Abort(This)

#define ISnappy_GetSnapMode(This,pSnapMode)	\
    (This)->lpVtbl -> GetSnapMode(This,pSnapMode)

#define ISnappy_SetSnapMode(This,eSnapMode)	\
    (This)->lpVtbl -> SetSnapMode(This,eSnapMode)

#define ISnappy_IsSourceCamera(This,pbCamera)	\
    (This)->lpVtbl -> IsSourceCamera(This,pbCamera)

#define ISnappy_SetInputSource(This,bCamera)	\
    (This)->lpVtbl -> SetInputSource(This,bCamera)

#define ISnappy_IsSourceColor(This,pbColor)	\
    (This)->lpVtbl -> IsSourceColor(This,pbColor)

#define ISnappy_SetSourceColor(This,bColor)	\
    (This)->lpVtbl -> SetSourceColor(This,bColor)

#define ISnappy_IsSourceNegative(This,pbNegative)	\
    (This)->lpVtbl -> IsSourceNegative(This,pbNegative)

#define ISnappy_SetSourceNegative(This,bNegative)	\
    (This)->lpVtbl -> SetSourceNegative(This,bNegative)

#define ISnappy_SaveCurrentSettingsAsDefault(This)	\
    (This)->lpVtbl -> SaveCurrentSettingsAsDefault(This)

#define ISnappy_GetDefaultSettings(This)	\
    (This)->lpVtbl -> GetDefaultSettings(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT __stdcall ISnappy_SetAdvise_Proxy( 
    ISnappy __RPC_FAR * This,
    /* [in] */ ISnappyAdviseSync __RPC_FAR *pNotify);


void __RPC_STUB ISnappy_SetAdvise_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall ISnappy_Snap_Proxy( 
    ISnappy __RPC_FAR * This,
    /* [in] */ HGLOBAL hPackedDIB);


void __RPC_STUB ISnappy_Snap_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall ISnappy_SnapToUnprocessedData_Proxy( 
    ISnappy __RPC_FAR * This);


void __RPC_STUB ISnappy_SnapToUnprocessedData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall ISnappy_Abort_Proxy( 
    ISnappy __RPC_FAR * This);


void __RPC_STUB ISnappy_Abort_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall ISnappy_GetSnapMode_Proxy( 
    ISnappy __RPC_FAR * This,
    /* [out] */ ESnapMode __RPC_FAR *pSnapMode);


void __RPC_STUB ISnappy_GetSnapMode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall ISnappy_SetSnapMode_Proxy( 
    ISnappy __RPC_FAR * This,
    /* [in] */ ESnapMode eSnapMode);


void __RPC_STUB ISnappy_SetSnapMode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall ISnappy_IsSourceCamera_Proxy( 
    ISnappy __RPC_FAR * This,
    /* [out] */ BOOL __RPC_FAR *pbCamera);


void __RPC_STUB ISnappy_IsSourceCamera_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall ISnappy_SetInputSource_Proxy( 
    ISnappy __RPC_FAR * This,
    /* [in] */ BOOL bCamera);


void __RPC_STUB ISnappy_SetInputSource_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall ISnappy_IsSourceColor_Proxy( 
    ISnappy __RPC_FAR * This,
    /* [out] */ BOOL __RPC_FAR *pbColor);


void __RPC_STUB ISnappy_IsSourceColor_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall ISnappy_SetSourceColor_Proxy( 
    ISnappy __RPC_FAR * This,
    /* [in] */ BOOL bColor);


void __RPC_STUB ISnappy_SetSourceColor_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall ISnappy_IsSourceNegative_Proxy( 
    ISnappy __RPC_FAR * This,
    /* [out] */ BOOL __RPC_FAR *pbNegative);


void __RPC_STUB ISnappy_IsSourceNegative_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall ISnappy_SetSourceNegative_Proxy( 
    ISnappy __RPC_FAR * This,
    /* [in] */ BOOL bNegative);


void __RPC_STUB ISnappy_SetSourceNegative_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall ISnappy_SaveCurrentSettingsAsDefault_Proxy( 
    ISnappy __RPC_FAR * This);


void __RPC_STUB ISnappy_SaveCurrentSettingsAsDefault_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall ISnappy_GetDefaultSettings_Proxy( 
    ISnappy __RPC_FAR * This);


void __RPC_STUB ISnappy_GetDefaultSettings_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ISnappy_INTERFACE_DEFINED__ */


#ifndef __ISnappyAdviseSync_INTERFACE_DEFINED__
#define __ISnappyAdviseSync_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: ISnappyAdviseSync
 * at Tue May 13 18:04:40 1997
 * using MIDL 2.00.0102
 ****************************************/
/* [unique][uuid][local][object] */ 


			/* size is 2 */
typedef 
enum tagSnappyWarning
    {	SW_VideoLevelLow	= 0,
	SW_NotCamera	= SW_VideoLevelLow + 1
    }	ESnappyWarning;

			/* size is 2 */
typedef 
enum tagSnappyPhase
    {	SP_Acquiring	= 0,
	SP_Analyzing	= SP_Acquiring + 1
    }	ESnappyPhase;


EXTERN_C const IID IID_ISnappyAdviseSync;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface ISnappyAdviseSync : public IUnknown
    {
    public:
        virtual HRESULT __stdcall OnDIBReady( 
            /* [in] */ HGLOBAL hPackedDIB) = 0;
        
        virtual HRESULT __stdcall OnDataReady( void) = 0;
        
        virtual HRESULT __stdcall OnFieldSnapped( void) = 0;
        
        virtual HRESULT __stdcall OnLineProcessed( 
            /* [in] */ WORD nLine,
            /* [in] */ BYTE __RPC_FAR *pBits) = 0;
        
        virtual HRESULT __stdcall OnReadyToSnap( void) = 0;
        
        virtual HRESULT __stdcall OnPowerChanged( 
            /* [in] */ BOOL bPower) = 0;
        
        virtual HRESULT __stdcall OnVideoThruChanged( 
            /* [in] */ BOOL bTerminated) = 0;
        
        virtual HRESULT __stdcall OnPreviewImageReady( 
            /* [in] */ HGLOBAL hPackedDIB,
            /* [in] */ ISnappyPreview __RPC_FAR *pPreview) = 0;
        
        virtual HRESULT __stdcall OnLowBatteryChanged( 
            /* [in] */ BOOL bLow) = 0;
        
        virtual HRESULT __stdcall OnHotVideoChanged( 
            /* [in] */ BOOL bHot) = 0;
        
        virtual HRESULT __stdcall OnVideoAvailableChanged( 
            /* [in] */ BOOL bVideoAvailable) = 0;
        
        virtual HRESULT __stdcall OnError( 
            /* [in] */ int nErrorNum,
            int nCheckPoint) = 0;
        
        virtual HRESULT __stdcall OnWarning( 
            /* [in] */ ESnappyWarning eWaningNum) = 0;
        
        virtual HRESULT __stdcall OnStatusUpdate( 
            /* [in] */ ESnappyPhase ePhaseNum,
            /* [in] */ WORD nValue,
            /* [in] */ WORD nTotal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ISnappyAdviseSyncVtbl
    {
        
        HRESULT ( __stdcall __RPC_FAR *QueryInterface )( 
            ISnappyAdviseSync __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( __stdcall __RPC_FAR *AddRef )( 
            ISnappyAdviseSync __RPC_FAR * This);
        
        ULONG ( __stdcall __RPC_FAR *Release )( 
            ISnappyAdviseSync __RPC_FAR * This);
        
        HRESULT ( __stdcall __RPC_FAR *OnDIBReady )( 
            ISnappyAdviseSync __RPC_FAR * This,
            /* [in] */ HGLOBAL hPackedDIB);
        
        HRESULT ( __stdcall __RPC_FAR *OnDataReady )( 
            ISnappyAdviseSync __RPC_FAR * This);
        
        HRESULT ( __stdcall __RPC_FAR *OnFieldSnapped )( 
            ISnappyAdviseSync __RPC_FAR * This);
        
        HRESULT ( __stdcall __RPC_FAR *OnLineProcessed )( 
            ISnappyAdviseSync __RPC_FAR * This,
            /* [in] */ WORD nLine,
            /* [in] */ BYTE __RPC_FAR *pBits);
        
        HRESULT ( __stdcall __RPC_FAR *OnReadyToSnap )( 
            ISnappyAdviseSync __RPC_FAR * This);
        
        HRESULT ( __stdcall __RPC_FAR *OnPowerChanged )( 
            ISnappyAdviseSync __RPC_FAR * This,
            /* [in] */ BOOL bPower);
        
        HRESULT ( __stdcall __RPC_FAR *OnVideoThruChanged )( 
            ISnappyAdviseSync __RPC_FAR * This,
            /* [in] */ BOOL bTerminated);
        
        HRESULT ( __stdcall __RPC_FAR *OnPreviewImageReady )( 
            ISnappyAdviseSync __RPC_FAR * This,
            /* [in] */ HGLOBAL hPackedDIB,
            /* [in] */ ISnappyPreview __RPC_FAR *pPreview);
        
        HRESULT ( __stdcall __RPC_FAR *OnLowBatteryChanged )( 
            ISnappyAdviseSync __RPC_FAR * This,
            /* [in] */ BOOL bLow);
        
        HRESULT ( __stdcall __RPC_FAR *OnHotVideoChanged )( 
            ISnappyAdviseSync __RPC_FAR * This,
            /* [in] */ BOOL bHot);
        
        HRESULT ( __stdcall __RPC_FAR *OnVideoAvailableChanged )( 
            ISnappyAdviseSync __RPC_FAR * This,
            /* [in] */ BOOL bVideoAvailable);
        
        HRESULT ( __stdcall __RPC_FAR *OnError )( 
            ISnappyAdviseSync __RPC_FAR * This,
            /* [in] */ int nErrorNum,
            int nCheckPoint);
        
        HRESULT ( __stdcall __RPC_FAR *OnWarning )( 
            ISnappyAdviseSync __RPC_FAR * This,
            /* [in] */ ESnappyWarning eWaningNum);
        
        HRESULT ( __stdcall __RPC_FAR *OnStatusUpdate )( 
            ISnappyAdviseSync __RPC_FAR * This,
            /* [in] */ ESnappyPhase ePhaseNum,
            /* [in] */ WORD nValue,
            /* [in] */ WORD nTotal);
        
    } ISnappyAdviseSyncVtbl;

    interface ISnappyAdviseSync
    {
        CONST_VTBL struct ISnappyAdviseSyncVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISnappyAdviseSync_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ISnappyAdviseSync_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ISnappyAdviseSync_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ISnappyAdviseSync_OnDIBReady(This,hPackedDIB)	\
    (This)->lpVtbl -> OnDIBReady(This,hPackedDIB)

#define ISnappyAdviseSync_OnDataReady(This)	\
    (This)->lpVtbl -> OnDataReady(This)

#define ISnappyAdviseSync_OnFieldSnapped(This)	\
    (This)->lpVtbl -> OnFieldSnapped(This)

#define ISnappyAdviseSync_OnLineProcessed(This,nLine,pBits)	\
    (This)->lpVtbl -> OnLineProcessed(This,nLine,pBits)

#define ISnappyAdviseSync_OnReadyToSnap(This)	\
    (This)->lpVtbl -> OnReadyToSnap(This)

#define ISnappyAdviseSync_OnPowerChanged(This,bPower)	\
    (This)->lpVtbl -> OnPowerChanged(This,bPower)

#define ISnappyAdviseSync_OnVideoThruChanged(This,bTerminated)	\
    (This)->lpVtbl -> OnVideoThruChanged(This,bTerminated)

#define ISnappyAdviseSync_OnPreviewImageReady(This,hPackedDIB,pPreview)	\
    (This)->lpVtbl -> OnPreviewImageReady(This,hPackedDIB,pPreview)

#define ISnappyAdviseSync_OnLowBatteryChanged(This,bLow)	\
    (This)->lpVtbl -> OnLowBatteryChanged(This,bLow)

#define ISnappyAdviseSync_OnHotVideoChanged(This,bHot)	\
    (This)->lpVtbl -> OnHotVideoChanged(This,bHot)

#define ISnappyAdviseSync_OnVideoAvailableChanged(This,bVideoAvailable)	\
    (This)->lpVtbl -> OnVideoAvailableChanged(This,bVideoAvailable)

#define ISnappyAdviseSync_OnError(This,nErrorNum,nCheckPoint)	\
    (This)->lpVtbl -> OnError(This,nErrorNum,nCheckPoint)

#define ISnappyAdviseSync_OnWarning(This,eWaningNum)	\
    (This)->lpVtbl -> OnWarning(This,eWaningNum)

#define ISnappyAdviseSync_OnStatusUpdate(This,ePhaseNum,nValue,nTotal)	\
    (This)->lpVtbl -> OnStatusUpdate(This,ePhaseNum,nValue,nTotal)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT __stdcall ISnappyAdviseSync_OnDIBReady_Proxy( 
    ISnappyAdviseSync __RPC_FAR * This,
    /* [in] */ HGLOBAL hPackedDIB);


void __RPC_STUB ISnappyAdviseSync_OnDIBReady_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall ISnappyAdviseSync_OnDataReady_Proxy( 
    ISnappyAdviseSync __RPC_FAR * This);


void __RPC_STUB ISnappyAdviseSync_OnDataReady_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall ISnappyAdviseSync_OnFieldSnapped_Proxy( 
    ISnappyAdviseSync __RPC_FAR * This);


void __RPC_STUB ISnappyAdviseSync_OnFieldSnapped_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall ISnappyAdviseSync_OnLineProcessed_Proxy( 
    ISnappyAdviseSync __RPC_FAR * This,
    /* [in] */ WORD nLine,
    /* [in] */ BYTE __RPC_FAR *pBits);


void __RPC_STUB ISnappyAdviseSync_OnLineProcessed_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall ISnappyAdviseSync_OnReadyToSnap_Proxy( 
    ISnappyAdviseSync __RPC_FAR * This);


void __RPC_STUB ISnappyAdviseSync_OnReadyToSnap_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall ISnappyAdviseSync_OnPowerChanged_Proxy( 
    ISnappyAdviseSync __RPC_FAR * This,
    /* [in] */ BOOL bPower);


void __RPC_STUB ISnappyAdviseSync_OnPowerChanged_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall ISnappyAdviseSync_OnVideoThruChanged_Proxy( 
    ISnappyAdviseSync __RPC_FAR * This,
    /* [in] */ BOOL bTerminated);


void __RPC_STUB ISnappyAdviseSync_OnVideoThruChanged_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall ISnappyAdviseSync_OnPreviewImageReady_Proxy( 
    ISnappyAdviseSync __RPC_FAR * This,
    /* [in] */ HGLOBAL hPackedDIB,
    /* [in] */ ISnappyPreview __RPC_FAR *pPreview);


void __RPC_STUB ISnappyAdviseSync_OnPreviewImageReady_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall ISnappyAdviseSync_OnLowBatteryChanged_Proxy( 
    ISnappyAdviseSync __RPC_FAR * This,
    /* [in] */ BOOL bLow);


void __RPC_STUB ISnappyAdviseSync_OnLowBatteryChanged_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall ISnappyAdviseSync_OnHotVideoChanged_Proxy( 
    ISnappyAdviseSync __RPC_FAR * This,
    /* [in] */ BOOL bHot);


void __RPC_STUB ISnappyAdviseSync_OnHotVideoChanged_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall ISnappyAdviseSync_OnVideoAvailableChanged_Proxy( 
    ISnappyAdviseSync __RPC_FAR * This,
    /* [in] */ BOOL bVideoAvailable);


void __RPC_STUB ISnappyAdviseSync_OnVideoAvailableChanged_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall ISnappyAdviseSync_OnError_Proxy( 
    ISnappyAdviseSync __RPC_FAR * This,
    /* [in] */ int nErrorNum,
    int nCheckPoint);


void __RPC_STUB ISnappyAdviseSync_OnError_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall ISnappyAdviseSync_OnWarning_Proxy( 
    ISnappyAdviseSync __RPC_FAR * This,
    /* [in] */ ESnappyWarning eWaningNum);


void __RPC_STUB ISnappyAdviseSync_OnWarning_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall ISnappyAdviseSync_OnStatusUpdate_Proxy( 
    ISnappyAdviseSync __RPC_FAR * This,
    /* [in] */ ESnappyPhase ePhaseNum,
    /* [in] */ WORD nValue,
    /* [in] */ WORD nTotal);


void __RPC_STUB ISnappyAdviseSync_OnStatusUpdate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ISnappyAdviseSync_INTERFACE_DEFINED__ */


#ifndef __ISnappyPreview_INTERFACE_DEFINED__
#define __ISnappyPreview_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: ISnappyPreview
 * at Tue May 13 18:04:40 1997
 * using MIDL 2.00.0102
 ****************************************/
/* [unique][uuid][local][object] */ 



EXTERN_C const IID IID_ISnappyPreview;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface ISnappyPreview : public IUnknown
    {
    public:
        virtual HRESULT __stdcall SetAdvise( 
            /* [in] */ ISnappyAdviseSync __RPC_FAR *pNotify) = 0;
        
        virtual HRESULT __stdcall AllocPreviewDIB( 
            /* [out] */ HGLOBAL __RPC_FAR *phPackedDIB) = 0;
        
        virtual HRESULT __stdcall FreePreviewDIB( 
            /* [in] */ HGLOBAL hPackedDIB) = 0;
        
        virtual HRESULT __stdcall SetPreviewDIB( 
            /* [in] */ HGLOBAL hPackedDIB) = 0;
        
        virtual HRESULT __stdcall StartPreviewing( void) = 0;
        
        virtual HRESULT __stdcall UnlockPreviewImage( void) = 0;
        
        virtual HRESULT __stdcall Abort( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ISnappyPreviewVtbl
    {
        
        HRESULT ( __stdcall __RPC_FAR *QueryInterface )( 
            ISnappyPreview __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( __stdcall __RPC_FAR *AddRef )( 
            ISnappyPreview __RPC_FAR * This);
        
        ULONG ( __stdcall __RPC_FAR *Release )( 
            ISnappyPreview __RPC_FAR * This);
        
        HRESULT ( __stdcall __RPC_FAR *SetAdvise )( 
            ISnappyPreview __RPC_FAR * This,
            /* [in] */ ISnappyAdviseSync __RPC_FAR *pNotify);
        
        HRESULT ( __stdcall __RPC_FAR *AllocPreviewDIB )( 
            ISnappyPreview __RPC_FAR * This,
            /* [out] */ HGLOBAL __RPC_FAR *phPackedDIB);
        
        HRESULT ( __stdcall __RPC_FAR *FreePreviewDIB )( 
            ISnappyPreview __RPC_FAR * This,
            /* [in] */ HGLOBAL hPackedDIB);
        
        HRESULT ( __stdcall __RPC_FAR *SetPreviewDIB )( 
            ISnappyPreview __RPC_FAR * This,
            /* [in] */ HGLOBAL hPackedDIB);
        
        HRESULT ( __stdcall __RPC_FAR *StartPreviewing )( 
            ISnappyPreview __RPC_FAR * This);
        
        HRESULT ( __stdcall __RPC_FAR *UnlockPreviewImage )( 
            ISnappyPreview __RPC_FAR * This);
        
        HRESULT ( __stdcall __RPC_FAR *Abort )( 
            ISnappyPreview __RPC_FAR * This);
        
    } ISnappyPreviewVtbl;

    interface ISnappyPreview
    {
        CONST_VTBL struct ISnappyPreviewVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISnappyPreview_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ISnappyPreview_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ISnappyPreview_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ISnappyPreview_SetAdvise(This,pNotify)	\
    (This)->lpVtbl -> SetAdvise(This,pNotify)

#define ISnappyPreview_AllocPreviewDIB(This,phPackedDIB)	\
    (This)->lpVtbl -> AllocPreviewDIB(This,phPackedDIB)

#define ISnappyPreview_FreePreviewDIB(This,hPackedDIB)	\
    (This)->lpVtbl -> FreePreviewDIB(This,hPackedDIB)

#define ISnappyPreview_SetPreviewDIB(This,hPackedDIB)	\
    (This)->lpVtbl -> SetPreviewDIB(This,hPackedDIB)

#define ISnappyPreview_StartPreviewing(This)	\
    (This)->lpVtbl -> StartPreviewing(This)

#define ISnappyPreview_UnlockPreviewImage(This)	\
    (This)->lpVtbl -> UnlockPreviewImage(This)

#define ISnappyPreview_Abort(This)	\
    (This)->lpVtbl -> Abort(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT __stdcall ISnappyPreview_SetAdvise_Proxy( 
    ISnappyPreview __RPC_FAR * This,
    /* [in] */ ISnappyAdviseSync __RPC_FAR *pNotify);


void __RPC_STUB ISnappyPreview_SetAdvise_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall ISnappyPreview_AllocPreviewDIB_Proxy( 
    ISnappyPreview __RPC_FAR * This,
    /* [out] */ HGLOBAL __RPC_FAR *phPackedDIB);


void __RPC_STUB ISnappyPreview_AllocPreviewDIB_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall ISnappyPreview_FreePreviewDIB_Proxy( 
    ISnappyPreview __RPC_FAR * This,
    /* [in] */ HGLOBAL hPackedDIB);


void __RPC_STUB ISnappyPreview_FreePreviewDIB_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall ISnappyPreview_SetPreviewDIB_Proxy( 
    ISnappyPreview __RPC_FAR * This,
    /* [in] */ HGLOBAL hPackedDIB);


void __RPC_STUB ISnappyPreview_SetPreviewDIB_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall ISnappyPreview_StartPreviewing_Proxy( 
    ISnappyPreview __RPC_FAR * This);


void __RPC_STUB ISnappyPreview_StartPreviewing_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall ISnappyPreview_UnlockPreviewImage_Proxy( 
    ISnappyPreview __RPC_FAR * This);


void __RPC_STUB ISnappyPreview_UnlockPreviewImage_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall ISnappyPreview_Abort_Proxy( 
    ISnappyPreview __RPC_FAR * This);


void __RPC_STUB ISnappyPreview_Abort_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ISnappyPreview_INTERFACE_DEFINED__ */


#ifndef __ISnappyProcess_INTERFACE_DEFINED__
#define __ISnappyProcess_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: ISnappyProcess
 * at Tue May 13 18:04:40 1997
 * using MIDL 2.00.0102
 ****************************************/
/* [unique][uuid][local][object] */ 



EXTERN_C const IID IID_ISnappyProcess;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface ISnappyProcess : public IUnknown
    {
    public:
        virtual HRESULT __stdcall SetAdvise( 
            /* [in] */ ISnappyAdviseSync __RPC_FAR *pNotify) = 0;
        
        virtual HRESULT __stdcall GetSnappyData( 
            /* [out][in] */ BYTE __RPC_FAR *__RPC_FAR *ppData) = 0;
        
        virtual HRESULT __stdcall UseSnappyData( 
            /* [in] */ BYTE __RPC_FAR *pData) = 0;
        
        virtual HRESULT __stdcall SaveSnappyData( 
            /* [in] */ LPCTSTR pFileName) = 0;
        
        virtual HRESULT __stdcall LoadSnappyData( 
            /* [in] */ LPCTSTR pFileName) = 0;
        
        virtual HRESULT __stdcall ProcessSnappyData( void) = 0;
        
        virtual HRESULT __stdcall AllocProcessDIB( 
            /* [out] */ HGLOBAL __RPC_FAR *phPackedDIB) = 0;
        
        virtual HRESULT __stdcall FreeProcessDIB( 
            /* [in] */ HGLOBAL hPackedDIB) = 0;
        
        virtual HRESULT __stdcall SetProcessDIB( 
            /* [in] */ HGLOBAL hPackedDIB) = 0;
        
        virtual HRESULT __stdcall ProcessSnappyDataLine( 
            /* [in] */ WORD nLine,
            /* [in] */ BYTE __RPC_FAR *pBits) = 0;
        
        virtual HRESULT __stdcall SetProcessSpeed( 
            /* [in] */ BOOL bSpeed) = 0;
        
        virtual HRESULT __stdcall Abort( void) = 0;
        
        virtual HRESULT __stdcall GetImageSize( 
            /* [out] */ WORD __RPC_FAR *pnWidth,
            /* [out] */ WORD __RPC_FAR *pnHeight,
            /* [out] */ WORD __RPC_FAR *pnBitDepth) = 0;
        
        virtual HRESULT __stdcall SetImageSize( 
            /* [in] */ WORD nWidth,
            /* [in] */ WORD nHeight,
            /* [in] */ WORD nBitDepth) = 0;
        
        virtual HRESULT __stdcall GetSourceCropping( 
            /* [out] */ WORD __RPC_FAR *pnLeft,
            /* [out] */ WORD __RPC_FAR *pnTop,
            /* [out] */ WORD __RPC_FAR *pnRight,
            /* [out] */ WORD __RPC_FAR *pnBottom) = 0;
        
        virtual HRESULT __stdcall SetSourceCropping( 
            /* [in] */ WORD nLeft,
            /* [in] */ WORD nTop,
            /* [in] */ WORD nRight,
            /* [in] */ WORD nBottom) = 0;
        
        virtual HRESULT __stdcall GetMaxCropSize( 
            /* [out] */ WORD __RPC_FAR *pnWidth,
            /* [out] */ WORD __RPC_FAR *pnHeight) = 0;
        
        virtual HRESULT __stdcall GetTint( 
            /* [out] */ long __RPC_FAR *pnTint) = 0;
        
        virtual HRESULT __stdcall SetTint( 
            /* [in] */ long nTint) = 0;
        
        virtual HRESULT __stdcall GetRed( 
            /* [out] */ long __RPC_FAR *pnRed) = 0;
        
        virtual HRESULT __stdcall SetRed( 
            /* [in] */ long nRed) = 0;
        
        virtual HRESULT __stdcall GetGreen( 
            /* [out] */ long __RPC_FAR *pnGreen) = 0;
        
        virtual HRESULT __stdcall SetGreen( 
            /* [in] */ long nGreen) = 0;
        
        virtual HRESULT __stdcall GetBlue( 
            /* [out] */ long __RPC_FAR *pnBlue) = 0;
        
        virtual HRESULT __stdcall SetBlue( 
            /* [in] */ long nBlue) = 0;
        
        virtual HRESULT __stdcall GetSaturation( 
            /* [out] */ long __RPC_FAR *pnSaturation) = 0;
        
        virtual HRESULT __stdcall SetSaturation( 
            /* [in] */ long nSaturation) = 0;
        
        virtual HRESULT __stdcall GetBrightness( 
            /* [out] */ long __RPC_FAR *pnBrightness) = 0;
        
        virtual HRESULT __stdcall SetBrightness( 
            /* [in] */ long nBrightness) = 0;
        
        virtual HRESULT __stdcall GetContrast( 
            /* [out] */ long __RPC_FAR *pnContrast) = 0;
        
        virtual HRESULT __stdcall SetContrast( 
            /* [in] */ long nContrast) = 0;
        
        virtual HRESULT __stdcall GetGamma( 
            /* [out] */ long __RPC_FAR *pnGamma) = 0;
        
        virtual HRESULT __stdcall SetGamma( 
            /* [in] */ long nGamma) = 0;
        
        virtual HRESULT __stdcall GetSharpness( 
            /* [out] */ long __RPC_FAR *pnSharpness) = 0;
        
        virtual HRESULT __stdcall SetSharpness( 
            /* [in] */ long nSharpness) = 0;
        
        virtual HRESULT __stdcall SaveCurrentProcessSettingsAsDefault( void) = 0;
        
        virtual HRESULT __stdcall GetDefaultProcessSettings( void) = 0;
        
        virtual HRESULT __stdcall CanProcess( 
            /* [out] */ BOOL __RPC_FAR *pbProcessAllowed) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ISnappyProcessVtbl
    {
        
        HRESULT ( __stdcall __RPC_FAR *QueryInterface )( 
            ISnappyProcess __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( __stdcall __RPC_FAR *AddRef )( 
            ISnappyProcess __RPC_FAR * This);
        
        ULONG ( __stdcall __RPC_FAR *Release )( 
            ISnappyProcess __RPC_FAR * This);
        
        HRESULT ( __stdcall __RPC_FAR *SetAdvise )( 
            ISnappyProcess __RPC_FAR * This,
            /* [in] */ ISnappyAdviseSync __RPC_FAR *pNotify);
        
        HRESULT ( __stdcall __RPC_FAR *GetSnappyData )( 
            ISnappyProcess __RPC_FAR * This,
            /* [out][in] */ BYTE __RPC_FAR *__RPC_FAR *ppData);
        
        HRESULT ( __stdcall __RPC_FAR *UseSnappyData )( 
            ISnappyProcess __RPC_FAR * This,
            /* [in] */ BYTE __RPC_FAR *pData);
        
        HRESULT ( __stdcall __RPC_FAR *SaveSnappyData )( 
            ISnappyProcess __RPC_FAR * This,
            /* [in] */ LPCTSTR pFileName);
        
        HRESULT ( __stdcall __RPC_FAR *LoadSnappyData )( 
            ISnappyProcess __RPC_FAR * This,
            /* [in] */ LPCTSTR pFileName);
        
        HRESULT ( __stdcall __RPC_FAR *ProcessSnappyData )( 
            ISnappyProcess __RPC_FAR * This);
        
        HRESULT ( __stdcall __RPC_FAR *AllocProcessDIB )( 
            ISnappyProcess __RPC_FAR * This,
            /* [out] */ HGLOBAL __RPC_FAR *phPackedDIB);
        
        HRESULT ( __stdcall __RPC_FAR *FreeProcessDIB )( 
            ISnappyProcess __RPC_FAR * This,
            /* [in] */ HGLOBAL hPackedDIB);
        
        HRESULT ( __stdcall __RPC_FAR *SetProcessDIB )( 
            ISnappyProcess __RPC_FAR * This,
            /* [in] */ HGLOBAL hPackedDIB);
        
        HRESULT ( __stdcall __RPC_FAR *ProcessSnappyDataLine )( 
            ISnappyProcess __RPC_FAR * This,
            /* [in] */ WORD nLine,
            /* [in] */ BYTE __RPC_FAR *pBits);
        
        HRESULT ( __stdcall __RPC_FAR *SetProcessSpeed )( 
            ISnappyProcess __RPC_FAR * This,
            /* [in] */ BOOL bSpeed);
        
        HRESULT ( __stdcall __RPC_FAR *Abort )( 
            ISnappyProcess __RPC_FAR * This);
        
        HRESULT ( __stdcall __RPC_FAR *GetImageSize )( 
            ISnappyProcess __RPC_FAR * This,
            /* [out] */ WORD __RPC_FAR *pnWidth,
            /* [out] */ WORD __RPC_FAR *pnHeight,
            /* [out] */ WORD __RPC_FAR *pnBitDepth);
        
        HRESULT ( __stdcall __RPC_FAR *SetImageSize )( 
            ISnappyProcess __RPC_FAR * This,
            /* [in] */ WORD nWidth,
            /* [in] */ WORD nHeight,
            /* [in] */ WORD nBitDepth);
        
        HRESULT ( __stdcall __RPC_FAR *GetSourceCropping )( 
            ISnappyProcess __RPC_FAR * This,
            /* [out] */ WORD __RPC_FAR *pnLeft,
            /* [out] */ WORD __RPC_FAR *pnTop,
            /* [out] */ WORD __RPC_FAR *pnRight,
            /* [out] */ WORD __RPC_FAR *pnBottom);
        
        HRESULT ( __stdcall __RPC_FAR *SetSourceCropping )( 
            ISnappyProcess __RPC_FAR * This,
            /* [in] */ WORD nLeft,
            /* [in] */ WORD nTop,
            /* [in] */ WORD nRight,
            /* [in] */ WORD nBottom);
        
        HRESULT ( __stdcall __RPC_FAR *GetMaxCropSize )( 
            ISnappyProcess __RPC_FAR * This,
            /* [out] */ WORD __RPC_FAR *pnWidth,
            /* [out] */ WORD __RPC_FAR *pnHeight);
        
        HRESULT ( __stdcall __RPC_FAR *GetTint )( 
            ISnappyProcess __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *pnTint);
        
        HRESULT ( __stdcall __RPC_FAR *SetTint )( 
            ISnappyProcess __RPC_FAR * This,
            /* [in] */ long nTint);
        
        HRESULT ( __stdcall __RPC_FAR *GetRed )( 
            ISnappyProcess __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *pnRed);
        
        HRESULT ( __stdcall __RPC_FAR *SetRed )( 
            ISnappyProcess __RPC_FAR * This,
            /* [in] */ long nRed);
        
        HRESULT ( __stdcall __RPC_FAR *GetGreen )( 
            ISnappyProcess __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *pnGreen);
        
        HRESULT ( __stdcall __RPC_FAR *SetGreen )( 
            ISnappyProcess __RPC_FAR * This,
            /* [in] */ long nGreen);
        
        HRESULT ( __stdcall __RPC_FAR *GetBlue )( 
            ISnappyProcess __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *pnBlue);
        
        HRESULT ( __stdcall __RPC_FAR *SetBlue )( 
            ISnappyProcess __RPC_FAR * This,
            /* [in] */ long nBlue);
        
        HRESULT ( __stdcall __RPC_FAR *GetSaturation )( 
            ISnappyProcess __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *pnSaturation);
        
        HRESULT ( __stdcall __RPC_FAR *SetSaturation )( 
            ISnappyProcess __RPC_FAR * This,
            /* [in] */ long nSaturation);
        
        HRESULT ( __stdcall __RPC_FAR *GetBrightness )( 
            ISnappyProcess __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *pnBrightness);
        
        HRESULT ( __stdcall __RPC_FAR *SetBrightness )( 
            ISnappyProcess __RPC_FAR * This,
            /* [in] */ long nBrightness);
        
        HRESULT ( __stdcall __RPC_FAR *GetContrast )( 
            ISnappyProcess __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *pnContrast);
        
        HRESULT ( __stdcall __RPC_FAR *SetContrast )( 
            ISnappyProcess __RPC_FAR * This,
            /* [in] */ long nContrast);
        
        HRESULT ( __stdcall __RPC_FAR *GetGamma )( 
            ISnappyProcess __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *pnGamma);
        
        HRESULT ( __stdcall __RPC_FAR *SetGamma )( 
            ISnappyProcess __RPC_FAR * This,
            /* [in] */ long nGamma);
        
        HRESULT ( __stdcall __RPC_FAR *GetSharpness )( 
            ISnappyProcess __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *pnSharpness);
        
        HRESULT ( __stdcall __RPC_FAR *SetSharpness )( 
            ISnappyProcess __RPC_FAR * This,
            /* [in] */ long nSharpness);
        
        HRESULT ( __stdcall __RPC_FAR *SaveCurrentProcessSettingsAsDefault )( 
            ISnappyProcess __RPC_FAR * This);
        
        HRESULT ( __stdcall __RPC_FAR *GetDefaultProcessSettings )( 
            ISnappyProcess __RPC_FAR * This);
        
        HRESULT ( __stdcall __RPC_FAR *CanProcess )( 
            ISnappyProcess __RPC_FAR * This,
            /* [out] */ BOOL __RPC_FAR *pbProcessAllowed);
        
    } ISnappyProcessVtbl;

    interface ISnappyProcess
    {
        CONST_VTBL struct ISnappyProcessVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISnappyProcess_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ISnappyProcess_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ISnappyProcess_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ISnappyProcess_SetAdvise(This,pNotify)	\
    (This)->lpVtbl -> SetAdvise(This,pNotify)

#define ISnappyProcess_GetSnappyData(This,ppData)	\
    (This)->lpVtbl -> GetSnappyData(This,ppData)

#define ISnappyProcess_UseSnappyData(This,pData)	\
    (This)->lpVtbl -> UseSnappyData(This,pData)

#define ISnappyProcess_SaveSnappyData(This,pFileName)	\
    (This)->lpVtbl -> SaveSnappyData(This,pFileName)

#define ISnappyProcess_LoadSnappyData(This,pFileName)	\
    (This)->lpVtbl -> LoadSnappyData(This,pFileName)

#define ISnappyProcess_ProcessSnappyData(This)	\
    (This)->lpVtbl -> ProcessSnappyData(This)

#define ISnappyProcess_AllocProcessDIB(This,phPackedDIB)	\
    (This)->lpVtbl -> AllocProcessDIB(This,phPackedDIB)

#define ISnappyProcess_FreeProcessDIB(This,hPackedDIB)	\
    (This)->lpVtbl -> FreeProcessDIB(This,hPackedDIB)

#define ISnappyProcess_SetProcessDIB(This,hPackedDIB)	\
    (This)->lpVtbl -> SetProcessDIB(This,hPackedDIB)

#define ISnappyProcess_ProcessSnappyDataLine(This,nLine,pBits)	\
    (This)->lpVtbl -> ProcessSnappyDataLine(This,nLine,pBits)

#define ISnappyProcess_SetProcessSpeed(This,bSpeed)	\
    (This)->lpVtbl -> SetProcessSpeed(This,bSpeed)

#define ISnappyProcess_Abort(This)	\
    (This)->lpVtbl -> Abort(This)

#define ISnappyProcess_GetImageSize(This,pnWidth,pnHeight,pnBitDepth)	\
    (This)->lpVtbl -> GetImageSize(This,pnWidth,pnHeight,pnBitDepth)

#define ISnappyProcess_SetImageSize(This,nWidth,nHeight,nBitDepth)	\
    (This)->lpVtbl -> SetImageSize(This,nWidth,nHeight,nBitDepth)

#define ISnappyProcess_GetSourceCropping(This,pnLeft,pnTop,pnRight,pnBottom)	\
    (This)->lpVtbl -> GetSourceCropping(This,pnLeft,pnTop,pnRight,pnBottom)

#define ISnappyProcess_SetSourceCropping(This,nLeft,nTop,nRight,nBottom)	\
    (This)->lpVtbl -> SetSourceCropping(This,nLeft,nTop,nRight,nBottom)

#define ISnappyProcess_GetMaxCropSize(This,pnWidth,pnHeight)	\
    (This)->lpVtbl -> GetMaxCropSize(This,pnWidth,pnHeight)

#define ISnappyProcess_GetTint(This,pnTint)	\
    (This)->lpVtbl -> GetTint(This,pnTint)

#define ISnappyProcess_SetTint(This,nTint)	\
    (This)->lpVtbl -> SetTint(This,nTint)

#define ISnappyProcess_GetRed(This,pnRed)	\
    (This)->lpVtbl -> GetRed(This,pnRed)

#define ISnappyProcess_SetRed(This,nRed)	\
    (This)->lpVtbl -> SetRed(This,nRed)

#define ISnappyProcess_GetGreen(This,pnGreen)	\
    (This)->lpVtbl -> GetGreen(This,pnGreen)

#define ISnappyProcess_SetGreen(This,nGreen)	\
    (This)->lpVtbl -> SetGreen(This,nGreen)

#define ISnappyProcess_GetBlue(This,pnBlue)	\
    (This)->lpVtbl -> GetBlue(This,pnBlue)

#define ISnappyProcess_SetBlue(This,nBlue)	\
    (This)->lpVtbl -> SetBlue(This,nBlue)

#define ISnappyProcess_GetSaturation(This,pnSaturation)	\
    (This)->lpVtbl -> GetSaturation(This,pnSaturation)

#define ISnappyProcess_SetSaturation(This,nSaturation)	\
    (This)->lpVtbl -> SetSaturation(This,nSaturation)

#define ISnappyProcess_GetBrightness(This,pnBrightness)	\
    (This)->lpVtbl -> GetBrightness(This,pnBrightness)

#define ISnappyProcess_SetBrightness(This,nBrightness)	\
    (This)->lpVtbl -> SetBrightness(This,nBrightness)

#define ISnappyProcess_GetContrast(This,pnContrast)	\
    (This)->lpVtbl -> GetContrast(This,pnContrast)

#define ISnappyProcess_SetContrast(This,nContrast)	\
    (This)->lpVtbl -> SetContrast(This,nContrast)

#define ISnappyProcess_GetGamma(This,pnGamma)	\
    (This)->lpVtbl -> GetGamma(This,pnGamma)

#define ISnappyProcess_SetGamma(This,nGamma)	\
    (This)->lpVtbl -> SetGamma(This,nGamma)

#define ISnappyProcess_GetSharpness(This,pnSharpness)	\
    (This)->lpVtbl -> GetSharpness(This,pnSharpness)

#define ISnappyProcess_SetSharpness(This,nSharpness)	\
    (This)->lpVtbl -> SetSharpness(This,nSharpness)

#define ISnappyProcess_SaveCurrentProcessSettingsAsDefault(This)	\
    (This)->lpVtbl -> SaveCurrentProcessSettingsAsDefault(This)

#define ISnappyProcess_GetDefaultProcessSettings(This)	\
    (This)->lpVtbl -> GetDefaultProcessSettings(This)

#define ISnappyProcess_CanProcess(This,pbProcessAllowed)	\
    (This)->lpVtbl -> CanProcess(This,pbProcessAllowed)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT __stdcall ISnappyProcess_SetAdvise_Proxy( 
    ISnappyProcess __RPC_FAR * This,
    /* [in] */ ISnappyAdviseSync __RPC_FAR *pNotify);


void __RPC_STUB ISnappyProcess_SetAdvise_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall ISnappyProcess_GetSnappyData_Proxy( 
    ISnappyProcess __RPC_FAR * This,
    /* [out][in] */ BYTE __RPC_FAR *__RPC_FAR *ppData);


void __RPC_STUB ISnappyProcess_GetSnappyData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall ISnappyProcess_UseSnappyData_Proxy( 
    ISnappyProcess __RPC_FAR * This,
    /* [in] */ BYTE __RPC_FAR *pData);


void __RPC_STUB ISnappyProcess_UseSnappyData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall ISnappyProcess_SaveSnappyData_Proxy( 
    ISnappyProcess __RPC_FAR * This,
    /* [in] */ LPCTSTR pFileName);


void __RPC_STUB ISnappyProcess_SaveSnappyData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall ISnappyProcess_LoadSnappyData_Proxy( 
    ISnappyProcess __RPC_FAR * This,
    /* [in] */ LPCTSTR pFileName);


void __RPC_STUB ISnappyProcess_LoadSnappyData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall ISnappyProcess_ProcessSnappyData_Proxy( 
    ISnappyProcess __RPC_FAR * This);


void __RPC_STUB ISnappyProcess_ProcessSnappyData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall ISnappyProcess_AllocProcessDIB_Proxy( 
    ISnappyProcess __RPC_FAR * This,
    /* [out] */ HGLOBAL __RPC_FAR *phPackedDIB);


void __RPC_STUB ISnappyProcess_AllocProcessDIB_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall ISnappyProcess_FreeProcessDIB_Proxy( 
    ISnappyProcess __RPC_FAR * This,
    /* [in] */ HGLOBAL hPackedDIB);


void __RPC_STUB ISnappyProcess_FreeProcessDIB_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall ISnappyProcess_SetProcessDIB_Proxy( 
    ISnappyProcess __RPC_FAR * This,
    /* [in] */ HGLOBAL hPackedDIB);


void __RPC_STUB ISnappyProcess_SetProcessDIB_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall ISnappyProcess_ProcessSnappyDataLine_Proxy( 
    ISnappyProcess __RPC_FAR * This,
    /* [in] */ WORD nLine,
    /* [in] */ BYTE __RPC_FAR *pBits);


void __RPC_STUB ISnappyProcess_ProcessSnappyDataLine_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall ISnappyProcess_SetProcessSpeed_Proxy( 
    ISnappyProcess __RPC_FAR * This,
    /* [in] */ BOOL bSpeed);


void __RPC_STUB ISnappyProcess_SetProcessSpeed_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall ISnappyProcess_Abort_Proxy( 
    ISnappyProcess __RPC_FAR * This);


void __RPC_STUB ISnappyProcess_Abort_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall ISnappyProcess_GetImageSize_Proxy( 
    ISnappyProcess __RPC_FAR * This,
    /* [out] */ WORD __RPC_FAR *pnWidth,
    /* [out] */ WORD __RPC_FAR *pnHeight,
    /* [out] */ WORD __RPC_FAR *pnBitDepth);


void __RPC_STUB ISnappyProcess_GetImageSize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall ISnappyProcess_SetImageSize_Proxy( 
    ISnappyProcess __RPC_FAR * This,
    /* [in] */ WORD nWidth,
    /* [in] */ WORD nHeight,
    /* [in] */ WORD nBitDepth);


void __RPC_STUB ISnappyProcess_SetImageSize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall ISnappyProcess_GetSourceCropping_Proxy( 
    ISnappyProcess __RPC_FAR * This,
    /* [out] */ WORD __RPC_FAR *pnLeft,
    /* [out] */ WORD __RPC_FAR *pnTop,
    /* [out] */ WORD __RPC_FAR *pnRight,
    /* [out] */ WORD __RPC_FAR *pnBottom);


void __RPC_STUB ISnappyProcess_GetSourceCropping_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall ISnappyProcess_SetSourceCropping_Proxy( 
    ISnappyProcess __RPC_FAR * This,
    /* [in] */ WORD nLeft,
    /* [in] */ WORD nTop,
    /* [in] */ WORD nRight,
    /* [in] */ WORD nBottom);


void __RPC_STUB ISnappyProcess_SetSourceCropping_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall ISnappyProcess_GetMaxCropSize_Proxy( 
    ISnappyProcess __RPC_FAR * This,
    /* [out] */ WORD __RPC_FAR *pnWidth,
    /* [out] */ WORD __RPC_FAR *pnHeight);


void __RPC_STUB ISnappyProcess_GetMaxCropSize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall ISnappyProcess_GetTint_Proxy( 
    ISnappyProcess __RPC_FAR * This,
    /* [out] */ long __RPC_FAR *pnTint);


void __RPC_STUB ISnappyProcess_GetTint_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall ISnappyProcess_SetTint_Proxy( 
    ISnappyProcess __RPC_FAR * This,
    /* [in] */ long nTint);


void __RPC_STUB ISnappyProcess_SetTint_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall ISnappyProcess_GetRed_Proxy( 
    ISnappyProcess __RPC_FAR * This,
    /* [out] */ long __RPC_FAR *pnRed);


void __RPC_STUB ISnappyProcess_GetRed_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall ISnappyProcess_SetRed_Proxy( 
    ISnappyProcess __RPC_FAR * This,
    /* [in] */ long nRed);


void __RPC_STUB ISnappyProcess_SetRed_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall ISnappyProcess_GetGreen_Proxy( 
    ISnappyProcess __RPC_FAR * This,
    /* [out] */ long __RPC_FAR *pnGreen);


void __RPC_STUB ISnappyProcess_GetGreen_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall ISnappyProcess_SetGreen_Proxy( 
    ISnappyProcess __RPC_FAR * This,
    /* [in] */ long nGreen);


void __RPC_STUB ISnappyProcess_SetGreen_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall ISnappyProcess_GetBlue_Proxy( 
    ISnappyProcess __RPC_FAR * This,
    /* [out] */ long __RPC_FAR *pnBlue);


void __RPC_STUB ISnappyProcess_GetBlue_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall ISnappyProcess_SetBlue_Proxy( 
    ISnappyProcess __RPC_FAR * This,
    /* [in] */ long nBlue);


void __RPC_STUB ISnappyProcess_SetBlue_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall ISnappyProcess_GetSaturation_Proxy( 
    ISnappyProcess __RPC_FAR * This,
    /* [out] */ long __RPC_FAR *pnSaturation);


void __RPC_STUB ISnappyProcess_GetSaturation_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall ISnappyProcess_SetSaturation_Proxy( 
    ISnappyProcess __RPC_FAR * This,
    /* [in] */ long nSaturation);


void __RPC_STUB ISnappyProcess_SetSaturation_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall ISnappyProcess_GetBrightness_Proxy( 
    ISnappyProcess __RPC_FAR * This,
    /* [out] */ long __RPC_FAR *pnBrightness);


void __RPC_STUB ISnappyProcess_GetBrightness_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall ISnappyProcess_SetBrightness_Proxy( 
    ISnappyProcess __RPC_FAR * This,
    /* [in] */ long nBrightness);


void __RPC_STUB ISnappyProcess_SetBrightness_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall ISnappyProcess_GetContrast_Proxy( 
    ISnappyProcess __RPC_FAR * This,
    /* [out] */ long __RPC_FAR *pnContrast);


void __RPC_STUB ISnappyProcess_GetContrast_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall ISnappyProcess_SetContrast_Proxy( 
    ISnappyProcess __RPC_FAR * This,
    /* [in] */ long nContrast);


void __RPC_STUB ISnappyProcess_SetContrast_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall ISnappyProcess_GetGamma_Proxy( 
    ISnappyProcess __RPC_FAR * This,
    /* [out] */ long __RPC_FAR *pnGamma);


void __RPC_STUB ISnappyProcess_GetGamma_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall ISnappyProcess_SetGamma_Proxy( 
    ISnappyProcess __RPC_FAR * This,
    /* [in] */ long nGamma);


void __RPC_STUB ISnappyProcess_SetGamma_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall ISnappyProcess_GetSharpness_Proxy( 
    ISnappyProcess __RPC_FAR * This,
    /* [out] */ long __RPC_FAR *pnSharpness);


void __RPC_STUB ISnappyProcess_GetSharpness_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall ISnappyProcess_SetSharpness_Proxy( 
    ISnappyProcess __RPC_FAR * This,
    /* [in] */ long nSharpness);


void __RPC_STUB ISnappyProcess_SetSharpness_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall ISnappyProcess_SaveCurrentProcessSettingsAsDefault_Proxy( 
    ISnappyProcess __RPC_FAR * This);


void __RPC_STUB ISnappyProcess_SaveCurrentProcessSettingsAsDefault_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall ISnappyProcess_GetDefaultProcessSettings_Proxy( 
    ISnappyProcess __RPC_FAR * This);


void __RPC_STUB ISnappyProcess_GetDefaultProcessSettings_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall ISnappyProcess_CanProcess_Proxy( 
    ISnappyProcess __RPC_FAR * This,
    /* [out] */ BOOL __RPC_FAR *pbProcessAllowed);


void __RPC_STUB ISnappyProcess_CanProcess_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ISnappyProcess_INTERFACE_DEFINED__ */


#ifndef __ISnappyHardware_INTERFACE_DEFINED__
#define __ISnappyHardware_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: ISnappyHardware
 * at Tue May 13 18:04:40 1997
 * using MIDL 2.00.0102
 ****************************************/
/* [unique][uuid][local][object] */ 



EXTERN_C const IID IID_ISnappyHardware;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface ISnappyHardware : public IUnknown
    {
    public:
        virtual HRESULT __stdcall SetAdvise( 
            /* [in] */ ISnappyAdviseSync __RPC_FAR *pNotify) = 0;
        
        virtual HRESULT __stdcall GetLPTPort( 
            /* [out] */ WORD __RPC_FAR *pnPortNum) = 0;
        
        virtual HRESULT __stdcall SetLPTPort( 
            /* [in] */ WORD nPortNum) = 0;
        
        virtual HRESULT __stdcall GetNumPorts( 
            /* [out] */ unsigned long __RPC_FAR *pnNumPorts) = 0;
        
        virtual HRESULT __stdcall PrepareToSnap( void) = 0;
        
        virtual HRESULT __stdcall IsTerminated( 
            /* [out] */ BOOL __RPC_FAR *pbTerminated) = 0;
        
        virtual HRESULT __stdcall SetTermination( 
            /* [in] */ BOOL bTerminate) = 0;
        
        virtual HRESULT __stdcall IsSVideo( 
            /* [out] */ BOOL __RPC_FAR *pbSVideo) = 0;
        
        virtual HRESULT __stdcall SetSVideo( 
            /* [in] */ BOOL bSVideo) = 0;
        
        virtual HRESULT __stdcall IsPowerSaver( 
            /* [out] */ BOOL __RPC_FAR *pbPowerSaver) = 0;
        
        virtual HRESULT __stdcall PowerSaver( 
            /* [in] */ BOOL bPowerSaver) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ISnappyHardwareVtbl
    {
        
        HRESULT ( __stdcall __RPC_FAR *QueryInterface )( 
            ISnappyHardware __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( __stdcall __RPC_FAR *AddRef )( 
            ISnappyHardware __RPC_FAR * This);
        
        ULONG ( __stdcall __RPC_FAR *Release )( 
            ISnappyHardware __RPC_FAR * This);
        
        HRESULT ( __stdcall __RPC_FAR *SetAdvise )( 
            ISnappyHardware __RPC_FAR * This,
            /* [in] */ ISnappyAdviseSync __RPC_FAR *pNotify);
        
        HRESULT ( __stdcall __RPC_FAR *GetLPTPort )( 
            ISnappyHardware __RPC_FAR * This,
            /* [out] */ WORD __RPC_FAR *pnPortNum);
        
        HRESULT ( __stdcall __RPC_FAR *SetLPTPort )( 
            ISnappyHardware __RPC_FAR * This,
            /* [in] */ WORD nPortNum);
        
        HRESULT ( __stdcall __RPC_FAR *GetNumPorts )( 
            ISnappyHardware __RPC_FAR * This,
            /* [out] */ unsigned long __RPC_FAR *pnNumPorts);
        
        HRESULT ( __stdcall __RPC_FAR *PrepareToSnap )( 
            ISnappyHardware __RPC_FAR * This);
        
        HRESULT ( __stdcall __RPC_FAR *IsTerminated )( 
            ISnappyHardware __RPC_FAR * This,
            /* [out] */ BOOL __RPC_FAR *pbTerminated);
        
        HRESULT ( __stdcall __RPC_FAR *SetTermination )( 
            ISnappyHardware __RPC_FAR * This,
            /* [in] */ BOOL bTerminate);
        
        HRESULT ( __stdcall __RPC_FAR *IsSVideo )( 
            ISnappyHardware __RPC_FAR * This,
            /* [out] */ BOOL __RPC_FAR *pbSVideo);
        
        HRESULT ( __stdcall __RPC_FAR *SetSVideo )( 
            ISnappyHardware __RPC_FAR * This,
            /* [in] */ BOOL bSVideo);
        
        HRESULT ( __stdcall __RPC_FAR *IsPowerSaver )( 
            ISnappyHardware __RPC_FAR * This,
            /* [out] */ BOOL __RPC_FAR *pbPowerSaver);
        
        HRESULT ( __stdcall __RPC_FAR *PowerSaver )( 
            ISnappyHardware __RPC_FAR * This,
            /* [in] */ BOOL bPowerSaver);
        
    } ISnappyHardwareVtbl;

    interface ISnappyHardware
    {
        CONST_VTBL struct ISnappyHardwareVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISnappyHardware_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ISnappyHardware_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ISnappyHardware_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ISnappyHardware_SetAdvise(This,pNotify)	\
    (This)->lpVtbl -> SetAdvise(This,pNotify)

#define ISnappyHardware_GetLPTPort(This,pnPortNum)	\
    (This)->lpVtbl -> GetLPTPort(This,pnPortNum)

#define ISnappyHardware_SetLPTPort(This,nPortNum)	\
    (This)->lpVtbl -> SetLPTPort(This,nPortNum)

#define ISnappyHardware_GetNumPorts(This,pnNumPorts)	\
    (This)->lpVtbl -> GetNumPorts(This,pnNumPorts)

#define ISnappyHardware_PrepareToSnap(This)	\
    (This)->lpVtbl -> PrepareToSnap(This)

#define ISnappyHardware_IsTerminated(This,pbTerminated)	\
    (This)->lpVtbl -> IsTerminated(This,pbTerminated)

#define ISnappyHardware_SetTermination(This,bTerminate)	\
    (This)->lpVtbl -> SetTermination(This,bTerminate)

#define ISnappyHardware_IsSVideo(This,pbSVideo)	\
    (This)->lpVtbl -> IsSVideo(This,pbSVideo)

#define ISnappyHardware_SetSVideo(This,bSVideo)	\
    (This)->lpVtbl -> SetSVideo(This,bSVideo)

#define ISnappyHardware_IsPowerSaver(This,pbPowerSaver)	\
    (This)->lpVtbl -> IsPowerSaver(This,pbPowerSaver)

#define ISnappyHardware_PowerSaver(This,bPowerSaver)	\
    (This)->lpVtbl -> PowerSaver(This,bPowerSaver)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT __stdcall ISnappyHardware_SetAdvise_Proxy( 
    ISnappyHardware __RPC_FAR * This,
    /* [in] */ ISnappyAdviseSync __RPC_FAR *pNotify);


void __RPC_STUB ISnappyHardware_SetAdvise_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall ISnappyHardware_GetLPTPort_Proxy( 
    ISnappyHardware __RPC_FAR * This,
    /* [out] */ WORD __RPC_FAR *pnPortNum);


void __RPC_STUB ISnappyHardware_GetLPTPort_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall ISnappyHardware_SetLPTPort_Proxy( 
    ISnappyHardware __RPC_FAR * This,
    /* [in] */ WORD nPortNum);


void __RPC_STUB ISnappyHardware_SetLPTPort_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall ISnappyHardware_GetNumPorts_Proxy( 
    ISnappyHardware __RPC_FAR * This,
    /* [out] */ unsigned long __RPC_FAR *pnNumPorts);


void __RPC_STUB ISnappyHardware_GetNumPorts_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall ISnappyHardware_PrepareToSnap_Proxy( 
    ISnappyHardware __RPC_FAR * This);


void __RPC_STUB ISnappyHardware_PrepareToSnap_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall ISnappyHardware_IsTerminated_Proxy( 
    ISnappyHardware __RPC_FAR * This,
    /* [out] */ BOOL __RPC_FAR *pbTerminated);


void __RPC_STUB ISnappyHardware_IsTerminated_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall ISnappyHardware_SetTermination_Proxy( 
    ISnappyHardware __RPC_FAR * This,
    /* [in] */ BOOL bTerminate);


void __RPC_STUB ISnappyHardware_SetTermination_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall ISnappyHardware_IsSVideo_Proxy( 
    ISnappyHardware __RPC_FAR * This,
    /* [out] */ BOOL __RPC_FAR *pbSVideo);


void __RPC_STUB ISnappyHardware_IsSVideo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall ISnappyHardware_SetSVideo_Proxy( 
    ISnappyHardware __RPC_FAR * This,
    /* [in] */ BOOL bSVideo);


void __RPC_STUB ISnappyHardware_SetSVideo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall ISnappyHardware_IsPowerSaver_Proxy( 
    ISnappyHardware __RPC_FAR * This,
    /* [out] */ BOOL __RPC_FAR *pbPowerSaver);


void __RPC_STUB ISnappyHardware_IsPowerSaver_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall ISnappyHardware_PowerSaver_Proxy( 
    ISnappyHardware __RPC_FAR * This,
    /* [in] */ BOOL bPowerSaver);


void __RPC_STUB ISnappyHardware_PowerSaver_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ISnappyHardware_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
