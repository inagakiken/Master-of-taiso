/*

#pragma once
#include "inputbase.h"
#include "Skeleton.h"
#include "CircularBuffer.h"
#include <vector>
#include <iostream>

class Input :
	public InputBase
{
private:
	Skeleton **buffer;
	int bufferSize;
	int count;
	cv::Mat colorImage;

	openni::VideoFrameRef colorFrame;
	openni::VideoStream colorStream;
	std::vector<openni::VideoStream*> streams;
	nite::UserTracker userTracker;

public:
	Input(void);
	Input(int n);
	~Input(void);

	Skeleton getBuffer();
	void initialize();
	void pushBuffer();
	void setColorImage();
	cv::Mat getColorImage();
	nite::Point3f getPosition(int jointNumber, int time);

	void viewImage();
};

#include "StdAfx.h"
#include "Input.h"
#include "Skeleton.h"
#include "CircularBuffer.h"
#include <vector>
#include <iostream>
//#include   <time.h>


Input::Input(void)
{
	count=0;

	bufferSize = 600;
	buffer = new Skeleton*[bufferSize];
	for(int i=0 ; i<bufferSize ; i++){
		buffer[i] = new Skeleton();
	}
}

Input::Input(int n)
{
	count=0;

	bufferSize = n;
	buffer = new Skeleton*[bufferSize];
	for(int i=0 ; i<bufferSize ; i++){
		buffer[i] = new Skeleton();
	}
}

void Input::initialize()
{
	openni::OpenNI::initialize();

    openni::Device device;
    auto ret = device.open( openni::ANY_DEVICE );
    if ( ret != openni::STATUS_OK ) {
        throw std::runtime_error( "" );
    }

	nite::Status niteRet = nite::NiTE::initialize();

    
    niteRet = userTracker.create();
    if ( niteRet != nite::STATUS_OK ) {
        throw std::runtime_error( "userTracker.create" );
    }

    
    colorStream.create( device, openni::SensorType::SENSOR_COLOR );
    colorStream.start();
	
	
    streams.push_back( &colorStream );
}



Input::~Input(void)
{	

}

Skeleton Input::getBuffer()
{
	return *buffer[count-1];
}


nite::Point3f Input::getPosition(int jointNumber, int time)
{
	nite::Point3f pos;

	if(jointNumber<0 || jointNumber >= 15 || time < 0 || time >= bufferSize){
		std::cout << "Input is wrong!!" << std::endl;
		pos.set(-1,-1,-1);
		return pos;
	}else{
		pos = buffer[time]->getJointPosition(jointNumber);
		return pos;
	}
}



void drawJoint(cv::Mat& colorImage, nite::UserTracker& userTracker, Skeleton skeleton, int count, int jointNumber)
{
	//if(jointNumber==0){
		cv::Point center;
		center = skeleton.get2DPositon(userTracker, jointNumber);
		//std::cout << count << "::" <<center <<"\n";
		cv::circle( colorImage, center, 5, cv::Scalar( 0, 0, 255 ), 5 );
	//}

}

void kinectGetSkeleton(cv::Mat& colorImage, nite::UserTracker& userTracker, nite::UserTrackerFrameRef& userFrame,
					Skeleton& skeleton, int count)
{
	const nite::Array<nite::UserData>& users = userFrame.getUsers();
    //for ( int i = 0; i < users.getSize(); ++i ) { //ユーザーは一人限定とする
	if(users.getSize() > 0){
        const nite::UserData& user = users[0];
        if ( user.isNew() ) {
            userTracker.startSkeletonTracking( user.getId() );
        }
        else if ( !user.isLost() ) {
			const nite::Skeleton& skeelton = user.getSkeleton();
            if ( skeelton.getState() == nite::SkeletonState::SKELETON_TRACKED ) {
                for ( int j = 0; j <= 14; ++j ) {
                   const nite::SkeletonJoint& joint = skeelton.getJoint((nite::JointType)j);
                    if ( joint.getPositionConfidence() >= 0.7f ) {
                        nite::Point3f position = joint.getPosition();
						skeleton.setJointPosition(j, position);
						
						drawJoint(colorImage, userTracker, skeleton, count, j);

                    }
                }
            }
		}
	}
    //}
}


///////////////使用してない
///////////////////////////////////////////////////////////////////////////////////////////////////
void Input::pushBuffer()
{
	try{
		//clock_t  start, end;
		//start = clock();

        while ( 1 ) {

			nite::UserTrackerFrameRef userFrame;
            userTracker.readFrame( &userFrame );
            

            int changedIndex;
            openni::OpenNI::waitForAnyStream( &streams[0], streams.size(), &changedIndex );
            if ( changedIndex == 0 ) {
                openni::VideoFrameRef colorFrame;
                colorStream.readFrame( &colorFrame );
                if ( colorFrame.isValid() ) {
                    colorImage = cv::Mat( colorStream.getVideoMode().getResolutionY(),
                                          colorStream.getVideoMode().getResolutionX(),
                                          CV_8UC3, (char*)colorFrame.getData() );
                }

                cv::cvtColor( colorImage, colorImage, CV_BGR2RGB );

				
				kinectGetSkeleton(colorImage, userTracker, userFrame, *buffer[count], count);

				
                cv::imshow( "Color Camera", colorImage );

				count++;
				if(count==bufferSize){
					std::cout<< "Buffer is full!!" << std::endl;
					count=1;
					break;
					
				}

                int key = cv::waitKey( 10 );
                if ( key == 'q' ) {
                    break;
                }
            }
        }
		//end = clock();
		//std::cout<< "time:" << (end-start)/CLOCKS_PER_SEC <<std::endl;

    }
    catch ( std::exception& ) {
        std::cout << openni::OpenNI::getExtendedError() << std::endl;
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void Input::setColorImage()
{
	try{
		//clock_t  start, end;
		//start = clock();

       // while ( 1 ) {

			nite::UserTrackerFrameRef userFrame;
            userTracker.readFrame( &userFrame );
            

            int changedIndex;
            openni::OpenNI::waitForAnyStream( &streams[0], streams.size(), &changedIndex );
            if ( changedIndex == 0 ) {
                colorStream.readFrame( &colorFrame );
                if ( colorFrame.isValid() ) {
                    colorImage = cv::Mat( colorStream.getVideoMode().getResolutionY(),
                                          colorStream.getVideoMode().getResolutionX(),
                                          CV_8UC3, (char*)colorFrame.getData() );
                }

                cv::cvtColor( colorImage, colorImage, CV_BGR2RGB );

				
				kinectGetSkeleton(colorImage, userTracker, userFrame, *buffer[count], count);

				//imwrite("img.jpeg", colorImage);
								
				count++;
				if(count>=bufferSize){
					std::cout<< "Buffer is full!!" << std::endl;
					count=0;
					//break;
					return;
				}
				/*
				int key = cv::waitKey( 10 );
                if ( key == 'q' ) {
                    break;
                }*/

				//break;
           // }
			
       // }
		//end = clock();
		//std::cout<< "time:" << (end-start)/CLOCKS_PER_SEC <<std::endl;
	/*		
    }
    catch ( std::exception& ) {
        std::cout << openni::OpenNI::getExtendedError() << std::endl;
    }
}

cv::Mat Input::getColorImage()
{
	return colorImage;
}

void Input::viewImage()
{
	cv::imshow( "Color Camera", colorImage );
	int key = cv::waitKey( 10 );
}
*/