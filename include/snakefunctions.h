#ifndef __SNAKE_FUNCTIONS_H
#define __SNAKE_FUNCTIONS_H

#include "snakeconfig.h"

void setUpGame(uint8_t *x, uint8_t *y);
void makeMove(const uint8_t move, uint8_t *x, uint8_t *y, uint8_t *previousMove);
Food generateFood(const Snake *fullSnake);

#endif