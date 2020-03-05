#include <ti/devices/msp432p4xx/driverlib/driverlib.h>
#include "homework3.h"
#include "myGPIO.h"
#include "myTimer.h"
typedef enum
{SX, S1, S2, S3, S4, S5, S6, S7} hw3;
int main(void)
{
    // Count variables to control the LEDs.
    unsigned int count0 = 0;
    unsigned int count1 = 0;
    // TODO: Declare the variables that main uses to interact with your state machine.
    unsigned char buttonhistory = 0x10;
    bool reset = false;

    // Stops the Watchdog timer.
    initBoard();
    // Initialize the GPIO.
    // YOU MUST WRITE THIS FUNCTION IN myGPIO.c
    initGPIO();
    // Initialize Timer0 to provide a one second count interval for updating LED2.
    // YOU MUST WRITE THIS FUNCTION IN myTimer.c
    initTimer(TIMER0, 16, TIMER0_COUNT);
    // Initialize Timer1 to provide a one millisecond count interval for updating the button history.
    // YOU MUST WRITE THIS FUNCTION IN myTimer.c
    initTimer(TIMER1, 16, TIMER1_COUNT);

    while(1)
    {
        // Update the color of LED2 using count0 as the index.
        // YOU MUST WRITE THIS FUNCTION BELOW.
        changeLaunchpadLED2(count0);
        // Update the color of the Boosterpack LED using count1 as the index.
        // YOU MUST WRITE THIS FUNCTION BELOW.
        changeBoosterpackLED(count1);

        // TODO: If Timer0 has expired, increment count0.
        // YOU MUST WRITE timer0expired IN myTimer.c
        int time0 = timer0Expired();
        if(time0 == 1)
        {
            ++count0;
        }
        // TODO: If Timer1 has expired, update the button history from the pushbutton value.
        // YOU MUST WRITE timer1expired IN myTimer.c
        int time1 = timer1Expired();
        if(time1 == 1)
        {
            unsigned char status = checkStatus_LaunchpadS1();
          buttonhistory = (buttonhistory << 1) + status;
        }

        // TODO: Call the button state machine function to check for a completed, debounced button press.
        // YOU MUST WRITE THIS FUNCTION BELOW.

        bool pressed = fsmBoosterpackButtonS1(buttonhistory);

        // TODO: If a completed, debounced button press has occurred, increment count1.
        if (pressed == 1)
        {
            ++count1;
        }


    }
}

void initBoard()
{
    WDT_A_hold(WDT_A_BASE);
}

// TODO: Map the value of a count variable to a color for LED2.
// Since count is an unsigned integer, you can mask the value in some way.
void changeLaunchpadLED2(unsigned int count)
{
    unsigned int mask = 0x07;
    count = (count & mask);
    static hw3 currentState = SX;
    switch(currentState)
    {
    case SX:
        if(count==1)
        {
            turnOn_LaunchpadLED2Red();
            currentState=S1;
        }
        break;
    case S1:
        if(count==2)
        {
            turnOff_LaunchpadLED2Red();
            turnOn_LaunchpadLED2Green();
            currentState=S2;
        }
        break;
    case S2:
        if(count==3)
        {
            turnOn_LaunchpadLED2Red();
            currentState=S3;
        }
        break;
    case S3:
        if(count==4)
        {
            turnOff_LaunchpadLED2Red();
            turnOff_LaunchpadLED2Green();
            turnOn_LaunchpadLED2Blue();
            currentState=S4;
        }
        break;
    case S4:
        if(count==5)
        {
           turnOn_LaunchpadLED2Red();
           currentState=S5;
        }
        break;
    case S5:
        if(count==6)
        {
           turnOff_LaunchpadLED2Red();
           turnOn_LaunchpadLED2Green();
           currentState=S6;
        }
        break;
    case S6:
        if(count==7)
        {
           turnOn_LaunchpadLED2Red();
           turnOn_LaunchpadLED2Green();
           currentState=S7;
        }
        break;
    case S7:
        if(count==0)
        {
            turnOff_LaunchpadLED2Red();
            turnOff_LaunchpadLED2Green();
            turnOff_LaunchpadLED2Blue();
            currentState=SX;;
        }
        break;
    }
}

// TODO: Maybe the value of a count variable to a color for the Boosterpack LED
// This is essentially a copy of the previous function, using a different LED
void changeBoosterpackLED(unsigned int count)
{
    unsigned int mask = 0x07;
    count = (count & mask);
    static hw3 currentState = SX;
    switch(currentState)
    {
        case SX:
            if(count==1)
            {
                turnOn_BoosterpackLEDRed();
                currentState=S1;
            }
            break;
        case S1:
            if(count==2)
            {
                turnOff_BoosterpackLEDRed();
                turnOn_BoosterpackLEDGreen();
                currentState=S2;
            }
            break;
        case S2:
            if(count==3)
            {
                turnOn_BoosterpackLEDRed();
                currentState=S3;
            }
            break;
        case S3:
            if(count==4)
            {
                turnOff_BoosterpackLEDRed();
                turnOff_BoosterpackLEDGreen();
                turnOn_BoosterpackLEDBlue();
                currentState=S4;
            }
            break;
        case S4:
            if(count==5)
            {
               turnOn_BoosterpackLEDRed();
               currentState=S5;
            }
            break;
        case S5:
            if(count==6)
            {
               turnOff_BoosterpackLEDRed();
               turnOn_BoosterpackLEDGreen();
               currentState=S6;
            }
            break;
        case S6:
            if(count==7)
            {
               turnOn_BoosterpackLEDRed();
               turnOn_BoosterpackLEDGreen();
               currentState=S7;
            }
            break;
        case S7:
            if(count==0)
            {
                turnOff_BoosterpackLEDRed();
                turnOff_BoosterpackLEDGreen();
                turnOff_BoosterpackLEDBlue();
                currentState=SX;
            }
            break;
    }
}

// TODO: Create a button state machine.
// The button state machine should return true or false to indicate a completed, debounced button press.
bool fsmBoosterpackButtonS1(unsigned char buttonhistory)
{
    bool pressed = false;
    if (buttonhistory == PRESSED)
    {
       return pressed = true;
    }
    if (buttonhistory == UNPRESSED)
    {
        return pressed = false;
    }
    return pressed;
}
