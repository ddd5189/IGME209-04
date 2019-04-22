#pragma once
#include <iostream>
#include "Node.h"
using namespace std;
template <class T>
class Stack
{
public:
	Stack();
	//copy constructor
	Stack(const Stack& other);
	//copy aassignment operator
	Stack<T>& operator= (const Stack& other); 
	//because I craeted the stack using nodes, this isn't necessary 
	//friend ostream& operator<<(ostream& ostr, Test const& rhs);
	void Push(T);
	void Pop();
	void Print();
	int GetSize();
	bool IsEmpty();
	~Stack();

private:
	int count;
	Node<T>* head;
	Node<T>* current;
	Node<T>* tail;
};


template <class T>
Stack<T>::Stack()
{
	count = 0;
	head = current = tail = nullptr;
}

//copy constructor
template <class T>
Stack<T>::Stack(const Stack& other)
{
	head = other.head;
	current = other.current;
	tail = other.tail;
}

// copy assignment operator
template <class T>
Stack<T>& Stack<T>::operator= (const Stack& other)
{
	if (this != &other)
	{
		head = other.head;
		current = other.current;
		tail = other.tail;
	}
	return *this;
}

//this wasn't working trying to implement it
/*
template <class T>
ostream& Stack<T>::operator<< (ostream& ostr, Test const& rhs)
{

}
*/

template <class T>
void Stack<T>::Push(T var)
{
	Node<T>* newNode = new Node<T>(var);
	count++;
	if (head == nullptr)
	{
		head = newNode;
		current = head;
	}
	else
	{
		tail->SetNext(newNode);
	}
	tail = newNode;
}

template <class T>
void Stack<T>::Pop()
{
	Node<T>* newNode = nullptr;
	count--;
	if (head != nullptr)
	{
		newNode = head;
		if (tail != nullptr)
		{
			head = head->next;
		}
		else
		{
			head = nullptr;
		}

	}

	newNode->PrintPopped();
}

template <class T>
void Stack<T>::Print()
{
	Node<T>* ptr = head;
	if (ptr == nullptr)
	{
		cout << "There is nothing to print" << endl;
	}
	else 
	{
		while (ptr != nullptr)
		{
			ptr->Print();
			ptr = ptr->next;
		}
	}
}

template <class T>
int Stack<T>::GetSize()
{
	return count;
}

template <class T>
bool Stack<T>::IsEmpty()
{
	if (count == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template <class T>
Stack<T>::~Stack()
{
	//delete newNode;
}
