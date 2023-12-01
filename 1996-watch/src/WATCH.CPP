/*
 *	WATCH.CPP	: DIGITAL WATCH PROGRAM 
 *
 *	AUTHOR		: ZERONE
 *	DATE		: 1996.12.28 ~ 12.29
 *	
 *
 *  구현 사항	: 
 *		1. MOUSE DRAG 
 *		2. BITMAP PROCESS
 *		3. REGISTRY 사용
 *		4. POPUP MENU
 *		5. CD PLAY 기능
 *
 */
  

#include <windows.h>
#include <winnt.h>
#include <mmsystem.h>
#include <stdlib.h>

#include "resource.h"
#include "CWATCH.H"		/* BITMAP PROCESS */
#include "CMOVE.H"		/* MOUSE DRAG PROCESS */
#include "ABOUT.H"		/* ABOUT DIALOG BOX */
#include "CREGIST.H"	/* REGISTRY PROCESS */


#define ID_TIMER 1

LRESULT CALLBACK WndProc (HWND, UINT, WPARAM, LPARAM) ;
HINSTANCE	ghInstance;
static char  szAppName[] = "WATCH" ;

int WINAPI WinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance,
                    PSTR szCmdLine, int iCmdShow)
{
	HWND         hwnd ;
	MSG          msg ;
	WNDCLASSEX   wndclass ;

	ghInstance = hInstance;

	wndclass.cbSize        = sizeof (wndclass) ;
	wndclass.style         = CS_DBLCLKS;
	wndclass.lpfnWndProc   = WndProc ;
	wndclass.cbClsExtra    = 0 ;
	wndclass.cbWndExtra    = DLGWINDOWEXTRA ;
	wndclass.hInstance     = hInstance ;
	wndclass.hIcon         = LoadIcon (hInstance, szAppName) ;
	wndclass.hCursor       = LoadCursor (NULL, IDC_ARROW) ;
	wndclass.hbrBackground = (HBRUSH) (COLOR_WINDOW + 1) ;
	wndclass.lpszMenuName  = NULL ;
	wndclass.lpszClassName = szAppName ;
	wndclass.hIconSm       = LoadIcon (hInstance, szAppName) ;

	RegisterClassEx (&wndclass) ;

	hwnd = CreateWindow(szAppName,
						szAppName,
						WS_DLGFRAME|WS_POPUP|WS_SYSMENU,
						CW_USEDEFAULT,
						CW_USEDEFAULT,
						CW_USEDEFAULT,
						CW_USEDEFAULT,
						NULL,
						NULL,
						hInstance,
						NULL);

	SetTimer(hwnd,ID_TIMER,1000,NULL);

	ShowWindow (hwnd, iCmdShow) ;
	UpdateWindow(hwnd);

	while (GetMessage (&msg, NULL, 0, 0))
	{
		TranslateMessage (&msg) ;
		DispatchMessage (&msg) ;
	}
	return msg.wParam ;
}


