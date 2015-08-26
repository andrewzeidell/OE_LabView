# Microsoft Developer Studio Generated NMAKE File, Format Version 40001
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Dynamic-Link Library" 0x0102

!IF "$(CFG)" == ""
CFG=snappy - Win32 Debug
!MESSAGE No configuration specified.  Defaulting to snappy - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "snappy - Win32 Release" && "$(CFG)" != "snappy - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE on this makefile
!MESSAGE by defining the macro CFG on the command line.  For example:
!MESSAGE 
!MESSAGE NMAKE /f "snappy.mak" CFG="snappy - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "snappy - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "snappy - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
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
# PROP Target_Last_Scanned "snappy - Win32 Debug"
CPP=cl.exe
RSC=rc.exe
MTL=mktyplib.exe

!IF  "$(CFG)" == "snappy - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "../.."
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
OUTDIR=.\../..
INTDIR=.\Release

ALL : "$(OUTDIR)\snappy.dll"

CLEAN : 
	-@erase "..\..\snappy.dll"
	-@erase ".\Release\MyNotify.obj"
	-@erase ".\snappy.h"
	-@erase ".\Release\UseSnap.obj"
	-@erase ".\Release\snappy_i.obj"
	-@erase ".\snappy_i.c"
	-@erase ".\Release\SnapVer.obj"
	-@erase ".\Release\snappy.obj"
	-@erase "..\..\snappy.lib"
	-@erase "..\..\snappy.exp"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

"$(INTDIR)" :
    if not exist "$(INTDIR)/$(NULL)" mkdir "$(INTDIR)"

# ADD BASE CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /YX /c
# ADD CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /YX /c
CPP_PROJ=/nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS"\
 /Fp"$(INTDIR)/snappy.pch" /YX /Fo"$(INTDIR)/" /c 
CPP_OBJS=.\Release/
CPP_SBRS=
# ADD BASE MTL /nologo /D "NDEBUG" /win32
# ADD MTL /nologo /D "NDEBUG" /win32
MTL_PROJ=/nologo /D "NDEBUG" /win32 
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/snappy.bsc" 
BSC32_SBRS=
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib /nologo /subsystem:windows /dll /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib version.lib /nologo /entry:"DllEntryPoint" /subsystem:windows /dll /machine:I386
# SUBTRACT LINK32 /incremental:yes
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib\
 advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib version.lib /nologo\
 /entry:"DllEntryPoint" /subsystem:windows /dll /incremental:no\
 /pdb:"$(OUTDIR)/snappy.pdb" /machine:I386 /out:"$(OUTDIR)/snappy.dll"\
 /implib:"$(OUTDIR)/snappy.lib" 
LINK32_OBJS= \
	"$(INTDIR)/MyNotify.obj" \
	"$(INTDIR)/UseSnap.obj" \
	"$(INTDIR)/snappy_i.obj" \
	"$(INTDIR)/SnapVer.obj" \
	"$(INTDIR)/snappy.obj"

"$(OUTDIR)\snappy.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "snappy - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "snappy__"
# PROP BASE Intermediate_Dir "snappy__"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "../.."
# PROP Intermediate_Dir "snappy__"
# PROP Target_Dir ""
OUTDIR=.\../..
INTDIR=.\snappy__

ALL : "$(OUTDIR)\snappy.dll"

CLEAN : 
	-@erase ".\snappy__\vc40.pdb"
	-@erase ".\snappy_i.c"
	-@erase ".\snappy.h"
	-@erase ".\snappy__\vc40.idb"
	-@erase "..\..\snappy.dll"
	-@erase ".\snappy__\MyNotify.obj"
	-@erase ".\snappy__\UseSnap.obj"
	-@erase ".\snappy__\SnapVer.obj"
	-@erase ".\snappy__\snappy.obj"
	-@erase ".\snappy__\snappy_i.obj"
	-@erase "..\..\snappy.lib"
	-@erase "..\..\snappy.exp"
	-@erase "..\..\snappy.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

"$(INTDIR)" :
    if not exist "$(INTDIR)/$(NULL)" mkdir "$(INTDIR)"

# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /YX /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /YX /c
CPP_PROJ=/nologo /MTd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS"\
 /Fp"$(INTDIR)/snappy.pch" /YX /Fo"$(INTDIR)/" /Fd"$(INTDIR)/" /c 
CPP_OBJS=.\snappy__/
CPP_SBRS=
# ADD BASE MTL /nologo /D "_DEBUG" /win32
# ADD MTL /nologo /D "_DEBUG" /win32
MTL_PROJ=/nologo /D "_DEBUG" /win32 
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/snappy.bsc" 
BSC32_SBRS=
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib /nologo /subsystem:windows /dll /debug /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib version.lib /nologo /entry:"DllEntryPoint" /subsystem:windows /dll /incremental:no /debug /machine:I386
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib\
 advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib version.lib /nologo\
 /entry:"DllEntryPoint" /subsystem:windows /dll /incremental:no\
 /pdb:"$(OUTDIR)/snappy.pdb" /debug /machine:I386 /out:"$(OUTDIR)/snappy.dll"\
 /implib:"$(OUTDIR)/snappy.lib" 
LINK32_OBJS= \
	"$(INTDIR)/MyNotify.obj" \
	"$(INTDIR)/UseSnap.obj" \
	"$(INTDIR)/SnapVer.obj" \
	"$(INTDIR)/snappy.obj" \
	"$(INTDIR)/snappy_i.obj"

"$(OUTDIR)\snappy.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF 

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

################################################################################
# Begin Target

# Name "snappy - Win32 Release"
# Name "snappy - Win32 Debug"

!IF  "$(CFG)" == "snappy - Win32 Release"

!ELSEIF  "$(CFG)" == "snappy - Win32 Debug"

!ENDIF 

################################################################################
# Begin Source File

SOURCE=.\UseSnap.cpp
DEP_CPP_USESN=\
	".\Sample1.h"\
	".\snappy.h"\
	".\sCLSIDs.h"\
	".\MyNotify.h"\
	".\snapcom.h"\
	

"$(INTDIR)\UseSnap.obj" : $(SOURCE) $(DEP_CPP_USESN) "$(INTDIR)" ".\snappy.h"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\snappy.cpp
DEP_CPP_SNAPP=\
	".\snappy.h"\
	".\Sample1.h"\
	

"$(INTDIR)\snappy.obj" : $(SOURCE) $(DEP_CPP_SNAPP) "$(INTDIR)" ".\snappy.h"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\SnapVer.cpp
DEP_CPP_SNAPV=\
	".\Sample1.h"\
	

"$(INTDIR)\SnapVer.obj" : $(SOURCE) $(DEP_CPP_SNAPV) "$(INTDIR)"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\MyNotify.cpp
DEP_CPP_MYNOT=\
	".\snappy.h"\
	".\MyNotify.h"\
	".\Sample1.h"\
	".\snapcom.h"\
	

"$(INTDIR)\MyNotify.obj" : $(SOURCE) $(DEP_CPP_MYNOT) "$(INTDIR)" ".\snappy.h"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\snappy.idl

!IF  "$(CFG)" == "snappy - Win32 Release"

# Begin Custom Build
ProjDir=.
InputPath=.\snappy.idl
InputName=snappy

BuildCmds= \
	MIDL $(InputPath) /ms_ext /c_ext /out $(ProjDir) \
	

"$(ProjDir)\$(InputName)_i.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"$(ProjDir)\$(InputName).h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)
# End Custom Build

!ELSEIF  "$(CFG)" == "snappy - Win32 Debug"

# Begin Custom Build
ProjDir=.
InputPath=.\snappy.idl
InputName=snappy

BuildCmds= \
	MIDL $(InputPath) /ms_ext /c_ext /out $(ProjDir) \
	

"$(ProjDir)\$(InputName)_i.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"$(ProjDir)\$(InputName).h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)
# End Custom Build

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\snappy_i.c

"$(INTDIR)\snappy_i.obj" : $(SOURCE) "$(INTDIR)"


# End Source File
# End Target
# End Project
################################################################################
