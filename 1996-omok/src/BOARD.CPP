/* 1996. 5.
	BOARD.CPP
*/
#include <windows.h>
#include "board.h"


/* PRIVATE AREA */
void BOARD::Line(HDC hdc, int left, int top, int right, int bottom)
{
	MoveToEx(hdc,left,top,NULL);
	LineTo(hdc,right,bottom);
}


/* PUBLIC AREA */
BOARD::BOARD(int icxSize, int icySize, int ixSize, int iySize)
{
	cxSize = icxSize;
	cySize = icySize; 
	Resize(ixSize, iySize);
	Clear();
}                          
int BOARD::Getx(int cx){return (cx+1)*xTab;}
int BOARD::Gety(int cy){return (cy+1)*yTab;} 
int BOARD::Getcx(int x){return (x+xTab/2)/xTab -1 ;}
int BOARD::Getcy(int y){return (y+yTab/2)/yTab -1 ;}
void BOARD::Resize(int ix, int iy)
{
	xTab = ix / ( cxSize + 1 ) ;
	yTab = iy / ( cySize + 1 ) ; 
}



void BOARD::Clear(void)
{
	int x, y;
	for(x=0;x<=cxSize;x++) {
		for(y=0;y<=cySize;y++) {
			tbl[x][y]=VACANT;
		}
	}              
}
BOOL BOARD::Put(HDC hdc, int icx, int icy, int color)
{
	if(color==VACANT) {
		if(!tbl[icx][icy]) return FALSE;
		else {
			tbl[icx][icy]=VACANT;
			return TRUE;
		}
	}

	/* else */
	if(tbl[icx][icy]) return FALSE; 
	if(icx<0 || icy<0 || icx>=cxSize || icy>=cySize) return FALSE ;
	else tbl[icx][icy]=color;
	DrawStone(hdc,icx,icy);
	return TRUE;
}
int BOARD::Get(int ix,int iy)
{                          
	if(ix<0 || iy<0 || ix>=cxSize || iy>=cySize) return -1;
	return tbl[ix][iy];
}
void BOARD::DrawGrid(HDC hdc)
{                          
	int x, y;
	HPEN hPen1,hPen2;
	hPen1=CreatePen(PS_SOLID,0,RGB(0,0,0));
	hPen2=CreatePen(PS_SOLID,0,RGB(220,220,220));

	SelectObject(hdc,hPen2);
	for(y=0;y<cySize;y++) {  
		Line(hdc,Getx(0),Gety(y)+1,Getx(cxSize-1),Gety(y)+1);
	}
	for(x=0;x<cxSize;x++) {  
		Line(hdc,Getx(x)+1,Gety(0),Getx(x)+1,Gety(cySize-1));
	}
	SelectObject(hdc,hPen1);
	for(y=0;y<cySize;y++) {  
		Line(hdc,Getx(0),Gety(y),Getx(cxSize-1),Gety(y));
	}
	for(x=0;x<cxSize;x++) {  
		Line(hdc,Getx(x),Gety(0),Getx(x),Gety(cySize-1));
	}
	SelectObject(hdc,hPen2);
	DeleteObject(SelectObject(hdc,hPen1));
	DeleteObject(SelectObject(hdc,hPen2));

}

void BOARD::DrawAllStone(HDC hdc)
{
	int x, y;
	for(x=0;x<cxSize;x++) {
		for(y=0;y<cySize;y++) {
			DrawStone(hdc, x, y);
		}
	}
}

void BOARD::DrawStone(HDC hdc, int icx, int icy)
{                                                
	HBRUSH hbrush;       
	if(tbl[icx][icy]==WHITE) hbrush=(HBRUSH)GetStockObject(NULL);
	else if(tbl[icx][icy]==BLACK) hbrush=(HBRUSH)GetStockObject(GRAY_BRUSH);
	else return ;
	SelectObject(hdc,hbrush);
	Ellipse(hdc,Getx(icx)-(int)(xTab/2.2),Gety(icy)-(int)(yTab/2.2),Getx(icx)+(int)(xTab/2.2),Gety(icy)+(int)(yTab/2.2));
	DeleteObject(hbrush);
}
