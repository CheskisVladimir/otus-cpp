#pragma once

#include "abstarct_processor.h"

namespace sort_ip
{

    enum class pos_in_bytes : byte_t
    {
        byte_1,
        byte_2,
        byte_3,
        byte_4
    };

    using selected_byt_t = std::tuple<pos_in_bytes, byte_t>;

    

} // namespaces ort_ip
