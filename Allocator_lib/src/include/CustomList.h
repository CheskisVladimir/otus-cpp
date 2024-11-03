#pragma once

#include <memory>
#include <functional>
#include <stddef.h>

namespace container_ns
{

    template <typename Type>
    struct Node
    {
        Node *m_next = nullptr;
        Type m_value;
    };

    template <typename Type, typename Allocator = std::allocator<Type>>
    class CustomList
    {
    public:
        using value_type = Type;
        using pointer = Type *;
        using const_pointer = const Type *;
        using reference = Type &;
        using const_reference = const Type &;
        using NodeType = Node<Type>;
        using NodeAllocator = typename Allocator::template rebind<Node<Type>>::other;
        using traits_t = std::allocator_traits<NodeAllocator>;

        CustomList() = default;
        ~CustomList()
        {
            delete_nodes();
        }

        class iterator
        {
        public:
            iterator(const NodeType *node) : m_node(node) {};
            iterator &operator++(int k)
            {
                for (int i = 0; i <= k; i++)
                    m_node = m_node->m_next;
                return *this;
            }

            operator const_reference()
            {
                return m_node->m_value;
            }

            constexpr bool operator== (const iterator &other)
            {
                return m_node == other.m_node;
            }

            constexpr bool operator!=(const iterator &other)
            {
                return m_node != other.m_node;
            }

        private:
            const NodeType *m_node;
        };

    public:
        size_t size() const { return m_size; }
        bool empty() const { return m_size == 0; }

        void add(const_reference value)
        {
            NodeType *node = traits_t::allocate(m_allocator, 1);
            traits_t::construct(m_allocator, node);
            node->m_value = value;
            //std::cout << node << "\n";
            if (m_last == nullptr)
            {
                m_root = node;
                m_last = m_root;
            }
            else
            {
                m_last->m_next = node;
                m_last = node;
            }
            m_size++;
        }

        iterator begin()
        {
            return iterator(m_root);
        }

        iterator end()
        {
            return iterator(nullptr);
        }

    private:
        void delete_nodes()
        {
            if (m_root == nullptr)
                return;
            NodeType *current = m_root;
            for (NodeType *next = current->m_next;; next = current->m_next)
            {
                traits_t::destroy(m_allocator, current);
                traits_t::deallocate(m_allocator, current, 1);
                current = next;
                if (current == nullptr)
                    break;
            }
        }
        NodeType *m_root = nullptr;
        NodeType *m_last = m_root;
        size_t m_size = 0;

        NodeAllocator m_allocator;
    };

}