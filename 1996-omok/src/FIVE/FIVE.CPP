/*

        Code Name : FSS ( Five Stone Story ..) µ¡¡¢·¡´¡‹¡
		Compiler  : bc++3.1
        Date      : '95. 5¶© - 6¶©

        ¬÷i·¡ˆa  e—i´ö´á¶a..ÒÒ•.             Lee Sung Ryoul.  < kkol >
*/

#include <alloc.h>
#include <conio.h>
#include <dos.h>
#include <fcntl.h>
#include <io.h>
#include <mem.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys\stat.h>
#include <time.h>

#include "adlib.h"
#include "han.h"
#include "ims.h"
#include "key.h"
#include "mouse.h"
#include "pcx.h"
#include "screen.h"
#include "speech.h"
#include "sprite.h"

#define XLEN 22
#define YLEN 20
#define LIBLEN 200
#define ATTACK -20
#define ICONX 260
#define ICONY 80

char crntDir[100];
char ibuf[100], icom[100], iman[100];
char Table[XLEN*YLEN];
int SBflag=OFF, BGMflag=OFF, SOUNDflag=OFF;
int tX, tY, x, y, comOx, comOy, manOx, manOy, value;
int crntDol=1, libCount=0;
int numPlayer=1;
char textBuf[80*25*2];
char textSwap[80*25*2];
int attack=ATTACK, dolCount;
char *putdol, *help, *thank, *hoho, *select, *ting;
char *icon[3];

struct
{
	int value;
	int len;
	char dol[15];
} lib[LIBLEN];

class Sprite Icon("icon.kol");
class Sprite T("text.kol");

void Start(void);
void Init(void);
void End(void);
//void SaveBoard(void);
void KeyCheck(void);
void OutSound(char *voc=NULL);
void Get(char *ibuf=ibuf);
void Put(char *ibuf=ibuf);
void PutDol(int x=x, int y=y);
void ChangeDol(void);
void ComPutDol(void);
int Check5Attack(void);
int Check5Defense(void);
int DolValue(int x, int y, int dol=crntDol);
int DirValue(int x, int y, int dx, int dy, int dol=crntDol);
void AddLib( char *dol, int value, int len);
void InitLib(void);
void InitLibDefault(void);
int GetGoodDol(int *x=&x, int *y=&y, int dol=crntDol);
void TextSplit(void);
void ScrollIn(void);
void ScrollOut(void);
void GameOver(int dol);
void PutIcon(int num);
void PutText(int num);
void Main(void);


