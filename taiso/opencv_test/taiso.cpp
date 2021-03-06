#include "Input.h"
#include "SkeletonPoser.h"
#include<time.h>


///////////////SΔkinect©η©½ϋό///////////////
static const int ABOVE  = 1;//γ
static const int BELOW  = 2;//Ί
static const int LEFT   = 3;//Ά
static const int RIGHT  = 4;//E
static const int FRONT  = 5;//O
static const int BEHIND = 6;//γ

static const int HEAD            = 0;//ͺ
static const int NECK            = 1;//ρ
static const int LEFT_SHOULDER   = 2;//Ά¨
static const int RIGHT_SHOULDER  = 3;//E¨
static const int LEFT_ELBOW      = 4;//ΆI
static const int RIGHT_ELBOW     = 5;//EI
static const int LEFT_HAND       = 6;//Άθ
static const int RIGHT_HAND      = 7;//Eθ
static const int TORSO           = 8;//·
static const int LEFT_HIP        = 9;//ΆK
static const int RIGHT_HIP       = 10;//EK
static const int LEFT_KNEE       = 11;//ΆG
static const int RIGHT_KNEE      = 12;//EG
static const int LEFT_FOOT       = 13;//Ά«ρ
static const int RIGHT_FOOT      = 14;//E«ρ

void main()
{

	

	Skeleton skeleton;
	SkeletonPoser* handUp = new SkeletonPoser();
	handUp->addRule(LEFT_HAND, ABOVE, NECK);
	//handUp->addRule(RIGHT_HAND, ABOVE, HEAD);

	//ψΝobt@[Μ
	Input* input = new Input(5400);

	input->initialize();

	//cv::Mat image;
	//cv::namedWindow("window", CV_WINDOW_AUTOSIZE);

	clock_t  start, end;
	start = clock();

	while(1){
		//image = (input->getColorImage());
		input->setColorImage();
		
		input->viewImage();

		skeleton = input->getBuffer();

		//int key = cv::waitKey( 10 );

		if(handUp->check(skeleton)){
			std::cout<< "|[Yo" << std::endl;
			//break;
		}
		if(input->isBufferFull()) break;

		/*
		//imwrite("img.jpeg", image);
		//image = cv::imread("img.jpeg", 1);
		
		cv::imshow( "window", image);
		//std::cout<< "empty:" << (image.empty()?"true":"false") << std::endl;
		
		int key = cv::waitKey( 10 );
        if ( key == 'q' ) {
            break;
        }
		*/
		
	}
	end = clock();
	std::cout<< "time:" << (end-start)/CLOCKS_PER_SEC <<std::endl;
	
	int num1=-1, num2=-1;
	nite::Point3f pos;

	while(1){
		std::cout << "ΦίΤΖt[" <<std::endl;
		std::cin >> num1;
		std::cin >> num2;
		pos = input->getPosition(num1,num2);
		std::cout <<"("<< pos.x <<","<< pos.y <<","<< pos.z <<")"<< std::endl;
	}
	

	return;
}