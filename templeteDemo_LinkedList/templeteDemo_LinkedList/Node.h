#pragma once

template<class T>
class Node
{
public:
	Node(T data);
	~Node();
	void Print();
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
}

template<class T>
void Node<T>::Print()
{
	cout << "Data is: " << _data << endl;
}

template<class T>
void Node<T>::SetNext(Node<T>* n)
{
	next = n;
}