void Start(void)
{
	puts("ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo");
	puts("o                  Five  Stone  Story                                 o");
	puts("ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo");
	puts("                                             Lee SungRyoul. [ID:kkol]  ");

	InitLib();
	tX=wherex();
	tY=wherey();
	Delay(100);

	gettext(1, 1, 80, 25, textSwap);
	TextSplit();

	Spr.LoadSpr("five.kol");

	if(SBReset()==ON)
	{
		SBflag=ON;
		BGMflag=ON;
		SOUNDflag=ON;
		set_machine(2);
		putdol 	= read_voc("put.voc");
		help	= read_voc("help.voc");
		thank   = read_voc("thank.voc");
		hoho   	= read_voc("hoho.voc");
		select	= read_voc("select.voc");
		ting	= read_voc("ting.voc");
		load_ims("angel.ims");
		load_bnk("angel.bnk");
		Clk_install();
	}


	Scr.SetMode();
	page2 = (char *) farcalloc(320, 200);
	if(page2==NULL) End();
	randomize();
	for(int i=0; i<3; i++)
	{
		icon[i] = (char *) farcalloc(50, 25);
		if( icon[i] == NULL) End();
	}
	Init();
}
void End(void)
{
	if(SBflag==ON)
	{
		Clk_uninstall();
		end_ims();
		OutSound(thank);
		while(voice_condition());

		farfree(putdol);
		farfree(help);
		farfree(thank);
		farfree(hoho);
		farfree(select);
		farfree(ting);
		speaker_off();

	}
	farfree(page2);
	Scr.SetMode(MONO);
	puttext(1, 1, 80, 25, textSwap);
	gotoxy(tX, tY);
	exit(0);
}
void Init(void)
{
	crntDol=1;
	dolCount=0;
	x = XLEN/2;
	y = YLEN/2;
	attack=ATTACK;
	setmem(Table, XLEN*YLEN, 0);
	Pcx.Load("board.pcx", page2);
	OutSound(select);
	ScrollOut();
	for(int i=0; i<3; i++)
	{
		Scr.GetImage(ICONX, ICONY+i*25, 50, 25, icon[i]);
	}
	PutIcon(0);
	PutIcon(1);
	PutIcon(2);
}
/*
void SaveBoard(void)
{
	int i,j;

	Scr.Clear();

	for(i=0; i<YLEN; i++)
	{
		Scr.Line(5, i*10+5, XLEN*10-10+5, i*10+5, 255);
	}
	for(i=0; i<XLEN; i++)
	{
		Scr.Line(i*10+5, 5, i*10+5, YLEN*10-10+5, 255);
	}

	Pcx.Save("swap.pcx");
}
*/
void KeyCheck(void)
{

	if(keyValue==0) return;
	else keyValue=0;

	char buf[40];
	int value=0, i;

	if(scan[__ESC]) End();
	else if(scan[__F1])   // help
	{
		page3 = (char*) farcalloc(320, 200);

		Scr.Copy(screen, page3);

		Pcx.Load("help.pcx", page2);
		ScrollOut();

		OutSound(help);
		if(SBflag==ON)
		{
			while(voice_condition());
		}
		Pcx.Load("help1.pcx", page2);
		ScrollOut();
		OutSound();
		while(scan[__F1]);
		keyValue=0;
		while(keyValue==0);
		OutSound(ting);
		for(i=320; i>=0; i-=5)
		{
			Scr.PutImageClip(i, 0, 320, 200, page3);
		}
		OutSound();

		farfree(page3);
	}
	else if(scan[__F2] && dolCount>0 && manOx!=-1) //Undo
	{
		Put();
		dolCount--;
		if(numPlayer==1)
		{
			dolCount--;
			x=comOx; y=comOy;
			Put(icom);
			Table[y*XLEN+x]=0;
			OutSound();
			Delay(100);
		}
		else if(numPlayer==2)
		{
			ChangeDol();
		}

		x=manOx; y=manOy;
		Put(iman);
		Table[y*XLEN+x]=0;
		OutSound(ting);
		Delay(100);

		manOx=-1;
		Get();
		Spr.PutSpr(x*10, y*10, 0);
	}
	else if(scan[__F3]) // start again
	{
		Scr.Copy(screen, page2);
		PutText(0);
		OutSound();
		while(1)
		{
			if(scan[__Y])
			{
				while(scan[__Y]);
				OutSound(ting);
				Init();
				Get();
				Spr.PutSpr(x*10, y*10, 0);
				break;
			}
			else if(scan[__N] || scan[__ESC])
			{
				while(scan[__N]);
				OutSound(ting);
				Scr.Copy(page2);
				while(scan[__ESC]);
				break;
			}
		}
	}
	else if(scan[__F4]) // choose player
	{
		if(numPlayer==1)
		{
			numPlayer=2;
			manOx=-1;
			OutSound(ting);
		}
		else if(numPlayer==2)
		{
			numPlayer=1;
			OutSound(ting);
			if(crntDol==2)
			{
				ComPutDol();
			}
		}
		while(scan[__F4]);
		PutIcon(2);

	}
	else if(scan[__F5] && SBflag)// music on/off
	{
		if(BGMflag==ON)
		{
			BGMflag=OFF;
			StopIms();
		}
		else if(BGMflag==OFF)
		{
			BGMflag=ON;
			ContinueIms();
		}
		OutSound(ting);
		while(scan[__F5]);
		PutIcon(0);

	}
	else if(scan[__F6] && SBflag)  // sound on/off
	{
		if(SOUNDflag==ON)
		{
			SOUNDflag=OFF;
		}
		else if(SOUNDflag==OFF)
		{
			SOUNDflag=ON;
		}

		OutSound(ting);
		while(scan[__F6]);
		PutIcon(1);
	}
	else if(scan[__1])
	{

		value = DolValue(x, y, 1);
		sprintf(buf, "value = %03d  x=%d  y=%d ", value, x, y);
		Scr.Bar(10, 190, 200, 200, 0);
		Han.Out(buf, 10, 190, 100);
		OutSound();
		while(scan[__1]);
	}
	else if(scan[__2])
	{

		value = DolValue(x, y, 2);
		sprintf(buf, "value = %03d  x=%d  y=%d ", value, x, y);
		Scr.Bar(10, 190, 200, 200, 0);
		Han.Out(buf, 10, 190, 100);
		OutSound();
		while(scan[__2]);
	}

}
void OutSound(char *voc)
{
		if(SBflag && SOUNDflag && voc!=NULL)
		{
			voice_play(voc);
		}
		else
		{
			sound(4000);
			Delay(10);
			sound(1000);
			Delay(20);
			nosound();
		}

}
void Get(char *ibuf)
{
	Scr.GetImage(x*10, y*10, 10, 10, ibuf);
}
void Put(char *ibuf)
{
	Scr.PutImage(x*10, y*10, 10, 10, ibuf);
}
void PutDol(int x, int y)
{
	Table[y*XLEN+x]=crntDol;
	Spr.PutSpr(x*10, y*10, crntDol);
	dolCount++;
	OutSound(putdol);
}
void ChangeDol(void)
{
	if(crntDol==1) crntDol=2;
	else crntDol=1;
}
void ComPutDol(void)
{
	int cx, cy, mx, my;
	int com, man;
	char buf[40];

	Put();
	man = GetGoodDol(&mx, &my, 1);
	com = GetGoodDol(&cx, &cy, 2);

	if(com>=1000) x=cx, y=cy;
	else if(com>=90 && com+20>=man) x=cx, y=cy;
	else if(com<30 && com<=man) x=mx, y=my;
	else if(com<30 && com>man) x=cx, y=cy;
	else if(com+attack>=man) x=cx, y=cy;
	else x=mx, y=my;

	Get(icom);
	comOx=x, comOy=y;

	if(attack<=15) attack+=2;
	else attack=-10;


	PutDol();
	ChangeDol();
	Get();
	Spr.PutSpr(x*10, y*10, 0);
	if(com>=1000)
	{
		OutSound();
		Delay(500);
		GameOver(2);
	}
}

