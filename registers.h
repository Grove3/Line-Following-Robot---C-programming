
#define SYSCTL_RCGCGPIO		(*((volatile unsigned long *)0x400FE608))
#define SYSCTL_PRGPIO			(*((volatile unsigned long *)0x400FEA08))
#define SYSCTL_RCGCUART   (*((volatile unsigned long *)0x400FE618))
#define SYSCTL_PRUART			(*((volatile unsigned long *)0x400FEA18))
#define SYSCTL_RCGCTIMER  (*((volatile unsigned long *)0x400FE604))
#define SYSCTL_PRTIMER    (*((volatile unsigned long *)0x400FEA04))
#define SYSCTL_RCGCADC		(*((volatile unsigned long *)0x400FE638))
#define SYSCTL_PRADC			(*((volatile unsigned long *)0x400FEA38))


//-------------------------------------------------------------------------------------------------	

#define NVIC_ST_CTL       (*((volatile unsigned long *)0xE000E010))
#define NVIC_ST_RELOAD    (*((volatile unsigned long *)0xE000E014))
#define NVIC_ST_CURRENT   (*((volatile unsigned long *)0xE000E018))
#define NVIC_SYS_PRI3     (*((volatile unsigned long *)0xE000ED20))

//-------------------------------------------------------------------------------------------------	
	
#define GPIO_A_BASE				(*((volatile unsigned long *)0x40004000))
#define GPIO_B_BASE				(*((volatile unsigned long *)0x40005000))
#define GPIO_C_BASE				(*((volatile unsigned long *)0x40006000))
#define GPIO_D_BASE				(*((volatile unsigned long *)0x40007000))
#define GPIO_E_BASE				(*((volatile unsigned long *)0x40024000))
#define GPIO_F_BASE				(*((volatile unsigned long *)0x40025000))

//-------------------------------------------------------------------------------------------------	

#define GPIO_A_DIR				(*((volatile unsigned long *)0x40004400))
#define GPIO_A_IS					(*((volatile unsigned long *)0x40004404))
#define GPIO_A_IBE				(*((volatile unsigned long *)0x40004408))
#define GPIO_A_IEV				(*((volatile unsigned long *)0x4000440C))
#define GPIO_A_IM					(*((volatile unsigned long *)0x40004410))
#define GPIO_A_RIS				(*((volatile unsigned long *)0x40004414))
#define GPIO_A_MIS				(*((volatile unsigned long *)0x40004418))
#define GPIO_A_ICR				(*((volatile unsigned long *)0x4000441C))
#define GPIO_A_AFSEL			(*((volatile unsigned long *)0x40004420))
#define GPIO_A_DR8R				(*((volatile unsigned long *)0x40004508))
#define GPIO_A_PUR				(*((volatile unsigned long *)0x40004510))
#define GPIO_A_PDR				(*((volatile unsigned long *)0x40004514))
#define GPIO_A_DEN				(*((volatile unsigned long *)0x4000451C))
#define GPIO_A_PCTL				(*((volatile unsigned long *)0x4000452C))
#define GPIO_A_AMSEL      (*((volatile unsigned long *)0x40004528))
#define GPIO_A_CR					(*((volatile unsigned long *)0x40004524))
#define GPIO_A_LOCK       (*((volatile unsigned long *)0x40004520))
#define GPIO_A_NVICEN     (*((volatile unsigned long *)0xE000E100))
#define GPIO_A_NVICPR     (*((volatile unsigned long *)0xE000E404))

//-------------------------------------------------------------------------------------------------	

#define GPIO_B_DIR				(*((volatile unsigned long *)0x40005400))
#define GPIO_B_IS					(*((volatile unsigned long *)0x40005404))
#define GPIO_B_IBE				(*((volatile unsigned long *)0x40005408))
#define GPIO_B_IEV				(*((volatile unsigned long *)0x4000540C))
#define GPIO_B_IM					(*((volatile unsigned long *)0x40005410))
#define GPIO_B_RIS				(*((volatile unsigned long *)0x40005414))
#define GPIO_B_MIS				(*((volatile unsigned long *)0x40005418))
#define GPIO_B_ICR				(*((volatile unsigned long *)0x4000541C))
#define GPIO_B_AFSEL			(*((volatile unsigned long *)0x40005420))
#define GPIO_B_DR8R				(*((volatile unsigned long *)0x40005508))
#define GPIO_B_PUR				(*((volatile unsigned long *)0x40005510))
#define GPIO_B_PDR				(*((volatile unsigned long *)0x40005514))
#define GPIO_B_DEN				(*((volatile unsigned long *)0x4000551C))
#define GPIO_B_PCTL				(*((volatile unsigned long *)0x4000552C))
#define GPIO_B_AMSEL      (*((volatile unsigned long *)0x40005528))
#define GPIO_B_CR					(*((volatile unsigned long *)0x40005524))
#define GPIO_B_LOCK       (*((volatile unsigned long *)0x40005520))
#define GPIO_B_NVICEN     (*((volatile unsigned long *)0xE000E100))
#define GPIO_B_NVICPR     (*((volatile unsigned long *)0xE000E40C))

