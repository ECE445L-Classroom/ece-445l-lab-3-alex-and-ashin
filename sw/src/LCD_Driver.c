// LCD.c
#include "../inc/ST7735.h"
#include <stdio.h>
#include "LCD_Driver.h"
#include "Globals.h"


void LCD_Init(void) {
    ST7735_InitR(INITR_REDTAB);             // Initialize the LCD (Red Tab version)
    ST7735_FillScreen(ST7735_BLACK);        // Clear the display
    ST7735_SetRotation(1);                  // Set orientation
}

void LCD_DisplayTime(void) {
    char timeStr[16];
    sprintf(timeStr, "%02d:%02d:%02d", TimeHours, TimeMinutes, TimeSeconds); // Format time
    ST7735_SetCursor(0, 0);                 // Set the cursor to the top-left corner
    ST7735_OutString(timeStr);              // Output the time string
}
