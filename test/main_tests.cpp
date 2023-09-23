#include <gtest/gtest.h>
// #include "consoleTest.cpp"

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    int a = RUN_ALL_TESTS();
}