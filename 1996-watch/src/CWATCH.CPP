/*
 * CWATCH.CPP	: WATCH BITMAP PROCESS - GET TIME AND MAKE 'HMEMDC'
 */

#include "cwatch.H"

/****************************************************************************
* 																			*
* PUBLIC MEMBER FUNCTIONS                                                 	*
* 																			*
****************************************************************************/
CWatch::CWatch(HINSTANCE hInstance,HWND ihDlg,HDC hDC)
{
	int i;
	hDlg = ihDlg;
	try 
	{
 		for(i=0;i<MAX_BITMAP_NUM;i++) {
//			hBitmap[i]=LoadBitmap(hInstance,MAKEINTRESOURCE(IDB_BITMAP0+i));
			hBitmap[i]=LoadBitmap(hInstance,MAKEINTRESOURCE(IDB_SM_BITMAP0+i));
		}
	}

	catch(...)
	{
		MessageBox(hDlg,"ERROR","CANNOT READ BITMAP",MB_OK);
		throw ;
	}
	hMemDC	= CreateCompatibleDC(hDC);
	hSmallMemDC	= CreateCompatibleDC(hDC);
	hBigBitmap = CreateCompatibleBitmap(hDC,GetWidth(),GetHeight());
	is24Hour = TRUE;
	SelectObject(hMemDC,hBigBitmap);
	SetTime();
}

CWatch::~CWatch(void)
{
	int i;
	DeleteDC(hMemDC);
	DeleteDC(hSmallMemDC);
	for(i=0;i<MAX_BITMAP_NUM;i++)
		DeleteObject((HGDIOBJ)hBitmap[i]);
}

BOOL CWatch::SetTime(void)
{
	GetLocalTime(&systime);
	if(systime.wSecond==prevsystime.wSecond) return FALSE;
	prevsystime=systime;
	if(!is24Hour) if(systime.wHour>12) systime.wHour-=12;
	wsprintf(szTime,"%2d:%2d:%2d",systime.wHour,systime.wMinute,systime.wSecond);
	ProcessBitmap();
	return TRUE;
}

HDC	CWatch::GetMemDC(void)
{
	return hMemDC;
}
int	CWatch::GetWidth(void)
{
	return MAX_COLUMN*BITMAP_WIDTH;
}
int	CWatch::GetHeight(void)
{
	return BITMAP_HEIGHT;
}
void CWatch::Set24Hour(BOOL set)
{
	if(set==TRUE) is24Hour = TRUE;
	else is24Hour = FALSE;
}

/****************************************************************************
* 																			*
* PRIVATE MEMBER FUNCTIONS                                                 	*
* 																			*
****************************************************************************/

void CWatch::ProcessBitmap(void)
{
	int i;

	for(i=0;i<MAX_COLUMN;i++) {
		switch(szTime[i]) {
		case '0':	
			SelectObject(hSmallMemDC,hBitmap[0]);
			break;
		case '1':	
			SelectObject(hSmallMemDC,hBitmap[1]);
			break;
		case '2':	
			SelectObject(hSmallMemDC,hBitmap[2]);
			break;
		case '3':	
			SelectObject(hSmallMemDC,hBitmap[3]);
			break;
		case '4':	
			SelectObject(hSmallMemDC,hBitmap[4]);
			break;
		case '5':	
			SelectObject(hSmallMemDC,hBitmap[5]);
			break;
		case '6':	
			SelectObject(hSmallMemDC,hBitmap[6]);
			break;
		case '7':	
			SelectObject(hSmallMemDC,hBitmap[7]);
			break;
		case '8':	
			SelectObject(hSmallMemDC,hBitmap[8]);
			break;
		case '9':	
			SelectObject(hSmallMemDC,hBitmap[9]);
			break;
		case ':':
			SelectObject(hSmallMemDC,hBitmap[9+1]);
			break;
		default :
			SelectObject(hSmallMemDC,hBitmap[0]);
			break;
		}
		BitBlt(hMemDC,i*BITMAP_WIDTH,0,
			BITMAP_WIDTH,BITMAP_HEIGHT,
			hSmallMemDC,0,0,SRCCOPY);
	}
}

