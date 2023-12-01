# Microsoft Developer Studio Generated NMAKE File, Format Version 4.20
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

!IF "$(CFG)" == ""
CFG=Bio - Win32 Debug
!MESSAGE No configuration specified.  Defaulting to Bio - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "Bio - Win32 Release" && "$(CFG)" != "Bio - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE on this makefile
!MESSAGE by defining the macro CFG on the command line.  For example:
!MESSAGE 
!MESSAGE NMAKE /f "Bio.mak" CFG="Bio - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Bio - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "Bio - Win32 Debug" (based on "Win32 (x86) Application")
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
# PROP Target_Last_Scanned "Bio - Win32 Debug"
RSC=rc.exe
MTL=mktyplib.exe
CPP=cl.exe

!IF  "$(CFG)" == "Bio - Win32 Release"

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

ALL : "$(OUTDIR)\Bio.exe"

CLEAN : 
	-@erase "$(INTDIR)\Bio.obj"
	-@erase "$(INTDIR)\biownd.obj"
	-@erase "$(INTDIR)\getdate.obj"
	-@erase "$(INTDIR)\playsnd.obj"
	-@erase "$(INTDIR)\resource.res"
	-@erase "$(OUTDIR)\Bio.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /YX /c
# ADD CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /YX /c
CPP_PROJ=/nologo /ML /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS"\
 /Fp"$(INTDIR)/Bio.pch" /YX /Fo"$(INTDIR)/" /c 
CPP_OBJS=.\Release/
CPP_SBRS=.\.
# ADD BASE MTL /nologo /D "NDEBUG" /win32
# ADD MTL /nologo /D "NDEBUG" /win32
MTL_PROJ=/nologo /D "NDEBUG" /win32 
# ADD BASE RSC /l 0x412 /d "NDEBUG"
# ADD RSC /l 0x412 /d "NDEBUG"
RSC_PROJ=/l 0x412 /fo"$(INTDIR)/resource.res" /d "NDEBUG" 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/Bio.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib winmm.lib /nologo /subsystem:windows /machine:I386
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib\
 advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib\
 odbccp32.lib winmm.lib /nologo /subsystem:windows /incremental:no\
 /pdb:"$(OUTDIR)/Bio.pdb" /machine:I386 /out:"$(OUTDIR)/Bio.exe" 
LINK32_OBJS= \
	"$(INTDIR)\Bio.obj" \
	"$(INTDIR)\biownd.obj" \
	"$(INTDIR)\getdate.obj" \
	"$(INTDIR)\playsnd.obj" \
	"$(INTDIR)\resource.res"

"$(OUTDIR)\Bio.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "Bio - Win32 Debug"

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

ALL : "$(OUTDIR)\Bio.exe" "$(OUTDIR)\Bio.bsc"

CLEAN : 
	-@erase "$(INTDIR)\Bio.obj"
	-@erase "$(INTDIR)\Bio.sbr"
	-@erase "$(INTDIR)\biownd.obj"
	-@erase "$(INTDIR)\biownd.sbr"
	-@erase "$(INTDIR)\getdate.obj"
	-@erase "$(INTDIR)\getdate.sbr"
	-@erase "$(INTDIR)\playsnd.obj"
	-@erase "$(INTDIR)\playsnd.sbr"
	-@erase "$(INTDIR)\resource.res"
	-@erase "$(INTDIR)\vc40.idb"
	-@erase "$(INTDIR)\vc40.pdb"
	-@erase "$(OUTDIR)\Bio.bsc"
	-@erase "$(OUTDIR)\Bio.exe"
	-@erase "$(OUTDIR)\Bio.ilk"
	-@erase "$(OUTDIR)\Bio.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

# ADD BASE CPP /nologo /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /YX /c
# ADD CPP /nologo /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /FR /YX /c
CPP_PROJ=/nologo /MLd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS"\
 /FR"$(INTDIR)/" /Fp"$(INTDIR)/Bio.pch" /YX /Fo"$(INTDIR)/" /Fd"$(INTDIR)/" /c 
CPP_OBJS=.\Debug/
CPP_SBRS=.\Debug/
# ADD BASE MTL /nologo /D "_DEBUG" /win32
# ADD MTL /nologo /D "_DEBUG" /win32
MTL_PROJ=/nologo /D "_DEBUG" /win32 
# ADD BASE RSC /l 0x412 /d "_DEBUG"
# ADD RSC /l 0x412 /d "_DEBUG"
RSC_PROJ=/l 0x412 /fo"$(INTDIR)/resource.res" /d "_DEBUG" 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/Bio.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\Bio.sbr" \
	"$(INTDIR)\biownd.sbr" \
	"$(INTDIR)\getdate.sbr" \
	"$(INTDIR)\playsnd.sbr"

"$(OUTDIR)\Bio.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /debug /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib winmm.lib /nologo /subsystem:windows /debug /machine:I386
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib\
 advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib\
 odbccp32.lib winmm.lib /nologo /subsystem:windows /incremental:yes\
 /pdb:"$(OUTDIR)/Bio.pdb" /debug /machine:I386 /out:"$(OUTDIR)/Bio.exe" 
