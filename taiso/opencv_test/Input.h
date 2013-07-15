#pragma once
#include "inputbase.h"


class Input :
	public InputBase
{
private:
	CircularBuffer* buffer;
	int bufferSize;
	int count;

	cv::Mat colorImage;

	openni::VideoFrameRef colorFrame;
	openni::VideoStream colorStream;
	std::vector<openni::VideoStream*> streams;
	nite::UserTrackerFrameRef userFrame;
	nite::UserTracker userTracker;

public:
	Input(void);
	Input(int n);
	~Input(void);

	Skeleton getBuffer();
	void pushBuffer(Skeleton skeleton);
	void initialize();
	
	bool isBufferFull();
	void setColorImage();
	cv::Mat getColorImage();
	nite::Point3f getPosition(int jointNumber, int time);

	void drawJoint(int jointNumber, Skeleton skeleton);
	void kinectGetSkeleton();
	void viewImage();
};

