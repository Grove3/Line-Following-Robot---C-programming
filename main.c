
#include "registers.h"

// Setup Functions

void Init_PPL(void);
void Init_GPIO(void);
void Init_UART(void);
void Init_ADC(void);
void Init_SysTick(void);
void Init_SetupTimer2(void);
void Init_SetupTimer3(void);
void Delay_Ms(int a);
void ADC_ISR(void);
extern void DisableInterrupts(void);
extern void EnableInterrupts(void);
void WriteChar(int a);
void UART_ISR(void);
void UART3_ISR(void);
void WriteStack(int a);
void mode_ISR(void);

//Global Variables

	int S1_VALUE = 0;
	int S2_VALUE = 0;
	int S3_VALUE = 0;
	int S4_VALUE = 0;
	int S5_VALUE = 0;
	unsigned long achar;				//UART0 character
	unsigned long bchar;				//UART3 character
	int mode = 1;								//Mode switch
	double kp = 12;							//Part constant
	double ki = 0;							//Intigal constant
	double kd = 180;						//Derivative constant
	double tp = 30000;					//power of wheel
	double integral = 0;
	double lasterror = 0;
	double derivative = 0;
	double errorS1 = 0;
	double errorS2 = 0;
	double errorS3 = 0;
	double errorS4 = 0;
	double errorS5 = 0;
	double totalerror = 0;
	double power = 0;
	double powerA = 0;
	double powerB = 0;
	int j;

int main(void)
{
	DisableInterrupts();
	Init_PPL();
	Init_GPIO();
	Init_UART();
	Init_ADC();
	Init_SysTick();
	Init_SetupTimer2();
	Init_SetupTimer3();
	EnableInterrupts();
	
	
	WriteChar('G');
	WriteChar('O');
	
	for(j = 0; j < 20; j++)	//Start delay
		{
			GPIO_F_DATA ^= 0x2;
			Delay_Ms(100);
		}
		
	while(1)
	{
		
		if(mode == 0)
		{

		}
	
		else
		{
			GPIO_F_DATA = 0x8;
			errorS1 = S1_VALUE * 4;	//error of sensor 1
			errorS2 = S2_VALUE * 2; //error of sensor 2
			errorS3 = S3_VALUE;		//error of sensor 3
			errorS4 = S4_VALUE * 2; //error of sensor 4
			errorS5 = S5_VALUE * 4;	//error of sensor 5
			totalerror = ((((errorS1 + errorS2)  - (errorS4 + errorS5)) / errorS3)*1000); //total error
			integral = ((2/3)*integral) + totalerror; //cumlative error total
			derivative = totalerror - lasterror; //derivative error
			power = (kp * totalerror) + (ki * integral) + (kd * derivative); //total power
			powerA = (tp - power); //power to motor A	
			powerB = (tp + power); //power to motor b
			if(powerA < 15000)																																		
			{
				powerA = 15000; //No negative number to Timer 2 match
			}
			if(powerB < 15000)
			{
				powerB = 15000; //No negative number to Timer 2 match
			}
			if(powerA > 40000)
			{
				powerA = 65500; //Low motor stop threshold
			}
			if(powerB > 40000)
			{
				powerB = 65500; //Low motor stop threshold
			}
			TIMER2_TAMATCH	= powerA;
			TIMER2_TBMATCH	= powerB;
			GPIO_A_DATA		|= 0x28; //drive motor fwd
			GPIO_A_DATA		&= ~0x14;
			lasterror = totalerror;
		}
	}
	return(0);
}

void Init_PPL(void)
{
// Set Clock Speed to 50MHz
	PPL_RCC2		|= (unsigned long int)(1 << 31);
	PPL_RCC2		|= (1 << 11);
	PPL_RCC			&= ~(0x1F << 6);
	PPL_RCC			|= (0x15 << 6);
	PPL_RCC2		&= ~(0x7 << 4);
	PPL_RCC2		&= ~(1 <<13);
	PPL_RCC2		&= ~(0x7F << 22);
	PPL_RCC2		|= (0x1 << 22);
	PPL_RCC2		|= (0x3 << 23);
	PPL_RCC2		|= (1 << 30);
	while((PPL_RSI & 0x40) == 0)
		{};
	PPL_RCC2		&= ~(0x1 << 11);
}

