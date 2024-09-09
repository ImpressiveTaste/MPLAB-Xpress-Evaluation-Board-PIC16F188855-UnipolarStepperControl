/**
 * Generated Pins header File
 * 
 * @file pins.h
 * 
 * @defgroup  pinsdriver Pins Driver
 * 
 * @brief This is generated driver header for pins. 
 *        This header file provides APIs for all pins selected in the GUI.
 *
 * @version Driver Version  3.0.0
*/

/*
© [2024] Microchip Technology Inc. and its subsidiaries.

    Subject to your compliance with these terms, you may use Microchip 
    software and any derivatives exclusively with Microchip products. 
    You are responsible for complying with 3rd party license terms  
    applicable to your use of 3rd party software (including open source  
    software) that may accompany Microchip software. SOFTWARE IS ?AS IS.? 
    NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS 
    SOFTWARE, INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT,  
    MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT 
    WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY 
    KIND WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF 
    MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE 
    FORESEEABLE. TO THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP?S 
    TOTAL LIABILITY ON ALL CLAIMS RELATED TO THE SOFTWARE WILL NOT 
    EXCEED AMOUNT OF FEES, IF ANY, YOU PAID DIRECTLY TO MICROCHIP FOR 
    THIS SOFTWARE.
*/

#ifndef PINS_H
#define PINS_H

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set IO_RA5 aliases
#define SW_TRIS                 TRISAbits.TRISA5
#define SW_LAT                  LATAbits.LATA5
#define SW_PORT                 PORTAbits.RA5
#define SW_WPU                  WPUAbits.WPUA5
#define SW_OD                   ODCONAbits.ODCA5
#define SW_ANS                  ANSELAbits.ANSA5
#define SW_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define SW_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define SW_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define SW_GetValue()           PORTAbits.RA5
#define SW_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define SW_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define SW_SetPullup()          do { WPUAbits.WPUA5 = 1; } while(0)
#define SW_ResetPullup()        do { WPUAbits.WPUA5 = 0; } while(0)
#define SW_SetPushPull()        do { ODCONAbits.ODCA5 = 0; } while(0)
#define SW_SetOpenDrain()       do { ODCONAbits.ODCA5 = 1; } while(0)
#define SW_SetAnalogMode()      do { ANSELAbits.ANSA5 = 1; } while(0)
#define SW_SetDigitalMode()     do { ANSELAbits.ANSA5 = 0; } while(0)
#define RA5_SetInterruptHandler  SW_SetInterruptHandler
// get/set IO_RB2 aliases
#define PhA_TRIS                 TRISBbits.TRISB2
#define PhA_LAT                  LATBbits.LATB2
#define PhA_PORT                 PORTBbits.RB2
#define PhA_WPU                  WPUBbits.WPUB2
#define PhA_OD                   ODCONBbits.ODCB2
#define PhA_ANS                  ANSELBbits.ANSB2
#define PhA_SetHigh()            do { LATBbits.LATB2 = 1; } while(0)
#define PhA_SetLow()             do { LATBbits.LATB2 = 0; } while(0)
#define PhA_Toggle()             do { LATBbits.LATB2 = ~LATBbits.LATB2; } while(0)
#define PhA_GetValue()           PORTBbits.RB2
#define PhA_SetDigitalInput()    do { TRISBbits.TRISB2 = 1; } while(0)
#define PhA_SetDigitalOutput()   do { TRISBbits.TRISB2 = 0; } while(0)
#define PhA_SetPullup()          do { WPUBbits.WPUB2 = 1; } while(0)
#define PhA_ResetPullup()        do { WPUBbits.WPUB2 = 0; } while(0)
#define PhA_SetPushPull()        do { ODCONBbits.ODCB2 = 0; } while(0)
#define PhA_SetOpenDrain()       do { ODCONBbits.ODCB2 = 1; } while(0)
#define PhA_SetAnalogMode()      do { ANSELBbits.ANSB2 = 1; } while(0)
#define PhA_SetDigitalMode()     do { ANSELBbits.ANSB2 = 0; } while(0)
// get/set IO_RB3 aliases
#define PhB_TRIS                 TRISBbits.TRISB3
#define PhB_LAT                  LATBbits.LATB3
#define PhB_PORT                 PORTBbits.RB3
#define PhB_WPU                  WPUBbits.WPUB3
#define PhB_OD                   ODCONBbits.ODCB3
#define PhB_ANS                  ANSELBbits.ANSB3
#define PhB_SetHigh()            do { LATBbits.LATB3 = 1; } while(0)
#define PhB_SetLow()             do { LATBbits.LATB3 = 0; } while(0)
#define PhB_Toggle()             do { LATBbits.LATB3 = ~LATBbits.LATB3; } while(0)
#define PhB_GetValue()           PORTBbits.RB3
#define PhB_SetDigitalInput()    do { TRISBbits.TRISB3 = 1; } while(0)
#define PhB_SetDigitalOutput()   do { TRISBbits.TRISB3 = 0; } while(0)
#define PhB_SetPullup()          do { WPUBbits.WPUB3 = 1; } while(0)
#define PhB_ResetPullup()        do { WPUBbits.WPUB3 = 0; } while(0)
#define PhB_SetPushPull()        do { ODCONBbits.ODCB3 = 0; } while(0)
#define PhB_SetOpenDrain()       do { ODCONBbits.ODCB3 = 1; } while(0)
#define PhB_SetAnalogMode()      do { ANSELBbits.ANSB3 = 1; } while(0)
#define PhB_SetDigitalMode()     do { ANSELBbits.ANSB3 = 0; } while(0)
// get/set IO_RB4 aliases
#define PhC_TRIS                 TRISBbits.TRISB4
#define PhC_LAT                  LATBbits.LATB4
#define PhC_PORT                 PORTBbits.RB4
#define PhC_WPU                  WPUBbits.WPUB4
#define PhC_OD                   ODCONBbits.ODCB4
#define PhC_ANS                  ANSELBbits.ANSB4
#define PhC_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define PhC_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define PhC_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define PhC_GetValue()           PORTBbits.RB4
#define PhC_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define PhC_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define PhC_SetPullup()          do { WPUBbits.WPUB4 = 1; } while(0)
#define PhC_ResetPullup()        do { WPUBbits.WPUB4 = 0; } while(0)
#define PhC_SetPushPull()        do { ODCONBbits.ODCB4 = 0; } while(0)
#define PhC_SetOpenDrain()       do { ODCONBbits.ODCB4 = 1; } while(0)
#define PhC_SetAnalogMode()      do { ANSELBbits.ANSB4 = 1; } while(0)
#define PhC_SetDigitalMode()     do { ANSELBbits.ANSB4 = 0; } while(0)
// get/set IO_RB5 aliases
#define PhD_TRIS                 TRISBbits.TRISB5
#define PhD_LAT                  LATBbits.LATB5
#define PhD_PORT                 PORTBbits.RB5
#define PhD_WPU                  WPUBbits.WPUB5
#define PhD_OD                   ODCONBbits.ODCB5
#define PhD_ANS                  ANSELBbits.ANSB5
#define PhD_SetHigh()            do { LATBbits.LATB5 = 1; } while(0)
#define PhD_SetLow()             do { LATBbits.LATB5 = 0; } while(0)
#define PhD_Toggle()             do { LATBbits.LATB5 = ~LATBbits.LATB5; } while(0)
#define PhD_GetValue()           PORTBbits.RB5
#define PhD_SetDigitalInput()    do { TRISBbits.TRISB5 = 1; } while(0)
#define PhD_SetDigitalOutput()   do { TRISBbits.TRISB5 = 0; } while(0)
#define PhD_SetPullup()          do { WPUBbits.WPUB5 = 1; } while(0)
#define PhD_ResetPullup()        do { WPUBbits.WPUB5 = 0; } while(0)
#define PhD_SetPushPull()        do { ODCONBbits.ODCB5 = 0; } while(0)
#define PhD_SetOpenDrain()       do { ODCONBbits.ODCB5 = 1; } while(0)
#define PhD_SetAnalogMode()      do { ANSELBbits.ANSB5 = 1; } while(0)
#define PhD_SetDigitalMode()     do { ANSELBbits.ANSB5 = 0; } while(0)
/**
 * @ingroup  pinsdriver
 * @brief GPIO and peripheral I/O initialization
 * @param none
 * @return none
 */
