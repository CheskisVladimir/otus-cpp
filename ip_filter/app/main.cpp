
#include <iostream>
#include "../src/include/ip_lib.h"

namespace ip_lib
{
int ip_main();
}

#include <iostream>
#include "../src/include/ip_lib.h"

namespace ip_lib
{
    std::vector<std::string> split(const std::string &str, char d)
    {
        std::vector<std::string> r;

        std::string::size_type start = 0;
        std::string::size_type stop = str.find_first_of(d);
        while (stop != std::string::npos)
        {
            r.push_back(str.substr(start, stop - start));

            start = stop + 1;
            stop = str.find_first_of(d, start);
        }

        r.push_back(str.substr(start));

        return r;
    }

    std::vector<ip_t> load()
    {
        using namespace std;

        std::vector<ip_t> ip_pool;
        for (std::string line; std::getline(std::cin, line);)
        {
            std::vector<std::string> v = split(line, '\t');
            auto ipstrings = split(v.at(0), '.');

            bool ok = false;
            ip_t ip;
            tie(ok, ip) = parse(ipstrings);
            if (!ok)
                throw std::invalid_argument("Invalid IP address");

            ip_pool.push_back(ip);
        }
        return ip_pool;
    }

    int ip_main()
    {
        using namespace std;
        using namespace ip_lib;

        try
        {
            std::vector<ip_t> ip_pool = load();

            auto cekck_all = [](const ip_t &)
            {
                return true;
            };

            // we create ip_pool_to_sort in scope, it will be destroed after printing
            {
                ip_proc_t proc(
                    [](const ip_t &)
                    { return true; },
                    [](const ip_t &ip)
                    { print(ip); });

                std::vector<ip_t> ip_pool_to_sort = ip_pool;
                ip_lib::sort_ip_vector(ip_pool_to_sort, sort_order_t::inverted);
                process(ip_pool_to_sort, proc);
            }

            ip_proc_t proc_byte_1(
                [](const ip_t &ip)
                { return ip.bytes[0] == 1; },
                [](const ip_t &ip)
                { print(ip); });
            process(ip_pool, proc_byte_1);

            ip_proc_t proc_byte_2(
                [](const ip_t &ip)
                { return ip.bytes[0] == 46 && ip.bytes[1] == 70; },
                [](const ip_t &ip)
                { print(ip); });
            process(ip_pool, proc_byte_2);

            ip_proc_t proc_byte_46(
                [](const ip_t &ip)
                { 
                    byte_t to_find =  46;
                    return ip.bytes[0] == to_find || ip.bytes[1] == to_find || ip.bytes[2] == to_find|| ip.bytes[3] == to_find; },
                [](const ip_t &ip)
                { print(ip); });
            process(ip_pool, proc_byte_46);
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << std::endl;
        }
        return 0;
    }
} // namespace ip_lib

int main (int, char **) {
    

    std::cout << "Hello, world!" << std::endl;

    return ip_lib::ip_main();
}