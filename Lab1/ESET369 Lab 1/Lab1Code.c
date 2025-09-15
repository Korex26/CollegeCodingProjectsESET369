/* Kyle Rex and Blake Jackson */
/* Section 501 */

#include <msp430.h>

/* Part A */

/*
int main(void)
{
    WDTCTL = WDTPW | WDTHOLD; // stop watchdog timer
    PM5CTL0 &= ~LOCKLPM5;
    P3DIR |= 0x01;
    P3OUT |= 0x01;
    while(1) 
    {
    P3OUT ^= 0x01;
    __delay_cycles(250000);
    }
}
*/

/* Part B */

int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;
    PM5CTL0 &= ~LOCKLPM5;
    P3DIR |= 0xF;
    P8DIR |= 0x0F;
    P6DIR &= ~0x1;
    P6REN |= 0x1;
    P6OUT |= 0x1;
    P3OUT |= 0xFF;
    P8OUT |= 0xFF;

    while(1)
    {
        if ((P6IN & 0x1) == 0)
        {
            P3OUT = 0xFE;
            P8OUT = 0xFF;
            __delay_cycles(150000);
            P3OUT = 0xFD;
            P8OUT = 0xFF;
            __delay_cycles(150000);
            P3OUT = 0xFB;
            P8OUT = 0xFF;
            __delay_cycles(150000);
            P3OUT = 0xF7;
            P8OUT = 0xFF;
            __delay_cycles(150000);
            P3OUT = 0xFF;
            P8OUT = 0xFE;
            __delay_cycles(150000);
            P3OUT = 0xFF;
            P8OUT = 0xFD;
            __delay_cycles(150000);
            P3OUT = 0xFF;
            P8OUT = 0xFB;
            __delay_cycles(150000);
            P3OUT = 0xFF;
            P8OUT = 0xF7;
            __delay_cycles(150000);
            P3OUT = 0xFF;
            P8OUT = 0xF7;
            __delay_cycles(150000);
            P3OUT = 0xFF;
            P8OUT = 0xFB;
            __delay_cycles(150000);
            P3OUT = 0xFF;
            P8OUT = 0xFD;
            __delay_cycles(150000);
            P3OUT = 0xFF;
            P8OUT = 0xFE;
            __delay_cycles(150000);
            P3OUT = 0xF7;
            P8OUT = 0xFF;
            __delay_cycles(150000);
            P3OUT = 0xFB;
            P8OUT = 0xFF;
            __delay_cycles(150000);
            P3OUT = 0xFD;
            P8OUT = 0xFF;
            __delay_cycles(150000);
            P3OUT = 0xFE;
            P8OUT = 0xFF;
            __delay_cycles(150000);
            P3OUT = 0xFF;
        }
    }
}