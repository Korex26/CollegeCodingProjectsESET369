#include <msp430.h> 
#include <stdio.h>


// NAME : Blake Jackson, Kyle Rex
// Section : 501//
int main(void)
{

    WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	PM5CTL0 &=~LOCKLPM5;



	P3DIR |= 0xF;
	P3OUT |= 0xF;

	P8DIR |= 0xF;
	P8OUT |= 0xF;

	P6DIR &= ~BIT0;
	P6REN |= BIT0;
	P6OUT |= BIT0; // PULL UP



	while(1)
	{
	   if ((P6IN & BIT0) == 0)
            {
               P3OUT &=~ 0X01;
               __delay_cycles(150000);
              P3OUT |=0X01;
              P3OUT &=~0X02;
              __delay_cycles(150000);
              P3OUT |= 0X02;
              P3OUT &=~ 0X04;
              __delay_cycles(150000);
              P3OUT |= 0X04;
              P3OUT &=~ 0X08;
              __delay_cycles(150000);
              P3OUT |= 0X08;
              P8OUT &=~0X01;
              __delay_cycles(150000);
              P8OUT |=0X01;
              P8OUT &=~ 0X02;
              __delay_cycles(150000);
              P8OUT |= 0X02;
              P8OUT &=~ 0X04;
              __delay_cycles(150000);
              P8OUT |= 0X04;
              P8OUT &=~ 0X08;
              __delay_cycles(150000);
              P8OUT |= 0X08;
              P8OUT &=~ 0X04;
              __delay_cycles(150000);
              P8OUT |= 0X04;
              P8OUT &=~ 0X02;
              __delay_cycles(150000);
              P8OUT |= 0X02;
              P8OUT &=~ 0X01;
              __delay_cycles(150000);
              P8OUT |= 0X01;
              P3OUT &=~ 0X08;
              __delay_cycles(150000);
              P3OUT |= 0X08;
              P3OUT &=~ 0X04;
              __delay_cycles(150000);
              P3OUT |= 0X04;
              P3OUT &=~ 0X02;
              __delay_cycles(150000);
              P3OUT |= 0X02;
              P3OUT &=~ 0X01;
              __delay_cycles(150000);
              P3OUT |= 0X01;










               }
       }

	

	return 0;
}
