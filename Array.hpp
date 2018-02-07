#ifndef _array_hpp
#define _array_hpp
#include <iostream>
template <class T> class Array
{
      private:
	struct array_struct {
		long key;
		T value;
	};

	struct array_struct *_array;

      public:
	Array()
	{
		_array = (array_struct *)malloc(sizeof(array_struct) * 10);
		std::cout << sizeof(array_struct) << std::endl;
		std::cout << sizeof(_array) << std::endl;
	}

	Array(long size)
	{
		
	}

	const char *operator[](const char *key)
	{
		return key;
	}
};

#endif