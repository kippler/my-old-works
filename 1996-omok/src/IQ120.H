/* IQ120.H */

#include <windows.h>
#include <memory.h>
#include <stdlib.h>
#include <string.h>
#include "board.h"
#include "stack.h"

#ifndef  __IQ120_H_ 
#define  __IQ120_H_ 

extern   HDC hdc;
#define  MAX_DEPTH 2
#define  END_RETURN_VALUE   10000

/* 현재의 공수 정도를 비교하기 위하여.. */
#define ENEMY '#'
#define MY '*'
#define SPACE '-'
#define LastAttack          4200
#define MaxAttack           1023
#define GenAttack           256
/* ------- 끝 ------  */


class IQ120 : public BOARD 
{
private :
	signed char ThinkBoard[MAX_X][MAX_Y];
	char		bestX[MAX_X*MAX_Y]; 
	char		bestY[MAX_X*MAX_Y]; 
    POINTSTACK  pointstack;
	char		boardXsize, boardYsize; 
	char		depth;
	int			bestValue;
	char		direction[4][20];
	void		ClearThinkBoard();
	char		IsOuter(char x,char y);
	int			CandidateChoose(void);
	int			Compare(POINT pnt,int color);
	void		Get4Direction(int ix, int iy, int color);
	int			Choose(POINT ipnt, int color);
	
public : 
	IQ120(int icx, int icy, int ix, int iy);
	int Think(POINT &retPnt,int side);
	int			WhoWin(POINT pnt);  
} ;
	

#endif
