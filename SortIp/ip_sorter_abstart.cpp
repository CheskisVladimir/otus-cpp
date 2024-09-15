#include "sort_ip.h"

namespace sort_ip
{

    void sorter::add(const bytes_4 &bytes)
    {
        auto add_data = [&] (std::vector<bytes_3> &bypes_vector, const bytes_4 &bytes) -> void  
        {
            bypes_vector.emplace_back(bytes_3{bytes[1], bytes[2], bytes[3]});
        };

        add_data(m_all_data[bytes[0]], bytes);

        if (bytes[0] == )
    }

    void sorter::build()
    {
        for()

    }

    void sorter::print() const
    {
        
    }

    void sorter::print_bytes(bytes_4 bytes) const
    {
        for (size_t i = 0; i < 4; i++)
        {
            std::cout << bytes.bytes[i];
            std::cout << (i < 3) ? '.' : std::endl;
        }
    }

} // namespaces ort_ip