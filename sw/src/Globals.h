#ifndef GLOBALS_H
#define GLOBALS_H

#include <stdint.h>  // To make sure uint32_t is defined

// Shared Time Variables
extern volatile uint32_t TimeSeconds;
extern volatile uint32_t TimeMinutes;
extern volatile uint32_t TimeHours;

// Alarm Variables
extern volatile uint8_t AlarmEnabled;
extern volatile uint32_t AlarmHour;
extern volatile uint32_t AlarmMinute;

// Function prototypes for shared functionalities
void Set_Time(uint32_t hours, uint32_t minutes);
void Set_Alarm(uint32_t hours, uint32_t minutes);
void Disable_Alarm(void);

#endif
