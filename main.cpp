#include "Array.hpp"
#include <iostream>

int main(int argc, char *argv[])
{
	Array<std::string> array;
	std::cout << array["hello"];
	return 0;
}