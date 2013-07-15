#include "StdAfx.h"
#include "Input.h"



Input::Input(void)
{
	count=0;

	bufferSize = 600;
	buffer = new CircularBuffer(bufferSize);
}

Input::Input(int n)
{
	count=0;

	bufferSize = n;
	buffer = new CircularBuffer(bufferSize);
}


Input::~Input(void)
{	

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






///////////////////////////////////////////////////////////////////////////////////////////////////
Skeleton Input::getBuffer()
{
	return buffer->getBuffer((count-1)%bufferSize);
}

void Input::pushBuffer(Skeleton skeleton)
{
	buffer->addLast(skeleton);
	return;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////


//確認用
nite::Point3f Input::getPosition(int jointNumber, int time)
{
	nite::Point3f pos;

	if(jointNumber<0 || jointNumber >= 15 || time < 0 || time >= bufferSize){
		std::cout << "Input is wrong!!" << std::endl;
		pos.set(-1,-1,-1);
		return pos;
	}else{
		pos = buffer->getBuffer(time).getJointPosition(jointNumber);
		return pos;
	}
}

bool Input::isBufferFull()
{
	bool result;
	if(count>=bufferSize-1){
		std::cout << "Buffer is full!!" <<std::endl;
		result = true;
	}else{
		result = false;
	}
	return result;
}

void Input::drawJoint(int jointNumber, Skeleton skeleton)
{
	//if(jointNumber==0){
		//Skeleton skeleton = buffer->getBuffer(count%bufferSize);
		cv::Point center;
		center = skeleton.get2DPositon(userTracker, jointNumber);
		//std::cout << count << "::" <<center <<"\n";
		cv::circle( colorImage, center, 5, cv::Scalar( 0, 0, 255 ), 5 );
	//}

}

void Input::kinectGetSkeleton()
{
	Skeleton *skeleton = new Skeleton();
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
				//std::cout<< "mituketa"<<std::endl;
                for ( int j = 0; j <= 14; ++j ) {
                   const nite::SkeletonJoint& joint = skeelton.getJoint((nite::JointType)j);
                    if ( joint.getPositionConfidence() >= 0.7f ) {
                        nite::Point3f position = joint.getPosition();
						skeleton->setJointPosition(j, position);
						
						drawJoint(j, *skeleton);

                    }
                }
				
            }
		}
	}
	pushBuffer(*skeleton);
    //}
}




void Input::setColorImage()
{
	try{
		//clock_t  start, end;
		//start = clock();

       // while ( 1 ) {

			
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

				
				kinectGetSkeleton();

				//imwrite("img.jpeg", colorImage);
								
				count++;

				/*
				if(count>=bufferSize){
					std::cout<< "Buffer is full!!" << std::endl;
					count=0;
					//break;
					return;
				}
				
				int key = cv::waitKey( 10 );
                if ( key == 'q' ) {
                    break;
                }*/

				//break;
            }
			
       // }
		//end = clock();
		//std::cout<< "time:" << (end-start)/CLOCKS_PER_SEC <<std::endl;
			
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