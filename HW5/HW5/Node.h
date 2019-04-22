#pragma once
#include <iostream>
using namespace std;
template<class T>
class Node
{
public:
	Node(T data);
	~Node();
	void Print();
	void PrintPopped();
	void SetNext(Node<T>* n);
	Node<T>* next;
private:
	T _data;
};

template<class T>
Node<T>::Node(T data)
{
	_data = data;
	next = nullptr;
}

template<class T>
Node<T>::~Node()
{
	delete next;
}

template<class T>
void Node<T>::Print()
{
	cout << "Data: " << _data << endl;
}

template<class T>
void Node<T>::PrintPopped()
{
	cout << "Popped: " << _data << endl;
}

template<class T>
void Node<T>::SetNext(Node<T>* n)
{
	next = n;
}


