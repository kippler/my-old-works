/* BOARD.H  - BOARD class heaer file */
#ifndef __BOARD_H__
#define __BOARD_H__


#define MAX_X 19
#define MAX_Y 19
#define BLACK 1
#define WHITE -1
#define VACANT 0   

class BOARD {
private :
	int cxSize, cySize;   
	int xTab, yTab ; 
	void Line(HDC hdc, int left, int top, int right, int bottom);
	
	public :
	char tbl[MAX_X][MAX_Y];
	BOARD(int icxSize, int icySize, int ixSize, int iySize);
	int Getx(int cx);
	int Gety(int cy);
	int Getcx(int x);
	int Getcy(int y);
	void Resize(int ix, int iy);
	void Clear(void);
	BOOL Put(HDC hdc, int ix, int iy, int color); 
	int Get(int ix, int iy);
	void DrawGrid(HDC hdc);
	void DrawAllStone(HDC hdc);
	void DrawStone(HDC hdc, int icx, int icy);
} ;
#endif
