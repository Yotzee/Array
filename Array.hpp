#ifndef _array_hpp
#define _array_hpp
#include <iostream>
#include <string.h>

template <class T> class Array
{
      private:
#define __default_array_size_ 10
	long _array_size;
	long _length;

	void initArray()
	{
		_length = 0;
		if (_array_size == 0) {
			_array_size = 10;
		}
		_array = (array_struct *)malloc(sizeof(array_struct) * _array_size);
	}

	struct array_struct {
		T value;
	};

	struct array_struct *_array;

      public:
	Array()
	{
		_array_size = __default_array_size_;
		initArray();
	}

	Array(long size)
	{
		_array_size = size;
		initArray();
	}

	~Array()
	{
		delete (_array);
	}

	void remove(long key)
	{
		if (key < _length) {
			struct array_struct *new_array = (array_struct *)malloc(sizeof(array_struct) * _array_size);
			memset(new_array, '\0', sizeof(array_struct) * _array_size);
			memcpy(new_array, _array, (sizeof(array_struct) * (key)));
			memcpy(new_array + key + 1, _array + key + 1, (sizeof(array_struct) * _array_size) - (sizeof(array_struct) * (key - 1)));
			delete (_array);
			_array = new_array;
			//_length--;
		} else {
			struct array_struct *new_array = (array_struct *)malloc(sizeof(array_struct) * _array_size);
			memset(new_array, '\0', sizeof(array_struct) * _array_size);
			memcpy(new_array, _array, (sizeof(array_struct) * _length - 1));
			delete (_array);
			_array = new_array;
			//_length--;
		}
	}

	int length()
	{
		return getLength();
	}

	int getLength()
	{
		return _length;
	}

	void append(T value)
	{
		if (_length > _array_size) {
			// add to array
			long new_size = __default_array_size_ + _array_size;
			struct array_struct *new_array = (array_struct *)malloc(sizeof(array_struct) * new_size);
			memset(new_array, '\0', sizeof(array_struct) * _array_size);
			memcpy(new_array, _array, (sizeof(array_struct) * new_size));
			delete (_array);
			_array = new_array;
			_array_size = __default_array_size_ + _array_size;
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