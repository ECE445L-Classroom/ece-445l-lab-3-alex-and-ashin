// Sound.c
#include <stdio.h>
#include <stdint.h>
#include "../inc/ST7735.h"
#include "../inc/PLL.h"
#include "../inc/tm4c123gh6pm.h"
#include "../inc/Timer0A.h"
#include "../inc/SysTick.h"
#include "../inc/Switch.h"
#include "Lab3.h"

void Sound_Init(void) {
    SYSCTL_RCGCGPIO_R |= 0x02;              // Enable clock for Port B
    GPIO_PORTB_DIR_R |= 0x40;               // Set PB6 as output (connected to speaker)
    GPIO_PORTB_DEN_R |= 0x40;               // Enable digital I/O on PB6
}

void Sound_Play(void) {
    GPIO_PORTB_DATA_R |= 0x40;              // Set PB6 high to play sound
}

void Sound_Stop(void) {
    GPIO_PORTB_DATA_R &= ~0x40;             // Set PB6 low to stop sound
}
