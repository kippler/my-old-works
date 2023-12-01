

#include <windows.h>
#include <time.h>
#include <stdio.h>

#include "resource.h"
#include "getdate.h"
#include "biownd.h"
#include "playsnd.h"


#define SCREEN_WIDTH	800
#define SCREEN_HEIGHT	600
#define BUTTON_WIDTH	81
#define BUTTON_HEIGHT	81
#define BUTTON_X		516
#define BUTTON_Y		122
#define MAX_BUTTON_NUM	14	/* 0~9(10) + BACKSPACE + RESTART + RUN + EXIT = 14 */
#define DATE_X			487
#define DATE_Y			72
#define DATE_WIDTH		27
#define DATE_HEIGHT		31
							   
#define BIO_X			55
#define BIO_Y			139
#define BIO_WIDTH		(487-BIO_X)
#define BIO_HEIGHT		(395-BIO_Y)

#define TEXT_X			55
#define TEXT_Y			446
#define TEXT_WIDTH		(488-TEXT_X)
#define TEXT_HEIGHT		(528-TEXT_Y)

#define EXIT_X			686
#define EXIT_Y			490
#define EXIT_WIDTH		91
#define EXIT_HEIGHT		86

#define MAX_DATE_NUM	6

#define BUTTON_BACK		10		// BACK SPACE BUTTON
#define BUTTON_RUN		11		// RUN BUTTON 
#define BUTTON_RESTART	12		// RESTART BUTTON 
#define BUTTON_EXIT		13		// EXIT BUTTON 

LRESULT CALLBACK WndProc (HWND, UINT, WPARAM, LPARAM) ;
LRESULT CALLBACK BitmapWndProc (HWND, UINT, WPARAM, LPARAM) ;
LRESULT CALLBACK DateWndProc (HWND, UINT, WPARAM, LPARAM) ;

HINSTANCE		ghInstance;
HWND			hWndMain;
HWND			hWndButton[MAX_BUTTON_NUM] ;
HWND			hWndDate[MAX_DATE_NUM] ;
HWND			hWndBio;
HWND			hWndText;
HWND			hWndExit;
POINT			pntScrMouse;
CGetDate		getDate;

