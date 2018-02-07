#include "Array.hpp"
#include <iostream>

int main(int argc, char *argv[])
{
	Array<std::string> array = Array<std::string>(20);
	array += std::string("hello");
	array += std::string("world");
	std::cout << array[0] << std::endl;
	std::cout << array[1] << std::endl;
	Array<int> numbers;
	for (int i = 0; i < 3000; i++) {
		numbers += i;
		printf("%d\n", numbers[i]);
	}

	Array<char> letters;
	letters += 's';
	letters += 'w';
	std::cout << letters[0] << std::endl;
	std::cout << letters[1] << std::endl;

	return 0;
}