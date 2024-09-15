#include "sort_by_1st_byte.h"
#include "ip_tools.h"

namespace sort_ip
{

    void sort_by_1st_byte::add(const ip_adress_t &ip)
    {
        auto add_data = [&](std::vector<last_bytes_t> &last_bytes_vector, const ip_adress_t &ip) -> void
        {
            last_bytes_vector.emplace_back(last_bytes_t{ip[1], ip[2], ip[3]});
        };

        add_data(m_last_bytes[ip[0]], ip);
    }

    void sort_by_1st_byte::build()
    {
        auto compare = [&](const last_bytes_t &a, const last_bytes_t &b) -> bool
        {
            auto num_a = bytes_to_uint32(0, a[0], a[1], a[2]);
            auto num_b = bytes_to_uint32(0, b[0], b[1], b[2]);
            return num_a - num_b;
        };

        for (const auto &last_bytes : m_last_bytes)
        {
            std::sort(last_bytes.begin(), last_bytes.end(), compare);
        }
    }

    void sort_by_1st_byte::for_each(ip_function_t function) const
    {

        for (byte_t first_byte = 0; first_byte < max_byte_value; first_byte++)
        {
            for (const auto &last_bytes : m_last_bytes[first_byte])
            {
                function({first_byte, last_bytes[0], last_bytes[1], last_bytes[2]});
            }
        }
    }

} // namespace sort_ip