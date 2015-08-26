/* this ALWAYS GENERATED file contains the actual definitions of */
/* the IIDs and CLSIDs */

/* link this file in with the server and any clients */


/* File created by MIDL compiler version 2.00.0102 */
/* at Tue May 13 18:04:40 1997
 */
//@@MIDL_FILE_HEADING(  )
#ifdef __cplusplus
extern "C"{
#endif 


#ifndef IID_DEFINED
#define IID_DEFINED

typedef struct _IID
{
    unsigned long x;
    unsigned short s1;
    unsigned short s2;
    unsigned char  c[8];
} IID;

#endif // IID_DEFINED

#ifndef CLSID_DEFINED
#define CLSID_DEFINED
typedef IID CLSID;
#endif // CLSID_DEFINED

const IID IID_ISnappy = {0x441958E0,0xA822,0x11cf,{0xB9,0x08,0x00,0x00,0xB4,0x68,0x1E,0xAD}};


const IID IID_ISnappyAdviseSync = {0x441958E1,0xA822,0x11cf,{0xB9,0x08,0x00,0x00,0xB4,0x68,0x1E,0xAD}};


const IID IID_ISnappyPreview = {0x441958E2,0xA822,0x11cf,{0xB9,0x08,0x00,0x00,0xB4,0x68,0x1E,0xAD}};


const IID IID_ISnappyProcess = {0x441958E3,0xA822,0x11cf,{0xB9,0x08,0x00,0x00,0xB4,0x68,0x1E,0xAD}};


const IID IID_ISnappyHardware = {0x441958E4,0xA822,0x11cf,{0xB9,0x08,0x00,0x00,0xB4,0x68,0x1E,0xAD}};


#ifdef __cplusplus
}
#endif

