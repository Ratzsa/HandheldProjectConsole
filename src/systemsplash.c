#include <stdio.h>
#include <stdint.h>
#include "main.h"
#include "ssd1306.h"
#include "ssd1306_tests.h"

void logoScreen()
{
	  uint8_t pixelHorizontal = 110;
	  uint8_t pixelVertical = 64;
	  ssd1306_Fill(Black);
//	  ssd1306_Line(20, 10, 20, 50, White);
//	  ssd1306_Line(10, 40, 110, 40, White);
	  ssd1306_SetCursor(22, 22);
	  ssd1306_WriteString("PlaySonX", Font_11x18, White);
	  ssd1306_UpdateScreen();
	  for(uint8_t i = 0; i < 110; i++)
	  {
		  ssd1306_DrawPixel(pixelHorizontal, 40, White);
		  ssd1306_DrawPixel(pixelHorizontal - 1, 40, White);
		  ssd1306_DrawPixel(20, pixelVertical, White);
		  ssd1306_UpdateScreen();
		  pixelHorizontal = pixelHorizontal - 2;
		  pixelVertical--;
		  HAL_Delay(5);
	  }
	  HAL_Delay(3000);
}

void trademarkScreen()
{
	  ssd1306_Fill(Black);
	  ssd1306_SetCursor(3, 0);
	  ssd1306_WriteString("Licenses:", Font_6x8, White);
	  ssd1306_SetCursor(3, 8);
	  ssd1306_WriteString("MIT, BSD, APACHE 2.0", Font_6x8, White);
	  ssd1306_SetCursor(3, 18);
	  ssd1306_WriteString("      TRADEMARK", Font_6x8, White); // TRADEMARK
	  ssd1306_SetCursor(3, 28);
	  ssd1306_WriteString("      DANIEL W", Font_6x8, White); // DANIEL W
	  ssd1306_SetCursor(3, 37);
	  ssd1306_WriteString("Offenders will be", Font_6x8, White);
	  ssd1306_SetCursor(3, 46);
	  ssd1306_WriteString("shot or something.", Font_6x8, White);
	  ssd1306_SetCursor(3, 56);
	  ssd1306_WriteString("I dunno. Hi.", Font_6x8, White);
	  ssd1306_UpdateScreen();
	  HAL_Delay(3000);
}