int DolValue(int x, int y, int dol)
{
	int value=0;
	int buf;
	int samsam=0;

	buf = DirValue(x, y, -1, 0, dol);
	if(buf==41) samsam++;
	value += buf;

	buf = DirValue(x, y, -1, -1, dol);
	if(buf==41) samsam++;
	value += buf;

	buf = DirValue(x, y, 0, -1, dol);
	if(buf==41) samsam++;
	value += buf;

	buf = DirValue(x, y, 1, -1, dol);
	if(buf==41) samsam++;
	value += buf;

	if(samsam >= 2) return -1;
	else return value;
}
int DirValue(int x, int y, int dx, int dy, int dol)
{
	int value=0;
	int i, j, k;
	int x1=x, y1=y;
	char dolBuf[20];
	int dol2 = (dol==1 ? 2 : 1);
	int oldDol, startFlag=0;


	setmem(dolBuf, 20, 'x');

	oldDol = Table[y*XLEN+x];
	Table[y*XLEN+x]=dol;


	while(ON)
	{
		while(Table[y1*XLEN+x1]==dol && x1>=0 && y1>=0 && x1<XLEN && y1<YLEN)
		{
			x1+=dx;	y1+=dy;
		}

		if(x1<0 || y1<0)
		{
			x1-=dx; y1-=dy;
			startFlag=1;
			break;
		}
		else if(x1>=XLEN || y1>=YLEN)
		{
			x1-=dx; y1-=dy;
			break;
		}

		if(Table[y1*XLEN+x1]==0)
		{
			x1+=dx; y1+=dy;
			if(Table[y1*XLEN+x1]==0 && x1>=0 && y1>=0 && x1<XLEN && y1<YLEN)
			{
				x1-=dx; y1-=dy;
				x1-=dx; y1-=dy;
				break;
			}
			else if(Table[y1*XLEN+x1]==dol && x1>=0 && y1>=0 && x1<XLEN && y1<YLEN)
			{
				continue;
			}
			else if(Table[y1*XLEN+x1]==dol2 && x1>=0 && y1>=0 && x1<XLEN && y1<YLEN)
			{
				break;
			}
			else
			{
				x1-=dx; y1-=dy;
				x1-=dx; y1-=dy;
				break;
			}

		}
		else break;
	}
	for(i=startFlag; i<15; i++)
	{
		if(Table[y1*XLEN+x1]==0) dolBuf[i]=' ';
		else if(Table[y1*XLEN+x1]==dol) dolBuf[i]='o';
		else if(Table[y1*XLEN+x1]==dol2) dolBuf[i]='x';
		x1-=dx; y1-=dy;
		if( x1<0 || y1<0 || x1>=XLEN || y1>=YLEN) break;
	}

	int equalFlag=ON;

	for(i=0; i<libCount; i++)
	{
		for(j=0; j<lib[i].len; j++)
		{
			if(dolBuf[j] != lib[i].dol[j])
			{
				equalFlag=OFF;
				break;
			}
		}
		if(equalFlag==ON)
		{
			value = lib[i].value;
			break;
		}
		else
		{
			equalFlag=ON;
		}
	}

	Table[y*XLEN+x]=oldDol;

	return value;
}

