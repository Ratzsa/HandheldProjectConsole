#include <gtest/gtest.h>
#include <stdint.h>

extern "C"
{
    #include "snakegame.c"
}

class TestSnakeMovement : public testing::Test
{
protected:
    void SetUp() override
    {
        // initialize
    }
};

TEST_F(TestSnakeMovement,IfMovementUpReturnMovementMinusThreeYAxis)
{
    // ARRANGE
    uint8_t movement = 0;
    uint8_t xCoords = 10;
    uint8_t yCoords = 10;
    uint8_t previousMove = 0;

    // ACT
    makeMove(movement, &xCoords, &yCoords, &previousMove);

    // ASSERT
    ASSERT_EQ(7, yCoords);
}
