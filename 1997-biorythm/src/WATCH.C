/*----------------------------------------
   HEXCALC.C -- Hexadecimal Calculator
                (c) Charles Petzold, 1996
  ----------------------------------------*/

#include <windows.h>
#include "resource.h"
#define WIDTH_NUM_BITMAP	17
#define HEIGHT_NUM_BITMAP	28

#define ID_TIMER 1

LRESULT CALLBACK WndProc (HWND, UINT, WPARAM, LPARAM) ;
HINSTANCE	ghInstance;

int WINAPI WinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance,
                    PSTR szCmdLine, int iCmdShow)
{
	static char  szAppName[] = "WATCH" ;
	HWND         hwnd ;
	MSG          msg ;
	WNDCLASSEX   wndclass ;

	ghInstance = hInstance;

	wndclass.cbSize        = sizeof (wndclass) ;
	wndclass.style         = CS_HREDRAW | CS_VREDRAW;
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

	hwnd = CreateDialog (hInstance, szAppName, 0, NULL) ;
	SetTimer(hwnd,ID_TIMER,1000,NULL);

	ShowWindow (hwnd, iCmdShow) ;

	while (GetMessage (&msg, NULL, 0, 0))
	{
		TranslateMessage (&msg) ;
		DispatchMessage (&msg) ;
	}
	return msg.wParam ;
}

void DrawBitmap(HWND hDlg,int nItem,char chr)
{
	HWND		hCtrl;
	HBITMAP		hBitmap;
	HDC			hDC,hMemDC;

	hCtrl = GetDlgItem(hDlg,nItem);

	switch(chr) {
	case '0':	case '1':	case '2':	case '3':	case '4':
	case '5':	case '6':	case '7':	case '8':	case '9':
		hBitmap=LoadBitmap(ghInstance,MAKEINTRESOURCE(IDB_BITMAP0+chr-'0'));
		break;
	case ':':
		hBitmap=LoadBitmap(ghInstance,MAKEINTRESOURCE(IDB_BITMAP_SEMICOLON));
		break;
	default:
		hBitmap=LoadBitmap(ghInstance,MAKEINTRESOURCE(IDB_BITMAP0));
		break;
	}
		
	hDC		= GetDC(hCtrl);
	hMemDC	= CreateCompatibleDC(hDC);
	SelectObject(hMemDC,hBitmap);
	StretchBlt(hDC,0,0,WIDTH_NUM_BITMAP,HEIGHT_NUM_BITMAP,
				hMemDC,0,0,WIDTH_NUM_BITMAP,HEIGHT_NUM_BITMAP,SRCCOPY);
	ReleaseDC(hDlg,hDC);
	DeleteDC(hMemDC);
	DeleteObject((HGDIOBJ)hBitmap);
}


LRESULT CALLBACK WndProc (HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	SYSTEMTIME		sysTime;
	char			szTime[256];

	switch (iMsg)
	{
	case WM_CREATE :
		return 0;
/*
	case WM_PAINT :	   
		GetSystemTime(&sysTime);
		wsprintf(szTime,"%2d%2d%2d",sysTime.wHour,sysTime.wMinute,sysTime.wSecond);
		hDC = GetDC(hCtrl1);
		hMemDC = CreateCompatibleDC(NULL);
		SelectObject(hMemDC,hBitmap);
		StretchBlt(hDC,0,0,20,20,
			hMemDC,0,0,20,20,SRCCOPY);
		ReleaseDC(hwnd,hDC);
		break;
*/		
	case WM_PAINT :	
	case WM_TIMER :
		GetSystemTime(&sysTime);
		wsprintf(szTime,"%2d:%2d:%2d",sysTime.wHour,sysTime.wMinute,sysTime.wSecond);
		DrawBitmap(hwnd,IDD_PAINT1,szTime[0]);
		DrawBitmap(hwnd,IDD_PAINT2,szTime[1]);
/*		
		DrawBitmap(hwnd,IDD_PAINT3,szTime[2]);
		DrawBitmap(hwnd,IDD_PAINT4,szTime[3]);
		DrawBitmap(hwnd,IDD_PAINT5,szTime[4]);
		DrawBitmap(hwnd,IDD_PAINT6,szTime[5]);
		DrawBitmap(hwnd,IDD_PAINT7,szTime[6]);
		DrawBitmap(hwnd,IDD_PAINT8,szTime[7]);
*/
		return 0;
	case WM_DESTROY :
		PostQuitMessage (0) ;
		return 0 ;
	}
return DefWindowProc (hwnd, iMsg, wParam, lParam) ;
}
