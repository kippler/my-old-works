#include		<windows.h>
#include		<stdio.h> 
#include		<memory.h>
#include		"public.h"
#include		"iq120.h"
#define			X 14		// x size of board
#define			Y 14		// notice : this numer is start from 0 ( 0 to 18 )
#define			BI_EXIT 1   // button ID

extern void		DrawBitmap(HDC hdc, HBITMAP hBitmap, int xStart, int yStart);
char			szAppName[] = "안뇽"	;
HINSTANCE			hInst;
HWND			hWndMain;
HDC				hdc;
static	int		nLeft, nTop;
IQ120			Omok(X,Y,1,1);
#include		"resource.h"
HWND			hDlgBox;

LRESULT			CALLBACK  MainWndProc(HWND, UINT, WPARAM, LPARAM);     
BOOL			CALLBACK DlgBox(HWND,UINT,WPARAM,LPARAM);


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszArg, int nCmdShow)
{
	MSG			msg;
	WNDCLASS	wndclass;
	char		szBuf[200];
	char		szIniFullPathName[300];

	
	hInst = hInstance;      

	if (!hPrevInstance) {
		wndclass.style			= CS_HREDRAW | CS_VREDRAW;
		wndclass.lpfnWndProc	= MainWndProc;
		wndclass.cbClsExtra		= 0;
		wndclass.cbWndExtra		= 0;
		wndclass.hInstance		= hInstance;
		wndclass.hIcon			= LoadIcon(hInst, MAKEINTRESOURCE(IDI_ICON1));
		wndclass.hCursor		= LoadCursor(hInst, MAKEINTRESOURCE(IDC_CURSOR1));
		wndclass.hbrBackground	= (HBRUSH)GetStockObject (WHITE_BRUSH);
		wndclass.lpszMenuName	= NULL; 
		wndclass.lpszClassName	= szAppName;
		if (!RegisterClass(&wndclass))
			return FALSE;
	}
												            
/* INI 파일 읽기 */
	GetCurrentDirectory(199,szBuf);
	wsprintf(szIniFullPathName,"%s/%s",szBuf,INIFILENAME);
	nLeft = GetPrivateProfileInt("POSITION","LEFT",0,szIniFullPathName);
	nTop= GetPrivateProfileInt("POSITION","TOP",0,szIniFullPathName);

	hWndMain = CreateWindow(szAppName, "IQ 120 V1.3 ",
							WS_CAPTION | WS_SYSMENU ,
							//WS_OVERLAPPEDWINDOW | WS_CLIPCHILDREN,
							LEFT+nLeft,TOP+nTop,RIGHT,BOTTOM,
							NULL, NULL, hInstance, NULL);
	ShowWindow(hWndMain, nCmdShow);
	UpdateWindow(hWndMain);

/* 다이알로그 박스 */
	hDlgBox = CreateDialog(hInstance, MAKEINTRESOURCE(IDD_IQ120),hWndMain,(DLGPROC)DlgBox);


	while (GetMessage (&msg, NULL, 0, 0))
	{
		if (hDlgBox == 0 || !IsDialogMessage (hDlgBox, &msg))
		{
			TranslateMessage (&msg) ;
			DispatchMessage  (&msg) ;
		}
	}

/*  INI 파일 처리 */
	wsprintf(szBuf,"%d",nLeft);
	WritePrivateProfileString("POSITION","LEFT",szBuf,szIniFullPathName);
	wsprintf(szBuf,"%d",nTop);
	WritePrivateProfileString("POSITION","TOP",szBuf,szIniFullPathName);
	return msg.wParam;
}


