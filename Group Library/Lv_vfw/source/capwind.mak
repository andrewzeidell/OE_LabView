# Microsoft Developer Studio Generated NMAKE File, Format Version 40001
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101
# TARGTYPE "Win32 (x86) Dynamic-Link Library" 0x0102

!IF "$(CFG)" == ""
CFG=test - Win32 Debug
!MESSAGE No configuration specified.  Defaulting to test - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "capwind - Win32 Release" && "$(CFG)" !=\
 "capwind - Win32 Debug" && "$(CFG)" != "test - Win32 Release" && "$(CFG)" !=\
 "test - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE on this makefile
!MESSAGE by defining the macro CFG on the command line.  For example:
!MESSAGE 
!MESSAGE NMAKE /f "capwind.mak" CFG="test - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "capwind - Win32 Release" (based on\
 "Win32 (x86) Dynamic-Link Library")
!MESSAGE "capwind - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "test - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "test - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 
################################################################################
# Begin Project
# PROP Target_Last_Scanned "test - Win32 Debug"

!IF  "$(CFG)" == "capwind - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir ".."
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
OUTDIR=.\..
INTDIR=.\Release

ALL : "$(OUTDIR)\capwind.dll"

CLEAN : 
	-@erase "..\capwind.dll"
	-@erase ".\Release\dib.obj"
	-@erase ".\Release\capwind.obj"
	-@erase ".\Release\capwind.res"
	-@erase "..\capwind.lib"
	-@erase "..\capwind.exp"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

"$(INTDIR)" :
    if not exist "$(INTDIR)/$(NULL)" mkdir "$(INTDIR)"

CPP=cl.exe
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /YX /c
# ADD CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /YX /c
CPP_PROJ=/nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS"\
 /Fp"$(INTDIR)/capwind.pch" /YX /Fo"$(INTDIR)/" /c 
CPP_OBJS=.\Release/
CPP_SBRS=

