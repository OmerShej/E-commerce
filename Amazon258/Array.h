#pragma once
#include <iostream>
using namespace std;

template<class T>
class Array
{
private:
	int physicalSize, logicalSize;
	T* arr;
public:
	Array(int size = 2);
	Array(const Array& other);
	~Array();
	const Array& operator=( const Array& other);
	const Array& operator+=(const T& newVal);
	const T& operator[](int index)const ;
	friend ostream& operator<<(ostream& os, const Array& arr) 
	{
		for (int i = 0; i < arr.logicalSize; i++)
		{
			os << arr.arr[i] << arr.delimeter;
		}
		return os;
	}
};

template<class T>
Array<T>::Array(int size)
{
	this->physicalSize = size;
	arr = new T[physicalSize];
	this->logicalSize = 0;
}

template <class T>
Array<T>::Array(const Array& other)
{
	this->arr = NULL;
	*this = other;
}

template<class T>
Array<T>::~Array()
{
	delete arr;
}

template<class T>
const Array<T>&Array<T>:: operator+=(const T& newVal)
{
	// physical the size of the array 
	// logicalSize the obejcts in the arr  
	if (logicalSize >= physicalSize)
	{
		physicalSize *= 2;
		T* temp = new T[physicalSize];
		for (int i = 0; i < logicalSize; i++) 
		{
			temp[i] = arr[i];
		}
		delete[]this->arr;
		this->arr = temp;	
	}
	arr[logicalSize++] = newVal;

	return *this;
}

template<class T>
const Array<T>&Array<T>::operator=(const Array& other)
{
	delete[]arr;
	physicalSize = other.physicalSize;
	logicalSize = other.logicalSize;
	arr = new T[physicalSize];
	for (int i = 0; i < logicalSize; i++)
	{
		arr[i] = other.arr[i];
	}
	return *this;
}

template <class T>
const T&Array<T>::operator[](int index) const 
{
	return this->arr[index];
}