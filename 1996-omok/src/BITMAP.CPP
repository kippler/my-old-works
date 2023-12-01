
#include <windows.h>

void DrawBitmap(HDC hdc, HBITMAP hBitmap, int xStart, int yStart)
{
	BITMAP	bm;
	HDC		hdcMem;
//	DWORD	dwSize;
	POINT	ptSize, ptOrg;

	hdcMem=CreateCompatibleDC(hdc);
	SelectObject(hdcMem,hBitmap);
	SetMapMode(hdcMem,GetMapMode(hdc));

	GetObject(hBitmap, sizeof(BITMAP), (LPVOID)&bm);
	ptSize.x=bm.bmWidth;
	ptSize.y=bm.bmHeight;
	DPtoLP(hdc,&ptSize,1);
	ptOrg.x=0;
	ptOrg.y=0;
	DPtoLP(hdcMem,&ptOrg,1);

	BitBlt(hdc,xStart,yStart,  ptSize.x,ptSize.y, 
			hdcMem,ptOrg.x, ptOrg.y, SRCCOPY);
	DeleteDC(hdcMem);
}
