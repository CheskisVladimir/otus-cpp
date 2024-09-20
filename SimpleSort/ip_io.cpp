#include <iostream>
#include "ip_lib.h"

namespace ip_lib
{
    void print(const ip_t &ip)
    {
        using namespace std;
        std::cout
            << ip.bytes[0] << '.'
            << ip.bytes[1] << '.'
            << ip.bytes[2] << '.'
            << ip.bytes[3] << endl;
    }

    ip_optional_t pars(const std::array<std::string, 4> &byte_strings)
    {
        ip_t ip;
        for (int i = 0; i < 4; i++)
        {
            const auto &str = byte_strings[i];
            if (str.length() > 3)
                return {false, {}};

            for (const auto ch : str)
            {
                if (!std::isdigit(ch))
                    return {false, {}};
            }

            int number = atoi(str.c_str());
            if (number < 0 || number > 256)
                return {false, {}};

            ip.bytes[i] = static_cast<byte_t>(number);
        }
        return {true, ip};
    }

} // namespace ip_lib
