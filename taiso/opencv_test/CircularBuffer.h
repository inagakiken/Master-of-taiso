#pragma once

#include "Skeleton.h"

class CircularBuffer
{
private:
	Skeleton** data;
	int top, bottom;
	int size,length;

public:
	CircularBuffer(void);
	~CircularBuffer(void);
	CircularBuffer(int i);

	void setBuffer(Skeleton skeleton, int i);
	Skeleton getBuffer(int i);

	void addFirst(Skeleton skeleton);
	void addLast(Skeleton skeleton);
	void deleteFirst();
	void deleteLast();

};

