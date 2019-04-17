#pragma once
#include "MemoryInterface.h"
#include <thread>
#include <mutex>
using namespace std;
class Memory :
	public IMemory
{
private:
	char* data=nullptr;
	int freeMemory=0;
	recursive_mutex george;
public:
	Memory();
	~Memory();

	virtual void Init();
	virtual int GetFreeMemory();
	virtual	void Release();
	virtual void* Allocate(int size);
	virtual void Delete(void* size);
};



