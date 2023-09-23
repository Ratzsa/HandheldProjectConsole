#include <stdio.h>

void dummyfunc();

//void checkMoveButtons()
//{
//	static uint8_t previousState[NUMBUTTONSMOVE];
//	static uint8_t currentState[NUMBUTTONSMOVE];
//	static uint32_t lastTime;
//
//	if(HAL_GetTick() < lastTime)
//	{
//		lastTime = HAL_GetTick();
//	}
//
//	if((lastTime + DEBOUNCE) > HAL_GetTick())
//	{
//		return;
//	}
//
//	lastTime = HAL_GetTick();
//
//	for(uint8_t i = 0; i < NUMBUTTONSMOVE; i++)
//	{
//		justPressed[i] = 0;
//		justReleased[i] = 0;
//
//		currentState[i] = HAL_GPIO_ReadPin(GPIOC, buttonsMovement[i]);
//
//		if(currentState[i] == previousState[i])
//		{
//			if((pressed[i] == 0) && (currentState[i] == 0))
//			{
//				justReleased[i] = 1;
//			}
//			else if((pressed[i] == 1) && (currentState[i] == 1))
//			{
//				justPressed[i] = 1;
//			}
//			pressed[i] = !currentState[i];
//		}
//		previousState[i] = currentState[i];
//	}
//}

// void dummyfunc()
// {
//     int a = 1;
//     int b = 2;
//     int c = a + b;
//     //
// }