LRESULT CALLBACK MainWndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT			ps;
	POINT				cPnt,scrPnt;
	POINT				point;
	static HBITMAP		hBitmap;
	static HWND			hWndButton;
	static int			cxChar, cyChar;
	int					yesno;
	static RECT			rect;

	int bGameEnd=FALSE;
	static int userColor = WHITE, comColor ; 
                             
	switch (iMessage) {    
		case WM_CREATE :
	/* 시작 */
			if(MessageBox(hWnd,"먼저 두시겠습니껴?","골러",MB_YESNO)==IDYES) userColor=BLACK;
			else Omok.Put(hdc,X/2,X/2,BLACK);
			comColor = -userColor ; 
			Omok.Resize(XSIZE, YSIZE);
	/* 배경 */
			hBitmap = LoadBitmap(hInst,MAKEINTRESOURCE(IDB_BITMAP2));
			break ; 

		case WM_COMMAND :
			switch(wParam) {
				case IDB_END :
					SendMessage(hWnd,WM_DESTROY,NULL,NULL);
					break;
				case IDB_RESTART:
					Omok.Clear();
					InvalidateRect(hWnd,NULL,TRUE);
					if (userColor==WHITE) Omok.Put(hdc,X/2,X/2,BLACK);
					break;
			}
			return TRUE;

		case WM_MOVE :
			GetWindowRect(hWnd,&rect);
			nLeft = max(rect.left,0);    
			nTop  = max(rect.top, 0); 
			break ; 

        case WM_LBUTTONDOWN :  
			SetCursor(LoadCursor(NULL,IDC_WAIT));
			hdc = GetDC(hWnd);
			scrPnt.x=LOWORD(lParam);
			scrPnt.y=HIWORD(lParam);
			cPnt.x=Omok.Getcx(scrPnt.x);
			cPnt.y=Omok.Getcy(scrPnt.y);
			if(Omok.Put(hdc,cPnt.x,cPnt.y,userColor)==TRUE ) {
				if(Omok.WhoWin(cPnt)==TRUE) bGameEnd=userColor;
				else {
					if(Omok.Think(cPnt,comColor)!=FALSE) { 
						Omok.Put(hdc,cPnt.x,cPnt.y,comColor);
						/* 컴퓨터가 둔 위치로 커서를 옮긴다. */
						point.x=Omok.Getx(cPnt.x);
						point.y=Omok.Gety(cPnt.y);
						ClientToScreen(hWnd,&point);
						SetCursorPos(point.x,point.y);
					}					
					else bGameEnd=DRAWGAME;
					if(Omok.WhoWin(cPnt)==TRUE) bGameEnd=comColor;
				}
			}                   
			if(bGameEnd) {
				if(bGameEnd==WHITE) MessageBox(hWnd,"흰돌","승리",MB_OK);
				else if(bGameEnd==BLACK) MessageBox(hWnd,"깜장돌","승리",MB_OK);
				else if(bGameEnd==DRAWGAME) MessageBox(hWnd,"얼랄라 ?","무승부",MB_OK);
				Omok.Clear();
				InvalidateRect(hWnd,NULL,TRUE);
				if (userColor==WHITE) Omok.Put(hdc,X/2,X/2,BLACK);
			}
			ReleaseDC(hWnd,hdc);
        	SetCursor(LoadCursor(NULL,IDC_ARROW));
			break ; 
		case WM_PAINT:
			hdc = BeginPaint(hWnd, &ps);   
			DrawBitmap(hdc,hBitmap,0,0);
			Omok.DrawGrid(hdc);
			Omok.DrawAllStone(hdc);
			EndPaint(hWnd, &ps);
			break;
		case WM_DESTROY:
			yesno = MessageBox(hWnd," 정말로 끝내시렵니까 ? ","IQ120",MB_YESNO);
			if(yesno==IDYES) 
				PostQuitMessage(0);
			break;
		case WM_CLOSE:
			break ; 
		default:
			return DefWindowProc(hWnd, iMessage, wParam, lParam);
	}						   
	return 0L;
}


void DrawBitmap(HDC hdc, HBITMAP hBitmap, int xStart, int yStart)
{
	BITMAP	bm;
	HDC		hdcMem;
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

	BitBlt(hdc,xStart,yStart,  ptSize.x,ptSize.y, hdcMem,ptOrg.x, ptOrg.y, SRCCOPY);
	DeleteDC(hdcMem);
}



BOOL	CALLBACK DlgBox(HWND hDlg,UINT iMsg,WPARAM wParam,LPARAM lParam)
{

	static char		szBuf[200];
	static char		szIniFullPathName[300];
	static int		nDlgLeft, nDlgTop;
	static RECT		rect;

	switch (iMsg)
	{
		case WM_INITDIALOG :
			GetWindowRect(hDlg,&rect);
		/* INI 파일 읽기 */
			GetCurrentDirectory(199,szBuf);
			wsprintf(szIniFullPathName,"%s/%s",szBuf,INIFILENAME);
			nDlgLeft = GetPrivateProfileInt("DIALOG","LEFT",0,szIniFullPathName);
			nDlgTop  = GetPrivateProfileInt("DIALOG","TOP",0,szIniFullPathName);
			MoveWindow(hDlg,nDlgLeft,nDlgTop,rect.right-rect.left,
						rect.bottom-rect.top,TRUE);
			return TRUE ;

		case WM_COMMAND :
			switch(wParam) {
				case IDB_END :
				/*  INI 파일 처리 */
					wsprintf(szBuf,"%d",nDlgLeft);
					WritePrivateProfileString("DIALOG","LEFT",szBuf,szIniFullPathName);
					wsprintf(szBuf,"%d",nDlgTop);
					WritePrivateProfileString("DIALOG","TOP",szBuf,szIniFullPathName);
				case IDB_RESTART:
					SendMessage(hWndMain,WM_COMMAND,wParam,lParam);
					return TRUE;
				case IDB_ABOUT :
					MessageBox(hDlg,"만든이:park","요거는",MB_OK);
					return TRUE;
			}
			return TRUE;

		case WM_MOVE :
			GetWindowRect(hDlg,&rect);
			nDlgLeft = max(rect.left,0);    
			nDlgTop  = max(rect.top, 0); 

			return TRUE ;
	}
	return FALSE;
}

