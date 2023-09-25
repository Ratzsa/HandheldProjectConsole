#include <stdio.h>
#include <stdint.h>
#include "main.h"
#include "controller.h"

void transmitController()
{
    uint8_t controllerState = 0;
    uint32_t sendTimer = HAL_GetTick();
    while(1)
    {
        if(HAL_GetTick() - sendTimer > 16)
        {
            controllerState = SET_CONTROLLER;
            HAL_UART_Transmit_DMA(&huart1, &controllerState, sizeof(controllerState));
        }
    }
}