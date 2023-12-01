
#include <WINDOWS.H>
#include "getdate.h"

#define MAX_DATE_NUM	6


CGetDate::CGetDate(void)
{
	Clear();
}

BOOL	CGetDate::Add(int num)
{
	if(posStr>=MAX_DATE_NUM) return FALSE;
	szDate[posStr]=num+'0';
	if(CheckValid()) {
		posStr++;
		return TRUE;
	}
	else {
		szDate[posStr]=' ';
		return FALSE;
	}
}
BOOL	CGetDate::Back(void) 
{
	if(posStr-1<0) return FALSE; 
	posStr--;
	szDate[posStr]=' ' ;
	return TRUE;
}
void	CGetDate::Clear(void) 
{
	strcpy(szDate,"       ");
	posStr = 0;
}
char*	CGetDate::GetDate(void) 
{
	return szDate;
}
int		CGetDate::GetPos(void)
{
	return posStr;
}

BOOL	CGetDate::IsValidDate(void)
{
	if(posStr==MAX_DATE_NUM) return TRUE;
	return FALSE;
}
BOOL	CGetDate::CheckValid()
{
	char		year[3],month[3],day[3];
	int			yy,mm,dd;
	int days[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

	strncpy(year,szDate,2);
	year[2]=NULL;
	strncpy(month,szDate+2,2);
	month[2]=NULL;
	strncpy(day,szDate+4,2);
	day[2]=NULL;

	yy=atoi(year);
	mm=atoi(month);
	dd=atoi(day);


	if(yy>96) return FALSE;
	if(mm>12) return FALSE;
	if(dd>31) return FALSE;

	if(month[0]>'1') return FALSE;
	if(day  [0]>'3') return FALSE;

	if(month[0]=='0' && month[1]=='0') return FALSE;
	if(day[0]  =='0' && day[1]  =='0') return FALSE;

	
	if(mm>0 &&mm<13) {
		if(mm==2 && day[0]=='3') return FALSE; 
		if(day[0]==' '||day[1]==' ') return TRUE;
		if(days[mm-1]<dd) {
			if(mm!=2) return FALSE;
			else { // dd is 2
				if (yy % 4 == 0 && (yy % 100 != 0 || yy % 400 == 0)) { 	  //if leap year..
					if (dd>29) return FALSE;
					else return TRUE;
				}
				return FALSE;
			}
		}
	}

	return TRUE;
}

