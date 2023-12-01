# Microsoft Developer Studio Generated NMAKE File, Format Version 4.20
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

!IF "$(CFG)" == ""
CFG=WATCH - Win32 Debug
!MESSAGE No configuration specified.  Defaulting to WATCH - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "WATCH - Win32 Release" && "$(CFG)" != "WATCH - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE on this makefile
!MESSAGE by defining the macro CFG on the command line.  For example:
!MESSAGE 
!MESSAGE NMAKE /f "WATCH.mak" CFG="WATCH - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "WATCH - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "WATCH - Win32 Debug" (based on "Win32 (x86) Application")
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
# PROP Target_Last_Scanned "WATCH - Win32 Debug"
RSC=rc.exe
CPP=cl.exe
MTL=mktyplib.exe

!IF  "$(CFG)" == "WATCH - Win32 Release"

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

ALL : "$(OUTDIR)\WATCH.exe"

CLEAN : 
	-@erase "$(INTDIR)\about.obj"
	-@erase "$(INTDIR)\Cmove.obj"
	-@erase "$(INTDIR)\cregist.obj"
	-@erase "$(INTDIR)\cwatch.obj"
	-@erase "$(INTDIR)\Watch.obj"
	-@erase "$(INTDIR)\Watch.res"
	-@erase "$(OUTDIR)\WATCH.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /YX /c
# ADD CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /YX /c
CPP_PROJ=/nologo /ML /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS"\
 /Fp"$(INTDIR)/WATCH.pch" /YX /Fo"$(INTDIR)/" /c 
CPP_OBJS=.\Release/
CPP_SBRS=.\.
# ADD BASE MTL /nologo /D "NDEBUG" /win32
# ADD MTL /nologo /D "NDEBUG" /win32
MTL_PROJ=/nologo /D "NDEBUG" /win32 
# ADD BASE RSC /l 0x412 /d "NDEBUG"
# ADD RSC /l 0x412 /d "NDEBUG"
RSC_PROJ=/l 0x412 /fo"$(INTDIR)/Watch.res" /d "NDEBUG" 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/WATCH.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib winmm.lib /nologo /subsystem:windows /machine:I386
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib\
 advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib\
 odbccp32.lib winmm.lib /nologo /subsystem:windows /incremental:no\
 /pdb:"$(OUTDIR)/WATCH.pdb" /machine:I386 /out:"$(OUTDIR)/WATCH.exe" 
LINK32_OBJS= \
	"$(INTDIR)\about.obj" \
	"$(INTDIR)\Cmove.obj" \
	"$(INTDIR)\cregist.obj" \
	"$(INTDIR)\cwatch.obj" \
	"$(INTDIR)\Watch.obj" \
	"$(INTDIR)\Watch.res"

"$(OUTDIR)\WATCH.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "WATCH - Win32 Debug"

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

ALL : "$(OUTDIR)\WATCH.exe" "$(OUTDIR)\WATCH.bsc"

CLEAN : 
	-@erase "$(INTDIR)\about.obj"
	-@erase "$(INTDIR)\about.sbr"
	-@erase "$(INTDIR)\Cmove.obj"
	-@erase "$(INTDIR)\Cmove.sbr"
	-@erase "$(INTDIR)\cregist.obj"
	-@erase "$(INTDIR)\cregist.sbr"
	-@erase "$(INTDIR)\cwatch.obj"
	-@erase "$(INTDIR)\cwatch.sbr"
	-@erase "$(INTDIR)\vc40.idb"
	-@erase "$(INTDIR)\vc40.pdb"
	-@erase "$(INTDIR)\Watch.obj"
	-@erase "$(INTDIR)\Watch.res"
	-@erase "$(INTDIR)\Watch.sbr"
	-@erase "$(OUTDIR)\WATCH.bsc"
	-@erase "$(OUTDIR)\WATCH.exe"
	-@erase "$(OUTDIR)\WATCH.ilk"
	-@erase "$(OUTDIR)\WATCH.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

# ADD BASE CPP /nologo /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /YX /c
# ADD CPP /nologo /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /FR /YX /c
CPP_PROJ=/nologo /MLd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS"\
 /FR"$(INTDIR)/" /Fp"$(INTDIR)/WATCH.pch" /YX /Fo"$(INTDIR)/" /Fd"$(INTDIR)/" /c\
 
CPP_OBJS=.\Debug/
CPP_SBRS=.\Debug/
# ADD BASE MTL /nologo /D "_DEBUG" /win32
# ADD MTL /nologo /D "_DEBUG" /win32
MTL_PROJ=/nologo /D "_DEBUG" /win32 
# ADD BASE RSC /l 0x412 /d "_DEBUG"
# ADD RSC /l 0x412 /d "_DEBUG"
RSC_PROJ=/l 0x412 /fo"$(INTDIR)/Watch.res" /d "_DEBUG" 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/WATCH.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\about.sbr" \
	"$(INTDIR)\Cmove.sbr" \
	"$(INTDIR)\cregist.sbr" \
	"$(INTDIR)\cwatch.sbr" \
	"$(INTDIR)\Watch.sbr"

