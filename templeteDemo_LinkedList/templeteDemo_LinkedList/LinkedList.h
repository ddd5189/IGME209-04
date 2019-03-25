#pragma once

#include "Node.h"

template<class T>
class LinkedList
{
public:
	LinkedList();
	~LinkedList();
	void Print();
	void Add(T newdata);
private:
	Node<T>* head;
	Node<T>* current;
	Node<T>* tail;
	int count;
};

template<class T>
LinkedList<T>::LinkedList()
{
	count = 0;
	head = current = tail = nullptr;
}

template<class T>
LinkedList<T>::~LinkedList()
{
	// should delete the data
}

template<class T>
void LinkedList<T>::Print()
{
	Node<T>* ptr = head;
	while (ptr != nullptr)
	{
		ptr->Print();
		ptr = ptr->next;
	}
}

template<class T>
void LinkedList<T>::Add(T newdata)
{
	Node<T>* newNode = new Node<T>(newdata);

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
	count++;
}
