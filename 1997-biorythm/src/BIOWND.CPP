
#include <WINDOWS.H>

#include "biownd.h"
#include "getdate.h"
#include "math.h"
#include "resource.h"

#define		EMOTIONAL_CYCLE		28
#define		PHYSICAL_CYCLE		23
#define		INTELECTURE_CYCLE	33
#define		PI					3.14159265
#define		FONT_WIDTH			10
#define		FONT_HEIGHT			20
#define		FONT_NAME			"굴림체"

extern CGetDate		getDate;
extern HINSTANCE	ghInstance;
extern HWND			hWndText;

struct MYDATE{
	int yy;
	int mm;
	int dd;
}; 


#define YEAR_DAYS  365
int DateCalculation(MYDATE date)
{
    int i,yt;
    int m_result=0,result=0;
	int days[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    for (i=1901;i<=date.yy;i++)
      { if (i % 4 == 0 && (i % 100 != 0 || i % 400 == 0))
	       yt=YEAR_DAYS+1;
	 else  yt=YEAR_DAYS;
	 result += yt;
      }
    result -= yt;
    days[1] = 28;
    days[1] += ( yt - YEAR_DAYS );
    if  ( date.mm == 1 )   m_result = 0;
	       else
		  {  for (i=0;i<=date.mm-2;i++)
		    { m_result += days[i]; }
		  }
    result = result + m_result + date.dd;
    return result;
}

/* 오늘이 몇일인가?*/
int		GetToday()
{
	SYSTEMTIME			sysTime;
	GetLocalTime(&sysTime);
	return sysTime.wDay;
}

/* 현재까지 살아온 날들 */
int		GetLifeDays(void)
{
	char				szBirth[10];
	MYDATE				birth,now;
	SYSTEMTIME			sysTime;
	int					gap;

	strcpy(szBirth,getDate.GetDate());
	birth.yy = 1900 + (szBirth[0]-'0')*10 + szBirth[1]-'0';
	birth.mm = (szBirth[2]-'0')*10 + szBirth[3]-'0';
	birth.dd = (szBirth[4]-'0')*10 + szBirth[5]-'0';

	GetLocalTime(&sysTime);
	now.yy = sysTime.wYear;
	now.mm = sysTime.wMonth;
	now.dd = sysTime.wDay;
	gap = DateCalculation(now)-DateCalculation(birth);
	return gap;
}

/* 이번달 월초까지 살아온 날들 */
int		GetLifeDays2(void)
{
	char				szBirth[10];
	MYDATE				birth,now;
	SYSTEMTIME			sysTime;
	int					gap;
	strcpy(szBirth,getDate.GetDate());
	birth.yy = 1900 + (szBirth[0]-'0')*10 + szBirth[1]-'0';
	birth.mm = (szBirth[2]-'0')*10 + szBirth[3]-'0';
	birth.dd = (szBirth[4]-'0')*10 + szBirth[5]-'0';
	GetLocalTime(&sysTime);
	now.yy = sysTime.wYear;
	now.mm = sysTime.wMonth;
	now.dd = 1;
	gap = DateCalculation(now)-DateCalculation(birth);
	return gap;
}

#define BALL_WIDTH	11
#define BALL_HEIGHT	11

int	GetRythm(int days,int today,int cycle,int height)
{
	return (int)(height-sin((today+days%cycle)*(2*PI)/cycle)*(height-BALL_HEIGHT*3));
}
void DrawBall(HWND hWnd,int x, int y,int BITMAP_ID)
{
	HBITMAP		hBitmap;
	HDC			hMemDC,hDC;
	hDC = GetDC(hWnd);
	hBitmap=LoadBitmap(ghInstance,MAKEINTRESOURCE(BITMAP_ID));
	hMemDC = CreateCompatibleDC(hDC);
	SelectObject(hMemDC,hBitmap);
	BitBlt(hDC,x-BALL_WIDTH/2,y-BALL_HEIGHT/2,BALL_WIDTH,BALL_HEIGHT,
		hMemDC,0,0,SRCCOPY);
	DeleteDC(hMemDC);
	DeleteObject((HGDIOBJ)hBitmap);
	ReleaseDC(hWnd, hDC);
}

LRESULT CALLBACK BioWndProc (HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	HDC					hDC;
	PAINTSTRUCT			ps;
	int					gap;
	RECT				rect;
	int					i;
	int					x,y;
	HPEN				hPen;
	char				szBuf[100];
	HFONT				hFont;

	switch (iMsg)
	{
	case WM_CREATE :
		return 0;
	case WM_PAINT :
		hDC = BeginPaint(hwnd,&ps);
	/* DRAW FORM */
		gap = GetLifeDays2();
		GetClientRect(hwnd,&rect);
		MoveToEx(hDC,0,rect.bottom/2,NULL);
		LineTo(hDC,rect.right,rect.bottom/2);
#define STEP	14
#define HEIGHT	(rect.bottom/2)
#define MARGIN  10
		hFont = (HFONT)CreateFont(10,5,
			0,0,100,0,
			0,0,0,0,0,0,0,
			FONT_NAME);
		hFont = (HFONT)SelectObject(hDC,hFont);
		for(i=1;i<=31;i++) {
			MoveToEx(hDC,i*STEP-MARGIN,rect.bottom/2-10,NULL);
			LineTo(hDC,i*STEP-MARGIN,rect.bottom/2+10);
			/* DRAW DATE */
			wsprintf(szBuf,"%d",i);
			TextOut(hDC,i*STEP-MARGIN-4,rect.bottom/2+10,szBuf,strlen(szBuf));
		}
		DeleteObject(SelectObject(hDC,hFont));

		if(getDate.IsValidDate()) {
			/* DRAW GRAPH */
			for(i=0;i<=31;i++) {
				y = GetRythm(i,gap,EMOTIONAL_CYCLE,HEIGHT);
				x = (i+1)*STEP-MARGIN;
				DrawBall(hwnd,x,y,IDB_BALL_BLUE);
				y = GetRythm(i,gap,PHYSICAL_CYCLE,HEIGHT);
				DrawBall(hwnd,x,y,IDB_BALL_GREEN);
				y = GetRythm(i,gap,INTELECTURE_CYCLE,HEIGHT);
				DrawBall(hwnd,x,y,IDB_BALL_RED);
			}
		}
		/* DRAW TODAY */
		hPen=CreatePen(PS_SOLID,3,RGB(255,0,255));
		SelectObject(hDC,hPen);
		x = (GetToday())*STEP-MARGIN;
		MoveToEx(hDC,x,20,NULL);
		LineTo(hDC,x,HEIGHT*2-20);
		DeleteObject(hPen);

		/* PRINT TODAY */
		SYSTEMTIME			sysTime;
		GetLocalTime(&sysTime);
		wsprintf(szBuf,"오늘은 %d년 %d월 %d일 입니다.",sysTime.wYear,sysTime.wMonth,sysTime.wDay);
		TextOut(hDC,3,3,szBuf,strlen(szBuf));
		
		EndPaint(hwnd,&ps);
		return 0;
	}
return DefWindowProc (hwnd, iMsg, wParam, lParam) ;
}

void TextWndProcess(void)
{
	int					gap;
	static char			szBuf[600];
	int					p,e,i,rest;
	static  char* szBioResult[3][3][3]={
"세 리듬이 모두 불안정한 상태인 극히 위험한 날. 조용히 휴식을 취하며 마음을 편히 가지는 것이 좋다. 판단이나 사건개입에 극도의 주의가 필요하다. 사고 발생가능성이 최고로 높은 날이다.",
"신체리듬과 감성리듬이 위험일이며 지성리듬도 저조하다. 둔하고 저조한 상태에 빠져있는 이날은 특별한 주의를 통해 말썽을 피하라.",
"신체리듬과 감성리듬이 위험일이다. 높은 지성리듬에 냉정한 판단력을 기대한다. 언행에 신중을 기하라.",
"신체리듬과 지성리듬이 모두 위험일이며 감성리듬도 저조하여 사는것이 힘들고 지겹다.",
"감성, 지성리듬이 모두 저조하여 위험한 신체리듬을 더욱 악화시킨다.",
"오로지 기대할 데는 지성리듬뿐, 신체리듬이 불안정하므로 끝장난 기분이 들 것이고, 감성적으로 우울하다. 조심해야 할 날이다.",
"신체리듬과 지성리듬이 위험일이다. 높은 감성리듬에 기대해야 하나 사고 가능성이 높은 날이다.",
"신체리듬이 위험일이므로 육체적으로는 지쳐있고 불안정하지만 감성리듬은 고조기이다. 높은 감성 리듬이 당신의 신체 리듬에 도움을 줄 것이다. 낮은 지성리듬을 극복하는 적응하는 현명함도 있어야 한다.",
"육체적으로 불안정하고 몹시 지쳐 있는 신체리듬 위험일이다. 감성리듬과 지성리듬이 높으므로 약간 보완된다.",
"감성리듬과 지성리듬이 위험상태이고, 신체리듬마저 저조하여 온갖 불상사가 일어날 수 있는 날이다. 만사에 신중을 기하고 자중하라.",
"가급적 만사를 편하게 생각하라. 세 리듬이 모두 나쁘므로 성급한 결정을 피하고 많은 휴식을 취하라. 육체적으로 무기력하고, 감성리듬이 위험하여 영감이 떠오르지 않는 날이다.",
"신체리듬은 저조하고 감성리듬은 위험일이다. 오로지 기대되는것은 당신의 높은 지성리듬 뿐이다.",
"당신의 모든 것을 재점검할 날이다. 신체적, 감성적으로 침체되고 지성적으로 위험하다. 생동감이 없고 적극성도 결여된다. 만사에 조심하라.",
"좋은 날을 기다리며 휴식을 취하라. 신체,감성,지성의 세 리듬이 모두 저조기라는데 대하여 그렇게 불안해 할 필요는 없다.",
"몸이 무겁고 기분이 우울한 날이지만 높은 지성리듬이 당신을 도와줄 것이다. 정다운 친구를 만나거나 음악감상을 하거나 무엇이든 즐거운 일을 통해서 이날을 잘 넘겨야 한다. 기분 전환할 일이 필요한 날이다.",
"신체리듬이 저조기이고, 지성리듬이 위험일 이지만 높은 감성 리듬을 잘 이용하며 그런대로 좋은 날이 될 수 있다.",
"감성리듬의 이점을 최대한 활용하라. 창조적인 일에 전념하면 가장 좋겠다. 육체적으로 피로하고 지성적으로 저조한 날이다.",
"육체적으로 피로를 느끼는 날이지만 감성리듬과 지성리듬이 높으므로 모든것을 극복할 수 있을 것이다. 육체적 상태보다는 지적인 활동에 전념하라.",
"신체적으로 힘이 넘치는 것처럼 느껴지지만 감성리듬과 지성리듬이 위험일이므로 의기소침해질 것이다. 행동하기전에 다시 생각하라.",
"육체적으로는 활력이 넘치나 감성리듬이 위험일이고 지성리듬은 저조하므로 말썽이나 함정에 빠지지 않도록 한 번 더 생각하고 행하라.",
"높은 신체리듬과 지성리듬으로 행동과 생각이 풍부하지만 감정을 조심하라. 감성리듬이 위험일 이지 않은가! 무기력감에 빠질 위험이 있다.",
"육체적인 일을 하기에 적합하다. 그렇지만 지성리듬이 위험하므로 정신 집중을 요하는 일은 피하라.",
"결코 경솔하게 행동해서는 안되는 날이다. 신체상태는 활력이 넘치고 있으나 감정을 주의해야 한다. 지성리듬 또한 저조하므로 모든 결정에 있어서 돌다리도 두드려 보고 건너라.",
"신체리듬이 높으니 가급적 육체적 활동에 전념하라. 또한 지성리듬도 높으므로 어떤 결정을 내리는 데에 알맞는 날이다. 나쁜 감성리듬에 말려들지 않도록 감정과 정서를 안정시키며 대인관계에 임하라.",
"신체적으로 활기차고 감성적으로 신나는 날이다. 지성리듬이 위험일 이므로 당신의 생각을 주의 깊게 더듬어 보아야 하는 날이다.",
"활기차게 기분이 생동하는 날이다. 지성리듬이 저조기에 있으니 모든 일에 사려깊게만 행동하면 목표하는 바를 달성할 수 있다.",
"바야흐로 당신의 날이다. 세개의 리듬이 모두 고조기, 이 절호의 기회를 최대로 이용하라."
	};

	if(getDate.IsValidDate()) {
		gap = GetLifeDays();
		rest = gap%PHYSICAL_CYCLE;
		if(rest==0||rest==12) p = 0;
		else if(rest<12) p = 2;
		else if(rest>12) p = 1;
		rest = gap%EMOTIONAL_CYCLE;
		if(rest==0||rest==14) e = 0;
		else if(rest<14) e = 2;
		else if(rest>14) e = 1;
		rest = gap%INTELECTURE_CYCLE;
		if(rest==0||rest==17) i = 0;
		else if(rest<17) i = 2;
		else if(rest>17) i = 1;
		wsprintf(szBuf,"오늘은 당신이 태어난지 %d일째 되는 날입니다.%c%c%s",gap,0x0d,0x0a,szBioResult[p][e][i]);
		SendMessage(hWndText,WM_SETTEXT,0,(LPARAM)(LPCTSTR)szBuf);
	}
	else
		strcpy(szBuf,"    생일(양력)을 입력후 '실행' 버튼을 눌러 주세요!");
		SendMessage(hWndText,WM_SETTEXT,0,(LPARAM)(LPCTSTR)szBuf);
}
