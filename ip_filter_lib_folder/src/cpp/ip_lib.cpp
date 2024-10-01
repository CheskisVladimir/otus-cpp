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
        // I'm not sure that it's a good idea, but tests works) 
        std::uint32_t *ip_index_in_1_number = reinterpret_cast<std::uint32_t *>(ip_vector.data());
        if (order == sort_order_t::inverted)
            std::sort(ip_index_in_1_number, ip_index_in_1_number + ip_vector.size(), std::greater<uint32_t>());
        else
            std::sort(ip_index_in_1_number, ip_index_in_1_number + ip_vector.size());
    }

} // namespace ip_lib