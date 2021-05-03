#pragma once
#include <iostream>
#include <cstring>

template <typename T>
class myVector
{
private:

	T* data;
	size_t size;
	size_t capacity;

	void copy(const myVector<T>& other);
	void resize();
	void destroy();

public:

	myVector();
	myVector(const myVector<T>& other);
	myVector<T>& operator=(const myVector<T>& other);
	~myVector();

	myVector(const T*);

	size_t getSize()const;
	size_t getCapacity()const;

	void push_back(const T& toAdd);
	void pop_back();
	const bool isEmpty() const;

	T& operator[](const size_t index) const;
	template<typename K>
	friend std::ostream& operator<<(std::ostream& os, const myVector<K>& _vector);
	void removeThisIndex(const int index);

};

template<typename T>
void myVector<T>::copy(const myVector<T>& other)
{
	if (this != &other)
	{
		size = other.size;
		capacity = other.capacity;
		data = new T[capacity];
		for (size_t i = 0; i < size; i++)
		{
			data[i] = other.data[i];
		}
	}
}

template<typename T>
void myVector<T>::resize()
{
	capacity *= 2;
	T* buffer = new T[capacity];
	for (size_t i = 0; i < size; i++)
	{
		buffer[i] = data[i];
	}
	destroy();
	//data = new T[capacity];
	data = buffer;

}

template<typename T>
void myVector<T>::destroy()
{
	delete[] data;
}

template<typename T>
myVector<T>::myVector()
{
	size = 0;
	capacity = 8;
	data = new T[capacity];
}

template<typename T>
myVector<T>::myVector(const myVector<T>& other)
{
	copy(other);
}

template<typename T>
myVector<T>& myVector<T>::operator=(const myVector<T>& other)
{
	if (this != &other)
	{
		destroy();
		copy(other);
	}
	return *this;
}

template<typename T>
myVector<T>::~myVector()
{
	destroy();
}

template<typename T>
myVector<T>::myVector(const T* Data)
{
	size_t Size = 0;
	while (Data[Size] != NULL)
	{
		Size++;
	}
	size_t Capacity = 8;
	while (Capacity < Size)
	{
		Capacity *= 2;
	}
	size = Size;
	capacity = Capacity;
	data = new T[capacity];
	for (size_t i = 0; i < size; i++)
	{
		data[i] = Data[i];
	}

}

template<typename T>
size_t myVector<T>::getSize() const
{
	return size;
}

template<typename T>
size_t myVector<T>::getCapacity() const
{
	return capacity;
}

template <typename T>
T& myVector<T>::operator[](const size_t index) const
{
	if (index > size)
	{
		exit(1);
	}
	return data[index];
}

template<typename T>
void myVector<T>::push_back(const T& toAdd)
{
	if (size == capacity)
	{
		resize();
	}
	data[size++] = toAdd;

}

template<typename T>
void myVector<T>::pop_back()
{
	size--;
}

template<typename T>
const bool myVector<T>::isEmpty() const
{
	return size == 0;
}

template<typename K>
std::ostream& operator<<(std::ostream& os, const myVector<K>& _vector)
{
	for (int i = 0;i < _vector.size;i++) {
		os << _vector.data[i];
	}
	return os;
}

template <typename T>
void myVector<T>::removeThisIndex(const int index) 
{
	if (index < size) {
		for (int i = index; i < size - 1;i++) {
			data[i] = data[i + 1];
		}
		size--;
	}

}