void Init_GPIO(void)
{
//set clocks for GPIO port A, B, C, F	
	SYSCTL_RCGCGPIO |= 0x2F;
	while ((SYSCTL_PRGPIO & 0x2F) == 0)
		{};
	
//GPIO A 0-UART0 PUTTY 1-UART1 PUTTY 2-PWM OUTPUT A1 3-PWM OUTPUT A2 4-PWM OUTPUT B1 5-PWM OUTPUT B2
	GPIO_A_DIR		&= ~0x3;
	GPIO_A_DIR 		|= 0x3C;
	GPIO_A_AFSEL 	&= ~0x3C;
	GPIO_A_AFSEL 	|= 0x3;
	GPIO_A_PCTL 	&= ~0xFF;
	GPIO_A_PCTL 	|= 0x11;
	GPIO_A_DR8R		|= 0x3C;
	GPIO_A_DEN 		|= 0x3F;
	
//GPIO B 0-PWM T2A 1-PWM T2B 2-ADC T3A 4-ADC AI10 5-ADC AI11
	GPIO_B_DIR 		&= ~0x33;
	GPIO_B_DIR 		|= 0x4;
	GPIO_B_AFSEL 	|= 0x37;
	GPIO_B_AMSEL	|= 0x30;
	GPIO_B_PCTL 	&= ~0xFFF;
	GPIO_B_PCTL 	|= 0x777;
	GPIO_B_DEN 		|= 0x7;
	
//GPIO C 6-UART4 BLUETOOTH 7-UART4 BLUETOOTH
	GPIO_C_AFSEL	|= 0xc0;
	GPIO_C_PUR		|= 0x40;
	GPIO_C_PCTL		&= ~0xff000000;
	GPIO_C_PCTL		|= 0x11000000;
	GPIO_C_DEN		|= 0xc0;
	
//GPIO D 0-ADC AI7 1-ADC AI6 2-ADC AI5
	GPIO_D_DIR 		&= ~0x7;
	GPIO_D_AFSEL 	|= 0x7;
	GPIO_D_AMSEL 	|= 0x7;

//GPIO F 0-Mode Switch 1-RED LED 2-BLUE LED 3-GREEN LED
	GPIO_F_DIR 		|= 0xe;
	GPIO_F_DIR 		&= ~0x10;
	GPIO_F_AFSEL 	&= ~0x1e;
	GPIO_F_DR8R		|= 0xe;
	GPIO_F_PUR		|= 0x10;
	GPIO_F_DEN		|= 0x1e;
	GPIO_F_DATA		&= ~0xe;
	GPIO_F_IS			|= 0x10;
	GPIO_F_IBE		&= ~0x10;
	GPIO_F_IEV		&= ~0x10;
	GPIO_F_IM			|= 0x10;
	GPIO_F_NVICEN	|= (1 << 30);
	GPIO_F_NVICPR &= ~(7 << 21);
	GPIO_F_NVICPR	|= (1 << 21);
	GPIO_F_ICR		|= 0x10;

}

void Init_UART(void)
{

	SYSCTL_RCGCUART |= 0x09;
	while((SYSCTL_PRUART & 0x09) == 0)
			{};
	
//Set uart0 communication parameters and enable uart
	UART0_CTL 		&= ~0x21;
	UART0_IBRD 		= 54;		//Baud Rate 57600
	UART0_FBRD 		= 16;
	UART0_LCRH		&= ~0xA;	//No Parity, one Stop bit
	UART0_LCRH		|= 0x60;	//8 bits
	UART0_CTL			|= 0x301;

//Set uart4 communication parameters and enable uart
	UART3_CTL 		&= ~0x21;
	UART3_IBRD 		= 326;		//Baud Rate 9600
	UART3_FBRD 		= 33;
	UART3_LCRH		&= ~0xA;	//No Parity, one Stop bit
	UART3_LCRH		|= 0x60;	//8 bits
	UART3_CTL			|= 0x301;
	
//Set Interupt GPIO Port A Uart 0
	UART0_IM			|= 0x10;
	GPIO_A_NVICEN	|= (1 << 5);
	GPIO_A_NVICPR	&= ~(7 << 13);
	GPIO_A_NVICPR	|= (1 << 13);
	UART0_ICR 		|= 0x10;

//Set Interupt GPIO Port C Uart 4
	UART3_IM			|= 0x10;
	GPIO_C_NVICEN	|= (1 << 27);
	GPIO_C_NVICPR	&= ~(7 << 29);
	GPIO_C_NVICPR	|= (1 << 29);
	UART3_ICR			|= 0x10;
}

