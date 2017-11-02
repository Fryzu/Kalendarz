#include <iostream>
#include <date.h>
#include <gtest/gtest.h>

int main(int argc, char* argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

Date testDate1;
Date testDate2;

TEST(DateTest, StartingValue)
{
    EXPECT_EQ(0, testDate1.getUnixDays());
}