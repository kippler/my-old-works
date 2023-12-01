# Microsoft Developer Studio Generated NMAKE File, Format Version 4.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

!IF "$(CFG)" == ""
CFG=iq - Win32 Debug
!MESSAGE No configuration specified.  Defaulting to iq - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "iq - Win32 Release" && "$(CFG)" != "iq - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE on this makefile
!MESSAGE by defining the macro CFG on the command line.  For example:
!MESSAGE 
!MESSAGE NMAKE /f "iq.mak" CFG="iq - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "iq - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "iq - Win32 Debug" (based on "Win32 (x86) Application")
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
# PROP Target_Last_Scanned "iq - Win32 Debug"
MTL=mktyplib.exe
RSC=rc.exe
CPP=cl.exe

!IF  "$(CFG)" == "iq - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
OUTDIR=.\Release
INTDIR=.\Release

ALL : "$(OUTDIR)\iq.exe"

CLEAN : 
	-@erase ".\Release\iq.exe"
	-@erase ".\Release\Stack.obj"
	-@erase ".\Release\Board.obj"
	-@erase ".\Release\Iq120.obj"
	-@erase ".\Release\iq120.res"
	-@erase ".\Release\Bdmain.obj"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /YX /c
# ADD CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /YX /c
CPP_PROJ=/nologo /ML /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS"\
 /Fp"$(INTDIR)/iq.pch" /YX /Fo"$(INTDIR)/" /c 
CPP_OBJS=.\Release/
CPP_SBRS=
# ADD BASE MTL /nologo /D "NDEBUG" /win32
# ADD MTL /nologo /D "NDEBUG" /win32
MTL_PROJ=/nologo /D "NDEBUG" /win32 
# ADD BASE RSC /l 0x412 /d "NDEBUG"
# ADD RSC /l 0x412 /d "NDEBUG"
RSC_PROJ=/l 0x412 /fo"$(INTDIR)/iq120.res" /d "NDEBUG" 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/iq.bsc" 
BSC32_SBRS=
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /machine:I386
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib\
 advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib\
 odbccp32.lib /nologo /subsystem:windows /incremental:no /pdb:"$(OUTDIR)/iq.pdb"\
 /machine:I386 /out:"$(OUTDIR)/iq.exe" 
LINK32_OBJS= \
	"$(INTDIR)/Stack.obj" \
	"$(INTDIR)/Board.obj" \
	"$(INTDIR)/Iq120.obj" \
	"$(INTDIR)/Bdmain.obj" \
	"$(INTDIR)/iq120.res"

"$(OUTDIR)\iq.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "iq - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "iq___Win"
# PROP BASE Intermediate_Dir "iq___Win"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "iq___Win"
# PROP Intermediate_Dir "iq___Win"
# PROP Target_Dir ""
OUTDIR=.\iq___Win
INTDIR=.\iq___Win

ALL : "$(OUTDIR)\iq.exe"

CLEAN : 
	-@erase ".\iq___Win\iq.exe"
	-@erase ".\iq___Win\Stack.obj"
	-@erase ".\iq___Win\Board.obj"
	-@erase ".\iq___Win\Iq120.obj"
	-@erase ".\iq___Win\iq120.res"
	-@erase ".\iq___Win\Bdmain.obj"
	-@erase ".\iq___Win\iq.ilk"
	-@erase ".\iq___Win\iq.pdb"
	-@erase ".\iq___Win\vc40.pdb"
	-@erase ".\iq___Win\vc40.idb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

# ADD BASE CPP /nologo /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /YX /c
# ADD CPP /nologo /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /YX /c
CPP_PROJ=/nologo /MLd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS"\
 /Fp"$(INTDIR)/iq.pch" /YX /Fo"$(INTDIR)/" /Fd"$(INTDIR)/" /c 
CPP_OBJS=.\iq___Win/
CPP_SBRS=
# ADD BASE MTL /nologo /D "_DEBUG" /win32
# ADD MTL /nologo /D "_DEBUG" /win32
MTL_PROJ=/nologo /D "_DEBUG" /win32 
# ADD BASE RSC /l 0x412 /d "_DEBUG"
# ADD RSC /l 0x412 /d "_DEBUG"
RSC_PROJ=/l 0x412 /fo"$(INTDIR)/iq120.res" /d "_DEBUG" 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/iq.bsc" 
BSC32_SBRS=
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /debug /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /debug /machine:I386
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib\
 advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib\
 odbccp32.lib /nologo /subsystem:windows /incremental:yes\
 /pdb:"$(OUTDIR)/iq.pdb" /debug /machine:I386 /out:"$(OUTDIR)/iq.exe" 
LINK32_OBJS= \
	"$(INTDIR)/Stack.obj" \
	"$(INTDIR)/Board.obj" \
	"$(INTDIR)/Iq120.obj" \
	"$(INTDIR)/Bdmain.obj" \
	"$(INTDIR)/iq120.res"

"$(OUTDIR)\iq.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
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

# Name "iq - Win32 Release"
# Name "iq - Win32 Debug"

!IF  "$(CFG)" == "iq - Win32 Release"

!ELSEIF  "$(CFG)" == "iq - Win32 Debug"

!ENDIF 

################################################################################
# Begin Source File

SOURCE=.\Stack.cpp
DEP_CPP_STACK=\
	".\stack.h"\
	".\Public.h"\
	

"$(INTDIR)\Stack.obj" : $(SOURCE) $(DEP_CPP_STACK) "$(INTDIR)"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\Board.cpp
DEP_CPP_BOARD=\
	".\Board.h"\
	

"$(INTDIR)\Board.obj" : $(SOURCE) $(DEP_CPP_BOARD) "$(INTDIR)"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\Iq120.cpp
DEP_CPP_IQ120=\
	".\iq120.h"\
	".\Board.h"\
	".\stack.h"\
	

"$(INTDIR)\Iq120.obj" : $(SOURCE) $(DEP_CPP_IQ120) "$(INTDIR)"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\iq120.rc
DEP_RSC_IQ120_=\
	".\icon1.ico"\
	".\cursor1.cur"\
	".\bitmap1.bmp"\
	".\bitmap2.bmp"\
	

"$(INTDIR)\iq120.res" : $(SOURCE) $(DEP_RSC_IQ120_) "$(INTDIR)"
   $(RSC) $(RSC_PROJ) $(SOURCE)


# End Source File
################################################################################
# Begin Source File

SOURCE=.\Bdmain.cpp
DEP_CPP_BDMAI=\
	".\Public.h"\
	".\iq120.h"\
	".\Board.h"\
	".\stack.h"\
	

"$(INTDIR)\Bdmain.obj" : $(SOURCE) $(DEP_CPP_BDMAI) "$(INTDIR)"


# End Source File
# End Target
# End Project
################################################################################
