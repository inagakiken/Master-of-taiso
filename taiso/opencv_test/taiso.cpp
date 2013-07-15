#include "Input.h"
#include "SkeletonPoser.h"
#include<time.h>


///////////////全てkinectから見た方向///////////////
static const int ABOVE  = 1;//上
static const int BELOW  = 2;//下
static const int LEFT   = 3;//左
static const int RIGHT  = 4;//右
static const int FRONT  = 5;//前
static const int BEHIND = 6;//後

static const int HEAD            = 0;//頭
static const int NECK            = 1;//首
static const int LEFT_SHOULDER   = 2;//左肩
static const int RIGHT_SHOULDER  = 3;//右肩
static const int LEFT_ELBOW      = 4;//左肘
static const int RIGHT_ELBOW     = 5;//右肘
static const int LEFT_HAND       = 6;//左手
static const int RIGHT_HAND      = 7;//右手
static const int TORSO           = 8;//胴
static const int LEFT_HIP        = 9;//左尻
static const int RIGHT_HIP       = 10;//右尻
static const int LEFT_KNEE       = 11;//左膝
static const int RIGHT_KNEE      = 12;//右膝
static const int LEFT_FOOT       = 13;//左足首
static const int RIGHT_FOOT      = 14;//右足首

void main()
{

	

	Skeleton skeleton;
	SkeletonPoser* handUp = new SkeletonPoser();
	handUp->addRule(LEFT_HAND, ABOVE, NECK);
	//handUp->addRule(RIGHT_HAND, ABOVE, HEAD);

	//引数はバッファーの数
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
			std::cout<< "ポーズ検出" << std::endl;
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
		std::cout << "関節番号とフレーム" <<std::endl;
		std::cin >> num1;
		std::cin >> num2;
		pos = input->getPosition(num1,num2);
		std::cout <<"("<< pos.x <<","<< pos.y <<","<< pos.z <<")"<< std::endl;
	}
	

	return;
}