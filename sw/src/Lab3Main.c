// Lab3Main.c
// Runs on LM4F120/TM4C123
// Uses ST7735.c to display the clock
// patterns to the LCD.
//    16-bit color, 128 wide by 160 high LCD
// Mark McDermott, Daniel Valvano and Jonathan Valvano
// Lab solution, do not post
// August 3,2024

/* This example accompanies the book
   "Embedded Systems: Real Time Interfacing to Arm Cortex M Microcontrollers",
   ISBN: 978-1463590154, Jonathan Valvano, copyright (c) 2024

 Copyright 2024 by Jonathan W. Valvano, valvano@mail.utexas.edu
    You may use, edit, run or distribute this file
    as long as the above copyright notice remains
 THIS SOFTWARE IS PROVIDED "AS IS".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED
 OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
 MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
 VALVANO SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL,
 OR CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
 For more information about my classes, my research, and my books, see
 http://users.ece.utexas.edu/~valvano/
 */
// Specify your hardware connections, feel free to change
// PD0 is squarewave output to speaker
// PE0 is mode select
// PE1 is left
// PE2 is right 
// PE3 is up
// PE4 is down
// if alarm is sounding, any button will quiet the alarm

#include <stdio.h>
#include <stdint.h>
#include "../inc/ST7735.h"
#include "../inc/PLL.h"
#include "../inc/tm4c123gh6pm.h"
#include "../inc/Timer0A.h"
#include "../inc/SysTick.h"
#include "LCD_Driver.h"
#include "Sound_Driver.h"
#include "Switch_Driver.h"
#include "Lab3.h"
#include "Globals.h"
// ---------- Prototypes   -------------------------
void DisableInterrupts(void); // Disable interrupts
void EnableInterrupts(void);  // Enable interrupts
void WaitForInterrupt(void);  // low power mode


int main(void) {
  DisableInterrupts();            // Disable interrupts during initialization
  PLL_Init(Bus80MHz);             // Set system clock to 80 MHz
  
  // Initialize all the system components
  SysTick_Init();                 // Initialize SysTick timer for timekeeping
  LCD_Init();                     // Initialize the LCD display
  Sound_Init();                   // Initialize sound (alarm system)
  Switch_Init();                  // Initialize switches for user input
  
  EnableInterrupts();             // Enable interrupts after initialization is done
  
  while (1) {
      LCD_DisplayTime();          // Continuously update the LCD to show the time
      
      if (AlarmEnabled) {         // Check if the alarm is enabled
          // If the current time matches the set alarm time, play sound
          if (TimeHours == AlarmHour && TimeMinutes == AlarmMinute && TimeSeconds == 0) {
              Sound_Play();       // Play sound when the alarm goes off
          }
      }

      Switch_AlarmToggle();       // Handle alarm toggle (enable/disable) based on user input
      
      WaitForInterrupt();         // Enter low-power mode and wait for next interrupt
  }
}
