#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <exception>
#include <stdexcept>
#include <cstddef>

template <typename T>
class Array
{
	private:
		T *				_array;
		unsigned int	_size;

	public:
		Array() : _array(NULL), _size(0){}

		Array(unsigned int n) : _array(new T[n]), _size(n)
		{
			for (unsigned int i = 0; i < _size; i++)
	            _array[i] = T();
		}

		Array(const Array &src): _array(new T[src._size]), _size(src._size)
		{
	        for (unsigned int i = 0; i < _size; i++)
	            _array[i] = src._array[i];
		}

		Array& operator=(const Array& src)
		{
	        if (this != &src) {
	            delete[] _array;
	            _array = new T[src._size];
	            _size = src._size;
	            for (unsigned int i = 0; i < _size; i++)
	                _array[i] = src._array[i];
	        }
	        return *this;
	    }

		~Array()
		{
	        delete[] _array;
	    }

		T& operator[](unsigned int index)
		{
	        if (index >= _size) {
	            throw std::out_of_range("Index out of bounds.");
	        }
	        return _array[index];
	    }

	    unsigned int size() const {
	        return _size;
	    }
};

#endif
