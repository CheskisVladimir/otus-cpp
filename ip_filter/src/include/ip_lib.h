#pragma once

#include <cinttypes>
#include <functional>
#include <tuple>
#include <string>
#include <vector>
#include <iostream>

namespace ip_lib
{
    using byte_t = std::uint8_t;

    struct ip_t
    {
        byte_t bytes[4];
        ip_t() = default;
        ip_t(byte_t byte0, byte_t byte1, byte_t byte2, byte_t byte3)
            : bytes{byte0, byte1, byte2, byte3}
        {
        }
        [[maybe_unused]] bool operator==(const ip_t &other) const;
    };

    using ip_optional_t = std::tuple<bool, ip_t>;

    using ip_checker_t = std::function<bool(const ip_t &)>;
    using ip_func_t = std::function<void(const ip_t &)>;
    using ip_proc_t = std::tuple<ip_checker_t, ip_func_t>;

    enum class sort_order_t
    {
        normal,
        inverted
    };

    [[maybe_unused]]void process(const std::vector<ip_t> &ip_vector, const ip_proc_t &proc);
    [[maybe_unused]]void sort_ip_vector(std::vector<ip_t> &ip_vector, sort_order_t order);
}
