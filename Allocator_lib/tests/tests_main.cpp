#include <gtest/gtest.h>
#include "../src/include/PoolAllolcator.h"
#include "../src/include/CustomList.h"

TEST(allocator_tests, container)
{
    using namespace container_ns;

    CustomList<int> list; 
    std::vector<int> in_values {5,6,7};
    for (auto v : in_values)
        list.add(v);

    std::cout << "A\n";

    std::vector<int> out_values;
    std::cout << "Y\n";
    auto it1 = list.begin();
    std::cout << "Z\n";
    it1++;
    std::cout << "Zzzz\n";
    int val = it1;
    std::cout << "it\n";
    auto e = list.end();
    std::cout << "itq\n";
    for (auto it = list.begin(); it != list.end(); it++) 
    {
        std::cout << "X\n";

        out_values.push_back(it);
    }

    std::cout << "B\n";
    ASSERT_EQ(in_values, out_values);
    std::cout << "C\n";
}

TEST(allocator_tests, allocator)
{
    using namespace allocator_ns;
    PoolAllolcator<int, 3> allocator;


    // Add one item & check it's value
    auto one = allocator.allocate(1);
    *one = 1;
    ASSERT_EQ(*one, 1);

    // Add 2 items
    auto more = allocator.allocate(2);
    more[0] = 2;
    more[1] = 3;

    // The first is valid
    ASSERT_EQ(*one, 1);

    // 2 items are added
    ASSERT_EQ(more[0], 2);
    ASSERT_EQ(more[1], 3);

 
    // Deallocate  deallocates all
    allocator.deallocate(one, 1);
    auto next = allocator.allocate(3);
    for (int i = 0; i < 3; i++)
    {
        next[i] = i;
        ASSERT_EQ(next[i], i);
    }
}



int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}