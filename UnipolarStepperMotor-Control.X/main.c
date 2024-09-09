#include "mcc_generated_files/system/system.h"
#include "mcc_generated_files/system/pins.h"
#include "mcc_generated_files/system/interrupt.h"
#include "mcc_generated_files/timer/tmr0.h"
#include <xc.h>

#define clockwise 0
#define anticlockwise 1

// Delay constants for different speeds
#define SPEED_SLOW_DELAY 7031  // 7.031 seconds per step (1 rev in 60 minutes)
#define SPEED_FAST_DELAY 10    // 10 milliseconds per step (100 steps per second)

// Global variables
volatile unsigned long timerCounter = 0;  // Counter to track timer overflows
volatile int ButtonPress = 0;
unsigned long currentSpeed = SPEED_SLOW_DELAY;  // Start with slow speed
unsigned long stepTime = 0;  // Time between steps

// Function Prototypes
void fullStep(int stepNumber, int direction);
void StepperOff(void);
void motorStep(void);

// Timer0 overflow callback function
void Timer0_OverflowCallback(void) {
    timerCounter++;  // Increment timer counter on each overflow (1ms interval)
}

// Custom interrupt handler for switch
void MySwitchInterruptHandler(void) {
    // Add your custom interrupt logic here
    ButtonPress=1;
}

// Main application
int main(void) {
    SYSTEM_Initialize();

    
    // Register the custom switch interrupt handler
    SW_SetInterruptHandler(MySwitchInterruptHandler);
    
    // Enable Global and Peripheral Interrupts
    INTERRUPT_GlobalInterruptEnable();
    INTERRUPT_PeripheralInterruptEnable();
    
    // Initialize Timer0 and register overflow callback
    TMR0_Initialize();
    TMR0_OverflowCallbackRegister(Timer0_OverflowCallback);
    TMR0_Start();  // Start Timer0

    int prevButtonValue = 0;
    int motorRunning = 1;
    int stepNumber = 0;

    while (1) {
        // Full-step motor control logic
      if (motorRunning && (timerCounter - stepTime >= currentSpeed)) {
            fullStep(stepNumber, clockwise);  // Rotate motor clockwise
            stepNumber = (stepNumber + 1) % 4;  // Move to the next step in the sequence
            __delay_ms(500);//delay 1 millisecond
            StepperOff();  // Turn off the stepper after each step to save energy
            stepTime = timerCounter;  // Reset the step time for next step
      }

        // Check if button is pressed to toggle motor state and speed
        if (ButtonPress) {  // If button is pressed
                    currentSpeed = (currentSpeed == SPEED_SLOW_DELAY) ? SPEED_FAST_DELAY : SPEED_SLOW_DELAY;
                    ButtonPress=0;
        }  
    } 
}

// Function to turn off the stepper motor
void StepperOff(void) {
    PhA_SetLow();
    PhB_SetLow();
    PhC_SetLow();
    PhD_SetLow();
}

// Full step control for unipolar stepper motor
void fullStep(int stepNumber, int direction) {
    if (direction == clockwise) {
        switch (stepNumber) {
            case 0:
                PhA_SetHigh();  // Coil A+
                PhB_SetLow();   // Coil A-
                PhC_SetHigh();  // Coil B+
                PhD_SetLow();   // Coil B-
                break;
            case 1:
                PhA_SetLow();   // Coil A+
                PhB_SetHigh();  // Coil A-
                PhC_SetHigh();  // Coil B+
                PhD_SetLow();   // Coil B-
                break;
            case 2:
                PhA_SetLow();   // Coil A+
                PhB_SetHigh();  // Coil A-
                PhC_SetLow();   // Coil B+
                PhD_SetHigh();  // Coil B-
                break;
            case 3:
                PhA_SetHigh();  // Coil A+
                PhB_SetLow();   // Coil A-
                PhC_SetLow();   // Coil B+
                PhD_SetHigh();  // Coil B-
                break;
        }
    } else if (direction == anticlockwise) {
        switch (stepNumber) {
            case 0:
                PhA_SetHigh();  // Coil A+
                PhB_SetLow();   // Coil A-
                PhC_SetLow();   // Coil B+
                PhD_SetHigh();  // Coil B-
                break;
            case 1:
                PhA_SetLow();   // Coil A+
                PhB_SetHigh();  // Coil A-
                PhC_SetLow();   // Coil B+
                PhD_SetHigh();  // Coil B-
                break;
            case 2:
                PhA_SetLow();   // Coil A+
                PhB_SetHigh();  // Coil A-
                PhC_SetHigh();  // Coil B+
                PhD_SetLow();   // Coil B-
                break;
            case 3:
                PhA_SetHigh();  // Coil A+
                PhB_SetLow();   // Coil A-
                PhC_SetHigh();  // Coil B+
                PhD_SetLow();   // Coil B-
                break;
        }
    }
}


