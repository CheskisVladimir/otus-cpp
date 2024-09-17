#pragma once

#include <string>
#include "ip_address.h"

namespace ip_lib
{

ip_optional_t ip_parse (const std::string &str);
void ip_print(const ip_t &ip);


} // namespace ip_lib
