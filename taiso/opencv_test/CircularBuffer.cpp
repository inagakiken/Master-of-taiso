#include "StdAfx.h"
#include "CircularBuffer.h"


CircularBuffer::CircularBuffer(void)
{
	size = 1000;
	data = new Skeleton*[size];
	for(int j=0 ; j<size ; j++){
		data[j] = new Skeleton();
	}
	top = bottom = length = 0;
}


CircularBuffer::~CircularBuffer(void)
{
}


CircularBuffer::CircularBuffer(int i)
{
	size = i;
	data = new Skeleton*[size];
	for(int j=0 ; j<size ; j++){
		data[j] = new Skeleton();
	}
	top = bottom = length = 0;
}


void CircularBuffer::setBuffer(Skeleton skeleton, int i)
{
	*data[top+i] = skeleton;
}

Skeleton CircularBuffer::getBuffer(int i)
{
	return *data[top+i];
}

void CircularBuffer::addFirst(Skeleton skeleton)
{
	if(length==size){
		std::cout << "Buffer is full!!" <<std::endl; 
		return;
	}

	if(length!=0){
		if(top!=0){
			top = top-1;
		}else{
			top = size-1;
		}
	}

	length++;
		
	*data[top] = skeleton;
}

void CircularBuffer::addLast(Skeleton skeleton)
{
	if(length==size){
		std::cout << "Buffer is full!!" <<std::endl; 
		return;
	}

	if(length!=0){
		if(bottom!=size-1){
			bottom = bottom+1;
		}else{
			bottom = 0;
		}
	}

	length++;
		
	*data[bottom] = skeleton;
}

void CircularBuffer::deleteFirst()
{
	if(length==0){
		std::cout << "Buffer is empty!!" <<std::endl; 
		return;
	}

	if(top!=size-1){
		top = top+1;
	}else{
		top = 0;
	}

	length--;
}

void CircularBuffer::deleteLast()
{
	if(length==0){
		std::cout << "Buffer is empty!!" <<std::endl; 
		return;
	}

	if(bottom!=0){
		bottom = bottom-1;
	}else{
		bottom = size-1;
	}

	length--;
}