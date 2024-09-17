
#include "ip_container.h"

namespace ip_lib
{
    ip_container::ip_container(const ip_container &other)
    {
        m_data = other.m_data;
    }

    ip_container &ip_container::operator=(const ip_container &other)
    {
        if (&other == this)
            return *this;
        m_data = other.m_data;
        return *this;
    }

    void ip_container::add(const ip_t &ip)
    {
        m_data.push_back(ip);
    }

    void ip_container::sort(bool inverted_order = false)
    {
        auto comp = [inverted_order](const ip_t &a, const ip_t &b) -> bool
        {
            return !inverted_order ? a.numeric < b.numeric : b.numeric < a.numeric;
        };

        std::sort(m_data.begin(), m_data.end(), comp);
    }

    void ip_container::for_each(const ip_proc_t &proc) const
    {
        for (const auto &ip : m_data)
            process_ip(ip,  proc);

    }

} // namespace ip_lib