LRESULT CALLBACK WndProc (HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	static CWatch		*pWatch=NULL;
	static CMoveWindow	*pMoveWnd;
	static BOOL			bCapture=FALSE;
	static HMENU		hMenu;
	static CRegistry	regist;
	HDC					hDC;
	PAINTSTRUCT			ps;
	static POINT		pntWnd;
	static BOOL			is24Hour=TRUE,isTopMost=TRUE;

	switch (iMsg)
	{
	case WM_CREATE :
		/* GET DATA FROM REGISTRY */
		is24Hour = regist.Get24Hour();
		isTopMost = regist.GetTopMost();

		/* SET WATCH CLASS */
		hDC		= GetDC(hwnd);
		pWatch	= new CWatch(ghInstance,hwnd,hDC);
		ReleaseDC(hwnd,hDC);
		pWatch->Set24Hour(is24Hour);

		/* GET POSTION FROM REGISTRY AND SET POSITION */
		regist.GetPnt(pntWnd);
		pMoveWnd = new CMoveWindow(hwnd);
		pMoveWnd->SetPos(pntWnd.x,pntWnd.y);

		/* POP UP MENU PROCESSING */
		hMenu = LoadMenu(ghInstance,szAppName);
		hMenu = GetSubMenu(hMenu,0);
		if(is24Hour)  CheckMenuItem(hMenu,IDM_24,MF_BYCOMMAND|MF_CHECKED);
		if(isTopMost) {
			CheckMenuItem(hMenu,IDM_TOPMOST,MF_BYCOMMAND|MF_CHECKED);
			SetWindowPos(hwnd,HWND_TOPMOST,-1,-1,-1,-1,SWP_NOMOVE|SWP_NOSIZE);
		}
		return 0;

	case WM_TIMER :
		if(pWatch->SetTime()==FALSE) return 0;
		hDC		= GetDC(hwnd);
		BitBlt(hDC,0,0,pWatch->GetWidth(),pWatch->GetHeight(),
			pWatch->GetMemDC(),0,0,SRCCOPY);
		ReleaseDC(hwnd,hDC);
		return 0;

	case WM_PAINT :
		hDC = BeginPaint (hwnd,&ps);
		BitBlt(hDC,0,0,pWatch->GetWidth(),pWatch->GetHeight(),
			pWatch->GetMemDC(),0,0,SRCCOPY);
		EndPaint(hwnd,&ps);
		return 0;

	case WM_DESTROY :
		PostQuitMessage (0) ;
		pMoveWnd->GetPos(pntWnd);
		regist.SetPnt(pntWnd);
		regist.Set24Hour(is24Hour);
		regist.SetTopMost(isTopMost);
		delete pWatch;
		delete pMoveWnd;
		return 0 ;

/* DRAG SUPPORT */
	case WM_LBUTTONDOWN :
		bCapture = TRUE;
		pMoveWnd->Capture(LOWORD(lParam),HIWORD(lParam)); 
		SetCapture(hwnd);
		return 0;
	case WM_LBUTTONUP :
		bCapture = FALSE;
		ReleaseCapture();
		return 0;
	case WM_MOUSEMOVE :
		if(bCapture) {
			pMoveWnd->Move(LOWORD(lParam),HIWORD(lParam)); 
		}
		return 0;

/* POP-UP MENU PROCESSING */
	case WM_RBUTTONDOWN :
		POINT	pnt;
		pnt.x = LOWORD(lParam);
		pnt.y = HIWORD(wParam);
		ClientToScreen(hwnd,&pnt);
		TrackPopupMenu(hMenu,0,pnt.x,pnt.y,0,hwnd,NULL);
		return 0;

/* MENU PROCESSING */
	case WM_COMMAND :
		switch(LOWORD(wParam)) {
		case IDM_EXIT :
			SendMessage(hwnd,WM_CLOSE,0,0);
			return 0;
		case IDM_24 :
			is24Hour = !is24Hour;
			if(is24Hour)
				CheckMenuItem(hMenu,IDM_24,MF_BYCOMMAND|MF_CHECKED);
			else
				CheckMenuItem(hMenu,IDM_24,MF_BYCOMMAND|MF_UNCHECKED);
			pWatch->Set24Hour(is24Hour);
			return 0;
		case IDM_TOPMOST :
			isTopMost = !isTopMost;
			if(isTopMost) {
				CheckMenuItem(hMenu,IDM_TOPMOST,MF_BYCOMMAND|MF_CHECKED);
				SetWindowPos(hwnd,HWND_TOPMOST,-1,-1,-1,-1,SWP_NOMOVE|SWP_NOSIZE);
			}
			else {
				CheckMenuItem(hMenu,IDM_TOPMOST,MF_BYCOMMAND|MF_UNCHECKED);
				SetWindowPos(hwnd,HWND_BOTTOM,-1,-1,-1,-1,SWP_NOMOVE|SWP_NOSIZE);
			}
			return 0;
		case IDM_ABOUT :
			DialogBox(ghInstance,"ABOUTBOX",hwnd,(DLGPROC)AboutDlgProc);
			return 0;
		case IDM_PLAYCD :
			mciSendString("open cdaudio",NULL,0,NULL);
			mciSendString("set cdaudio time format TMSF",NULL,0,NULL);
			mciSendString("play cdaudio from 1 notify",NULL,0,hwnd);
			return 0;
		case IDM_STOPCD :
			mciSendString("close cdaudio",NULL,0,NULL) ;
			mciSendString("stop cdaudio",NULL,0,NULL) ;
			return 0;
		}
/* MENU PROCESSING END */

	}
	return DefWindowProc (hwnd, iMsg, wParam, lParam) ;
}
