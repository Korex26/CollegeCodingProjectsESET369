#include <msp430.h> 


//Name : Blake Jackson, Kyle Rex
// Section : 501 //
int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	PM5CTL0 &=~LOCKLPM5;
	 P3DIR |= BIT0;
	 P3OUT |= BIT0;
	while(1){
	   P3OUT ^= BIT0;
	   __delay_cycles(500000);

	}


	return 0;
}

// ACTIVE LOW PART B PORT 3.0 SHOULD BE ODD EVERYTHING ELSE SHOULD BE EVEN
