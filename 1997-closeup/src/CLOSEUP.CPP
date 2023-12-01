
#include <windows.h>
#include "resource.h"

#define		DEFAULT_CAPTURE_WIDTH	50
#define		DEFAULT_CAPTURE_HEIGHT	50
#define		CAPTURE_MAX				200
#define		CAPTURE_MIN				10

#define		TIMER_1					1
#define		TIMER_2					2


LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
VOID CALLBACK TimerProc(HWND hwnd, UINT uMsg, UINT idEvent,	DWORD dwTime);	

int WINAPI WinMain
(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszArg, int nCmdShow)
{

        HWND hWnd;
        MSG msg;
        WNDCLASSEX WndClass;
        char szAppName[] ="Close Up";

		WndClass.cbSize		=	sizeof(WNDCLASSEX); 
        WndClass.style		=	CS_HREDRAW|CS_VREDRAW;
        WndClass.lpfnWndProc = WndProc;
        WndClass.cbClsExtra =	0;
        WndClass.cbWndExtra =	0;
        WndClass.hInstance	=	hInstance;
        WndClass.hIcon		=	LoadIcon(NULL, IDI_QUESTION);
        WndClass.hIconSm	=	LoadIcon(NULL, IDI_QUESTION);
        WndClass.hCursor	=	LoadCursor(NULL, IDC_ARROW);
        WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
        WndClass.lpszMenuName = NULL;
        WndClass.lpszClassName = szAppName;
        if(!RegisterClassEx(&WndClass)) return NULL;

        hWnd = CreateWindow(
                szAppName,
                szAppName,
                WS_OVERLAPPEDWINDOW,
                10,10,150,150,
				NULL,
				NULL,
                hInstance,
				NULL
				);
		
		SetWindowPos(hWnd,
			HWND_TOPMOST,
			10,10,150,150,NULL);


		SetTimer(hWnd,TIMER_1,1,NULL);
		SetTimer(hWnd,TIMER_2,200,NULL);

        ShowWindow(hWnd, nCmdShow);
        UpdateWindow(hWnd);

        while(GetMessage(&msg, NULL, 0, 0))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
        return msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT mesg, WPARAM wParam, LPARAM lParam)
{
	HDC		hDispDC,hDC;
	static	POINT	pntCursor,pntPrev;
	static	int	xScr,yScr;
	static	int xCapture = DEFAULT_CAPTURE_WIDTH;
	static	int yCapture = DEFAULT_CAPTURE_HEIGHT;
	static char szAppName[] ="Close Up";
	static char szBuf[100];



	switch(mesg)
    {
        case WM_DESTROY :
            PostQuitMessage(0);
            return FALSE;
		case WM_SIZE :
			xScr = LOWORD(lParam); 
			yScr = HIWORD(lParam); 
			return FALSE;
		case WM_TIMER :
			switch(wParam) {
			case TIMER_1 :
				GetCursorPos(&pntCursor);
				if(pntCursor.x!=pntPrev.x ||pntCursor.y!=pntPrev.y  ) {
					hDispDC = GetDC(NULL);
					hDC = GetDC(hWnd);
					StretchBlt(hDC,0,0,xScr,yScr,
						hDispDC,max(0,pntCursor.x-xCapture/2),max(0,pntCursor.y-yCapture/2),
						xCapture,yCapture,SRCCOPY);
					ReleaseDC(hWnd,hDispDC);
					ReleaseDC(hWnd,hDC);
					pntPrev = pntCursor;
				}
				return FALSE;
			case TIMER_2 :
				hDispDC = GetDC(NULL);
				hDC = GetDC(hWnd);
				StretchBlt(hDC,0,0,xScr,yScr,
					hDispDC,max(0,pntCursor.x-xCapture/2),max(0,pntCursor.y-yCapture/2),
					xCapture,yCapture,SRCCOPY);
				ReleaseDC(hWnd,hDispDC);
				ReleaseDC(hWnd,hDC);
				pntPrev = pntCursor;
				return FALSE;
			}

		case WM_LBUTTONDOWN :
			xCapture -=10;
			yCapture -=10;
			xCapture = max(xCapture,CAPTURE_MIN);
			yCapture = max(yCapture,CAPTURE_MIN);
			wsprintf(szBuf,"%s %d x %d",szAppName,xCapture,yCapture);
			SetWindowText(hWnd,szBuf);
			return FALSE;
		case WM_RBUTTONDOWN :
			xCapture +=10;
			yCapture +=10;
			xCapture = min(xCapture,CAPTURE_MAX);
			yCapture = min(yCapture,CAPTURE_MAX);
			wsprintf(szBuf,"%s %d x %d",szAppName,xCapture,yCapture);
			SetWindowText(hWnd,szBuf);
			return FALSE;

    }
    return DefWindowProc(hWnd, mesg, wParam, lParam);
}
VOID CALLBACK TimerProc(HWND hwnd, UINT uMsg, UINT idEvent,	DWORD dwTime)
{
	HDC		hDC;
	static POINT	pntCursor;
	int		x,y,x2,y2,i;

	hDC = GetDC(NULL);
	SetROP2(hDC,R2_NOTXORPEN);
	GetCursorPos(&pntCursor);

	for(i=100;i>=0;i--) {
		x = pntCursor.x-i;
		x2 = pntCursor.x+i;
		y = pntCursor.y-i;
		y2 = pntCursor.y+i;
		Rectangle(hDC,x,y,x2,y2);
		Rectangle(hDC,x,y,x2,y2);
	}
	ReleaseDC(NULL,hDC);
	return ; 
}
