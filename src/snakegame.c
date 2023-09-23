#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include "snakegame.h"
#include "main.h"
#include "ssd1306.h"

void snakeStart()
{
	uint8_t endStatus = 0;
	uint8_t titleSnake[] = "SNAKE";

	while(1)
	{
        uint8_t titleStartX = 2;
		endStatus = 0;
		ssd1306_Fill(Black);

		for(uint8_t i = 0; i < 5; i++)
		{
			ssd1306_SetCursor(titleStartX, 10);
			ssd1306_WriteChar(titleSnake[i], Font_16x26, White);
			titleStartX += 28;
		}

		ssd1306_SetCursor(3, 40);
		ssd1306_WriteString("GREEN to play", Font_6x8, White);
		ssd1306_SetCursor(3, 50);
		ssd1306_WriteString("RED to exit", Font_6x8, White);
		ssd1306_UpdateScreen();
		HAL_Delay(250);

		while(!BUTTON_GREEN)
		{
			if(BUTTON_RED)
			{
				return;
			}
		}

		snakeGame(&endStatus);

		if(endStatus == 0)
		{
			ssd1306_SetCursor(20, 20);
			ssd1306_WriteString("LOSE", Font_16x26, White);
			ssd1306_UpdateScreen();
		}

		if(endStatus == 1)
		{
			ssd1306_SetCursor(20, 20);
			ssd1306_WriteString("WINNER", Font_16x26, White);
			ssd1306_UpdateScreen();
		}

		while(!BUTTON_GREEN)
		{
			// Pause
		}
		HAL_Delay(250);
	}
}

void snakeGame(uint8_t *endStatus)
{
    // bool inGame = true;
    bool gameIsRunning;
    bool hasMoved = false;
    srand(HAL_GetTick());
    volatile uint32_t timeAtLastMove;
    uint8_t move;
    char score[10];
    timeAtLastMove = HAL_GetTick();

    ssd1306_Fill(Black);

    // GAME SETUP
    SnakeBody snakeHead;
    Snake inGameSnake;
    inGameSnake.snakeLength = 1;

    setUpGame(&snakeHead.snakeX, &snakeHead.snakeY);
    drawHead(snakeHead.snakeX, snakeHead.snakeY);

    if(snakeHead.snakeX > (MAX_COLUMNS / 2))
    {
        move = MOVE_LEFT;
    }
    else
    {
        move = MOVE_RIGHT;
    }

    uint8_t previousMove = HORIZONTAL_AXIS;
    uint16_t timeBetweenMoves = TIME_BETWEEN_MOVES;
    inGameSnake.bodyPart[0] = snakeHead;

    // Setting up the first piece of food
    Food apple = generateFood(&inGameSnake);
    drawFood(apple.foodX, apple.foodY);

    ssd1306_DrawRectangle(2, 0, 98, 63, White);
    ssd1306_DrawRectangle(3, 1, 97, 63, White);
    ssd1306_SetCursor(101, 5);
    ssd1306_WriteString("SCORE", Font_6x8, White);

    ssd1306_UpdateScreen();

    // END OF GAME SETUP

    gameIsRunning = true;
    // volatile millis_t timeAtLastMove = 0;

    while(gameIsRunning)
    {
        // Only checking end game status if snake has moved
        if(hasMoved)
        {
            // LOSE GAME status checks
            if(snakeHead.snakeX > MAX_COLUMNS + 4 || snakeHead.snakeY >= (MAX_ROWS + 1) || snakeHead.snakeX < 5 || snakeHead.snakeY < 3)
            {
                gameIsRunning = false;
                // inGame = false;
                break;
            }

            for(uint8_t i = 1; i < inGameSnake.snakeLength; i++)
            {
                if((snakeHead.snakeX == inGameSnake.bodyPart[i].snakeX && snakeHead.snakeY == inGameSnake.bodyPart[i].snakeY) && inGameSnake.snakeLength > 1)
                {
                    gameIsRunning = false;
                    // inGame = false;
                    break;
                }
            }
            // End of LOSE GAME status checks

            // WIN GAME status check
            if(inGameSnake.snakeLength >= MAX_SNAKE_LENGTH)
            {
                *endStatus = 1;
                gameIsRunning = false;
                // inGame = false;
                break;
            }
            // End of WIN GAME status check

            // Checking for food
            if((snakeHead.snakeX == apple.foodX) && (snakeHead.snakeY == apple.foodY))
            {
                inGameSnake.snakeLength += 1;
                apple = generateFood(&inGameSnake);
                drawFood(apple.foodX, apple.foodY);
                ssd1306_UpdateScreen();
                // Adding a difficulty curve, reducing time between moves after every 5 pieces of food
                if(inGameSnake.snakeLength % 5 == 0)
                {
                    timeBetweenMoves -= TIME_BETWEEN_MOVES_REDUCTION;
                }
            }
            // End of Checking for food

            hasMoved = false;
        }

        move = setMovement(move, previousMove);

        if(HAL_GetTick() - timeAtLastMove > timeBetweenMoves)
        {
            makeMove(move, &snakeHead.snakeX, &snakeHead.snakeY, &previousMove);
            showMove(&inGameSnake, &snakeHead);
            drawFood(apple.foodX, apple.foodY);
            timeAtLastMove = HAL_GetTick();
            hasMoved = true;
            sprintf(score, "%d", (inGameSnake.snakeLength) - 1);
            ssd1306_SetCursor(110, 15);
            ssd1306_WriteString(score, Font_6x8, White);
            ssd1306_UpdateScreen();
        }
    }
}

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

