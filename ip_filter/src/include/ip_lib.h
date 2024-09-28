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

    // This struct containes ip address- 4 bytes
    struct ip_t
    {
        byte_t bytes[4];
        ip_t() = default;
        ip_t(byte_t byte0, byte_t byte1, byte_t byte2, byte_t byte3)
            : bytes{byte0, byte1, byte2, byte3}
        {
        }
        bool operator==(const ip_t &other) const;
    };

    // A kind of std::optional<ip_t>, implemented using std::tuple
    using ip_optional_t = std::tuple<bool, ip_t>;

    using ip_checker_t = std::function<bool(const ip_t &)>;
    using ip_func_t = std::function<void(const ip_t &)>;

    // It's a simple processor: first we check ip and it's checked, fucn applyed  
    using ip_proc_t = std::tuple<ip_checker_t, ip_func_t>;

    enum class sort_order_t
    {
        normal,
        inverted
    };

    // Processes all ip's in a the vector with a proc
    void process(const std::vector<ip_t> &ip_vector, const ip_proc_t &proc);

    // Sorts the vector in normal or inverted order
    void sort_ip_vector(std::vector<ip_t> &ip_vector, sort_order_t order);

    // input-output
    ip_optional_t parse(const std::vector<std::string> &byte_strings);
    void print(const ip_t &ip);
    void print(const std::vector<ip_t> &ip_vector);
}
