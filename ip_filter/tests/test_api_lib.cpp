#include <gtest/gtest.h>

#include "../src/include/ip_lib.h"

using namespace ip_lib;

TEST(TestGroupName, test_sort_ip_vector)
{
    auto check_eq = [&](const std::vector<ip_t> &a, const std::vector<ip_t> &b)
    {
        ASSERT_EQ(a.size(), b.size());
        for (size_t i = 0; i < a.size(); i++)
            ASSERT_EQ(a[i], b[i]);
    };

    ip_t small{100, 20, 50, 200};
    ip_t middle(150, 20, 50, 200);
    ip_t large(250, 20, 50, 200);

    std::vector<ip_t> v{middle, small, large};

    std::vector<ip_t> v_sorted_normal{small, middle, large};
    std::vector<ip_t> v_sorted_invert{large, middle, small};

    sort_ip_vector(v, sort_order_t::normal);
    check_eq(v, v_sorted_normal);
    sort_ip_vector(v, sort_order_t::inverted);
    check_eq(v, v_sorted_invert);
}

TEST(TestGroupName, test_process)
{
    ip_t small{100, 20, 50, 200};
    ip_t middle(150, 20, 50, 200);
    ip_t large(100, 20, 50, 200);
    std::vector<ip_t> v{small, middle, large};

    int processed = 0;
    ip_proc_t proc(
        [](const ip_t &ip)
        { return ip.bytes[0] == 100; },
        [&processed](const ip_t &)
        { processed++; });

    process(v, proc);
    ASSERT_EQ(processed, 2);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}