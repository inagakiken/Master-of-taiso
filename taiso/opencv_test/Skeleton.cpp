#include "StdAfx.h"
#include "Skeleton.h"
#include <NiTE.h>
#include <opencv2\opencv.hpp>


Skeleton::Skeleton(void)
{
	for(int i=0 ; i<15 ; i++ )
		jointPosition[i].set(-1,-1,-1);
}

Skeleton::~Skeleton(void)
{
}

void Skeleton::setJointPosition(int jointNumber, nite::Point3f pos)
{
	/*
	float x,y,z;
	x = pos.x;
	y = pos.y;
	z = pos.z; 
	*/
 	jointPosition[jointNumber]=pos;
	return;
}

nite::Point3f Skeleton::getJointPosition(int jointNumber)
{
	return jointPosition[jointNumber];
}

//画面表示用の座標変換（※左上が(0,0)）
cv::Point Skeleton::get2DPositon(nite::UserTracker& userTracker, int jointNumber)
{
	float x=0, y=0;
	userTracker.convertJointCoordinatesToDepth(jointPosition[jointNumber].x, jointPosition[jointNumber].y, jointPosition[jointNumber].z, &x, &y);
	cv::Point center;
	center = cvPoint((int)x,(int)y);
	return center;
}



