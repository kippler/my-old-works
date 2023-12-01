
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
#define		FONT_NAME			"����ü"

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

/* ������ �����ΰ�?*/
int		GetToday()
{
	SYSTEMTIME			sysTime;
	GetLocalTime(&sysTime);
	return sysTime.wDay;
}

/* ������� ��ƿ� ���� */
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

/* �̹��� ���ʱ��� ��ƿ� ���� */
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
		wsprintf(szBuf,"������ %d�� %d�� %d�� �Դϴ�.",sysTime.wYear,sysTime.wMonth,sysTime.wDay);
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
"�� ������ ��� �Ҿ����� ������ ���� ������ ��. ������ �޽��� ���ϸ� ������ ���� ������ ���� ����. �Ǵ��̳� ��ǰ��Կ� �ص��� ���ǰ� �ʿ��ϴ�. ��� �߻����ɼ��� �ְ��� ���� ���̴�.",
"��ü����� ���������� �������̸� �������뵵 �����ϴ�. ���ϰ� ������ ���¿� �����ִ� �̳��� Ư���� ���Ǹ� ���� ������ ���϶�.",
"��ü����� ���������� �������̴�. ���� �������뿡 ������ �Ǵܷ��� ����Ѵ�. ���࿡ ������ ���϶�.",
"��ü����� ���������� ��� �������̸� �������뵵 �����Ͽ� ��°��� ����� �����.",
"����, ���������� ��� �����Ͽ� ������ ��ü������ ���� ��ȭ��Ų��.",
"������ ����� ���� ���������, ��ü������ �Ҿ����ϹǷ� ���峭 ����� �� ���̰�, ���������� ����ϴ�. �����ؾ� �� ���̴�.",
"��ü����� ���������� �������̴�. ���� �������뿡 ����ؾ� �ϳ� ��� ���ɼ��� ���� ���̴�.",
"��ü������ �������̹Ƿ� ��ü�����δ� �����ְ� �Ҿ��������� ���������� �������̴�. ���� ���� ������ ����� ��ü ���뿡 ������ �� ���̴�. ���� ���������� �غ��ϴ� �����ϴ� �����Ե� �־�� �Ѵ�.",
"��ü������ �Ҿ����ϰ� ���� ���� �ִ� ��ü���� �������̴�. ��������� ���������� �����Ƿ� �ణ ���ϵȴ�.",
"��������� ���������� ��������̰�, ��ü���븶�� �����Ͽ� �°� �һ�簡 �Ͼ �� �ִ� ���̴�. ���翡 ������ ���ϰ� �����϶�.",
"������ ���縦 ���ϰ� �����϶�. �� ������ ��� ���ڹǷ� ������ ������ ���ϰ� ���� �޽��� ���϶�. ��ü������ ������ϰ�, ���������� �����Ͽ� ������ �������� �ʴ� ���̴�.",
"��ü������ �����ϰ� ���������� �������̴�. ������ ���Ǵ°��� ����� ���� �������� ���̴�.",
"����� ��� ���� �������� ���̴�. ��ü��, ���������� ħü�ǰ� ���������� �����ϴ�. �������� ���� ���ؼ��� �Ῡ�ȴ�. ���翡 �����϶�.",
"���� ���� ��ٸ��� �޽��� ���϶�. ��ü,����,������ �� ������ ��� �������µ� ���Ͽ� �׷��� �Ҿ��� �� �ʿ�� ����.",
"���� ���̰� ����� ����� �������� ���� ���������� ����� ������ ���̴�. ���ٿ� ģ���� �����ų� ���ǰ����� �ϰų� �����̵� ��ſ� ���� ���ؼ� �̳��� �� �Ѱܾ� �Ѵ�. ��� ��ȯ�� ���� �ʿ��� ���̴�.",
"��ü������ �������̰�, ���������� ������ ������ ���� ���� ������ �� �̿��ϸ� �׷���� ���� ���� �� �� �ִ�.",
"���������� ������ �ִ��� Ȱ���϶�. â������ �Ͽ� �����ϸ� ���� ���ڴ�. ��ü������ �Ƿ��ϰ� ���������� ������ ���̴�.",
"��ü������ �Ƿθ� ������ �������� ��������� ���������� �����Ƿ� ������ �غ��� �� ���� ���̴�. ��ü�� ���º��ٴ� ������ Ȱ���� �����϶�.",
"��ü������ ���� ��ġ�� ��ó�� ���������� ��������� ���������� �������̹Ƿ� �Ǳ��ħ���� ���̴�. �ൿ�ϱ����� �ٽ� �����϶�.",
"��ü�����δ� Ȱ���� ��ġ�� ���������� �������̰� ���������� �����ϹǷ� �����̳� ������ ������ �ʵ��� �� �� �� �����ϰ� ���϶�.",
"���� ��ü����� ������������ �ൿ�� ������ ǳ�������� ������ �����϶�. ���������� ������ ���� ������! ����°��� ���� ������ �ִ�.",
"��ü���� ���� �ϱ⿡ �����ϴ�. �׷����� ���������� �����ϹǷ� ���� ������ ���ϴ� ���� ���϶�.",
"���� ����ϰ� �ൿ�ؼ��� �ȵǴ� ���̴�. ��ü���´� Ȱ���� ��ġ�� ������ ������ �����ؾ� �Ѵ�. �������� ���� �����ϹǷ� ��� ������ �־ ���ٸ��� �ε�� ���� �ǳʶ�.",
"��ü������ ������ ������ ��ü�� Ȱ���� �����϶�. ���� �������뵵 �����Ƿ� � ������ ������ ���� �˸´� ���̴�. ���� �������뿡 �������� �ʵ��� ������ ������ ������Ű�� ���ΰ��迡 ���϶�.",
"��ü������ Ȱ������ ���������� �ų��� ���̴�. ���������� ������ �̹Ƿ� ����� ������ ���� ���� ����� ���ƾ� �ϴ� ���̴�.",
"Ȱ������ ����� �����ϴ� ���̴�. ���������� �����⿡ ������ ��� �Ͽ� ������Ը� �ൿ�ϸ� ��ǥ�ϴ� �ٸ� �޼��� �� �ִ�.",
"�پ���� ����� ���̴�. ������ ������ ��� ������, �� ��ȣ�� ��ȸ�� �ִ�� �̿��϶�."
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
		wsprintf(szBuf,"������ ����� �¾�� %d��° �Ǵ� ���Դϴ�.%c%c%s",gap,0x0d,0x0a,szBioResult[p][e][i]);
		SendMessage(hWndText,WM_SETTEXT,0,(LPARAM)(LPCTSTR)szBuf);
	}
	else
		strcpy(szBuf,"    ����(���)�� �Է��� '����' ��ư�� ���� �ּ���!");
		SendMessage(hWndText,WM_SETTEXT,0,(LPARAM)(LPCTSTR)szBuf);
}