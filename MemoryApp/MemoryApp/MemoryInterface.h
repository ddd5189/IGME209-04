#pragma once

class IMemory
{
public:
	virtual void Init() = 0;
	virtual int GetFreeMemory() = 0;
	virtual	void Release() = 0;
	virtual void* Allocate(int size) = 0;
	virtual void Delete(void* size) = 0;

};