// Half-step control for unipolar stepper motor
void halfStep(int stepNumber, int direction) {
    if (direction == clockwise) {
        switch (stepNumber) {
            case 0:
                PhA_SetHigh();  // Coil A+
                PhB_SetLow();   // Coil A-
                PhC_SetHigh();  // Coil B+
                PhD_SetLow();   // Coil B-
                break;
            case 1:
                PhA_SetHigh();  // Coil A+
                PhB_SetLow();   // Coil A-
                PhC_SetLow();   // Coil B+
                PhD_SetLow();   // All other coils OFF
                break;
            case 2:
                PhA_SetHigh();  // Coil A+
                PhB_SetLow();   // Coil A-
                PhC_SetLow();   // Coil B+
                PhD_SetHigh();  // Coil B-
                break;
            case 3:
                PhA_SetLow();   // All other coils OFF
                PhB_SetLow();   // Coil A-
                PhC_SetLow();   // Coil B+
                PhD_SetHigh();  // Coil B-
                break;
            case 4:
                PhA_SetLow();   // Coil A+
                PhB_SetHigh();  // Coil A-
                PhC_SetLow();   // Coil B+
                PhD_SetHigh();  // Coil B-
                break;
            case 5:
                PhA_SetLow();   // Coil A+
                PhB_SetHigh();  // Coil A-
                PhC_SetLow();   // All other coils OFF
                PhD_SetLow();   // All other coils OFF
                break;
            case 6:
                PhA_SetLow();   // Coil A+
                PhB_SetHigh();  // Coil A-
                PhC_SetHigh();  // Coil B+
                PhD_SetLow();   // Coil B-
                break;
            case 7:
                PhA_SetLow();   // All other coils OFF
                PhB_SetLow();   // Coil A-
                PhC_SetHigh();  // Coil B+
                PhD_SetLow();   // Coil B-
                break;
        }
    } else if (direction == anticlockwise) {
        switch (stepNumber) {
            case 0:
                PhA_SetLow();
                PhB_SetLow();
                PhC_SetHigh();
                PhD_SetLow();
                break;
            case 1:
                PhA_SetLow();
                PhB_SetHigh();
                PhC_SetHigh();
                PhD_SetLow();
                break;
            case 2:
                PhA_SetLow();
                PhB_SetHigh();
                PhC_SetLow();
                PhD_SetLow();
                break;
            case 3:
                PhA_SetLow();
                PhB_SetHigh();
                PhC_SetLow();
                PhD_SetHigh();
                break;
            case 4:
                PhA_SetLow();
                PhB_SetLow();
                PhC_SetLow();
                PhD_SetHigh();
                break;
            case 5:
                PhA_SetHigh();
                PhB_SetLow();
                PhC_SetLow();
                PhD_SetHigh();
                break;
            case 6:
                PhA_SetHigh();
                PhB_SetLow();
                PhC_SetLow();
                PhD_SetLow();
                break;
            case 7:
                PhA_SetHigh();
                PhB_SetLow();
                PhC_SetHigh();
                PhD_SetLow();
                break;
        }
    }
}


// Wave drive (single-coil) control for unipolar stepper motor
void waveDrive(int stepNumber, int direction) {
    if (direction == clockwise) {
        switch (stepNumber) {
            case 0:
                PhA_SetHigh();  // Coil A+ ON
                PhB_SetLow();   // Coil A- OFF
                PhC_SetLow();   // Coil B+ OFF
                PhD_SetLow();   // Coil B- OFF
                break;
            case 1:
                PhA_SetLow();   // Coil A+ OFF
                PhB_SetHigh();  // Coil A- ON
                PhC_SetLow();   // Coil B+ OFF
                PhD_SetLow();   // Coil B- OFF
                break;
            case 2:
                PhA_SetLow();   // Coil A+ OFF
                PhB_SetLow();   // Coil A- OFF
                PhC_SetHigh();  // Coil B+ ON
                PhD_SetLow();   // Coil B- OFF
                break;
            case 3:
                PhA_SetLow();   // Coil A+ OFF
                PhB_SetLow();   // Coil A- OFF
                PhC_SetLow();   // Coil B+ OFF
                PhD_SetHigh();  // Coil B- ON
                break;
        }
    } else if (direction == anticlockwise) {
        switch (stepNumber) {
            case 0:
                PhA_SetLow();   // Coil A+ OFF
                PhB_SetLow();   // Coil A- OFF
                PhC_SetLow();   // Coil B+ OFF
                PhD_SetHigh();  // Coil B- ON
                break;
            case 1:
                PhA_SetLow();   // Coil A+ OFF
                PhB_SetLow();   // Coil A- OFF
                PhC_SetHigh();  // Coil B+ ON
                PhD_SetLow();   // Coil B- OFF
                break;
            case 2:
                PhA_SetLow();   // Coil A+ OFF
                PhB_SetHigh();  // Coil A- ON
                PhC_SetLow();   // Coil B+ OFF
                PhD_SetLow();   // Coil B- OFF
                break;
            case 3:
                PhA_SetHigh();  // Coil A+ ON
                PhB_SetLow();   // Coil A- OFF
                PhC_SetLow();   // Coil B+ OFF
                PhD_SetLow();   // Coil B- OFF
                break;
        }
    }
}

