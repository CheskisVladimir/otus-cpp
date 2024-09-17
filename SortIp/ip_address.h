#pragma once

#include <cinttypes>
#include <functional>
#include <tuple>
		

namespace ip_lib
{
    using byte_t = std::uint8_t;

    using ip_t = union
    {
        std::uint32_t numeric = 0;
        byte_t bytes[4];

    };


    using ip_checker_t = std::function<bool(const ip_t &)>;
    using ip_func_t = std::function<void(const ip_t &)>;
    using ip_proc_t = std::tuple<ip_checker_t, ip_func_t>;

    void process_ip(const ip_t &ip,  const ip_proc_t &proc);


    using ip_optional_t = std::tuple<bool, ip_t>;

} // namespace ip_lib