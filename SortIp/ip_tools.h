#pragma once

#include "abstarct_processor.h"
#include <cstdint> // for uint32_t

namespace sort_ip
{

  void print_ip(const ip_adress_t &ip);
  uint32_t bytes_to_uint32(byte_t byte1, byte_t byte2, byte_t byte3, byte_t byte4);
} // namespaces ort_ip
