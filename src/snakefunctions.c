#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include "snakegame.h"

void setUpGame(uint8_t *x, uint8_t *y)
{
    *x = ((rand() % (MAX_COLUMNS / 3)) * 3) + 5;
    *y = ((rand() % (MAX_ROWS / 3)) * 3) + 3;
}

void makeMove(const uint8_t move, uint8_t *x, uint8_t *y, uint8_t *previousMove)
{
    switch(move)
    {
        case MOVE_UP:
            (*y)-=3;
            *previousMove = VERTICAL_AXIS;
            break;

        case MOVE_RIGHT:
            (*x)+=3;
            *previousMove = HORIZONTAL_AXIS;
            break;

        case MOVE_DOWN:
            (*y)+=3;
            *previousMove = VERTICAL_AXIS;
            break;

        case MOVE_LEFT:
            (*x)-=3;
            *previousMove = HORIZONTAL_AXIS;
            break;

        default:
            break;
    }
}

Food generateFood(const Snake *fullSnake)
{
    Food generatedApple;
    bool noCollide = false;
    while(!noCollide)
    {
        generatedApple.foodX = ((rand() % (MAX_COLUMNS / 3)) * 3) + 5;
        generatedApple.foodY = ((rand() % (MAX_ROWS / 3)) * 3) + 3;
        uint8_t checkCollideCounter = 0;
        for(uint8_t i = 0; i < fullSnake->snakeLength; i++)
        {
            if((generatedApple.foodX == fullSnake->bodyPart[i].snakeX) && (generatedApple.foodY == fullSnake->bodyPart[i].snakeY))
            {
                checkCollideCounter++;
            }
        }

        if(checkCollideCounter == 0)
        {
            noCollide = true;
        }
    }

    return generatedApple;
}