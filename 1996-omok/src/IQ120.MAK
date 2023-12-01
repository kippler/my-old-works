# Microsoft Developer Studio Generated NMAKE File, Format Version 4.10
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

!IF "$(CFG)" == ""
CFG=iq120 - Win32 Debug
!MESSAGE No configuration specified.  Defaulting to iq120 - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "iq120 - Win32 Release" && "$(CFG)" != "iq120 - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE on this makefile
!MESSAGE by defining the macro CFG on the command line.  For example:
!MESSAGE 
!MESSAGE NMAKE /f "iq120.mak" CFG="iq120 - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "iq120 - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "iq120 - Win32 Debug" (based on "Win32 (x86) Application")
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
# PROP Target_Last_Scanned "iq120 - Win32 Debug"
CPP=cl.exe
RSC=rc.exe
MTL=mktyplib.exe

!IF  "$(CFG)" == "iq120 - Win32 Release"

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

ALL : ".\Release\iq120.exe"

CLEAN : 
	-@erase ".\Release\Bdmain.obj"
	-@erase ".\Release\Board.obj"
	-@erase ".\Release\iq120.exe"
	-@erase ".\Release\Iq120.obj"
	-@erase ".\Release\iq120.res"
	-@erase ".\Release\stack.obj"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /YX /c
# ADD CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /c
# SUBTRACT CPP /YX
CPP_PROJ=/nologo /ML /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_MBCS" /Fo"$(INTDIR)/" /c 
CPP_OBJS=.\Release/
CPP_SBRS=.\.
# ADD BASE MTL /nologo /D "NDEBUG" /win32
# ADD MTL /nologo /D "NDEBUG" /win32
MTL_PROJ=/nologo /D "NDEBUG" /win32 
# ADD BASE RSC /l 0x412 /d "NDEBUG"
# ADD RSC /l 0x412 /d "NDEBUG"
RSC_PROJ=/l 0x412 /fo"$(INTDIR)/iq120.res" /d "NDEBUG" 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/iq120.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /machine:I386
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib\
 advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib\
 odbccp32.lib /nologo /subsystem:windows /incremental:no\
 /pdb:"$(OUTDIR)/iq120.pdb" /machine:I386 /out:"$(OUTDIR)/iq120.exe" 
LINK32_OBJS= \
	".\Release\Bdmain.obj" \
	".\Release\Board.obj" \
	".\Release\Iq120.obj" \
	".\Release\iq120.res" \
	".\Release\stack.obj"

".\Release\iq120.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "iq120 - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
OUTDIR=.\Debug
INTDIR=.\Debug

ALL : ".\Debug\iq120.exe"

CLEAN : 
	-@erase ".\Debug\Bdmain.obj"
	-@erase ".\Debug\Board.obj"
	-@erase ".\Debug\iq120.exe"
	-@erase ".\Debug\iq120.ilk"
	-@erase ".\Debug\Iq120.obj"
	-@erase ".\Debug\iq120.pdb"
	-@erase ".\Debug\iq120.res"
	-@erase ".\Debug\stack.obj"
	-@erase ".\Debug\vc40.idb"
	-@erase ".\Debug\vc40.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

# ADD BASE CPP /nologo /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /YX /c
# ADD CPP /nologo /W3 /Gm /GX /Zi /O2 /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /YX /c
CPP_PROJ=/nologo /MLd /W3 /Gm /GX /Zi /O2 /D "WIN32" /D "_DEBUG" /D "_WINDOWS"\
 /D "_MBCS" /Fp"$(INTDIR)/iq120.pch" /YX /Fo"$(INTDIR)/" /Fd"$(INTDIR)/" /c 
CPP_OBJS=.\Debug/
CPP_SBRS=.\.
# ADD BASE MTL /nologo /D "_DEBUG" /win32
# ADD MTL /nologo /D "_DEBUG" /win32
MTL_PROJ=/nologo /D "_DEBUG" /win32 
# ADD BASE RSC /l 0x412 /d "_DEBUG"
# ADD RSC /l 0x412 /d "_DEBUG"
RSC_PROJ=/l 0x412 /fo"$(INTDIR)/iq120.res" /d "_DEBUG" 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/iq120.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /debug /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /debug /machine:I386
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib\
 advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib\
 odbccp32.lib /nologo /subsystem:windows /incremental:yes\
 /pdb:"$(OUTDIR)/iq120.pdb" /debug /machine:I386 /out:"$(OUTDIR)/iq120.exe" 
LINK32_OBJS= \
	".\Debug\Bdmain.obj" \
	".\Debug\Board.obj" \
	".\Debug\Iq120.obj" \
	".\Debug\iq120.res" \
	".\Debug\stack.obj"

".\Debug\iq120.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
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

# Name "iq120 - Win32 Release"
# Name "iq120 - Win32 Debug"

!IF  "$(CFG)" == "iq120 - Win32 Release"

!ELSEIF  "$(CFG)" == "iq120 - Win32 Debug"

!ENDIF 

################################################################################
# Begin Source File

SOURCE=.\Board.cpp
DEP_CPP_BOARD=\
	".\board.h"\
	

!IF  "$(CFG)" == "iq120 - Win32 Release"


".\Release\Board.obj" : $(SOURCE) $(DEP_CPP_BOARD) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "iq120 - Win32 Debug"


".\Debug\Board.obj" : $(SOURCE) $(DEP_CPP_BOARD) "$(INTDIR)"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\stack.cpp
DEP_CPP_STACK=\
	".\public.h"\
	".\stack.h"\
	

!IF  "$(CFG)" == "iq120 - Win32 Release"


".\Release\stack.obj" : $(SOURCE) $(DEP_CPP_STACK) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "iq120 - Win32 Debug"


".\Debug\stack.obj" : $(SOURCE) $(DEP_CPP_STACK) "$(INTDIR)"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\Bdmain.cpp
DEP_CPP_BDMAI=\
	".\board.h"\
	".\iq120.h"\
	".\public.h"\
	".\stack.h"\
	

!IF  "$(CFG)" == "iq120 - Win32 Release"


".\Release\Bdmain.obj" : $(SOURCE) $(DEP_CPP_BDMAI) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "iq120 - Win32 Debug"


".\Debug\Bdmain.obj" : $(SOURCE) $(DEP_CPP_BDMAI) "$(INTDIR)"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\Iq120.cpp
DEP_CPP_IQ120=\
	".\board.h"\
	".\iq120.h"\
	".\stack.h"\
	

!IF  "$(CFG)" == "iq120 - Win32 Release"


".\Release\Iq120.obj" : $(SOURCE) $(DEP_CPP_IQ120) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "iq120 - Win32 Debug"


".\Debug\Iq120.obj" : $(SOURCE) $(DEP_CPP_IQ120) "$(INTDIR)"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\iq120.rc
DEP_RSC_IQ120_=\
	".\bitmap1.bmp"\
	".\bitmap2.bmp"\
	".\bitmap3.bmp"\
	".\cursor1.cur"\
	".\icon1.ico"\
	

!IF  "$(CFG)" == "iq120 - Win32 Release"


".\Release\iq120.res" : $(SOURCE) $(DEP_RSC_IQ120_) "$(INTDIR)"
   $(RSC) $(RSC_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "iq120 - Win32 Debug"


".\Debug\iq120.res" : $(SOURCE) $(DEP_RSC_IQ120_) "$(INTDIR)"
   $(RSC) $(RSC_PROJ) $(SOURCE)


!ENDIF 

# End Source File
# End Target
# End Project
################################################################################