//-------------------------------------------------------------------------------------------------	

#define GPIO_C_DIR				(*((volatile unsigned long *)0x40006400))
#define GPIO_C_IS					(*((volatile unsigned long *)0x40006404))
#define GPIO_C_IBE				(*((volatile unsigned long *)0x40006408))
#define GPIO_C_IEV				(*((volatile unsigned long *)0x4000640C))
#define GPIO_C_IM					(*((volatile unsigned long *)0x40006410))
#define GPIO_C_RIS				(*((volatile unsigned long *)0x40006414))
#define GPIO_C_MIS				(*((volatile unsigned long *)0x40006418))
#define GPIO_C_ICR				(*((volatile unsigned long *)0x4000641C))
#define GPIO_C_AFSEL			(*((volatile unsigned long *)0x40006420))
#define GPIO_C_DR8R				(*((volatile unsigned long *)0x40006508))
#define GPIO_C_PUR				(*((volatile unsigned long *)0x40006510))
#define GPIO_C_PDR				(*((volatile unsigned long *)0x40006514))
#define GPIO_C_DEN				(*((volatile unsigned long *)0x4000651C))
#define GPIO_C_PCTL				(*((volatile unsigned long *)0x4000652C))
#define GPIO_C_AMSEL      (*((volatile unsigned long *)0x40006528))
#define GPIO_C_CR					(*((volatile unsigned long *)0x40006524))
#define GPIO_C_LOCK       (*((volatile unsigned long *)0x40006520))
#define GPIO_C_NVICEN     (*((volatile unsigned long *)0xE000E104))
#define GPIO_C_NVICPR     (*((volatile unsigned long *)0xE000E438))

//-------------------------------------------------------------------------------------------------	

#define GPIO_D_DIR				(*((volatile unsigned long *)0x40007400))
#define GPIO_D_IS					(*((volatile unsigned long *)0x40007404))
#define GPIO_D_IBE				(*((volatile unsigned long *)0x40007408))
#define GPIO_D_IEV				(*((volatile unsigned long *)0x4000740C))
#define GPIO_D_IM					(*((volatile unsigned long *)0x40007410))
#define GPIO_D_RIS				(*((volatile unsigned long *)0x40007414))
#define GPIO_D_MIS				(*((volatile unsigned long *)0x40007418))
#define GPIO_D_ICR				(*((volatile unsigned long *)0x4000741C))
#define GPIO_D_AFSEL			(*((volatile unsigned long *)0x40007420))
#define GPIO_D_DR8R				(*((volatile unsigned long *)0x40007508))
#define GPIO_D_PUR				(*((volatile unsigned long *)0x40007510))
#define GPIO_D_PDR				(*((volatile unsigned long *)0x40007514))
#define GPIO_D_DEN				(*((volatile unsigned long *)0x4000751C))
#define GPIO_D_PCTL				(*((volatile unsigned long *)0x4000752C))
#define GPIO_D_AMSEL      (*((volatile unsigned long *)0x40007528))
#define GPIO_D_CR					(*((volatile unsigned long *)0x40007524))
#define GPIO_D_LOCK       (*((volatile unsigned long *)0x40007520))

//-------------------------------------------------------------------------------------------------

#define GPIO_F_DIR				(*((volatile unsigned long *)0x40025400))
#define GPIO_F_IS					(*((volatile unsigned long *)0x40025404))
#define GPIO_F_IBE				(*((volatile unsigned long *)0x40025408))
#define GPIO_F_IEV				(*((volatile unsigned long *)0x4002540C))
#define GPIO_F_IM					(*((volatile unsigned long *)0x40025410))
#define GPIO_F_RIS				(*((volatile unsigned long *)0x40025414))
#define GPIO_F_MIS				(*((volatile unsigned long *)0x40025418))
#define GPIO_F_ICR				(*((volatile unsigned long *)0x4002541C))
#define GPIO_F_AFSEL			(*((volatile unsigned long *)0x40025420))
#define GPIO_F_DR8R				(*((volatile unsigned long *)0x40025508))
#define GPIO_F_PUR				(*((volatile unsigned long *)0x40025510))
#define GPIO_F_PDR				(*((volatile unsigned long *)0x40025514))
#define GPIO_F_DEN				(*((volatile unsigned long *)0x4002551C))
#define GPIO_F_PCTL				(*((volatile unsigned long *)0x4002552C))
#define GPIO_F_AMSEL      (*((volatile unsigned long *)0x40025528))
#define GPIO_F_CR					(*((volatile unsigned long *)0x40025524))
#define GPIO_F_LOCK       (*((volatile unsigned long *)0x40025520))
#define GPIO_F_NVICEN     (*((volatile unsigned long *)0xE000E100))
#define GPIO_F_NVICPR     (*((volatile unsigned long *)0xE000E41C))

