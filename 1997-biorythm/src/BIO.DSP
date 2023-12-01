# Microsoft Developer Studio Project File - Name="Bio" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 5.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=Bio - Win32 Release
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "Bio.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "Bio.mak" CFG="Bio - Win32 Release"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Bio - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "Bio - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "Bio - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir ".\Release"
# PROP BASE Intermediate_Dir ".\Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir ".\Release"
# PROP Intermediate_Dir ".\Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /YX /c
# ADD CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /FR /YX /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "NDEBUG"
# ADD RSC /l 0x412 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib winmm.lib /nologo /subsystem:windows /machine:I386

!ELSEIF  "$(CFG)" == "Bio - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir ".\Debug"
# PROP BASE Intermediate_Dir ".\Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir ".\Debug"
# PROP Intermediate_Dir ".\Debug"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /YX /c
# ADD CPP /nologo /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /FR /YX /FD /c
# ADD BASE MTL /nologo /D "_DEBUG" /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "_DEBUG"
# ADD RSC /l 0x412 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /debug /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib winmm.lib /nologo /subsystem:windows /debug /machine:I386

!ENDIF 

# Begin Target

# Name "Bio - Win32 Release"
# Name "Bio - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;hpj;bat;for;f90"
# Begin Source File

SOURCE=.\Bio.cpp
# End Source File
# Begin Source File

SOURCE=.\biownd.cpp
# End Source File
# Begin Source File

SOURCE=.\getdate.cpp
# End Source File
# Begin Source File

SOURCE=.\playsnd.cpp
# End Source File
# Begin Source File

SOURCE=.\resource.rc
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl;fi;fd"
# Begin Source File

SOURCE=.\biownd.h
# End Source File
# Begin Source File

SOURCE=.\getdate.h
# End Source File
# Begin Source File

SOURCE=.\playsnd.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;cnt;rtf;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\BACK.BMP
# End Source File
# Begin Source File

SOURCE=.\backspc.bmp
# End Source File
# Begin Source File

SOURCE=.\ball_blue.bmp
# End Source File
# Begin Source File

SOURCE=.\ball_green.bmp
# End Source File
# Begin Source File

SOURCE=.\ball_red.bmp
# End Source File
# Begin Source File

SOURCE=.\button0.bmp
# End Source File
# Begin Source File

SOURCE=.\button1.bmp
# End Source File
# Begin Source File

SOURCE=.\button2.bmp
# End Source File
# Begin Source File

SOURCE=.\button3.bmp
# End Source File
# Begin Source File

SOURCE=.\button4.bmp
# End Source File
# Begin Source File

SOURCE=.\button5.bmp
# End Source File
# Begin Source File

SOURCE=.\button6.bmp
# End Source File
# Begin Source File

SOURCE=.\button7.bmp
# End Source File
# Begin Source File

SOURCE=.\button8.bmp
# End Source File
# Begin Source File

SOURCE=.\button9.bmp
# End Source File
# Begin Source File

SOURCE=.\buttons0.bmp
# End Source File
# Begin Source File

SOURCE=.\buttons1.bmp
# End Source File
# Begin Source File

SOURCE=.\buttons2.bmp
# End Source File
# Begin Source File

SOURCE=.\buttons3.bmp
# End Source File
# Begin Source File

SOURCE=.\buttons4.bmp
# End Source File
# Begin Source File

SOURCE=.\buttons5.bmp
# End Source File
# Begin Source File

SOURCE=.\buttons6.bmp
# End Source File
# Begin Source File

SOURCE=.\buttons7.bmp
# End Source File
# Begin Source File

SOURCE=.\buttons8.bmp
# End Source File
# Begin Source File

SOURCE=.\buttons9.bmp
# End Source File
# Begin Source File

SOURCE=.\date0.bmp
# End Source File
# Begin Source File

SOURCE=.\date1.bmp
# End Source File
# Begin Source File

SOURCE=.\date10.bmp
# End Source File
# Begin Source File

SOURCE=.\date2.bmp
# End Source File
# Begin Source File

SOURCE=.\date3.bmp
# End Source File
# Begin Source File

SOURCE=.\date4.bmp
# End Source File
# Begin Source File

SOURCE=.\date5.bmp
# End Source File
# Begin Source File

SOURCE=.\date6.bmp
# End Source File
# Begin Source File

SOURCE=.\date7.bmp
# End Source File
# Begin Source File

SOURCE=.\date8.bmp
# End Source File
# Begin Source File

SOURCE=.\date9.bmp
# End Source File
# Begin Source File

SOURCE=.\EXIT.bmp
# End Source File
# Begin Source File

SOURCE=.\exitS.bmp
# End Source File
# Begin Source File

SOURCE=.\icon1.ico
# End Source File
# Begin Source File

SOURCE=.\restart.bmp
# End Source File
# Begin Source File

SOURCE=.\run.bmp
# End Source File
# Begin Source File

SOURCE=.\sbackspc.bmp
# End Source File
# Begin Source File

SOURCE=.\srestart.bmp
# End Source File
# Begin Source File

SOURCE=.\srun.bmp
# End Source File
# End Group
# Begin Source File

SOURCE=.\click.wav
# End Source File
# Begin Source File

SOURCE=.\exit.wav
# End Source File
# Begin Source File

SOURCE=.\warning.wav
# End Source File
# End Target
# End Project
