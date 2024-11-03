#include <iostream>
#include <map>
#include <iostream>

#include "Allocator_lib/src/include/PoolAllolcator.h"
#include "Allocator_lib/src/include/Container.h"
#include "Allocator_lib/src/include/CustomList.h"

using namespace container_ns;
using namespace allocator_ns;


int calculate_factorial(int number)
{
    int result = 1;
    for (int i = 2; i <= number; i++)
        result *= i;
    return result;
}

template<typename Map>
void print (const Map &map)
{
    for (auto it = std::begin(map); it != std::end(map); it++)
    {
        std::cout << it->first << " " << it->second << std::endl;
    }
}

template <typename Type, typename Allocator>
void print (const Container<Type, Allocator> &container)
{
    for (size_t i = 0; i < container.size(); i++)
    {
        std::cout << container.at(i) << std::endl;
    }
}


int main(int, char **)
{

    constexpr int count = 10;
// std::map<int, int>
    std::map<int, int> standart_map;
    for (int i = 0; i < count; i++)
        standart_map[i] = calculate_factorial(i);
    print (standart_map);

//   std::map<int, int> with newallocator
    using map_allocator_t =  allocator_ns::PoolAllolcator<std::pair<int, int>, count>;
    std::map<int, int, std::less<int>, map_allocator_t> pool_map;
    for (int i = 0; i < count; i++)
        pool_map[i] = calculate_factorial(i);
    print (pool_map);


//   CustomList<int>
    CustomList<int> l;
    for (int i = 0; i < count; i++)
	{
		auto value = calculate_factorial(i);
        l.add(value);
	}

    for (auto it = l.begin(); it !=  l.end(); it++)
    {
        int value = it;
        std::cout << value << std::endl;
    }

//   CustomList<int> new allocator
    CustomList<int, map_allocator_t> lA;
    for (int i = 0; i < count; i++)
	{
		auto value = calculate_factorial(i);
        lA.add(value);
	}

    for (auto it = lA.begin(); it !=  lA.end(); it++)
    {
        int value = it;
        std::cout << value << std::endl;
    }
    return 0;
}