void PIN_MANAGER_Initialize (void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt on Change Handling routine
 * @param none
 * @return none
 */
void PIN_MANAGER_IOC(void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt on Change Handler for the SW pin functionality
 * @param none
 * @return none
 */
void SW_ISR(void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt Handler Setter for SW pin interrupt-on-change functionality.
 *        Allows selecting an interrupt handler for SW at application runtime.
 * @pre Pins intializer called
 * @param InterruptHandler function pointer.
 * @return none
 */
void SW_SetInterruptHandler(void (* InterruptHandler)(void));

/**
 * @ingroup  pinsdriver
 * @brief Dynamic Interrupt Handler for SW pin.
 *        This is a dynamic interrupt handler to be used together with the SW_SetInterruptHandler() method.
 *        This handler is called every time the SW ISR is executed and allows any function to be registered at runtime.
 * @pre Pins intializer called
 * @param none
 * @return none
 */
extern void (*SW_InterruptHandler)(void);

/**
 * @ingroup  pinsdriver
 * @brief Default Interrupt Handler for SW pin. 
 *        This is a predefined interrupt handler to be used together with the SW_SetInterruptHandler() method.
 *        This handler is called every time the SW ISR is executed. 
 * @pre Pins intializer called
 * @param none
 * @return none
 */
void SW_DefaultInterruptHandler(void);


#endif // PINS_H
/**
 End of File
*/