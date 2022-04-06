#pragma once

#include <iostream>
using namespace std;

template <typename T>
class List {
    T* v;
    int count;
    int size;

    void resize();
public:
    List();
    void push(T element);
    void remove(unsigned int index);
    void insert(unsigned int index, T element);
    void    set(unsigned int index, T element);
    T       pop();
    void  print();
    unsigned int listsize() const;
    const T&   get(T element);
    void sort(int (*compare)(T a, T b));
    unsigned int firstIndexOf(T element, int (*callback)(T a, T b));
};

template<typename T>
void List<T>::sort(int (*compare)(T a, T b)) {

    for(int i = 0; i < count-1; i++)
	    for(int j = i+1; j < count; j++)
	    {
		if(compare(v[i], v[j]) == 1)
		{
			swap(v[i], v[j]);
		}
	    }
}

template<typename T>
List<T>::List() {
    v = new T[5];
    count = 0;
    size = 5;
}

template<typename T>
unsigned int List<T>::listsize() const {
	return this->count;
}

template<typename T>
void List<T>::remove(unsigned int index) {
	for(int i = index; i < count-1; i++)
		v[i] = v[i+1];
	count--;
}

template<typename T>
void List<T>::insert(unsigned int index, T element) {
	if(index > size)
	{
		std::cerr << "Index out of size\n";
	}
	if(count == size)
		resize();
	for(int i = size-1; i > index; i--)
		v[i] = v[i-1];
	v[index] = element;
	if(index > count)
		count = index + 1;
	else
		count++;
}

template<typename T>
void List<T>::resize() {
    T* newV = new T[size * 2];
    for (int i = 0; i < count; ++i) {
        newV[i] = v[i];
    }
    delete[] v;
    v = newV;
    size = size * 2;
}

template<typename T>
void List<T>::push(T element) {
    if (count == size) {
        resize();
    }
    v[count] = element;
    count++;
}

template<typename T>
T List<T>::pop() {
    count--;
    return v[count];
}

template<typename T>
void List<T>::print() {
    for (int i = 0; i < count; ++i) {
        cout << v[i] << " ";
    }
    cout << endl;
}


template<typename T>
const T& List<T>::get(T element) {
    for (int i = 0; i < count; ++i) {
	if(v[i] == element)
		return v[i];
    }
    return nullptr;
}

template<typename T>
void List<T>::set(unsigned int index, T element) {
	if(index > count)
		std::cerr << "Element not in use\n";
	v[index] = element;
}

template<typename T>
unsigned int List<T>::firstIndexOf(T element, int (*callback)(T a, T b)) {
	if(callback == nullptr)
		callback = T::operator==;
	for(int i = 0; i < count; i++)
	{
		if(callback(v[i], element) == 0)
			return i;
	}
	return -1;
}