.c{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

.cpp{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

.cxx{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

.c{$(CPP_SBRS)}.sbr:
   $(CPP) $(CPP_PROJ) $<  

.cpp{$(CPP_SBRS)}.sbr:
   $(CPP) $(CPP_PROJ) $<  

.cxx{$(CPP_SBRS)}.sbr:
   $(CPP) $(CPP_PROJ) $<  

MTL=mktyplib.exe
# ADD BASE MTL /nologo /D "NDEBUG" /win32
# ADD MTL /nologo /D "NDEBUG" /win32
MTL_PROJ=/nologo /D "NDEBUG" /win32 
RSC=rc.exe
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
RSC_PROJ=/l 0x409 /fo"$(INTDIR)/capwind.res" /d "NDEBUG" 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/capwind.bsc" 
BSC32_SBRS=
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib /nologo /subsystem:windows /dll /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib vfw32.lib /nologo /entry:"DllEntryPoint" /subsystem:windows /dll /machine:I386
# SUBTRACT LINK32 /incremental:yes
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib\
 advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib vfw32.lib /nologo\
 /entry:"DllEntryPoint" /subsystem:windows /dll /incremental:no\
 /pdb:"$(OUTDIR)/capwind.pdb" /machine:I386 /out:"$(OUTDIR)/capwind.dll"\
 /implib:"$(OUTDIR)/capwind.lib" 
LINK32_OBJS= \
	"$(INTDIR)/dib.obj" \
	"$(INTDIR)/capwind.obj" \
	"$(INTDIR)/capwind.res"

"$(OUTDIR)\capwind.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "capwind - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir ".."
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
OUTDIR=.\..
INTDIR=.\Debug

ALL : "$(OUTDIR)\capwind.dll"

CLEAN : 
	-@erase ".\Debug\vc40.pdb"
	-@erase ".\Debug\vc40.idb"
	-@erase "..\capwind.dll"
	-@erase ".\Debug\capwind.obj"
	-@erase ".\Debug\dib.obj"
	-@erase ".\Debug\capwind.res"
	-@erase "..\capwind.lib"
	-@erase "..\capwind.exp"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

"$(INTDIR)" :
    if not exist "$(INTDIR)/$(NULL)" mkdir "$(INTDIR)"

CPP=cl.exe
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /YX /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /YX /c
CPP_PROJ=/nologo /MTd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS"\
 /Fp"$(INTDIR)/capwind.pch" /YX /Fo"$(INTDIR)/" /Fd"$(INTDIR)/" /c 
CPP_OBJS=.\Debug/
CPP_SBRS=

.c{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

.cpp{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

.cxx{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

.c{$(CPP_SBRS)}.sbr:
   $(CPP) $(CPP_PROJ) $<  

.cpp{$(CPP_SBRS)}.sbr:
   $(CPP) $(CPP_PROJ) $<  

.cxx{$(CPP_SBRS)}.sbr:
   $(CPP) $(CPP_PROJ) $<  

MTL=mktyplib.exe
# ADD BASE MTL /nologo /D "_DEBUG" /win32
# ADD MTL /nologo /D "_DEBUG" /win32
MTL_PROJ=/nologo /D "_DEBUG" /win32 
RSC=rc.exe
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
RSC_PROJ=/l 0x409 /fo"$(INTDIR)/capwind.res" /d "_DEBUG" 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/capwind.bsc" 
BSC32_SBRS=
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib /nologo /subsystem:windows /dll /debug /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib vfw32.lib libcmt.lib /nologo /entry:"DllEntryPoint" /subsystem:windows /dll /pdb:none /debug /machine:I386 /nodefaultlib
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib\
 advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib vfw32.lib libcmt.lib\
 /nologo /entry:"DllEntryPoint" /subsystem:windows /dll /pdb:none /debug\
 /machine:I386 /nodefaultlib /out:"$(OUTDIR)/capwind.dll"\
 /implib:"$(OUTDIR)/capwind.lib" 
LINK32_OBJS= \
	"$(INTDIR)/capwind.obj" \
	"$(INTDIR)/dib.obj" \
	"$(INTDIR)/capwind.res"

"$(OUTDIR)\capwind.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "test - Win32 Release"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "test\Release"
# PROP BASE Intermediate_Dir "test\Release"
# PROP BASE Target_Dir "test"
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 0
# PROP Output_Dir ".."
# PROP Intermediate_Dir "test\Release"
# PROP Target_Dir "test"
OUTDIR=.\..
INTDIR=.\test\Release

ALL : "capwind - Win32 Release" "$(OUTDIR)\test.exe"

CLEAN : 
	-@erase "..\test.exe"
	-@erase ".\test\Release\testDlg.obj"
	-@erase ".\test\Release\test.pch"
	-@erase ".\test\Release\StdAfx.obj"
	-@erase ".\test\Release\test.obj"
	-@erase ".\test\Release\test.res"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

"$(INTDIR)" :
    if not exist "$(INTDIR)/$(NULL)" mkdir "$(INTDIR)"

CPP=cl.exe
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /c
# ADD CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /c
CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)/test.pch" /Yu"stdafx.h" /Fo"$(INTDIR)/" /c 
CPP_OBJS=.\test\Release/
CPP_SBRS=

.c{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

.cpp{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

.cxx{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

.c{$(CPP_SBRS)}.sbr:
   $(CPP) $(CPP_PROJ) $<  

.cpp{$(CPP_SBRS)}.sbr:
   $(CPP) $(CPP_PROJ) $<  

.cxx{$(CPP_SBRS)}.sbr:
   $(CPP) $(CPP_PROJ) $<  

MTL=mktyplib.exe
# ADD BASE MTL /nologo /D "NDEBUG" /win32
# ADD MTL /nologo /D "NDEBUG" /win32
MTL_PROJ=/nologo /D "NDEBUG" /win32 
RSC=rc.exe
# ADD BASE RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
RSC_PROJ=/l 0x409 /fo"$(INTDIR)/test.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/test.bsc" 
BSC32_SBRS=
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 /nologo /subsystem:windows /machine:I386
# SUBTRACT LINK32 /incremental:yes
LINK32_FLAGS=/nologo /subsystem:windows /incremental:no\
 /pdb:"$(OUTDIR)/test.pdb" /machine:I386 /out:"$(OUTDIR)/test.exe" 
LINK32_OBJS= \
	"$(INTDIR)/testDlg.obj" \
	"$(INTDIR)/StdAfx.obj" \
	"$(INTDIR)/test.obj" \
	"$(INTDIR)/test.res" \
	"..\capwind.lib"

"$(OUTDIR)\test.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "test - Win32 Debug"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "test\Debug"
# PROP BASE Intermediate_Dir "test\Debug"
# PROP BASE Target_Dir "test"
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 1
# PROP Output_Dir ".."
# PROP Intermediate_Dir "test\Debug"
# PROP Target_Dir "test"
OUTDIR=.\..
INTDIR=.\test\Debug

ALL : "capwind - Win32 Debug" "$(OUTDIR)\test.exe"

CLEAN : 
	-@erase ".\test\Debug\vc40.pdb"
	-@erase ".\test\Debug\test.pch"
	-@erase ".\test\Debug\vc40.idb"
	-@erase "..\test.exe"
	-@erase ".\test\Debug\testDlg.obj"
	-@erase ".\test\Debug\test.obj"
	-@erase ".\test\Debug\StdAfx.obj"
	-@erase ".\test\Debug\test.res"
	-@erase "..\test.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

"$(INTDIR)" :
    if not exist "$(INTDIR)/$(NULL)" mkdir "$(INTDIR)"

CPP=cl.exe
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /c
CPP_PROJ=/nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS"\
 /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)/test.pch" /Yu"stdafx.h" /Fo"$(INTDIR)/"\
 /Fd"$(INTDIR)/" /c 
CPP_OBJS=.\test\Debug/
CPP_SBRS=

.c{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

.cpp{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

.cxx{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

.c{$(CPP_SBRS)}.sbr:
   $(CPP) $(CPP_PROJ) $<  

.cpp{$(CPP_SBRS)}.sbr:
   $(CPP) $(CPP_PROJ) $<  

.cxx{$(CPP_SBRS)}.sbr:
   $(CPP) $(CPP_PROJ) $<  

MTL=mktyplib.exe
# ADD BASE MTL /nologo /D "_DEBUG" /win32
# ADD MTL /nologo /D "_DEBUG" /win32
MTL_PROJ=/nologo /D "_DEBUG" /win32 
RSC=rc.exe
# ADD BASE RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
RSC_PROJ=/l 0x409 /fo"$(INTDIR)/test.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/test.bsc" 
BSC32_SBRS=
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386
# ADD LINK32 /nologo /subsystem:windows /incremental:no /debug /machine:I386
LINK32_FLAGS=/nologo /subsystem:windows /incremental:no\
 /pdb:"$(OUTDIR)/test.pdb" /debug /machine:I386 /out:"$(OUTDIR)/test.exe" 
LINK32_OBJS= \
	"$(INTDIR)/testDlg.obj" \
	"$(INTDIR)/test.obj" \
	"$(INTDIR)/StdAfx.obj" \
	"$(INTDIR)/test.res" \
	"..\capwind.lib"

"$(OUTDIR)\test.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF 

################################################################################
# Begin Target

# Name "capwind - Win32 Release"
# Name "capwind - Win32 Debug"

!IF  "$(CFG)" == "capwind - Win32 Release"

!ELSEIF  "$(CFG)" == "capwind - Win32 Debug"

!ENDIF 

################################################################################
# Begin Source File

SOURCE=.\capwind.cpp

!IF  "$(CFG)" == "capwind - Win32 Release"

DEP_CPP_CAPWI=\
	".\dib.h"\
	
NODEP_CPP_CAPWI=\
	".\switch"\
	".\bQuickSnap"\
	

"$(INTDIR)\capwind.obj" : $(SOURCE) $(DEP_CPP_CAPWI) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "capwind - Win32 Debug"

DEP_CPP_CAPWI=\
	".\dib.h"\
	

"$(INTDIR)\capwind.obj" : $(SOURCE) $(DEP_CPP_CAPWI) "$(INTDIR)"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\capwind.rc

!IF  "$(CFG)" == "capwind - Win32 Release"


"$(INTDIR)\capwind.res" : $(SOURCE) "$(INTDIR)"
   $(RSC) $(RSC_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "capwind - Win32 Debug"


"$(INTDIR)\capwind.res" : $(SOURCE) "$(INTDIR)"
   $(RSC) $(RSC_PROJ) $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\dib.cpp

!IF  "$(CFG)" == "capwind - Win32 Release"

DEP_CPP_DIB_C=\
	".\dib.h"\
	
NODEP_CPP_DIB_C=\
	".\{"\
	

"$(INTDIR)\dib.obj" : $(SOURCE) $(DEP_CPP_DIB_C) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "capwind - Win32 Debug"

DEP_CPP_DIB_C=\
	".\dib.h"\
	

"$(INTDIR)\dib.obj" : $(SOURCE) $(DEP_CPP_DIB_C) "$(INTDIR)"


!ENDIF 

# End Source File
# End Target
################################################################################
# Begin Target

# Name "test - Win32 Release"
# Name "test - Win32 Debug"

!IF  "$(CFG)" == "test - Win32 Release"

!ELSEIF  "$(CFG)" == "test - Win32 Debug"

!ENDIF 

################################################################################
# Begin Source File

SOURCE=.\test\ReadMe.txt

!IF  "$(CFG)" == "test - Win32 Release"

!ELSEIF  "$(CFG)" == "test - Win32 Debug"

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\test\test.cpp
DEP_CPP_TEST_=\
	".\test\StdAfx.h"\
	".\test\test.h"\
	".\test\testDlg.h"\
	

"$(INTDIR)\test.obj" : $(SOURCE) $(DEP_CPP_TEST_) "$(INTDIR)"\
 "$(INTDIR)\test.pch"
   $(CPP) $(CPP_PROJ) $(SOURCE)


# End Source File
################################################################################
# Begin Source File

SOURCE=.\test\testDlg.cpp

!IF  "$(CFG)" == "test - Win32 Release"

DEP_CPP_TESTD=\
	".\test\StdAfx.h"\
	".\test\test.h"\
	".\test\testDlg.h"\
	
NODEP_CPP_TESTD=\
	".\test\GetData"\
	

"$(INTDIR)\testDlg.obj" : $(SOURCE) $(DEP_CPP_TESTD) "$(INTDIR)"\
 "$(INTDIR)\test.pch"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "test - Win32 Debug"

DEP_CPP_TESTD=\
	".\test\StdAfx.h"\
	".\test\test.h"\
	".\test\testDlg.h"\
	

"$(INTDIR)\testDlg.obj" : $(SOURCE) $(DEP_CPP_TESTD) "$(INTDIR)"\
 "$(INTDIR)\test.pch"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\test\StdAfx.cpp
DEP_CPP_STDAF=\
	".\test\StdAfx.h"\
	

!IF  "$(CFG)" == "test - Win32 Release"

# ADD CPP /Yc"stdafx.h"

BuildCmds= \
	$(CPP) /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)/test.pch" /Yc"stdafx.h" /Fo"$(INTDIR)/" /c\
 $(SOURCE) \
	

"$(INTDIR)\StdAfx.obj" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

"$(INTDIR)\test.pch" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

!ELSEIF  "$(CFG)" == "test - Win32 Debug"

# ADD CPP /Yc"stdafx.h"

BuildCmds= \
	$(CPP) /nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS"\
 /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)/test.pch" /Yc"stdafx.h" /Fo"$(INTDIR)/"\
 /Fd"$(INTDIR)/" /c $(SOURCE) \
	

"$(INTDIR)\StdAfx.obj" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

"$(INTDIR)\test.pch" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\test\test.rc
DEP_RSC_TEST_R=\
	".\test\res\test.ico"\
	".\test\res\test.rc2"\
	

!IF  "$(CFG)" == "test - Win32 Release"


"$(INTDIR)\test.res" : $(SOURCE) $(DEP_RSC_TEST_R) "$(INTDIR)"
   $(RSC) /l 0x409 /fo"$(INTDIR)/test.res" /i "test" /d "NDEBUG" /d "_AFXDLL"\
 $(SOURCE)


!ELSEIF  "$(CFG)" == "test - Win32 Debug"


"$(INTDIR)\test.res" : $(SOURCE) $(DEP_RSC_TEST_R) "$(INTDIR)"
   $(RSC) /l 0x409 /fo"$(INTDIR)/test.res" /i "test" /d "_DEBUG" /d "_AFXDLL"\
 $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Project Dependency

# Project_Dep_Name "capwind"

!IF  "$(CFG)" == "test - Win32 Release"

"capwind - Win32 Release" : 
   $(MAKE) /$(MAKEFLAGS) /F .\capwind.mak CFG="capwind - Win32 Release" 

!ELSEIF  "$(CFG)" == "test - Win32 Debug"

"capwind - Win32 Debug" : 
   $(MAKE) /$(MAKEFLAGS) /F .\capwind.mak CFG="capwind - Win32 Debug" 

!ENDIF 

# End Project Dependency
# End Target
# End Project
################################################################################