void AddLib( char *dol, int value, int len)
{
	if(libCount>=LIBLEN) return;

	lib[libCount].value = value;
	lib[libCount].len = len;
	strcpy( lib[libCount].dol, dol);
	libCount++;
}
void InitLib(void)
{
	int handle;
	int i, value, len;
	char buf[60];

	handle = open("five.lib", O_RDONLY | O_TEXT );
	if(handle==-1)
	{
		puts("File Open Error");
		perror("Error");
		InitLibDefault();
		return ;
	}

	while(1)
	{
		read(handle, buf, 28);
		len = atoi(buf);
		if(len==0) break;
		value = atoi(buf+5);
		AddLib(buf+11, value, len);
	}
	printf("%d library loaded.....\n", libCount);

	close(handle);
}
void InitLibDefault(void)
{
	AddLib("o  ", 0, 3);
	AddLib("oo  ", 4, 4);
	AddLib("oo x", 3, 4);
	AddLib("oox", 1, 3);
	AddLib("xoo   ", 1, 6);
	AddLib("xoo  ", 0, 5);
	AddLib("xoo x", 0, 5);
	AddLib("x oo  ", 2, 6);
	AddLib("x oo x", 0, 6);
	AddLib("xoox", 0, 4);

	AddLib("o ox", 1, 4);
	AddLib("o o  ", 3, 5);
	AddLib("o o x", 3, 5);
	AddLib("xo ox", 0, 5);
	AddLib("xo o  ", 1, 6);
	AddLib("xo o x", 0, 6);
	AddLib("x o ox", 0, 6);
	AddLib("x o o  ", 3, 7);
	AddLib("x o o x", 2, 7);

	AddLib("ooo o ", 85, 6);
	AddLib("ooo ox", 85, 6);
	AddLib("o ooo ", 85, 6);
	AddLib("o ooox", 80, 6);
	AddLib("xooo o ", 80, 7);
	AddLib("xooo ox", 80, 7);
	AddLib("xo ooo ", 85, 7);
	AddLib("xo ooox", 80, 7);
	AddLib("x ooo o ", 80, 8);
	AddLib("x ooo ox", 80, 8);
	AddLib("x o ooo ", 85, 8);
	AddLib("x o ooox", 80, 8);
	AddLib("oo oo ", 80, 6);
	AddLib("oo oox", 80, 6);
	AddLib("xoo oo ", 80, 7);
	AddLib("xoo oox", 80, 7);
	AddLib("x oo oo ", 80, 8);
	AddLib("x oo oox", 80, 8);



	AddLib("ooo  ", 31, 5);
	AddLib("ooo x", 31, 5);
	AddLib("ooox", 2, 4);
	AddLib("x ooo  ", 31, 7);
	AddLib("x ooo x", 5, 7);
	AddLib("x ooox", 0, 6);
	AddLib("xooo  ", 5, 6);
	AddLib("xooo x", 0, 6);
	AddLib("xooox", 0, 5);

	AddLib("oo o ", 30, 5);
	AddLib("oo ox", 5, 5);
	AddLib("xoo o ", 5, 6);
	AddLib("xoo ox", 0, 6);
	AddLib("x oo o ", 30, 7);
	AddLib("x oo ox", 5, 7);
	AddLib("o oo ", 30, 5);
	AddLib("o oox", 5, 5);
	AddLib("xo oo ", 5, 6);
	AddLib("xo oox", 0, 6);
	AddLib("x o oo ", 30, 7);
	AddLib("x o oox", 5, 7);

	AddLib("ooooo ", 1000, 6);
	AddLib("ooooox", 1000, 6);
	AddLib("o ooooo ", 1000, 8);
	AddLib("o ooooox", 1000, 8);
	AddLib("oo ooooo ", 1000, 9);
	AddLib("oo ooooox", 1000, 9);
	AddLib("xooooo ", 1000, 7);
	AddLib("xooooox", 1000, 7);
	AddLib("x ooooo ", 1000, 8);
	AddLib("x ooooox", 1000, 8);
	AddLib("xo ooooo ", 1000, 9);
	AddLib("xo ooooox", 1000, 9);
	AddLib("x o ooooo ", 1000, 10);
	AddLib("x o ooooox", 1000, 10);

	AddLib("oooo  ", 100, 6);
	AddLib("oooo x", 100, 6);
	AddLib("oooo o", 80, 6);
	AddLib("x oooo ", 100, 7);
	AddLib("x oooox", 80, 7);
	AddLib("xoooo ", 80, 6);
	AddLib("oooox", 80, 5);
	AddLib("xoooox", 0, 6);

	AddLib("o ooo o ", 100, 8);
	AddLib("o ooo ox", 100, 8);
	AddLib("o ooo oo", 80, 8);
	AddLib("oo ooo o ",80, 9);
	AddLib("oo ooo oo", 0, 9);
	AddLib("oo ooo ox",80, 9);
	AddLib("xoo ooo o ",80, 10);
	AddLib("xoo ooo oo", 0, 10);
	AddLib("xoo ooo ox",80, 10);
	AddLib("x oo ooo o ",80, 11);
	AddLib("x oo ooo oo", 0, 11);
	AddLib("x oo ooo ox",80, 11);
	AddLib("xo ooo o ", 100, 9);
	AddLib("xo ooo ox", 100, 9);
	AddLib("xo ooo oo", 80, 9);
	AddLib("x o ooo o ", 100, 10);
	AddLib("x o ooo ox", 100, 10);
	AddLib("x o ooo oo", 80, 10);
	printf("%d library loaded.....\n", libCount);

}

