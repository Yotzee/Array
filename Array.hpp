#ifndef _array_hpp
#define _array_hpp
#include <iostream>
#include <string.h>

template <class T> class Array
{
      private:
	int default_array_size;
	void initArray()
	{
		_length = 0;
		default_array_size = 10;
		if (_size == 0) {
			_size = default_array_size;
		}
		_array = (array_struct *)malloc(sizeof(array_struct) * _size);
	}

	long _size;
	long _length;

	struct array_struct {
		T value;
	};

	struct array_struct *_array;

      public:
	Array()
	{
		_size = default_array_size;
		initArray();
	}

	Array(long size)
	{
		_size = size;
		initArray();
	}

	int getLength()
	{
		return _length;
	}

	void append(T value)
	{
		if (_length > _size) {
			// add to array
			long new_size = default_array_size + _size;
			printf("%ld\n", _size);
			struct array_struct *new_array = (array_struct *)malloc(sizeof(array_struct) * new_size);
			memcpy(new_array, _array, (sizeof(array_struct) * new_size));
			_array = new_array;
			_size = default_array_size + _size;
		}
		_array[_length++].value = value;
	}

	void operator+=(T value)
	{
		append(value);
	}

	T operator[](long key)
	{
		if (key < _length) {
			return _array[key].value;
		}
		return (T)NULL;
	}
};

#endif