void Init_ADC(void)
{
// Set ADC0 GPIO B Analog Inputs 5, 6, 7, 10, 11 
	SYSCTL_RCGCADC |= 0x1;
	while((SYSCTL_PRADC & 0x1) == 0)
	{};
	
	ADC0_ACTSS 		&= ~0x1;
	ADC0_EMUX 		&= ~0xF;
	ADC0_EMUX 		|= 0x5;
	ADC0_SSMUX0		&= ~0xFFFFF;
	ADC0_SSMUX0		|= 0xBA765;
	ADC0_SSCTL0		|= 0x64444;
	ADC0_IM				|= 0x1;
  GPIO_B_NVICEN	|= (1 << 14);
	GPIO_B_NVICPR	&= ~(7 << 21);
	GPIO_B_NVICPR	|= (1 << 21);
	ADC0_ISC			|= 0x1;
	ADC0_ACTSS		|= 0x1;

}

void Init_SysTick(void)
{
// Set SysTick Timer
	NVIC_ST_CTL 	&= ~1;
	NVIC_ST_RELOAD	= 0xFFFFFF;
	NVIC_ST_CURRENT	= 1;
	NVIC_ST_CTL		&= ~2;
	NVIC_ST_CTL		|= 5;
	
}

void Init_SetupTimer2(void)
{
//Set Timer 2 for PWM on GPIO B Pins 0, 1
	SYSCTL_RCGCTIMER |= 0x4;
	while ((SYSCTL_PRTIMER & 0x4) == 0)
	{};
	
	TIMER2_CTL 		&= ~0x4D4D;
	TIMER2_CFG		&= ~0x7;
	TIMER2_CFG		|= 0x4;
	TIMER2_TAMR		&= ~0x45;
	TIMER2_TAMR		|= 0x20a;
	TIMER2_TBMR		&= ~0x45;
	TIMER2_TBMR		|= 0x20a;
	TIMER2_TAILR	= 0xFFFF;
	TIMER2_TAPR		= 0;
	TIMER2_TAMATCH	= 0xFFF0;
	TIMER2_TAPMR	= 0;
	TIMER2_TBILR	= 0xFFFF;
	TIMER2_TBPR		= 0;
	TIMER2_TBMATCH	= 0xFFF0;
	TIMER2_TBPMR	= 0;
	TIMER2_CTL		|= 0x101;
	
}

void Init_SetupTimer3(void)
{
//Set Timer 3 for ADC on GPIO B, D For Analog Inputs 5, 6, 7, 10 and 11
	SYSCTL_RCGCTIMER |= 0x8;
	while ((SYSCTL_PRTIMER & 0x8) == 0)
	{};
	
	TIMER3_CTL 		&= ~0x1;
	TIMER3_CFG		&= ~0x7;
	TIMER3_CFG		|= 0x4;
	TIMER3_TAMR		&= ~0x3;
	TIMER3_TAMR		|= 0x2;
	TIMER3_TAILR	= 62499;
	TIMER3_TAPR		= 3;
	TIMER3_ICR		|= 0x4;
	TIMER3_CTL		|= 0x21;

}

void ADC_ISR(void)
{
	int i = 0;
	S1_VALUE = ADC0_SSFIFO0;
	while(i++ <= 50){};
	S2_VALUE = ADC0_SSFIFO0;
	while(i++ <= 50){};
	S3_VALUE = ADC0_SSFIFO0;
	while(i++ <= 50){};
	S4_VALUE = ADC0_SSFIFO0;
	while(i++ <= 50){};
	S5_VALUE = ADC0_SSFIFO0;

	ADC0_ISC |= 0x1;

}