int GetGoodDol(int *px, int *py, int dol)
{
	int i,j;
	int value=0, count=0;
	int oldValue=0;
	int x[100], y[100], choice;

	for(i=0; i<YLEN; i++)
	{
		for(j=0; j<XLEN; j++)
		{
			if(Table[i*XLEN+j]!=0 || j<0 || i<0 || j>=XLEN || i>=YLEN) continue;

			value =  DolValue(j, i, dol);
			if(value > oldValue )
			{
				count=0;
				x[count]=j; y[count]=i;
				oldValue = value;

			}
			else if(value == oldValue && value!=0)
			{
				if(count==100) count=99;
				else count++;
				x[count]=j; y[count]=i;
			}

		}
	}
	if(oldValue==0)
	{
		value=0;
		while(value==0)
		{
			*px = random(XLEN-10)+5;
			*py = random(YLEN-10)+5;
			if(Table[(*py)*XLEN+(*px)]==0) value=1;
		}
		return 0;
	}
	else
	{
		choice = random(count+1);
		*px = x[choice];
		*py = y[choice];
		return oldValue;
	}
}
void TextSplit(void)
{
	int i,j;

	for(i=0; i<40; i++)
	{
		setmem(textBuf, 80*25*2, 0);
		for(j=0; j<25; j++)
		{
			memcpy(textBuf+j*160, textScr+j*160+2, 39*2);
			memcpy(textBuf+j*160+82, textScr+j*160+80, 39*2);
		}
		memcpy(textScr, textBuf, 80*25*2);
		Delay(100);
	}


}
void ScrollIn(void)
{
	int i,j;

	for(i=0; i<=160; i+=4)
	{
		Scr.Copy(160-i, 0, 160, 199, 0, 0, page2);
		Scr.Copy(160, 0, 160+i, 199, 320-i, 0, page2);
	}
}
void ScrollOut(void)
{
	int i,j;
	for(i=0; i<=160; i+=5)
	{
		Scr.Copy(0, 0, i, 199, 160-i, 0, page2);
		Scr.Copy(320-i, 0, 320, 199, 160, 0, page2);
	}
}
void GameOver(int dol)
{
	OutSound(ting);
	Delay(4000);
	if(dol==1)
	{
		PutText(2);
	}
	else if(dol==2)
	{
		PutText(1);
		OutSound(hoho);
	}
	while(1)
	{
		if(scan[__Y]) break;
		else if(scan[__N] || scan[__ESC]) End();
	}
	OutSound(ting);
	Init();
	Get();
	Spr.PutSpr(x*10, y*10, 0);

}
void PutIcon(int num)
{
	if(num==0)
	{
		if(BGMflag==ON) Icon.PutSpr(ICONX, ICONY, num);
		else Scr.PutImage(ICONX, ICONY, 50, 25, icon[num]);
	}
	else if(num==1)
	{
		if(SOUNDflag==ON) Icon.PutSpr(ICONX, ICONY+25, num);
		else Scr.PutImage(ICONX, ICONY+25, 50, 25, icon[num]);
	}
	else if(num==2)
	{
		if(numPlayer==2) Icon.PutSpr(ICONX, ICONY+50, num);
		else Scr.PutImage(ICONX, ICONY+50, 50, 25, icon[num]);

	}

}
void PutText(int num)
{
	if(num==0)
	{
		T.PutSpr( 5, 100, num);
	}
	else if(num==1)
	{
		T.PutSpr( 30, 100, num);
	}
	else if(num==2)
	{
		T.PutSpr( 30, 100, num);
	}

}
void Main(void)
{

	Get();
	Spr.PutSpr(x*10, y*10, 0);

	if(SBflag==ON) play_ims();

	while(1)
	{
		KeyCheck();

		if(scan[__LEFT])
		{
			Put();
			if(x==0) x=XLEN-1;
			else x--;
			Get();
			Spr.PutSpr(x*10, y*10, 0);
			OutSound();
			Delay(1000);
		}
		if(scan[__RIGHT])
		{
			Put();
			if(x==XLEN-1) x=0;
			else x++;
			Get();
			Spr.PutSpr(x*10, y*10, 0);
			OutSound();
			Delay(1000);
		}
		if(scan[__UP])
		{
			Put();
			if(y==0) y=YLEN-1;
			else y--;
			Get();
			Spr.PutSpr(x*10, y*10, 0);
			OutSound();
			Delay(1000);
		}
		if(scan[__DOWN])
		{
			Put();
			if(y==YLEN-1) y=0;
			else y++;
			Get();
			Spr.PutSpr(x*10, y*10, 0);
			OutSound();
			Delay(1000);
		}
		if(scan[__SPACE])
		{
			if(Table[x + y*XLEN]==0 && DolValue(x, y)!=-1)
			{
				Put();
				Get(iman);
				manOx=x; manOy=y;
				PutDol();
				Get();
				Spr.PutSpr(x*10, y*10, 0);
				while(scan[__SPACE]);
				if(DolValue(x, y)>=1000)
				{
					GameOver(crntDol);
				}
				else if(numPlayer==1)
				{
					ChangeDol();
					ComPutDol();
				}
				else ChangeDol();

			}
		}


	}

}
void main(int argc, char **argv)
{
	int i;

	strcpy(crntDir, argv[0]);
	i = strlen(crntDir)-1;
	for(; i>0; i--)
		if(crntDir[i-1]=='\\')
		{
			crntDir[i]='\x0';
			break;
		}

	Start();
	Main();
	End();
}


