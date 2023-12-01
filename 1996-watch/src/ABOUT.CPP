/*
 * ABOUT.CPP	: PROCESSING ABOUT DLGBOX - SHOW ALITA !
 */
#include "ABOUT.H"

BOOL CALLBACK AboutDlgProc(HWND hDlg,UINT iMsg, WPARAM wParam,LPARAM lParam)
{
	switch(iMsg) 
	{
	case WM_INITDIALOG :
		return TRUE;
	case WM_COMMAND :
		switch(LOWORD(wParam))
		{
		case IDOK :
			EndDialog(hDlg,0);
			return TRUE;
		}
	}
	return FALSE;
}