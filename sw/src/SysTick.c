// SysTick.c
// Runs on TM4C123
// Ashin Shaji
// Last Modified: 9/19/2024
#include <stdint.h>
#include "../inc/tm4c123gh6pm.h"
#include "Globals.h"


volatile uint32_t TimeSeconds = 0;
volatile uint32_t TimeMinutes = 0;
volatile uint32_t TimeHours = 0;
volatile uint8_t AlarmEnabled = 0;  // Flag for whether the alarm is enabled
volatile uint32_t AlarmHour = 0;
volatile uint32_t AlarmMinute = 0;

// SysTick Initialization
void SysTick_Init(void) {
    NVIC_ST_CTRL_R = 0;                // Disable SysTick during setup
    NVIC_ST_RELOAD_R = 80000000 - 1;   // Reload value for 1-second tick (assuming 80 MHz clock)
    NVIC_ST_CURRENT_R = 0;             // Clear current
    NVIC_ST_CTRL_R = 0x07;             // Enable SysTick with core clock and interrupts
}

// SysTick Interrupt Handler
void SysTick_Handler(void) {
    TimeSeconds++;
    
    if (TimeSeconds >= 60) {
        TimeSeconds = 0;
        TimeMinutes++;
        
        if (TimeMinutes >= 60) {
            TimeMinutes = 0;
            TimeHours++;
            
            if (TimeHours >= 12) {
                TimeHours = 0;
            }
        }
    }
}

// Function to set the current time (hours, minutes)
void Set_Time(uint32_t hours, uint32_t minutes) {
    TimeHours = hours;
    TimeMinutes = minutes;
    TimeSeconds = 0;
}

// Function to set the alarm (hours, minutes)
void Set_Alarm(uint32_t hours, uint32_t minutes) {
    AlarmHour = hours;
    AlarmMinute = minutes;
    AlarmEnabled = 1;  // Enable the alarm once set
}

// Function to disable the alarm
void Disable_Alarm(void) {
    AlarmEnabled = 0;
}

