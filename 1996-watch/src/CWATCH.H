#ifndef __CWATCH_H__
#define __CWATCH_H__

#include <windows.h>
#include "resource.h"

//#define BITMAP_WIDTH		17
//#define BITMAP_HEIGHT		28
#define BITMAP_WIDTH		7
#define BITMAP_HEIGHT		11
#define MAX_COLUMN			8		// HH:MM:SS

#define MAX_BITMAP_NUM 11

class CWatch {
private :
	HBITMAP			hBitmap[MAX_BITMAP_NUM];
	HBITMAP			hBigBitmap;
	HDC				hMemDC,hSmallMemDC;
	char			szTime[128];
	HWND			hDlg;
	SYSTEMTIME		systime;
	SYSTEMTIME		prevsystime;
	void			ProcessBitmap(void);
	BOOL			is24Hour;

public :
	CWatch(HINSTANCE hInstance,HWND ihDlg,HDC hDC);
	~CWatch(void);

	BOOL	SetTime(void);
	HDC		GetMemDC(void);
	int		GetWidth(void);
	int		GetHeight(void);
	void	Set24Hour(BOOL set);
};

#endif
