#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "main.h"
#include "ssd1306.h"
#include "ssd1306_tests.h"
#include "systemsplash.h"
#include "snakegame.h"

void controlTest();
void printMenu(uint8_t selection);

#define OFFSET_Y_STEP 9
#define OFFSET_Y_START 10
#define OFFSET_X_START 12

typedef enum { menuOption1, menuOption2, menuOption3, menuOption4, menuOptionMax } menuSelections;

void mainMenu()
{
	menuSelections selection = menuOption1;
	uint8_t buttonPressed = false;

	ssd1306_Fill(Black);
	printMenu(selection);

	while(1)
	{
		if(DPAD_DOWN && (selection <= 2) && !buttonPressed)
		{
			selection++;
			buttonPressed = true;
			printMenu(selection);
		}

		if(DPAD_UP && (selection > 0) && !buttonPressed)
		{
			selection--;
			buttonPressed = true;
			printMenu(selection);
		}

		if(selection > 3)
		{
			selection = 3;
		}

		if(BUTTON_GREEN && !buttonPressed)
		{
			buttonPressed = true;
			switch(selection)
			{
			case 0:
				snakeStart();
				HAL_Delay(100);
				printMenu(selection);
				break;

			case 1:
				controlTest();
				printMenu(selection);
				break;

			case 2:
				ssd1306_TestAll();
				HAL_Delay(500);
				printMenu(selection);
				break;

			case 3:
				  trademarkScreen();
				  printMenu(selection);
				break;

			default:
				break;
			}
		}

		if(!BUTTON_GREEN && !DPAD_UP && !DPAD_DOWN)
		{
			buttonPressed = false;
		}
	}
}

void controlTest()
{
	ssd1306_Fill(Black);

	while(1)
	{
		ssd1306_SetCursor(14, 20); // UP
		ssd1306_WriteChar('U', Font_6x8, !DPAD_UP);

		ssd1306_SetCursor(8, 28); // LEFT
		ssd1306_WriteChar('L', Font_6x8, !DPAD_LEFT);

		ssd1306_SetCursor(20, 28); // RIGHT
		ssd1306_WriteChar('R', Font_6x8, !DPAD_RIGHT);

		ssd1306_SetCursor(14, 36); // DOWN
		ssd1306_WriteChar('D', Font_6x8, !DPAD_DOWN);

		ssd1306_SetCursor(122, 12); // SHOULDER
		ssd1306_WriteChar('S', Font_6x8, !BUTTON_SHOULDER);

		ssd1306_SetCursor(122, 48); // GREEN
		ssd1306_WriteChar('G', Font_6x8, !BUTTON_GREEN);

		ssd1306_SetCursor(110, 48); // RED
		ssd1306_WriteChar('R', Font_6x8, !BUTTON_RED);

		ssd1306_SetCursor(98, 48); // YELLOW
		ssd1306_WriteChar('Y', Font_6x8, !BUTTON_YELLOW);

		ssd1306_SetCursor(8, 48);
		ssd1306_WriteString("L+U+R to exit", Font_6x8, White);

		if(DPAD_LEFT && DPAD_UP && DPAD_RIGHT)
		{
			HAL_Delay(250);
			break;
		}

		ssd1306_UpdateScreen();
	}

}

void printMenu(uint8_t selection)
{
	ssd1306_Fill(Black);
	uint8_t offsetY = OFFSET_Y_START;
	char menuOptions[][15] = { "Snake", "Test Controls", "Test Display", "Credits" };

	for(uint8_t i = menuOption1; i < menuOptionMax; i++)
	{
		ssd1306_SetCursor(OFFSET_X_START, offsetY);
		ssd1306_WriteString(menuOptions[i], Font_6x8, (selection != i));
		offsetY += OFFSET_Y_STEP;
	}

	ssd1306_UpdateScreen();
}