LINK32_OBJS= \
	"$(INTDIR)\Bio.obj" \
	"$(INTDIR)\biownd.obj" \
	"$(INTDIR)\getdate.obj" \
	"$(INTDIR)\playsnd.obj" \
	"$(INTDIR)\resource.res"

"$(OUTDIR)\Bio.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
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

# Name "Bio - Win32 Release"
# Name "Bio - Win32 Debug"

!IF  "$(CFG)" == "Bio - Win32 Release"

!ELSEIF  "$(CFG)" == "Bio - Win32 Debug"

!ENDIF 

################################################################################
# Begin Source File

SOURCE=.\Bio.cpp
DEP_CPP_BIO_C=\
	".\biownd.h"\
	".\getdate.h"\
	".\playsnd.h"\
	

!IF  "$(CFG)" == "Bio - Win32 Release"


"$(INTDIR)\Bio.obj" : $(SOURCE) $(DEP_CPP_BIO_C) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "Bio - Win32 Debug"


"$(INTDIR)\Bio.obj" : $(SOURCE) $(DEP_CPP_BIO_C) "$(INTDIR)"

"$(INTDIR)\Bio.sbr" : $(SOURCE) $(DEP_CPP_BIO_C) "$(INTDIR)"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\resource.rc
DEP_RSC_RESOU=\
	".\BACK.BMP"\
	".\backspc.bmp"\
	".\ball_blue.bmp"\
	".\ball_green.bmp"\
	".\ball_red.bmp"\
	".\button0.bmp"\
	".\button1.bmp"\
	".\button2.bmp"\
	".\button3.bmp"\
	".\button4.bmp"\
	".\button5.bmp"\
	".\button6.bmp"\
	".\button7.bmp"\
	".\button8.bmp"\
	".\button9.bmp"\
	".\buttons0.bmp"\
	".\buttons1.bmp"\
	".\buttons2.bmp"\
	".\buttons3.bmp"\
	".\buttons4.bmp"\
	".\buttons5.bmp"\
	".\buttons6.bmp"\
	".\buttons7.bmp"\
	".\buttons8.bmp"\
	".\buttons9.bmp"\
	".\click.wav"\
	".\date0.bmp"\
	".\date1.bmp"\
	".\date10.bmp"\
	".\date2.bmp"\
	".\date3.bmp"\
	".\date4.bmp"\
	".\date5.bmp"\
	".\date6.bmp"\
	".\date7.bmp"\
	".\date8.bmp"\
	".\date9.bmp"\
	".\EXIT.bmp"\
	".\exit.wav"\
	".\exitS.bmp"\
	".\icon1.ico"\
	".\restart.bmp"\
	".\run.bmp"\
	".\sbackspc.bmp"\
	".\srestart.bmp"\
	".\srun.bmp"\
	".\warning.wav"\
	

"$(INTDIR)\resource.res" : $(SOURCE) $(DEP_RSC_RESOU) "$(INTDIR)"
   $(RSC) $(RSC_PROJ) $(SOURCE)


# End Source File
################################################################################
# Begin Source File

SOURCE=.\getdate.cpp
DEP_CPP_GETDA=\
	".\getdate.h"\
	

!IF  "$(CFG)" == "Bio - Win32 Release"


"$(INTDIR)\getdate.obj" : $(SOURCE) $(DEP_CPP_GETDA) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "Bio - Win32 Debug"


"$(INTDIR)\getdate.obj" : $(SOURCE) $(DEP_CPP_GETDA) "$(INTDIR)"

"$(INTDIR)\getdate.sbr" : $(SOURCE) $(DEP_CPP_GETDA) "$(INTDIR)"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\biownd.cpp
DEP_CPP_BIOWN=\
	".\biownd.h"\
	".\getdate.h"\
	

!IF  "$(CFG)" == "Bio - Win32 Release"


"$(INTDIR)\biownd.obj" : $(SOURCE) $(DEP_CPP_BIOWN) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "Bio - Win32 Debug"


"$(INTDIR)\biownd.obj" : $(SOURCE) $(DEP_CPP_BIOWN) "$(INTDIR)"

"$(INTDIR)\biownd.sbr" : $(SOURCE) $(DEP_CPP_BIOWN) "$(INTDIR)"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\playsnd.cpp
DEP_CPP_PLAYS=\
	".\playsnd.h"\
	

!IF  "$(CFG)" == "Bio - Win32 Release"


"$(INTDIR)\playsnd.obj" : $(SOURCE) $(DEP_CPP_PLAYS) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "Bio - Win32 Debug"


"$(INTDIR)\playsnd.obj" : $(SOURCE) $(DEP_CPP_PLAYS) "$(INTDIR)"

"$(INTDIR)\playsnd.sbr" : $(SOURCE) $(DEP_CPP_PLAYS) "$(INTDIR)"


!ENDIF 

# End Source File
# End Target
# End Project
################################################################################