uint8_t setMovement(uint8_t move, uint8_t previousMove)
{
    switch(previousMove)
    {
        case VERTICAL_AXIS:
            if(DPAD_RIGHT)
            {
                move = MOVE_RIGHT;
            }
            else if(DPAD_LEFT)
            {
                move = MOVE_LEFT;
            }
            break;

        case HORIZONTAL_AXIS:
            if(DPAD_DOWN)
            {
                move = MOVE_DOWN;
            }
            else if(DPAD_UP)
            {
                move = MOVE_UP;
            }
            break;

        default:
            break;
    }

    return move;
}

void showMove(Snake *fullSnake, SnakeBody *snakeCurrentHead)
{
    for(uint8_t i = fullSnake->snakeLength; i > 0; i--)
    {
        fullSnake->bodyPart[i] = fullSnake->bodyPart[i - 1];
        drawBody(fullSnake->bodyPart[i].snakeX, fullSnake->bodyPart[i].snakeY);
    }

    fullSnake->bodyPart[0] = *snakeCurrentHead;
    clearMarker(fullSnake->bodyPart[fullSnake->snakeLength].snakeX, fullSnake->bodyPart[fullSnake->snakeLength].snakeY);
    drawHead(snakeCurrentHead->snakeX, snakeCurrentHead->snakeY);
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

void drawHead(const uint8_t x, const uint8_t y)
{
	uint8_t headShape[3][3] =  {{ 0, 1, 0 }, { 1, 1, 1 }, { 0, 1, 0}};
	uint8_t startX = x - 1;
	uint8_t startY = y - 1;

	for(uint8_t i = 0; i < 3; i++)
	{
		for(uint8_t j = 0; j < 3; j++)
		{
			ssd1306_DrawPixel(startX + i, startY + j, headShape[i][j]);
		}
	}
}

void clearMarker(const uint8_t x, const uint8_t y)
{
	uint8_t startX = x - 1;
	uint8_t startY = y - 1;
	for(uint8_t i = 0; i < 3; i++)
	{
		for(uint8_t j = 0; j < 3; j++)
		{
			ssd1306_DrawPixel(startX + i, startY + j, Black);
		}
	}
}

void drawBody(const uint8_t x, const uint8_t y)
{
	uint8_t bodyShape[3][3] =  {{ 1, 1, 1 }, { 1, 0, 1 }, { 1, 1, 1}};
	uint8_t startX = x - 1;
	uint8_t startY = y - 1;

	for(uint8_t i = 0; i < 3; i++)
	{
		for(uint8_t j = 0; j < 3; j++)
		{
			ssd1306_DrawPixel(startX + i, startY + j, bodyShape[i][j]);
		}
	}
}

void drawFood(const uint8_t x, const uint8_t y)
{
	uint8_t foodShape[3][3] =  {{ 1, 0, 0 }, { 0, 1, 1 }, { 0, 1, 1}};
	uint8_t startX = x - 1;
	uint8_t startY = y - 1;

	for(uint8_t i = 0; i < 3; i++)
	{
		for(uint8_t j = 0; j < 3; j++)
		{
			ssd1306_DrawPixel(startX + i, startY + j, foodShape[i][j]);
		}
	}
}
