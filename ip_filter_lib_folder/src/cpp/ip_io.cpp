#include "../include/ip_lib.h"

namespace ip_lib
{
    void print(const ip_t &ip)
    {
        std::cout
            << static_cast<int>(ip.bytes[0]) << '.'
            << static_cast<int>(ip.bytes[1]) << '.'
            << static_cast<int>(ip.bytes[2]) << '.'
            << static_cast<int>(ip.bytes[3])
            << std::endl;
    }

    ip_optional_t parse(const std::vector<std::string> &byte_strings)
    {
        if (byte_strings.size() != 4)
            return {false, {}};
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
}