#pragma once
#include <NiTE.h>
#include <opencv2\opencv.hpp>


class Skeleton
{
private:
	nite::Point3f jointPosition[15];

public:
	
	Skeleton(void);
	~Skeleton(void);
	
	void setJointPosition(int jointNumber, nite::Point3f pos);
	nite::Point3f getJointPosition(int jointNumber);
	cv::Point get2DPositon(nite::UserTracker& userTracker, int jointNumber);
};