"$(OUTDIR)\WATCH.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /debug /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib winmm.lib /nologo /subsystem:windows /debug /machine:I386
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib\
 advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib\
 odbccp32.lib winmm.lib /nologo /subsystem:windows /incremental:yes\
 /pdb:"$(OUTDIR)/WATCH.pdb" /debug /machine:I386 /out:"$(OUTDIR)/WATCH.exe" 
LINK32_OBJS= \
	"$(INTDIR)\about.obj" \
	"$(INTDIR)\Cmove.obj" \
	"$(INTDIR)\cregist.obj" \
	"$(INTDIR)\cwatch.obj" \
	"$(INTDIR)\Watch.obj" \
	"$(INTDIR)\Watch.res"

"$(OUTDIR)\WATCH.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
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

# Name "WATCH - Win32 Release"
# Name "WATCH - Win32 Debug"

!IF  "$(CFG)" == "WATCH - Win32 Release"

!ELSEIF  "$(CFG)" == "WATCH - Win32 Debug"

!ENDIF 

################################################################################
# Begin Source File

SOURCE=.\Watch.rc
DEP_RSC_WATCH=\
	".\bitmap1.bmp"\
	".\bitmap10.bmp"\
	".\bitmap2.bmp"\
	".\bitmap3.bmp"\
	".\bitmap4.bmp"\
	".\bitmap5.bmp"\
	".\bitmap6.bmp"\
	".\bitmap7.bmp"\
	".\bitmap8.bmp"\
	".\bitmap9.bmp"\
	".\bmp00001.bmp"\
	".\bmp00002.bmp"\
	".\watch.ico"\
	

"$(INTDIR)\Watch.res" : $(SOURCE) $(DEP_RSC_WATCH) "$(INTDIR)"
   $(RSC) $(RSC_PROJ) $(SOURCE)


# End Source File
################################################################################
# Begin Source File

SOURCE=.\cwatch.cpp
DEP_CPP_CWATC=\
	".\cwatch.H"\
	

!IF  "$(CFG)" == "WATCH - Win32 Release"


"$(INTDIR)\cwatch.obj" : $(SOURCE) $(DEP_CPP_CWATC) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "WATCH - Win32 Debug"


"$(INTDIR)\cwatch.obj" : $(SOURCE) $(DEP_CPP_CWATC) "$(INTDIR)"

"$(INTDIR)\cwatch.sbr" : $(SOURCE) $(DEP_CPP_CWATC) "$(INTDIR)"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\Watch.cpp
DEP_CPP_WATCH_=\
	".\ABOUT.H"\
	".\CMOVE.H"\
	".\CREGIST.H"\
	".\cwatch.H"\
	

!IF  "$(CFG)" == "WATCH - Win32 Release"


"$(INTDIR)\Watch.obj" : $(SOURCE) $(DEP_CPP_WATCH_) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "WATCH - Win32 Debug"


"$(INTDIR)\Watch.obj" : $(SOURCE) $(DEP_CPP_WATCH_) "$(INTDIR)"

"$(INTDIR)\Watch.sbr" : $(SOURCE) $(DEP_CPP_WATCH_) "$(INTDIR)"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\Cmove.cpp
DEP_CPP_CMOVE=\
	".\CMOVE.H"\
	".\cwatch.H"\
	

!IF  "$(CFG)" == "WATCH - Win32 Release"


"$(INTDIR)\Cmove.obj" : $(SOURCE) $(DEP_CPP_CMOVE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "WATCH - Win32 Debug"


"$(INTDIR)\Cmove.obj" : $(SOURCE) $(DEP_CPP_CMOVE) "$(INTDIR)"

"$(INTDIR)\Cmove.sbr" : $(SOURCE) $(DEP_CPP_CMOVE) "$(INTDIR)"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\about.cpp
DEP_CPP_ABOUT=\
	".\ABOUT.H"\
	

!IF  "$(CFG)" == "WATCH - Win32 Release"


"$(INTDIR)\about.obj" : $(SOURCE) $(DEP_CPP_ABOUT) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "WATCH - Win32 Debug"


"$(INTDIR)\about.obj" : $(SOURCE) $(DEP_CPP_ABOUT) "$(INTDIR)"

"$(INTDIR)\about.sbr" : $(SOURCE) $(DEP_CPP_ABOUT) "$(INTDIR)"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\cregist.cpp
DEP_CPP_CREGI=\
	".\CREGIST.H"\
	

!IF  "$(CFG)" == "WATCH - Win32 Release"


"$(INTDIR)\cregist.obj" : $(SOURCE) $(DEP_CPP_CREGI) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "WATCH - Win32 Debug"


"$(INTDIR)\cregist.obj" : $(SOURCE) $(DEP_CPP_CREGI) "$(INTDIR)"

"$(INTDIR)\cregist.sbr" : $(SOURCE) $(DEP_CPP_CREGI) "$(INTDIR)"


!ENDIF 

# End Source File
# End Target
# End Project
################################################################################
