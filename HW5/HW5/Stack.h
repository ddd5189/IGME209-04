#pragma once
template <class T>
class Stack
{
public:
	Stack();
	void Push(T);
	void Pop(T);
	void Print(T);
	~Stack();
};

template <class T>
Stack<T>::Stack()
{

}

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
