#pragma once 

#include "ip_address.h"

namespace ip_lib
{
    class ip_container final
    {
    public:
        ip_container() {}
        ip_container(const ip_container &other);
        ip_container &operator=(const ip_container &other);

        void add(const ip_t &ip);
        void sort(bool inverted_order = false);

        void for_each(const ip_proc_t &proc) const;

    private:
        std::vector<ip_t> m_data;
    };

} // namespace ip_lib