int WINAPI WinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance,
                    PSTR szCmdLine, int iCmdShow)
{
	static char  szAppName[] = "BIO" ;
	static char	 szBitmapButton[]="BITMAPBUTTON";
	static char	 szDateWnd[]="DATEWINDOW";
	static char	 szBioWnd[]="BIOWINDOW";
	static char	 szTextWnd[]="TEXTWINDOW";

	HWND         hwnd ;
	MSG          msg ;
	WNDCLASSEX   wndclass ;

	ghInstance = hInstance;
	/* MAIN WINDOW */
	wndclass.cbSize        = sizeof (wndclass) ;
	wndclass.style         = CS_HREDRAW | CS_VREDRAW;
	wndclass.lpfnWndProc   = WndProc ;
	wndclass.cbClsExtra    = 0 ;
	wndclass.cbWndExtra    = 0 ;
	wndclass.hInstance     = hInstance ;
	wndclass.hIcon         = LoadIcon (NULL,szAppName);
	wndclass.hCursor       = LoadCursor (NULL, IDC_ARROW) ;
	wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wndclass.lpszMenuName  = NULL ;
	wndclass.lpszClassName = szAppName ;
	wndclass.hIconSm       = LoadIcon (hInstance, szAppName) ;
	RegisterClassEx (&wndclass) ;
	hWndMain = hwnd = CreateWindow(
		szAppName,"THE BIO RYTHM",
		WS_POPUP,
		(GetSystemMetrics(SM_CXSCREEN)-SCREEN_WIDTH)/2,
		(GetSystemMetrics(SM_CYSCREEN)-SCREEN_HEIGHT)/2,
		SCREEN_WIDTH,SCREEN_HEIGHT,
		NULL,NULL,hInstance,NULL);
	ShowWindow (hwnd, iCmdShow) ;
	UpdateWindow(hwnd);
	

	/* BUTTON WINDOW */
	int		i,j,x,y,num;
	POINT	pntButton[MAX_BUTTON_NUM]={
		BUTTON_X+BUTTON_WIDTH*1,BUTTON_Y+BUTTON_HEIGHT*3,	//0
		BUTTON_X+BUTTON_WIDTH*0,BUTTON_Y+BUTTON_HEIGHT*0,	//1
		BUTTON_X+BUTTON_WIDTH*1,BUTTON_Y+BUTTON_HEIGHT*0,	//2
		BUTTON_X+BUTTON_WIDTH*2,BUTTON_Y+BUTTON_HEIGHT*0,	//3
		BUTTON_X+BUTTON_WIDTH*0,BUTTON_Y+BUTTON_HEIGHT*1,   //4
		BUTTON_X+BUTTON_WIDTH*1,BUTTON_Y+BUTTON_HEIGHT*1,	//5
		BUTTON_X+BUTTON_WIDTH*2,BUTTON_Y+BUTTON_HEIGHT*1,	//6
		BUTTON_X+BUTTON_WIDTH*0,BUTTON_Y+BUTTON_HEIGHT*2,	//7
		BUTTON_X+BUTTON_WIDTH*1,BUTTON_Y+BUTTON_HEIGHT*2,	//8
		BUTTON_X+BUTTON_WIDTH*2,BUTTON_Y+BUTTON_HEIGHT*2,	//9
		BUTTON_X+BUTTON_WIDTH*0,BUTTON_Y+BUTTON_HEIGHT*3,	//BK
		BUTTON_X+BUTTON_WIDTH*2,BUTTON_Y+BUTTON_HEIGHT*3,   //Run
		BUTTON_X+BUTTON_WIDTH*0,BUTTON_Y+BUTTON_HEIGHT*4	//Restart
	};
	wndclass.lpfnWndProc   = BitmapWndProc ;
	wndclass.lpszClassName = szBitmapButton ;
	RegisterClassEx (&wndclass) ;
	for(j=0;j<4;j++) {
		for(i=0;i<3;i++) {
			num = i + j*3;
			x = pntButton[num].x;
			y = pntButton[num].y;
			hWndButton[num] = CreateWindow(
				szBitmapButton,	"BITMAP BUTTON",
				WS_CHILD,x,y,BUTTON_WIDTH,BUTTON_HEIGHT,
				hwnd,NULL,hInstance,NULL);
			ShowWindow (hWndButton[num], SW_SHOW) ;
			UpdateWindow(hWndButton[num]);
		}
	}

	/* RESTART BUTTON */
	x = pntButton[BUTTON_RESTART].x;
	y = pntButton[BUTTON_RESTART].y;
	hWndButton[BUTTON_RESTART] = CreateWindow(
		szBitmapButton,	"BITMAP BUTTON",
		WS_CHILD,x,y,BUTTON_WIDTH*2,BUTTON_HEIGHT,
		hwnd,NULL,hInstance,NULL);
	ShowWindow (hWndButton[BUTTON_RESTART], SW_SHOW) ;
	UpdateWindow(hWndButton[BUTTON_RESTART]);
	
	/* EXIT BUTTON */
	hWndButton[BUTTON_EXIT] = CreateWindow(
		szBitmapButton,	"BITMAP BUTTON",
		WS_CHILD,EXIT_X,EXIT_Y,EXIT_WIDTH,EXIT_HEIGHT,
		hwnd,NULL,hInstance,NULL);
	ShowWindow (hWndButton[BUTTON_EXIT], SW_SHOW) ;
	UpdateWindow(hWndButton[BUTTON_EXIT]);

	
	/* DATE WINDOW */
	POINT pntDate[MAX_DATE_NUM]={
		DATE_X + DATE_WIDTH*0,DATE_Y,
		DATE_X + DATE_WIDTH*1,DATE_Y,
		DATE_X + DATE_WIDTH*0+80,DATE_Y,
		DATE_X + DATE_WIDTH*1+80,DATE_Y,
		DATE_X + DATE_WIDTH*0+170,DATE_Y,
		DATE_X + DATE_WIDTH*1+170,DATE_Y};
	wndclass.lpfnWndProc   = DateWndProc ;
	wndclass.lpszClassName = szDateWnd;
	RegisterClassEx (&wndclass) ;
	for(i=0;i<MAX_DATE_NUM;i++) {
		x = pntDate[i].x;
		y = pntDate[i].y;
		hWndDate[i] = CreateWindow(
			szDateWnd,	"DATE WINDOW",
			WS_CHILD,x,y,DATE_WIDTH,DATE_HEIGHT,
			hwnd,NULL,hInstance,NULL);
			ShowWindow (hWndDate[i],SW_SHOW) ;
			UpdateWindow(hWndDate[i]);
	}

	/* BIO WINDOW */
	wndclass.lpfnWndProc   = BioWndProc ;
	wndclass.lpszClassName = szBioWnd;
	RegisterClassEx (&wndclass) ;
	hWndBio= CreateWindow(
		szBioWnd,	"BIO WINDOW",
		WS_CHILD,BIO_X,BIO_Y,BIO_WIDTH,BIO_HEIGHT,
		hwnd,NULL,hInstance,NULL);
	ShowWindow (hWndBio,SW_SHOW) ;
	UpdateWindow(hWndBio);

	/* TEXT WINDOW */
	hWndText= CreateWindow(
		"EDIT","",
		WS_CHILD|ES_MULTILINE,TEXT_X,TEXT_Y,TEXT_WIDTH,TEXT_HEIGHT,
		hwnd,NULL,hInstance,NULL);
	ShowWindow (hWndText,SW_SHOW) ;
	UpdateWindow(hWndText);
	TextWndProcess();
/*
	HDC	hDC;
	hDC=GetDC(hWndText);
	SetTextColor(hDC,RGB(255,0,0));
	SetBkColor(hDC,RGB(255,0,0));
	ReleaseDC(hWndText,hDC);
*/

	while (GetMessage (&msg, NULL, 0, 0))
	{
		TranslateMessage (&msg) ;
		DispatchMessage (&msg) ;
	}
	return msg.wParam ;
}

