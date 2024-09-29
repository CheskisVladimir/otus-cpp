#include "lib.h"

#include <iostream>

namespace ip_lib
{
int ip_main();
}

int main(int, char **) {
	//std::cout << "Version: " << version() << std::endl;
	//std::cout << "Hello, world!" << std::endl;

	return ip_lib::ip_main();
}
