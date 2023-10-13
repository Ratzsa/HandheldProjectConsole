#include <gtest/gtest.h>
#include <stdint.h>

extern "C"
{
    #include "snakefunctions.c"
    #include "fff.h"
    #include "snakeconfig.h"
    DEFINE_FFF_GLOBALS;
}

class TestSnakeMovement : public testing::Test
{
protected:
    void SetUp() override
    {
        // initialize
    }
};

TEST_F(TestSnakeMovement,TestToTestTestingTestShouldJustWork)
{
    // ARRANGE
    uint8_t numA = 5;
    uint8_t numB = 15;
    uint8_t numC = 20;
    uint8_t res;

    // ACT
    res = numA + numB;

    // ASSERT
    ASSERT_EQ(numC, res);
}

TEST_F(TestSnakeMovement,TestForDownwardsMovementShouldResultInYEqualsThirteen)
{
    // void makeMove(const uint8_t move, uint8_t *x, uint8_t *y, uint8_t *previousMove)
    // up right down left
    // ARRANGE
    uint8_t move = MOVE_DOWN; // 2 is down
    uint8_t x = 10;
    uint8_t y = 10;
    uint8_t previousMove = HORIZONTAL_AXIS; // 0 horizontal or 1 vertical

    uint8_t result = 13;

    // ACT
    makeMove(move, &x, &y, &previousMove);

    // ASSERT
    ASSERT_EQ(y, result);
}

TEST_F(TestSnakeMovement,TestForUpMovementShouldResultInYEqualsSeven)
{
    // void makeMove(const uint8_t move, uint8_t *x, uint8_t *y, uint8_t *previousMove)
    // up right down left
    // ARRANGE
    uint8_t move = MOVE_UP; // 0 is up
    uint8_t x = 10;
    uint8_t y = 10;
    uint8_t previousMove = HORIZONTAL_AXIS; // 0 horizontal or 1 vertical

    uint8_t result = 7;

    // ACT
    makeMove(move, &x, &y, &previousMove);

    // ASSERT
    ASSERT_EQ(y, result);
}

TEST_F(TestSnakeMovement,TestForLeftMovementShouldResultInXEqualsSeven)
{
    // void makeMove(const uint8_t move, uint8_t *x, uint8_t *y, uint8_t *previousMove)
    // up right down left
    // ARRANGE
    uint8_t move = MOVE_LEFT; // 3 is left
    uint8_t x = 10;
    uint8_t y = 10;
    uint8_t previousMove = VERTICAL_AXIS; // 0 horizontal or 1 vertical

    uint8_t result = 7;

    // ACT
    makeMove(move, &x, &y, &previousMove);

    // ASSERT
    ASSERT_EQ(x, result);
}

TEST_F(TestSnakeMovement,TestForLeftMovementShouldResultInpreviousMoveEqualsZero)
{
    // void makeMove(const uint8_t move, uint8_t *x, uint8_t *y, uint8_t *previousMove)
    // up right down left
    // ARRANGE
    uint8_t move = MOVE_LEFT; // 3 is left
    uint8_t x = 10;
    uint8_t y = 10;
    uint8_t previousMove = VERTICAL_AXIS; // 0 horizontal or 1 vertical

    uint8_t result = HORIZONTAL_AXIS;

    // ACT
    makeMove(move, &x, &y, &previousMove);

    // ASSERT
    ASSERT_EQ(previousMove, result);
}

TEST_F(TestSnakeMovement,TestForUpMovementShouldResultInpreviousMoveEqualsOne)
{
    // void makeMove(const uint8_t move, uint8_t *x, uint8_t *y, uint8_t *previousMove)
    // up right down left
    // ARRANGE
    uint8_t move = MOVE_UP; // 0 is up
    uint8_t x = 10;
    uint8_t y = 10;
    uint8_t previousMove = HORIZONTAL_AXIS; // 0 horizontal or 1 vertical

    uint8_t result = VERTICAL_AXIS;

    // ACT
    makeMove(move, &x, &y, &previousMove);

    // ASSERT
    ASSERT_EQ(previousMove, result);
}