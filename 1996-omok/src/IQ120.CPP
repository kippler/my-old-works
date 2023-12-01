#include "iq120.h"
static char patternMap[30][11]={"-*****#","#*****-","-*****-","#*****#",
							 "-****-",
							 "-****#","#****-","-***-",
							 "-***#","#***-",
							 "-**-"};
static int mapValue[30]={LastAttack,LastAttack,LastAttack,LastAttack,
				  MaxAttack,
				  GenAttack,GenAttack,GenAttack,
				  63,63,
				  31};

IQ120::IQ120(int icx, int icy, int ix, int iy) : BOARD(icx,icy,ix,iy)
{
	boardXsize = icx; // from 0....
	boardYsize = icy;
}

void IQ120::ClearThinkBoard()
{
	memset(ThinkBoard,'\0',sizeof(ThinkBoard));
}

int IQ120::Think(POINT &retPnt,int side)
{
	int			i;
	int			candidateSize;
	int			bestPos=-1;
	int			ret;
	int			randNum;
	POINT		pnt;
//	char		szBuf[100];
	
	bestValue=-10000;
	ClearThinkBoard();
	depth=0;
	candidateSize = CandidateChoose();
	if(candidateSize==0) return FALSE;
	
	for(i=1;i<=candidateSize;i++) {
		pointstack.pop(pnt);
		ret = Choose(pnt,side);
/* for debug */
//		TextOut(hdc,320,25,szBuf,wsprintf(szBuf,"N:%d/%d V:%d x:%d y:%d    ",i,candidateSize,ret,pnt.x,pnt.y));

		if(ret==bestValue) {
			bestPos++;
			bestX[bestPos]=(char)pnt.x;
			bestY[bestPos]=(char)pnt.y;
		}
		else if(ret>bestValue) {
//TextOut(hdc,320,50,szBuf,wsprintf(szBuf,"V:%d x:%d y:%d    ",ret,pnt.x,pnt.y));
			bestPos=0;
			bestX[bestPos]=(char)pnt.x;
			bestY[bestPos]=(char)pnt.y;
			bestValue=ret;
		}
	}					
	srand(1);
	randNum=rand()%(bestPos+1);
	retPnt.x=bestX[randNum];	
	retPnt.y=bestY[randNum];
//	TextOut(hdc,10,10,szBuf,wsprintf(szBuf,"randNum :%d  bestPos :%d  ",randNum,bestPos));
	return TRUE;         
}
					
char IQ120::IsOuter(char x,char y)
{
    if( x<0||y<0||x>=boardXsize||y>=boardYsize ) return TRUE;
    else return FALSE;
}
int IQ120::CandidateChoose(void)
{
    char x,y,i,j;
	int retVal=0;		 
	POINT pnt;
    for(x=0;x<boardXsize;x++){
        for(y=0;y<boardYsize;y++){
            if(tbl[x][y]!=VACANT) {
				for(i=max(x-2,0);i<=min(x+2,boardXsize-1);i++) {
					for(j=max(y-2,0);j<=min(y+2,boardYsize-1);j++) {
						ThinkBoard[i][j]=TRUE;
					}
				}
			}
		}
	}

    for(x=0;x<boardXsize;x++){
        for(y=0;y<boardYsize;y++){
            if(tbl[x][y]!=VACANT) ThinkBoard[x][y]=FALSE;
        }
    }


    for(x=0;x<boardXsize;x++){
        for(y=0;y<boardYsize;y++){
            if(ThinkBoard[x][y]) {
				pnt.x=x;
				pnt.y=y;
				pointstack.push(pnt);
				retVal++;
			}
        }
    }

	return retVal ; 
}            


int IQ120::WhoWin(POINT pnt)
{
	int side,x,y;
	int j00=0,j45=0,j90=0,j135=0;
	x=pnt.x;y=pnt.y;
	side=tbl[x][y];
	if(side==VACANT) {
//		printf("function WhoWin call error...");
		return FALSE;
	}
	// angle 0 to 180 
	x=pnt.x;
	for(y=pnt.y-1;y>=0;y--){
		if(tbl[x][y]==side) j00++;
		else break;
	}
	for(y=pnt.y+1;y<boardYsize;y++){
		if(tbl[x][y]==side) j00++;
		else break;
    }
	// angle 90 to 270
	y=pnt.y;
	for(x=pnt.x-1;x>=0;x--){
		if(tbl[x][y]==side) j90++;
		else break;
	}
	for(x=pnt.x+1;x<=boardXsize;x++){
		if(tbl[x][y]==side) j90++;
		else break;
    }
	
	// angle 135 to 180+135
	for(y=pnt.y-1,x=pnt.x-1 ; y>=0&&x>=0 ; y--,x--){
		if(tbl[x][y]==side) j135++;
		else break;
	}
	for(y=pnt.y+1,x=pnt.x+1 ; y<=boardYsize&&x<=boardXsize ; y++,x++){
		if(tbl[x][y]==side) j135++;
		else break;
    }
	// angle 45 to 180+45
	for(y=pnt.y-1,x=pnt.x+1 ; y>=0&&x<=boardXsize ; y--,x++){
		if(tbl[x][y]==side) j45++;
		else break;
	}
	for(y=pnt.y+1,x=pnt.x-1 ; y<=boardYsize&&x>=0 ; y++,x--){
		if(tbl[x][y]==side) j45++;
		else break;
	}
	
	if(j00>3||j45>3||j90>3||j135>3) {
		return TRUE;
	}
	return FALSE;	  
}
		
