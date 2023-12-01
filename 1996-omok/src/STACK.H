/* stack.h */

#include <windows.h>

#ifndef __STACK_H__
#define __STACK_H__

#define MAX_STACK_SIZE 5000
class POINTSTACK
{
	
	POINT	buf[MAX_STACK_SIZE];
	long	pos;
public:
	POINTSTACK();
	int		push(POINT);
	int		pop(POINT&);
};

#endif 
