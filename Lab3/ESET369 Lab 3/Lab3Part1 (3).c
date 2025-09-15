#include <msp430.h>

void delay_ms(unsigned int ms) {
    while (ms--) {
        __delay_cycles(1000);  // Assuming 1 MHz clock
    }
}

int main(void) {
    WDTCTL = WDTPW | WDTHOLD;   // Stop watchdog timer
    PM5CTL0 &= ~LOCKLPM5;       // Enable GPIO

    // Configure RGB LED pins as outputs (Active Low)
    P6DIR |= BIT0 | BIT1 | BIT2;
    P6OUT |= BIT0 | BIT1 | BIT2; // Turn off LEDs initially

    // Configure S2 button (P5.5) as input with pull-up resistor
    P5DIR &= ~BIT5;
    P5REN |= BIT5;
    P5OUT |= BIT5;

    while (1) {
        if ((P5IN & BIT5) == 0) {  // Button pressed (active low)
            P6OUT &= ~BIT0;  // Red ON
            P6OUT |= BIT1 | BIT2;
            delay_ms(500);

            P6OUT &= ~BIT1;  // Green ON
            P6OUT |= BIT0 | BIT2;
            delay_ms(500);

            P6OUT &= ~BIT2;  // Blue ON
            P6OUT |= BIT0 | BIT1;
            delay_ms(500);

            P6OUT &= ~(BIT1 | BIT2);  // Cyan ON (Green + Blue)
            P6OUT |= BIT0;
            delay_ms(500);

            P6OUT &= ~(BIT0 | BIT2);  // Magenta ON (Red + Blue)
            P6OUT |= BIT1;
            delay_ms(500);

            P6OUT &= ~(BIT0 | BIT1);  // Yellow ON (Red + Green)
            P6OUT |= BIT2;
            delay_ms(500);
        } else {
            P6OUT |= BIT0 | BIT1 | BIT2; // Turn off LED when button is released
        }
    }
}
