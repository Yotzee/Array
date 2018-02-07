#include "Array.hpp"
#include <iostream>

int main(int argc, char *argv[])
{

	Array<char> letters;
	char lets[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghifklmnopqrstuvwxyz";
	for(int i = 0; i < strlen(lets); i++){
		letters += lets[i];	
	}
	std::cout << letters.getLength() << std::endl;
	letters.remove(letters.getLength());
	std::cout << letters.getLength() << std::endl;
	std::cout << letters[5] << std::endl;
	letters.remove(2);
	std::cout << letters.getLength() << std::endl;
	std::cout << letters[5] << std::endl;
	letters.remove(5);
	std::cout << letters.getLength() << std::endl;
	std::cout << letters[5] << std::endl;

	for(int i = 0; i < letters.length(); i++){
		std::cout << letters[i];
	}


	return 0;
}