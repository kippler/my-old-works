/*
 * REGIST.CPP	:   SAVE AND GET REGISTRY DATA 
 */

#include "cregist.h"


#define	MAX_BUF_SIZE			100
#define	REGISTRY_SUB_KEY		"SOFTWARE\\WATCH"
#define REGISTRY_NAME_X			"POINTX"
#define REGISTRY_NAME_Y			"POINTY"
#define REGISTRY_NAME_24HOUR	"IS24HOUR"
#define REGISTRY_NAME_TOPMOST	"TOPMOST"

CRegistry::CRegistry(void)
{
	pntWnd.x = pntWnd.y = 0;
	is24Hour = TRUE;
	isTopMost = FALSE;

	LONG	err;
	HKEY	hKey;
	DWORD	type;
	DWORD	size=MAX_BUF_SIZE;
	unsigned char szBuf[MAX_BUF_SIZE];
	err = RegOpenKey(HKEY_LOCAL_MACHINE,REGISTRY_SUB_KEY,&hKey);
	if(ERROR_SUCCESS==err) {
		size=MAX_BUF_SIZE;
		err = RegQueryValueEx(hKey,REGISTRY_NAME_X,0,&type,szBuf,&size);
		if(err==ERROR_SUCCESS) 	{
			pntWnd.x = atoi((char*)szBuf);
		}
		size=MAX_BUF_SIZE;
		err = RegQueryValueEx(hKey,REGISTRY_NAME_Y,0,&type,szBuf,&size);
		if(err==ERROR_SUCCESS) {
			pntWnd.y = atoi((char*)szBuf);
		}
		size=MAX_BUF_SIZE;
		err = RegQueryValueEx(hKey,REGISTRY_NAME_24HOUR,0,&type,szBuf,&size);
		if(err==ERROR_SUCCESS) {
			is24Hour= (BOOL)atoi((char*)szBuf);
		}
		size=MAX_BUF_SIZE;
		err = RegQueryValueEx(hKey,REGISTRY_NAME_TOPMOST,0,&type,szBuf,&size);
		if(err==ERROR_SUCCESS) {
			isTopMost= (BOOL)atoi((char*)szBuf);
		}
		RegCloseKey(hKey);
	}
}
 
void CRegistry::GetPnt(POINT &pnt)
{
	pnt = pntWnd;
}
void CRegistry::SetPnt(POINT pnt)
{
	pntWnd = pnt;
}
void CRegistry::Set24Hour(BOOL bParam)
{
	is24Hour = bParam;
}
void CRegistry::SetTopMost(BOOL bParam)
{
	isTopMost = bParam;
}
BOOL CRegistry::Get24Hour(void)
{
	return is24Hour;
}
BOOL CRegistry::GetTopMost(void)
{
	return isTopMost;
}


CRegistry::~CRegistry(void)
{
	LONG	err;
	HKEY	hKey;
	char szBuf[MAX_BUF_SIZE];


	err = RegOpenKey(HKEY_LOCAL_MACHINE,REGISTRY_SUB_KEY,&hKey);
	if(ERROR_SUCCESS!=err) {// 키가 존재 하지 않을 경우 
		err = RegCreateKey(HKEY_LOCAL_MACHINE,REGISTRY_SUB_KEY,&hKey);
	}
	if(ERROR_SUCCESS==err) {
		wsprintf(szBuf,"%d",pntWnd.x);
		RegSetValueEx(hKey,REGISTRY_NAME_X,0,REG_SZ,(const unsigned char *)szBuf,strlen(szBuf));
		wsprintf(szBuf,"%d",pntWnd.y);
		RegSetValueEx(hKey,REGISTRY_NAME_Y,0,REG_SZ,(const unsigned char *)szBuf,strlen(szBuf));
		
		wsprintf(szBuf,"%d",is24Hour);
		RegSetValueEx(hKey,REGISTRY_NAME_24HOUR,0,REG_SZ,(const unsigned char *)szBuf,strlen(szBuf));
		wsprintf(szBuf,"%d",isTopMost);
		RegSetValueEx(hKey,REGISTRY_NAME_TOPMOST,0,REG_SZ,(const unsigned char *)szBuf,strlen(szBuf));
		RegCloseKey(hKey);
	}
}



