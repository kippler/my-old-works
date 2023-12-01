

#include "playsnd.h"
extern HINSTANCE ghInstance;

BOOL PlayResource(int	iWave)  
{ 
    BOOL bRtn; 
    LPSTR lpRes; 
    HANDLE hResInfo, hRes; 
 
    /* Find the WAVE resource. */ 
 
	switch(iWave) {
	case WAVE_CLICK :
	    hResInfo = FindResource(ghInstance, "WAVE_CLICK", "WAVE"); 
		break;
	case WAVE_EXIT :
	    hResInfo = FindResource(ghInstance, "WAVE_EXIT", "WAVE"); 
		break;
	case WAVE_WARNING :
	    hResInfo = FindResource(ghInstance, "WAVE_WARNING", "WAVE"); 
		break;
	default :
		return FALSE;
	}
    if (hResInfo == NULL) 
        return FALSE; 
 
    /* Load the WAVE resource. */ 
 
    hRes = LoadResource(ghInstance, (HRSRC)hResInfo); 
    if (hRes == NULL) 
        return FALSE; 
 
    /* Lock the WAVE resource and play it. */ 
 
    lpRes = (char*)LockResource(hRes); 
    if (lpRes != NULL) { 
        bRtn = sndPlaySound(lpRes, SND_MEMORY | SND_SYNC | 
            SND_NODEFAULT); 
        UnlockResource(hRes); 
    } 
    else 
        bRtn = 0; 
 
    /* Free the WAVE resource and return success or failure. */ 
 
    FreeResource(hRes); 
    return bRtn; 
} 
 
