
#ifndef __CREGIST_H__
#define __CREGIST_H__

#include <windows.h>

class CRegistry {
private :
	POINT	pntWnd;
	BOOL	is24Hour,isTopMost;
public :
	CRegistry(void);
	~CRegistry(void);
	void	GetPnt(POINT &pnt);
	void	SetPnt(POINT pnt);
	BOOL	Get24Hour(void);
	BOOL	GetTopMost(void);
	void	Set24Hour(BOOL	bParam);
	void	SetTopMost(BOOL	bParam);
};

#endif