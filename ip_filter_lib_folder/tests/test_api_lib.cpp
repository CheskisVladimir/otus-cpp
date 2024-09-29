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

TEST(TestGroupName, test_parse)
{
    // ip_optional_t parse(const std::vector<std::string> &byte_strings);

    bool ok = false;
    ip_t ip;

    std::vector<std::string> too_many{"1", "2", "3", "4", "5"};
    std::tie(ok, ip) = parse(too_many);
    ASSERT_FALSE(ok);

    std::vector<std::string> invalid{"a", "2", "3", "4"};
    std::tie(ok, ip) = parse(too_many);
    ASSERT_FALSE(ok);

    std::vector<std::string> large{"500", "2", "3", "4"};
    std::tie(ok, ip) = parse(too_many);
    ASSERT_FALSE(ok);

    std::vector<std::string> valid{"255", "100", "1", "2"};
    std::tie(ok, ip) = parse(valid);
    ASSERT_TRUE(ok);

    ip_t eq {255, 100, 1, 2};
    ASSERT_EQ(ip, eq);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}