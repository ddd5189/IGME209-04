#pragma once
#include "MemoryInterface.h"
class Memory :
	public IMemory
{
private:
	char* data=nullptr;
	int freeMemory=0;
public:
	Memory();
	~Memory();

	virtual void Init();
	virtual int GetFreeMemory();
	virtual	void Release();
	virtual void* Allocate(int size);
	virtual void Delete(void* size);
};



