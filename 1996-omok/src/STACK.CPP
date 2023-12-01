/* stack.cpp */

#include "stack.h"
#include "public.h"


POINTSTACK::POINTSTACK()
{
	pos=-1;	 // stack empty;
}

int POINTSTACK::push(POINT data)
{
	pos++;
	if(pos>MAX_STACK_SIZE) {
		MessageBox(hWndMain,"stack overflow at pointstack","",MB_OK);
		pos--;
		return FALSE;
	}
	else {
		buf[pos]=data;
		return TRUE;
	}
}
int POINTSTACK::pop(POINT &data)
{
	if(pos<0) {
		MessageBox(hWndMain,"stack underflow at pointstack","",MB_OK);
		return FALSE;
	}
	else {
		data=buf[pos];
		pos--;
		return TRUE;
	}

}



