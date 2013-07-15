#pragma once

#include "Skeleton.h"
#include "CircularBuffer.h"
#include <opencv2\opencv.hpp>
#include <NiTE.h>
#include <string>
#include <vector>
#include <iostream>


class InputBase
{
public:
	InputBase(void);
	~InputBase(void);
	virtual nite::Point3f getPosition(int jointNumber, int time)=0;
};

