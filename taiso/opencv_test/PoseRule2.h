#pragma once

#include "Skeleton.h"

//理想位置との比較を行うためのクラス
class PoseRule2
{
private:

	int jointNumber;
	
	//
	//　頭　　：0
	//　首　　：1
	//　左肩　：2
	//　右肩　：3
	//　左肘　：4
	//　右肘　：5
	//　左手　：6
	//　右手　：7
	//　胴　　：8
	//　左尻　：9
	//　右尻　：10
	//　左膝　：11
	//　右膝　：12
	//　左足首：13
	//　右足首：14
	//

	
	
	int jointRelation; //関節の位置関係によって以下の値をとる
	static const int ABOVE  = 1;//上
	static const int BELOW  = 2;//下
	static const int LEFT   = 3;//左
	static const int RIGHT  = 4;//右
	static const int FRONT  = 5;//前
	static const int BEHIND = 6;//後

public:
	PoseRule2(int tempJointNumber, int tempJointRelation);
	~PoseRule2(void);

	//キネクトから見て理想モデルに対してのユーザーの位置をチェック
	bool check(Skeleton user, Skeleton model);
};

