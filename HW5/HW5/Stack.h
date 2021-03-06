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
	Stack(const Stack& other, int size);
	//copy aassignment operator
	Stack<T>& operator= (const Stack& other); 
	//because I created the stack using nodes, this isn't necessary 
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
};


template <class T>
Stack<T>::Stack()
{
	count = 0;
	head = nullptr;
}

//copy constructor
template <class T>
Stack<T>::Stack(const Stack& other, int size)
{
	head = other.head;
	count = size;
}

// copy assignment operator
template <class T>
Stack<T>& Stack<T>::operator= (const Stack& other)
{
	if (this != &other)
	{
		head = other.head;
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
	//create a new node to add the data
	Node<T>* newNode = new Node<T>(var);
	count++;
	//if there is no data set this to the head 
	if (head == nullptr)
	{
		head = newNode;
	}
	//if there is data set the next of the newNode to head and make the newNode the head
	else
	{
		newNode->SetNext(head);
		head = newNode;
	}
}

template <class T>
void Stack<T>::Pop()
{
	//create a new null node
	Node<T>* newNode = nullptr;
	count--;
	//if head is not null
	if (head != nullptr)
	{
		//set new node to head
		newNode = head;
		//if count is greater than 0 which means there is data in the stack
		if (count > 0)
		{
			//set head to it's next node
			head = head->next;
		}
		else
		{
			//if count is not greater than 0 which means there is no data in the stack
			head = nullptr;
		}

	}
	//print the data of the popped node
	newNode->PrintPopped();
}

template <class T>
void Stack<T>::Print()
{
	//create a pointer to the head
	Node<T>* ptr = head;
	//if head is null, print there is nothing to print
	if (ptr == nullptr)
	{
		cout << "There is nothing to print" << endl;
	}
	else 
	{
		//while head is not null
		while (ptr != nullptr)
		{
			//print the data using the Node print method, and then set the ptr to the next node to print that out
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
	delete head;
}
