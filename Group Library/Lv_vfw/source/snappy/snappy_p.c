/* this ALWAYS GENERATED file contains the proxy stub code */


/* File created by MIDL compiler version 2.00.0102 */
/* at Tue May 13 18:04:40 1997
 */
//@@MIDL_FILE_HEADING(  )

#include "rpcproxy.h"
#include "snappy.h"


extern const MIDL_FORMAT_STRING __MIDLFormatString;

extern const MIDL_FORMAT_STRING __MIDLProcFormatString;

#pragma data_seg(".rdata")

#if !defined(__RPC_WIN32__)
#error  Invalid build platform for this stub.
#endif

static const MIDL_FORMAT_STRING __MIDLProcFormatString =
    {
        0,
        {

			0x0
        }
    };

static const MIDL_FORMAT_STRING __MIDLFormatString =
    {
        0,
        {

			0x0
        }
    };

const CInterfaceProxyVtbl * _snappy_ProxyVtblList[] = 
{
    0
};

const CInterfaceStubVtbl * _snappy_StubVtblList[] = 
{
    0
};

PCInterfaceName const _snappy_InterfaceNamesList[] = 
{
    0
};


#define _snappy_CHECK_IID(n)	IID_GENERIC_CHECK_IID( _snappy, pIID, n)

int __stdcall _snappy_IID_Lookup( const IID * pIID, int * pIndex )
{
    return 0;
}

const ExtendedProxyFileInfo snappy_ProxyFileInfo = 
{
    (PCInterfaceProxyVtblList *) & _snappy_ProxyVtblList,
    (PCInterfaceStubVtblList *) & _snappy_StubVtblList,
    (const PCInterfaceName * ) & _snappy_InterfaceNamesList,
    0, // no delegation
    & _snappy_IID_Lookup, 
    0,
    1
};
