// Switch.c
#include "../inc/tm4c123gh6pm.h"
#include "Globals.h"
#include <stdint.h>


void Switch_Init(void) {
    SYSCTL_RCGCGPIO_R |= 0x20;              // Enable clock for Port F
    GPIO_PORTF_DIR_R &= ~0x11;              // Set PF0 and PF4 as input
    GPIO_PORTF_DEN_R |= 0x11;               // Enable digital function for PF0 and PF4
    GPIO_PORTF_PUR_R |= 0x11;               // Enable pull-up resistors on PF0 and PF4
}

uint8_t Switch_Read(void) {
    return (GPIO_PORTF_DATA_R & 0x11);      // Read PF0 and PF4 switches
}


void Switch_AlarmToggle(void) {
    if (Switch_Read() & 0x01) {             // Check if the switch on PF0 is pressed
        AlarmEnabled ^= 1;                  // Toggle the alarm enabled state
    }
}
