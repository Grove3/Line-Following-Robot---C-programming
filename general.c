#include "registers.h"
void Delay(unsigned int);
//void SetupUart(void);
//void outChar (unsigned long);
//unsigned long inChar (void);
//void SetupPortF(void);
//void SetupSysTick(void);

void Delay(unsigned int numLoops)
{
volatile unsigned int lp;
volatile unsigned int i;

for(lp=0; lp<numLoops; lp++)
	for (i=0; i<=0xFFFF; i++) ;
}

//void SetupUart(void)
//{	

//}

//void outChar (unsigned long achar)
//{

//}
	
//unsigned long inChar (void)
//{ 
//    
//}	


