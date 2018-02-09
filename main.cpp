#include "Array.hpp"
#include <assert.h>
#include <cstdlib>
#include <iostream>
int main(int argc, char *argv[])
{
	int count = 0;
	for(;;){
		Array<int> array;
		for (int i = 0; i < 1024; i++) {
			array += i;
		}
	}
	return 0;
}
