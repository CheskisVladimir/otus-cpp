/*! \file main.cpp
    \brief A Documented file.
    
    Details.
*/

#include <iostream>
#include "main.h"

int asum(int a, int b)
{
    return a + b;
}

/**
 * @brief Entry point
 *
 * Execution of the program
 * starts here.
 *
 * @param argc Number of arguments
 * @param argv List of arguments
 *
 * @return Program exit status
 */
int main(int, char **) {
	std::cout << "Sum: " << asum(1,2) << std::endl;
	std::cout << "Hello, world!" << std::endl;
	return 0;
}