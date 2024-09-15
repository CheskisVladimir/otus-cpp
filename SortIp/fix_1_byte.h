#pragma once

#include "abstarct_processor.h"

namespace sort_ip
{
    class fix_2_bytes final : public abstarct_processor
    {
        using last_bytes = std::array<byte_t, 2>;

    public:
        fix_2_bytes();
        void add(const ip_adress &addres) override final;
        void build() override final;
        void for_each(ip_function function) const override final;

    private:
        std::vector<std::vector<last_bytes>> m_data;
    }
} // namespace sort_ip