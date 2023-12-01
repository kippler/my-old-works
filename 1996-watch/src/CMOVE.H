
#ifndef __CMOVE_H__
#define __CMOVE_H__

#include <windows.h>


class CMoveWindow {
private :
	POINT	pntWnd,pntPrev,pntCurrent;
	RECT	rectWnd;
	HWND	hWnd;
public :
	CMoveWindow(HWND ihWnd);
	void Capture(int x, int y);
	void SetPos(int x, int y);
	void Move(int x, int y);
	void GetPos(POINT &pnt);
};


#endif

