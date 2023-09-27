#include <gtest/gtest.h>
#include <stdint.h>

extern "C"
{
    // #include "snakegame.c"
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
    uint8_t numA = 5;
    uint8_t numB = 15;
    uint8_t numC = 20;
    uint8_t res;

    // ACT
    res = numA + numB;

    // ASSERT
    ASSERT_EQ(numC, res);
}
