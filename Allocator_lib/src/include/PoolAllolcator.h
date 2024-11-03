#pragma once

#include <stddef.h>
#include <stdint.h>
#include <vector>
#include <memory>
#include <stdexcept>
#include <iostream>

namespace allocator_ns
{
    template <typename T, size_t Size>
    class PoolAllolcator
    {
    public:
        using value_type = T;
        using pointer = T *;
        using const_pointer = const T *;
        using reference = T &;
        using const_reference = const T &;

        PoolAllolcator() noexcept = default;
        ~PoolAllolcator() = default;

        PoolAllolcator(const PoolAllolcator<T, Size> &other) : m_pool(other.m_pool) {}
        PoolAllolcator(const PoolAllolcator<T, Size> &&other) : m_pool(std::move(other.m_pool)) {}

        PoolAllolcator<T, Size> &operator=(const PoolAllolcator<T, Size> &other)
        {
            if (&other == this)
                return *this;
            m_pool = other.m_pool;
            return *this;
        }

        PoolAllolcator<T, Size> &operator=(PoolAllolcator<T, Size> &&other)
        {
            if (&other == this)
                return *this;
            m_pool = std::move(other.m_pool);
            return *this;
        }

        bool operator==(const PoolAllolcator &other)
        {
            if (&other == this)
                return true;

            return m_pool == other.m_pool;
        }

        pointer allocate(size_t n)
        {
            if (n <= 0)
            {
                throw std::invalid_argument("Invalid allocate size");
            }

            if (m_pool.size() + n > m_size)
            {
                throw std::out_of_range("Pull limit has been reached");
            }

            if (m_pool.capacity() == 0)
                m_pool.reserve(m_size);
            pointer allocacated = m_pool.data() + m_pool.size();
            m_pool.resize(m_pool.size() + n);
            return allocacated;
        }

        void deallocate(T *p, size_t n)
        {
            if (n == 0)
                return;

            T *from = p;
            T *to = p + n;
            T *pull_start = m_pool.data();
            T *pull_end = m_pool.data() + m_size;
            if (from < pull_start || to > pull_end)
                throw std::out_of_range("PoolAllolcator deallocate invalid pointer");

            m_pool.clear();
        }

        template <class U>
        struct rebind
        {
            typedef PoolAllolcator<U, Size> other;
        };

        template <typename U, typename... Args>
        void construct(U *p, Args &&...args)
        {
            new (p) U(std::forward<Args>(args)...);
        }

        template <typename U>
        void destroy(U *p)
        {
            p->~U();
        }

    private:
        using propagate_on_container_copy_assignment = std::true_type;
        using propagate_on_container_move_assignment = std::true_type;
        using propagate_on_container_swap = std::true_type;

        std::vector<T> m_pool;
        size_t m_size = Size;
    };
} // namespace allocator_ns