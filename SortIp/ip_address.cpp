#include "ip_address.h"

namespace ip_lib
{

    void process_ip(const ip_t &ip, const ip_proc_t &proc)
    {
        auto check = std::get<0>(proc);
        auto func = std::get<1>(proc);

        if (!func)
            return;
        if (check && !check(ip))
            return;
        func(ip);
    }

} // namespace ip_lib