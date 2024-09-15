#include "ip_tools.h"

namespace sort_ip
{

    void print_ip(const ip_adress_t &ip)
    {
        for (size_t i = 0; i < 4; i++)
        {
            std::cout << ip[i];
            if (i < 3)
                std::cout << '.';
            else
                std::cout << std::endl;
        }
    }

    uint32_t bytes_to_uint32(uint8_t byte1, uint8_t byte2, uint8_t byte3, uint8_t byte4)
    {
        return (static_cast<uint32_t>(byte1) << 24) |
               (static_cast<uint32_t>(byte2) << 16) |
               (static_cast<uint32_t>(byte3) << 8) |
               (static_cast<uint32_t>(byte4));
    }

} // namespaces ort_ip