LRESULT CALLBACK WndProc (HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	static HBITMAP		hBitmap;
	HDC			hDC,hMemDC;
	PAINTSTRUCT	ps;

	switch (iMsg)
	{
	case WM_CREATE :
		hBitmap=LoadBitmap(ghInstance,MAKEINTRESOURCE(IDB_BACKGROUND));
		return 0;
	case WM_PAINT :
		hDC = BeginPaint(hwnd,&ps);
		hMemDC	= CreateCompatibleDC(hDC);
		SelectObject(hMemDC,hBitmap);
		StretchBlt(hDC,0,0,SCREEN_WIDTH,SCREEN_HEIGHT,
				hMemDC,0,0,SCREEN_WIDTH,SCREEN_HEIGHT,SRCCOPY);
		EndPaint(hwnd,NULL);
		DeleteDC(hMemDC);
		return 0;
	case WM_DESTROY :
		DeleteObject((HGDIOBJ)hBitmap);
		PostQuitMessage (0) ;
		return 0 ;
	}
return DefWindowProc (hwnd, iMsg, wParam, lParam) ;
}

LRESULT CALLBACK BitmapWndProc (HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	HBITMAP				hBitmap;
	HDC					hDC,hMemDC;
	PAINTSTRUCT			ps;
	int					i,iWin;
	static BOOL			isSelected[MAX_BUTTON_NUM]={FALSE,};
//	static BOOL			bCaptured=FALSE;
	static int			iBeep=0;


	switch (iMsg)
	{
	case WM_CREATE :
		return 0;
	case WM_PAINT :
		for(i=0;i<MAX_BUTTON_NUM;i++) {
			if(hWndButton[i]==hwnd) {
				if(isSelected[i]) {
					hBitmap=LoadBitmap(ghInstance,MAKEINTRESOURCE(IDB_BUTTONS0 + i));
					isSelected[i]=FALSE;
				}
				else 
					hBitmap=LoadBitmap(ghInstance,MAKEINTRESOURCE(IDB_BUTTON0 + i));
				break;
			}
		}
		hDC = BeginPaint(hwnd,&ps);
		hMemDC	= CreateCompatibleDC(hDC);
		SelectObject(hMemDC,hBitmap);
		StretchBlt(hDC,0,0,SCREEN_WIDTH,SCREEN_HEIGHT,
				hMemDC,0,0,SCREEN_WIDTH,SCREEN_HEIGHT,SRCCOPY);
		EndPaint(hwnd,NULL);
		DeleteDC(hMemDC);
		DeleteObject((HGDIOBJ)hBitmap);
		if(iBeep) {
			PlayResource(iBeep) ;
			if(iBeep==WAVE_EXIT)
				SendMessage(hWndMain,WM_CLOSE,0,0);
			InvalidateRect(hwnd,NULL,FALSE);
		}
		iBeep = FALSE;
		return 0;

	case WM_LBUTTONDOWN :
		printf("aa");
		if(iBeep) return 0;
		for(i=0;i<MAX_BUTTON_NUM;i++) 
			if(isSelected[i]) return 0;

		for(i=0;i<MAX_BUTTON_NUM;i++) {
			if(hWndButton[i]==hwnd) {
				iWin=i;
				break;
			}
		}
		isSelected[iWin]=TRUE;
//		SetCapture(hwnd);
//		bCaptured = TRUE;
		InvalidateRect(hwnd,NULL,TRUE);
		if(iWin<=9) {
			if(getDate.Add(iWin)==TRUE) {
				iBeep = WAVE_CLICK;
				InvalidateRect(hWndDate[getDate.GetPos()-1],NULL,FALSE);
			}
			else iBeep = WAVE_WARNING;
		}
		if(iWin==BUTTON_BACK) {
			if(getDate.Back()==TRUE) {
				iBeep = WAVE_CLICK;
				InvalidateRect(hWndDate[getDate.GetPos()],NULL,FALSE);
			}
			else iBeep = WAVE_WARNING;
			InvalidateRect(hWndBio,NULL,TRUE);
			TextWndProcess();
		}
 		if(iWin==BUTTON_RUN) {
			if(getDate.IsValidDate()) {
				iBeep = WAVE_CLICK;
				InvalidateRect(hWndBio,NULL,TRUE);
			}
			else {
				iBeep = WAVE_WARNING;
				InvalidateRect(hWndBio,NULL,TRUE);
			}
			TextWndProcess();
		}
 		if(iWin==BUTTON_RESTART) {
			iBeep = WAVE_CLICK;
			getDate.Clear();
			for(i=0;i<MAX_DATE_NUM;i++)
				InvalidateRect(hWndDate[i],NULL,FALSE);
			InvalidateRect(hWndBio,NULL,TRUE);
			TextWndProcess();
		}
 		if(iWin==BUTTON_EXIT) {
			iBeep = WAVE_EXIT;
			InvalidateRect(hWndBio,NULL,TRUE);
		}
		return 0;

	case WM_LBUTTONUP :
//		if(bCaptured==FALSE) return 0;
/*
		for(i=0;i<MAX_BUTTON_NUM;i++) {
			if(hWndButton[i]==hwnd) {
				iWin=i;
				break;
			}
		}
		isSelected[iWin]=FALSE;
*/
//		ReleaseCapture();
//		bCaptured=TRUE;
//		InvalidateRect(hwnd,NULL,FALSE);
		return 0;
	}
return DefWindowProc (hwnd, iMsg, wParam, lParam) ;
}

