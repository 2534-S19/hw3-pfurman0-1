/*
 * GPIO.c
 *
 *  Created on: 3/2/2020
 *      Author: Paul Furman
 */

// For the code you place here, you may use your code that uses register references.
// However, I encourage you to start using the Driver Library as soon as possible.

#include <ti/devices/msp432p4xx/driverlib/driverlib.h>
#include "myGPIO.h"

// TODO: Create a function to initialize the GPIO.
// Even though this assignment does not use all of the pushbuttons, you should write one function that does a complete GPIO init.
void initGPIO()
{
    // Launchpad S1
    P1DIR &= ~BIT1;
    P1REN |= BIT1;
    P1OUT |= BIT1;
    // Launchpad S2
    P1DIR &= ~BIT4;
    // Boosterpack S1
    P3DIR &= ~BIT5;
    // Boosterpack S2
    P5DIR &= ~BIT1;
    // Launchpad LED1
    P1DIR |= BIT0;
    // Launchpad LED2 Red
    P2DIR |= BIT0;
    // Launchpad LED2 Green
    P2DIR |= BIT1;
    // Launchpad LED2 Blue
    P2DIR |= BIT2;
    // Boosterpack LED Red
    P2DIR |= BIT4;
    // Boosterpack LED Green
    P2DIR |= BIT6;
    // Boosterpack LED Blue
    P5DIR |= BIT6;

    // Turn off all LEDs at the start.
    P1OUT = P1OUT & ~BIT0;
    P2OUT = P2OUT & ~BIT4;
    P2OUT = P2OUT & ~BIT6;
    P5OUT = P5OUT & ~BIT6;
    P2OUT = P2OUT & ~BIT1;
    P2OUT = P2OUT & ~BIT0;
    P2OUT = P2OUT & ~BIT2;
    P2OUT = P2OUT & ~BIT4;
}

// TODO: Create a function to return the status of Launchpad Pushbutton S1
unsigned char checkStatus_LaunchpadS1()
{
    if ((P1IN & BIT1) == 0)
    {
        return 1;
    }
    if ((P1IN & BIT1) == 1)
    {
       return 0;
    }
}

// TODO: Create a function to return the status of Launchpad Pushbutton S2
unsigned char checkStatus_LaunchpadS2()
{
    if ((P1IN & BIT4) == 0)
    {
        return 1;
    }
    if ((P1IN & BIT4) == 1)
    {
       return 0;
    }
}

// TODO: Create a function to return the status of Boosterpack Pushbutton S1
unsigned char checkStatus_BoosterpackS1()
{
    if ((P5IN & BIT1) == 0)
    {
        return 1;
    }
    if ((P5IN & BIT1) == 1)
    {
       return 0;
    }
}

// TODO: Create a function to return the status of Boosterpack Pushbutton S2
unsigned char checkStatus_BoosterpackS2()
{
    if ((P3IN & BIT5) == 0)
    {
        return 1;
    }
    if ((P3IN & BIT5) == 1)
    {
       return 0;
    }
}

// TODO: Create a function to turn on Launchpad LED1.
void turnOn_LaunchpadLED1()
{
    P1OUT = P1OUT | BIT0;
}

// TODO: Create a function to turn off Launchpad LED1.
void turnOff_LaunchpadLED1()
{
    P1OUT = P1OUT & ~BIT0;
}

// TODO: Create a function to turn on the Red Launchpad LED2.
void turnOn_LaunchpadLED2Red()
{
    P2OUT = P2OUT | BIT0;
}

// TODO: Create a function to turn off the Red Launchpad LED2.
void turnOff_LaunchpadLED2Red()
{
    P2OUT = P2OUT & ~BIT0;
}

// TODO: Create a function to turn on the Green Launchpad LED2.
void turnOn_LaunchpadLED2Green()
{
    P2OUT = P2OUT | BIT1;
}

// TODO: Create a function to turn off the Green Launchpad LED2.
void turnOff_LaunchpadLED2Green()
{
    P2OUT = P2OUT & ~BIT1;
}

// TODO: Create a function to turn on the Blue Launchpad LED2.
void turnOn_LaunchpadLED2Blue()
{
    P2OUT = P2OUT | BIT2;
}

// TODO: Create a function to turn off the Blue Launchpad LED2.
void turnOff_LaunchpadLED2Blue()
{
    P2OUT = P2OUT & ~BIT2;
}

// TODO: Create a function to turn on the Red Boosterpack LED2.
void turnOn_BoosterpackLEDRed()
{
    P2OUT = P2OUT | BIT6;
}

// TODO: Create a function to turn off the Red Boosterpack LED2.
void turnOff_BoosterpackLEDRed()
{
    P2OUT = P2OUT & ~BIT6;
}

// TODO: Create a function to turn on the Green Boosterpack LED2.
void turnOn_BoosterpackLEDGreen()
{
    P2OUT = P2OUT | BIT4;
}

// TODO: Create a function to turn off the Green Boosterpack LED2.
void turnOff_BoosterpackLEDGreen()
{
    P2OUT = P2OUT & ~BIT4;
}

// TODO: Create a function to turn on the Blue Boosterpack LED2.
void turnOn_BoosterpackLEDBlue()
{
    P5OUT = P5OUT | BIT6;
}

// TODO: Create a function to turn off the Green Boosterpack LED2.
void turnOff_BoosterpackLEDBlue()
{
    P5OUT = P5OUT & ~BIT6;
}