/* ---------------- 정도 계산 ------------- */
void IQ120::Get4Direction(int ix, int iy, int color)
{
    int x,y,i,j,startX,startY;
    int dir[4][2]={1,0, 1,1, 0,1, -1,1};   // 방향....
	memset(direction,0,sizeof(direction));

    for(i=0;i<=3;i++){        // 방향 설정...
        startX=ix;
        startY=iy;
        for(j=1;j<=10;j++){
            x=ix+dir[i][0]*j;
            y=iy+dir[i][1]*j;
            if(IsOuter(x,y)==TRUE){
                startX=x;startY=y;
                direction[i][0]=ENEMY;
                break;
            }
            if (tbl[x][y]!=color) {
                startX=x;startY=y;
                if(tbl[x][y]==VACANT) direction[i][0]=SPACE;
                else   direction[i][0]=ENEMY;
                break;
            }
        }     // start 찾기 !!!!!!!!
        
        for(j=1;j<=10;j++){
            x=startX-dir[i][0]*j;
            y=startY-dir[i][1]*j;
            if(IsOuter(x,y)==TRUE) {
                direction[i][j]=ENEMY;
                direction[i][j+1]=NULL;
                break;
            }
            if(tbl[x][y]==color) {
                direction[i][j]=MY;
            }
            if(tbl[x][y]!=color) {
                if(tbl[x][y]==VACANT) direction[i][j]=SPACE;
                else direction[i][j]=ENEMY;
                direction[i][j+1]=NULL;
                break;
            }
        }          // 지도 만들기..!!!!!(direction)
    }
}

int IQ120::Compare(POINT pnt,int color)
{
	int i,j,compValue=0;
	Get4Direction(pnt.x, pnt.y, color); 
	for(i=0;i<=10;i++) {
		for (j=0;j<=3;j++) {
				if(strcmp(direction[j],patternMap[i])==0)
					if(compValue<mapValue[i]) compValue=mapValue[i]; // 제일 좋은것 찾기 
		}
	}
	Get4Direction(pnt.x, pnt.y, -color); 
	for(i=0;i<=10;i++) {
		for (j=0;j<=3;j++) {
				if(strcmp(direction[j],patternMap[i])==0)
					if(compValue<(mapValue[i]-1)) compValue=(mapValue[i]-1); // 제일 좋은것 찾기 
		}
	}
	return compValue;
}


int IQ120::Choose(POINT ipnt, int color)
{
	int retValue=0;
	int getValue=0;
	int i, candidateSize;
	POINT pnt;
	int tmp;
	depth++;

	tbl[ipnt.x][ipnt.y]=color;
	if (WhoWin(ipnt)) {
		retValue=END_RETURN_VALUE;
		tbl[ipnt.x][ipnt.y]=VACANT;
		depth--;
		return retValue;
	}

	if (tmp=Compare(ipnt,color)) {
		retValue+=tmp;
	}

	ClearThinkBoard();
	candidateSize = CandidateChoose();
/* 테이블을 사용 */
	for(i=1;i<=candidateSize;i++) {
		pointstack.pop(pnt);
		if(depth<MAX_DEPTH) {
			getValue=Choose(pnt,-color);
			retValue-=getValue/2;
		}
	}						
#if 0  /* 무조건 무식하게 찾기 */
		if(getValue!=END_RETURN_VALUE) {
			if( (retValue>bestValue&&depth%2) || 
				(-retValue>bestValue&&!(depth%2)) ||retValue==0){
				if(depth<MAX_DEPTH) {
					getValue=Choose(pnt,-color);
					retValue-=getValue/2;
				}
			}
		}
#endif
	tbl[ipnt.x][ipnt.y]=VACANT;
	depth--;
	return retValue;
}
