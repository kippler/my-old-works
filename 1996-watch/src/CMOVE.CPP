/*
 * CMOVE.CPP	: PROCESSING MOVE WINDOW PROCESS
 */

#include "cmove.h"
#include "cwatch.h"

#define WIDTH				(BITMAP_WIDTH*MAX_COLUMN+6)
#define HEIGHT				(BITMAP_HEIGHT+6)
/* 6 IS MAGIC NUMBER - SIZE OF BORDER *2 */

CMoveWindow::CMoveWindow(HWND ihWnd)
{
	GetWindowRect(ihWnd,&rectWnd);
	hWnd = ihWnd;
}
void CMoveWindow::SetPos(int x, int y)
{
	if(x<0) x = 0;
	if(y<0) y = 0;
	GetWindowRect(hWnd,&rectWnd);
	if(x+rectWnd.right-rectWnd.left>GetSystemMetrics(SM_CXSCREEN)) x = 
		GetSystemMetrics(SM_CXSCREEN) - (rectWnd.right-rectWnd.left);
	if(y+rectWnd.bottom-rectWnd.top>GetSystemMetrics(SM_CYSCREEN)) y = 
		GetSystemMetrics(SM_CYSCREEN) - (rectWnd.bottom-rectWnd.top);

	pntWnd.x = x;
	pntWnd.y = y;
	MoveWindow(hWnd,pntWnd.x,pntWnd.y,
		WIDTH,HEIGHT,TRUE);
}
void CMoveWindow::GetPos(POINT &pnt)
{
	GetWindowRect(hWnd,&rectWnd);
	pnt.x = rectWnd.left;
	pnt.y = rectWnd.top;
}

void CMoveWindow::Capture(int x, int y)
{
	pntCurrent.x = x;
	pntCurrent.y = y;
	pntPrev = pntCurrent;
}
void CMoveWindow::Move(int x, int y)
{
	pntCurrent.x = x;
	pntCurrent.y = y;
	pntWnd.x = pntWnd.x + ( pntCurrent.x - pntPrev.x );
	pntWnd.y = pntWnd.y + ( pntCurrent.y - pntPrev.y );
	
	MoveWindow(hWnd,pntWnd.x,pntWnd.y,
		WIDTH,HEIGHT,TRUE);
}
