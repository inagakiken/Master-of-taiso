#include "StdAfx.h"
#include "PoseRule2.h"


//PoseRule::PoseRule(void)
//{
//}

PoseRule2::PoseRule2(int tempJointNumber, int tempJointRelation)
{
	jointNumber = tempJointNumber;
	jointRelation = tempJointRelation;

}


PoseRule2::~PoseRule2(void)
{
}



//キネクトから見て理想モデルに対してのユーザーの位置をチェック
bool PoseRule2::check(Skeleton user, Skeleton model)
{
	nite::Point3f userPos;
	nite::Point3f modelPos;

	userPos = user.getJointPosition(jointNumber);
	modelPos = model.getJointPosition(jointNumber);

	bool result = false;

	switch(jointRelation){
		case ABOVE:
			result = (userPos.y > modelPos.y);
			break;
		case BELOW:
			result = (userPos.y < modelPos.y);
			break;
		case LEFT:
			result = (userPos.x < modelPos.x);
			break;
		case RIGHT:
			result = (userPos.x > modelPos.x);
			break;
		case FRONT:
			result = (userPos.z < modelPos.z);
			break;
		case BEHIND:
			result = (userPos.z > modelPos.z);
			break;
	}

	return result;

}