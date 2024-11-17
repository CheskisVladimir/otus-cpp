/*! \file main.cpp
    \brief It's a main c++ file.
    
    Details.
*/



#include "lib.h"

#include <iostream>

/**
 * @brief Calculates sum of the integer numbers
 *
 * @param a The  1st argument
 * @param b The  2nd argument
 *
 * @return Sum
 */
int sum(int a, int b)
{
	return a + b;
}


int main(int, char **) {
	std::cout << "Version: " << version() << std::endl;
	std::cout << "Hello, world!" << std::endl;
	return 0;
}
