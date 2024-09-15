#pragma once


#include "abstarct_processor.h"

namespace sort_ip
{
    constexpr size_t max_byte_value = std::numeric_limits<uint8_t>::max();

    class sort_by_1st_byte final : public abstarct_processor
    {
        using last_bytes_t = std::array<byte_t, 3>;

    public:
        sort_by_1st_byte() = default;
        void add(const ip_adress_t &addres) override final;
        void build() override final;
        void for_each(ip_function_t function) const override final;

    private:
        std::array<std::vector<last_bytes_t>, max_byte_value> m_last_bytes;
    }
} // namespace sort_ip