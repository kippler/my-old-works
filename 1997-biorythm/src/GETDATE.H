
#ifndef _GETDATE_CPP_
#define _GETDATE_CPP_

class CGetDate {
private :
	char	szDate[10];
	int		posStr;
	BOOL	CheckValid();
public :
	CGetDate(void);
	BOOL	Add(int num);
	BOOL 	Back(void);
	void	Clear(void);
	char*	GetDate(void);
	int		GetPos();
	BOOL	IsValidDate(void);
};


#endif