//-------------------------------------------------------------------------------------------------	

#define GPIO_A_DATA				(*((volatile unsigned long *)0x400043FC))
#define GPIO_B_DATA 			(*((volatile unsigned long *)0x400053FC))
#define GPIO_C_DATA				(*((volatile unsigned long *)0x400063FC))
#define GPIO_D_DATA				(*((volatile unsigned long *)0x400073FC))
#define GPIO_E_DATA 			(*((volatile unsigned long *)0x400243FC))
#define GPIO_F_DATA				(*((volatile unsigned long *)0x400253FC))

//-------------------------------------------------------------------------------------------------	

#define UART0_DR_R     	 	(*((volatile unsigned long *)0x4000C000))
#define UART0_FR_R       	(*((volatile unsigned long *)0x4000C018))
#define UART0_IBRD       	(*((volatile unsigned long *)0x4000C024))
#define UART0_FBRD       	(*((volatile unsigned long *)0x4000C028))
#define UART0_LCRH       	(*((volatile unsigned long *)0x4000C02C))
#define UART0_CTL        	(*((volatile unsigned long *)0x4000C030))
#define UART0_IM        	(*((volatile unsigned long *)0x4000C038))
#define UART0_ICR        	(*((volatile unsigned long *)0x4000C044))

//-------------------------------------------------------------------------------------------------	

#define UART3_DR_R       	(*((volatile unsigned long *)0x4000F000))
#define UART3_FR_R       	(*((volatile unsigned long *)0x4000F018))
#define UART3_IBRD       	(*((volatile unsigned long *)0x4000F024))
#define UART3_FBRD       	(*((volatile unsigned long *)0x4000F028))
#define UART3_LCRH       	(*((volatile unsigned long *)0x4000F02C))
#define UART3_CTL        	(*((volatile unsigned long *)0x4000F030))
#define UART3_IM        	(*((volatile unsigned long *)0x4000F038))
#define UART3_ICR        	(*((volatile unsigned long *)0x4000F044))

//-------------------------------------------------------------------------------------------------	

#define UART4_DR_R       	(*((volatile unsigned long *)0x40010000))
#define UART4_FR_R       	(*((volatile unsigned long *)0x40010018))
#define UART4_IBRD       	(*((volatile unsigned long *)0x40010024))
#define UART4_FBRD       	(*((volatile unsigned long *)0x40010028))
#define UART4_LCRH       	(*((volatile unsigned long *)0x4001002C))
#define UART4_CTL        	(*((volatile unsigned long *)0x40010030))
#define UART4_IM        	(*((volatile unsigned long *)0x40010038))
#define UART4_ICR        	(*((volatile unsigned long *)0x40010044))

//-------------------------------------------------------------------------------------------------	
	
#define TIMER0_BASE     	(*((volatile unsigned long *)0x40030000))
#define TIMER1_BASE     	(*((volatile unsigned long *)0x40031000))

//-------------------------------------------------------------------------------------------------	

#define TIMER2_CTL       	(*((volatile unsigned long *)0x4003200C))
#define TIMER2_CFG				(*((volatile unsigned long *)0x40032000))
#define TIMER2_TAMR				(*((volatile unsigned long *)0x40032004))
#define TIMER2_TBMR				(*((volatile unsigned long *)0x40032008))
#define TIMER2_TAILR			(*((volatile unsigned long *)0x40032028))
#define TIMER2_TBILR			(*((volatile unsigned long *)0x4003202C))
#define TIMER2_TAPR				(*((volatile unsigned long *)0x40032038))
#define TIMER2_TBPR				(*((volatile unsigned long *)0x4003203C))
#define TIMER2_IMR				(*((volatile unsigned long *)0x40032018))
#define TIMER2_ICR				(*((volatile unsigned long *)0x40032024))
#define TIMER2_TAR				(*((volatile unsigned long *)0x40032048))
#define TIMER2_TBR				(*((volatile unsigned long *)0x4003204C))
#define TIMER2_RIS       	(*((volatile unsigned long *)0x4003201C))
#define TIMER2_TAMATCH    (*((volatile unsigned long *)0x40032030))
#define TIMER2_TBMATCH    (*((volatile unsigned long *)0x40032034))
#define TIMER2_TAPMR      (*((volatile unsigned long *)0x40032040))
#define TIMER2_TBPMR      (*((volatile unsigned long *)0x40032044))

