#ifndef _array_hpp
#define _array_hpp
#include <assert.h>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string.h>

template <class T> class Array
{
      private:
#define __default_array_size_ 200
	long _array_size;
	long _length;

	T *_array;

	void initArray()
	{
		_length = 0;
		
		_array = (T *)malloc(_array_size * sizeof(T));
		assert(_array != NULL);
		memset(_array, '\0', sizeof(T) * _array_size);
	}

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
		
		free(_array);
		assert(_array != NULL);
	}

	void remove(long key)
	{
		if (key < _length) {
			T *new_array = _array;
			_array = (T *)malloc(_array_size * sizeof(T));
			memset(_array, '\0', sizeof(T) * _array_size);
			memcpy(_array, new_array, (sizeof(T) * key));
			memcpy(_array + key, new_array + key + 1, (sizeof(T) * _array_size) - (sizeof(T) * (key)));
			free(new_array);
			_length--;
		} else {
			T *new_array = _array;
			_array = (T *)malloc(_array_size * sizeof(T));
			memset(_array, '\0', sizeof(T) * _array_size);
			memcpy(_array, new_array, (sizeof(T) * key - 1));
			free(new_array);
			_length--;
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
		if (_length >= _array_size) {
			int new_size = __default_array_size_ + _array_size;
			T *new_array = _array;
			_array = (T *)malloc(new_size * sizeof(T));
			memset(_array, '\0', new_size * sizeof(T));
			memcpy(_array, new_array, sizeof(T) * new_size);
			memcpy(_array, new_array, sizeof(T) * new_size);
			memcpy(_array, new_array, sizeof(T) * new_size);
			free(new_array);
			_array_size = new_size;
		}
		*(_array + _length) = value;
		_length++;
	}

	void operator+=(T value)
	{
		append(value);
	}

	T operator[](long key)
	{
		if (key < _length) {
			return _array[key];
		}
		return (T)NULL;
	}
};

#endif
