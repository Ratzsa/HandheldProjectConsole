#ifndef _GAME_H_SNAKE_
#define _GAME_H_SNAKE_

#include "snakeconfig.h"

typedef struct
{
    uint8_t snakeX;
    uint8_t snakeY;
} SnakeBody;

typedef struct
{
    uint16_t snakeLength;
    SnakeBody bodyPart[SNAKE_ARRAY_SIZE];
} Snake;

typedef struct
{
    uint8_t foodX;
    uint8_t foodY;
} Food;

void snakeStart();
void snakeGame(uint8_t *endStatus);
void setUpGame(uint8_t *x, uint8_t *y);
void makeMove(const uint8_t move, uint8_t *x, uint8_t *y, uint8_t *previousMove);
uint8_t setMovement(uint8_t move, uint8_t previousMove);
void showMove(Snake *fullSnake, SnakeBody *snakeCurrentHead);
Food generateFood(const Snake *fullSnake);
void clearMarker(const uint8_t x, const uint8_t y);
void drawHead(const uint8_t x, const uint8_t y);
void drawBody(const uint8_t x, const uint8_t y);
void drawFood(const uint8_t x, const uint8_t y);

#endif
