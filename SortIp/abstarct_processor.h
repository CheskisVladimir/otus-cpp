
#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <array>
#include<functional>
#include <limits>  

namespace sort_ip
{

    using byte_t = uint8_t;

    // full ip address
    using ip_adress_t = std::array<byte_t, 4>;
    using ip_function_t = std::function<void(const ip_adress_t &)>;


 class abstarct_processor
    {
    public:
        virtual ~abstarct_processor() = default;

        virtual void add(const ip_adress_t &addres) = 0;
        virtual void build() = 0;
        virtual void for_each(ip_function_t function) const;
    };

} // namespaces ort_ip

