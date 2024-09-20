#include "ip_input_output.h"
#include <cassert>
#include <cstdlib>
#include <iostream>
#include <string_view>

namespace ip_lib
{

ip_optional_t ip_parse (const std::string &str)
{
    auto to_byte = [](const stf)
    for (size_t i = 0; i,)
}

void ip_print(const ip_t &ip)
{
    using namespace std;
    cout 
    << ip.bytes[0] << '.'
    << ip.bytes[1] << '.'
    << ip.bytes[2] << '.'
    << ip.bytes[3] << endl;
}


} // namespace ip_lib