void Delay_Ms(int a)
{
// Delay Fuction in Milliseconds
int j;
int i;

	for(j = 0; j < a; j++)
	{
		for(i = 0; i < 8250; i++)
		{	}
	}

}

void WriteChar(int a)
{
		int i = 0;
	  while (i++ <= 50000);
		UART0_DR_R = a & 0xFF;
}

void WriteStack(int a)
{
		int count = 0;
		int temp1[20];
		int i;
	
		while(a != 0)
		{
		temp1[count] = a%10;
		a /= 10;
		count++;
		}
		
		for(i = count-1; i >= 0; i--)
		{
			WriteChar(temp1[i]+'0');
		}
}

void UART_ISR(void)
{

	achar = UART0_DR_R;
	UART0_DR_R = achar;
	TIMER2_TAMATCH	= 10000;
	TIMER2_TBMATCH	= 10000;
			switch(achar)
			{
				case 'w':
					GPIO_F_DATA		&= ~0xE;
				  GPIO_F_DATA		|= 0x8;
//					TIMER2_TAMATCH	= 0x5000;
//				  TIMER2_TBMATCH	= 0x5000;
					GPIO_A_DATA		|= 0x28;
					GPIO_A_DATA		&= ~0x14;
					break;
				
				case 's':
					GPIO_F_DATA		&= ~0xE;
				  GPIO_F_DATA		|= 0x2;
//					TIMER2_TAMATCH	= 0x5000;
//				  TIMER2_TBMATCH	= 0x5000;
					GPIO_A_DATA		|= 0x14;
					GPIO_A_DATA		&= ~0x28;
					break;
				
				case 'd':
					GPIO_F_DATA		&= ~0xE;
				  GPIO_F_DATA		|= 0x4;
//				  TIMER2_TBMATCH	= 0x500;
//					TIMER2_TAMATCH	= 0x5000;
					GPIO_A_DATA		|= 0x28;
					GPIO_A_DATA		&= ~0x14;
					break;
				
				case 'a':
					GPIO_F_DATA		&= ~0xE;
				  GPIO_F_DATA		|= 0xa;
					GPIO_A_DATA		|= 0x28;
					GPIO_A_DATA		&= ~0x14;
					break;
				
				default:
					GPIO_F_DATA		&= ~0xE;
					GPIO_A_DATA		|= 0x3C;
					break;
			}
	
			UART0_ICR |= 0x10;

}
void UART3_ISR(void)
{

	bchar = UART3_DR_R;
	UART3_DR_R = bchar;
	UART0_DR_R = bchar;
	TIMER2_TAMATCH	= 0x30000;
	TIMER2_TBMATCH	= 0x30000;		
			switch(bchar)
			{
				case 'w':
					GPIO_F_DATA		&= ~0xE;
				  GPIO_F_DATA		|= 0x8;
					
					GPIO_A_DATA		|= 0x28;
					GPIO_A_DATA		&= ~0x14;
					break;
				
				case 's':
					GPIO_F_DATA		&= ~0xE;
				  GPIO_F_DATA		|= 0x2;
					GPIO_A_DATA		|= 0x14;
					GPIO_A_DATA		&= ~0x28;
					break;
				
				case 'd':
					GPIO_F_DATA		&= ~0xE;
				  GPIO_F_DATA		|= 0x4;
					GPIO_A_DATA		|= 0x2c;
					GPIO_A_DATA		&= ~0x10;
					break;
				
				case 'a':
					GPIO_F_DATA		&= ~0xE;
				  GPIO_F_DATA		|= 0xa;
					GPIO_A_DATA		|= 0x38;
					GPIO_A_DATA		&= ~0x04;
					break;
				
				default:
					GPIO_F_DATA		&= ~0xE;
					GPIO_A_DATA		|= 0x3C;
					break;
			}

	
			UART3_ICR |= 0x10;

}
void mode_ISR(void)
{

	if(mode == 1)
	{
		mode = 0;
	}
	else
	{
		mode = 1;
	}
	
	GPIO_F_DATA &= ~0xe;
	GPIO_F_ICR		|= 0x10;

}