LRESULT CALLBACK DateWndProc (HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	HBITMAP				hBitmap=NULL;
	HDC					hDC,hMemDC;
	PAINTSTRUCT			ps;
	int					i;
	char				szDate[10];

	switch (iMsg)
	{
	case WM_CREATE :
		return 0;
	case WM_PAINT :
		strcpy(szDate,getDate.GetDate());
		for(i=0;i<MAX_DATE_NUM;i++) {
			if(hWndDate[i]==hwnd) {
				switch(szDate[i]) {
				case '0' :	case '1' :	case '2' :	case '3' :	case '4' :
				case '5' :	case '6' :	case '7' :	case '8' :	case '9' :
					hBitmap=LoadBitmap(ghInstance,MAKEINTRESOURCE(IDB_DATE0 + szDate[i]-'0'));
					break;
				default :
					hBitmap=LoadBitmap(ghInstance,MAKEINTRESOURCE(IDB_DATE_NULL));
					break;
				}
				break;
			}
		}
		hDC = BeginPaint(hwnd,&ps);
		hMemDC	= CreateCompatibleDC(hDC);
		SelectObject(hMemDC,hBitmap);
		StretchBlt(hDC,0,0,SCREEN_WIDTH,SCREEN_HEIGHT,
				hMemDC,0,0,SCREEN_WIDTH,SCREEN_HEIGHT,SRCCOPY);
		EndPaint(hwnd,NULL);
		DeleteDC(hMemDC);
		DeleteObject((HGDIOBJ)hBitmap);
		return 0;
	}
return DefWindowProc (hwnd, iMsg, wParam, lParam) ;

}

