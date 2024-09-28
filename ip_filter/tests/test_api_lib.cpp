#include <gtest/gtest.h>

#include "../src/include/ip_lib.h"


TEST(TestGroupName, test_1)
{
    ASSERT_EQ(a(), 1);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}