//-------------------------------------------------------------------------------------------------

#define TIMER3_CTL       	(*((volatile unsigned long *)0x4003300C))
#define TIMER3_CFG				(*((volatile unsigned long *)0x40033000))
#define TIMER3_TAMR				(*((volatile unsigned long *)0x40033004))
#define TIMER3_TBMR				(*((volatile unsigned long *)0x40033008))
#define TIMER3_TAILR			(*((volatile unsigned long *)0x40033028))
#define TIMER3_TBILR			(*((volatile unsigned long *)0x4003302C))
#define TIMER3_TAPR				(*((volatile unsigned long *)0x40033038))
#define TIMER3_TBPR				(*((volatile unsigned long *)0x4003303C))
#define TIMER3_IMR				(*((volatile unsigned long *)0x40033018))
#define TIMER3_ICR				(*((volatile unsigned long *)0x40033024))
#define TIMER3_TAR				(*((volatile unsigned long *)0x40033048))
#define TIMER3_TBR				(*((volatile unsigned long *)0x4003304C))
#define TIMER3_RIS       	(*((volatile unsigned long *)0x4003301C))

//-------------------------------------------------------------------------------------------------
    
#define TIMER4_CTL       	(*((volatile unsigned long *)0x4003400C))
#define TIMER4_CFG				(*((volatile unsigned long *)0x40034000))
#define TIMER4_TAMR				(*((volatile unsigned long *)0x40034004))
#define TIMER4_TBMR				(*((volatile unsigned long *)0x40034008))
#define TIMER4_TAILR			(*((volatile unsigned long *)0x40034028))
#define TIMER4_TBILR			(*((volatile unsigned long *)0x4003402C))
#define TIMER4_TAPR				(*((volatile unsigned long *)0x40034038))
#define TIMER4_TBPR				(*((volatile unsigned long *)0x4003403C))
#define TIMER4_IMR				(*((volatile unsigned long *)0x40034018))
#define TIMER4_ICR				(*((volatile unsigned long *)0x40034024))
#define TIMER4_TAR				(*((volatile unsigned long *)0x40034048))
#define TIMER4_TBR				(*((volatile unsigned long *)0x4003404C))
#define TIMER4_RIS       	(*((volatile unsigned long *)0x4003401C))

//-------------------------------------------------------------------------------------------------	
	
#define ADC0_ACTSS    		(*((volatile unsigned long *)0x40038000))
#define ADC0_SSPRI    		(*((volatile unsigned long *)0x40038020))
#define ADC0_EMUX     		(*((volatile unsigned long *)0x40038014))
#define ADC0_SSMUX0   		(*((volatile unsigned long *)0x40038040))
#define ADC0_SSMUX1   		(*((volatile unsigned long *)0x40038060))
#define ADC0_SSCTL0   		(*((volatile unsigned long *)0x40038044))
#define ADC0_SSCTL1   		(*((volatile unsigned long *)0x40038064))
#define ADC0_IM       		(*((volatile unsigned long *)0x40038008))
#define ADC0_ISC      		(*((volatile unsigned long *)0x4003800C))
#define ADC0_SSFIFO0  		(*((volatile unsigned long *)0x40038048))

//-------------------------------------------------------------------------------------------------

#define ADC1_ACTSS    		(*((volatile unsigned long *)0x40039000))
#define ADC1_SSPRI    		(*((volatile unsigned long *)0x40039020))
#define ADC1_EMUX     		(*((volatile unsigned long *)0x40039014))
#define ADC1_SSMUX0   		(*((volatile unsigned long *)0x40039040))
#define ADC1_SSMUX1   		(*((volatile unsigned long *)0x40039060))
#define ADC1_SSCTL0   		(*((volatile unsigned long *)0x40039044))
#define ADC1_SSCTL1   		(*((volatile unsigned long *)0x40039064))
#define ADC1_IM       		(*((volatile unsigned long *)0x40039008))
#define ADC1_ISC      		(*((volatile unsigned long *)0x4003900C))
#define ADC1_SSFIFO0  		(*((volatile unsigned long *)0x40039048))

//-------------------------------------------------------------------------------------------------	

#define PPL_RCC    				(*((volatile unsigned long *)0x400FE060))
#define PPL_RCC2    			(*((volatile unsigned long *)0x400FE070))
#define PPL_RSI    				(*((volatile unsigned long *)0x400FE050))
	


