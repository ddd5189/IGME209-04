#pragma once
#include <iostream>
using namespace std;
template <class T>
class Stack
{
public:
	Stack();
	//copy constructor
	Stack(const Stack& other);
	//copy aassignment operator
	Stack& operator= (const Stack& other); 
	void Push(T);
	void Pop(T);
	void Print(T);
	~Stack();
};


template <class T>
Stack<T>::Stack()
{

}

//copy constructor
template <class T>
Stack<T>::Stack(const Stack& other) : data()
{
	
}

// copy assignment operator
//template <class T>
//Stack<T>::Stack& operator= (const Stack& other)
//{
//	//if(this != &other)
//	
//}

template <class T>
void Stack<T>::Push(T var)
{

}

template <class T>
void Stack<T>::Pop(T var)
{

}

template <class T>
void Stack<T>::Print(T var)
{

}

template <class T>
Stack<T>::~Stack()
{
	delete[] data;
}
