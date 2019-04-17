#include "Memory.h"
#include <iostream>

struct header
{
	short nextFree = 0;
	short nextAllocated = 0;
	char padding[2];
};
struct itemheader
{
	short size = 0;
	short next = 0;
	char deleted = 0;
	char padding[1];
};

Memory::Memory()
{
}


Memory::~Memory()
{
}


void Memory::Init()
{
	cout << __FUNCTION__ << endl;
	lock_guard<recursive_mutex> lock(george);

	data = new char[64 * 1024];
	freeMemory = 64 * 1024;
	for (size_t i = 0; i < freeMemory; i++)
	{
		data[i] = -2;
	}

	// make a header
	// put it at data[0]
	// adjust the header info
	header* head = reinterpret_cast<header*>(data);
	head->nextFree = sizeof(header);
	head->nextAllocated = 0;
	freeMemory -= sizeof(header);
}

int Memory::GetFreeMemory()
{
	cout << __FUNCTION__ << endl;
	return freeMemory;
}
void Memory::Release()
{
	cout << __FUNCTION__ << endl;
	lock_guard<recursive_mutex> lock(george);

	delete[] data;
	data = nullptr;
	freeMemory = 0;
}

void* Memory::Allocate(int size)
{
	cout << __FUNCTION__ << endl;
	lock_guard<recursive_mutex> lock(george);

	if (data == nullptr)
	{
		Init();
	}

	// check if we might have enough memory
	if ((size + sizeof(itemheader)) > freeMemory)
		return nullptr;

	// check if we have a free block big enough


	// normal add a new item and adding first item
	header* head = (header*)data;
	itemheader* item = (itemheader*)&(data[head->nextFree]);
	if (head->nextAllocated == 0)
		head->nextAllocated = ((char*)item) - data;
	else
	{
		itemheader* currentHeader = (itemheader*) & (data[head->nextAllocated]);;
		while (currentHeader->next != 0)
		{
			currentHeader = (itemheader*) & (data[currentHeader->next]);
		}
		currentHeader->next = ((char*)item) - data;
	}
	item->size = size;
	item->deleted = 0;
	freeMemory -= (size+sizeof(itemheader));


	// return the address
	return (item + sizeof(itemheader));
}

void Memory::Delete(void* mem)
{
	cout << __FUNCTION__ << endl;
	lock_guard<recursive_mutex> lock(george);

	// get the item header
	itemheader* item = ((itemheader*)mem)-1;
	// set it to deleted
	item->deleted = true;
	// remove block from allocated list

	// add block to free list
	// defrag memory - neighbors
}



