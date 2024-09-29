#include <cassert>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include <cinttypes>
#include <functional>
#include <tuple>

#include "../include/ip_lib.h"

namespace ip_lib
{
    bool ip_t::operator==(const ip_t &other) const 
    {
        for (size_t i = 0; i < 4; i++)
            if (bytes[i] != other.bytes[i])
                return false;
        return true;
    }

    void process(const std::vector<ip_t> &ip_vector, const ip_proc_t &proc)
    {
        ip_checker_t check;
        ip_func_t func;

        std::tie(check, func) = proc;

        if (!func)
            return;

        for (const auto &ip : ip_vector)
        {
            if (check && !check(ip))
                continue;
            func(ip);
        }
    }

    void sort_ip_vector(std::vector<ip_t> &ip_vector, sort_order_t order)
    {
        auto less = [order](const ip_t &a, const ip_t &b) -> bool
        {
            bool a_is_less = false;
            bool b_is_less = false;
            for (size_t i = 0; i < 4; i++)
            {
                if (a.bytes[i] < b.bytes[i])
                {
                    a_is_less = true;
                    break;
                }
                if (a.bytes[i] > b.bytes[i])
                {
                    b_is_less = true;
                    break;
                }
            }
            if (!b_is_less && !a_is_less)
                return false;
            return order == sort_order_t::normal ? a_is_less : b_is_less;
        };

        std::sort(ip_vector.begin(), ip_vector.end(), less);
    }

} // namespace ip_lib