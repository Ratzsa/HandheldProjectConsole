#ifndef _CONFIG_SNAKE_GAME
#define _CONFIG_SNAKE_GAME

#define BIT_SET(a, b) ((a) |= (1ULL << (b)))
#define BIT_CLEAR(a,b) ((a) &= ~(1ULL<<(b)))
#define BIT_FLIP(a,b) ((a) ^= (1ULL<<(b)))
#define BIT_CHECK(a,b) (!!((a) & (1ULL<<(b))))

#define MAX_COLUMNS 93
#define MAX_ROWS 60

#define MAX_SNAKE_LENGTH (((MAX_COLUMNS / 3) * (MAX_ROWS / 3)) - 1)
#define SNAKE_ARRAY_SIZE ((MAX_COLUMNS / 3) * (MAX_ROWS / 3) + 1)

// Change for easier or harder difficulty
#define TIME_BETWEEN_MOVES 250
#define TIME_BETWEEN_MOVES_REDUCTION 1

#define MOVE_UP 0
#define MOVE_RIGHT 1
#define MOVE_DOWN 2
#define MOVE_LEFT 3

#define HORIZONTAL_AXIS 0
#define VERTICAL_AXIS 1

#endif