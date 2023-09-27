#include <stdio.h>
#include <stdint.h>
#include "main.h"
#include "controller.h"

void transmitController()
{
    uint8_t controllerState = 0;
    uint8_t oldControllerState = 0;
    uint32_t sendTimer = HAL_GetTick();
    while(1)
    {
        controllerState = SET_CONTROLLER;
        if((HAL_GetTick() - sendTimer > 16) && (controllerState != oldControllerState))
        {
            oldControllerState = controllerState;
            HAL_UART_Transmit(&huart1, &controllerState, sizeof(controllerState), 2);
        }
    }
}