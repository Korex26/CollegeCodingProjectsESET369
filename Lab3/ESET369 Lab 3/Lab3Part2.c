#include <msp430.h>

void delay(){
    _delay_cycles(1000);
}

int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;   // Stop watchdog timer
    PM5CTL0 &= ~LOCKLPM5;       // Unlock GPIO

    // Configure LED pins as outputs (Active Low)
    P5DIR |= 0x0B;  // P5.3 (LED1), P5.1 (LED2), P5.0 (LED3) output
    P8DIR |= 0x07;  // P8.2 (LED4), P8.1 (LED5), P8.0 (LED6) output

    P5OUT |= 0x0B;  // Turn off all LEDs (Active Low)
    P8OUT |= 0x07;

    // Configure keypad rows as output
    P7DIR |= 0x03;  // P7.0, P7.1 as output
    P7OUT |= 0x03;  // Set both rows high initially

    // Configure keypad columns as input
    P3DIR &= ~0x07;  // P3.0, P3.1, P3.2 as input
    P3REN |= 0x07;   // Enable pull-up/pull-down resistors
    P3OUT |= 0x07;   // Enable pull-up resistors

    while (1)
    {
        P7OUT |= 0x03;   // Set both rows high
        P7OUT &= ~0x01;  // Activate row 1
        delay();

        if ((P3IN & 0x01) == 0) { P8OUT &= ~0x01; } else { P8OUT |= 0x01; } // Button 1 -> LED 6
        if ((P3IN & 0x02) == 0) { P8OUT &= ~0x02; } else { P8OUT |= 0x02; } // Button 2 -> LED 5
        if ((P3IN & 0x04) == 0) { P8OUT &= ~0x04; } else { P8OUT |= 0x04; } // Button 3 -> LED 4

        P7OUT |= 0x03;   // Reset rows
        P7OUT &= ~0x02;  // Activate row 2
        delay();

        if ((P3IN & 0x01) == 0) { P5OUT &= ~0x01; } else { P5OUT |= 0x01; } // Button 4 -> LED 3
        if ((P3IN & 0x02) == 0) { P5OUT &= ~0x02; } else { P5OUT |= 0x02; } // Button 5 -> LED 2
        if ((P3IN & 0x04) == 0) { P5OUT &= ~0x08; } else { P5OUT |= 0x08; } // Button 6 -> LED 1
    }
    return 0;
}

