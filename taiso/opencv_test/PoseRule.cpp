#include "StdAfx.h"
#include "PoseRule.h"


//PoseRule::PoseRule(void)
//{
//}

PoseRule::PoseRule(int tempFromJoint, int tempJointRelation, int tempToJoint)
{
	jointRelation = tempJointRelation;
	fromJoint = tempFromJoint;
	toJoint = tempToJoint;
}


PoseRule::~PoseRule(void)
{
}

bool PoseRule::check(Skeleton skeleton)
{
	nite::Point3f fromPos;
	nite::Point3f toPos;

	fromPos = skeleton.getJointPosition(fromJoint);
	toPos = skeleton.getJointPosition(toJoint);

	bool result = false;

	switch(jointRelation){
		case ABOVE:
			result = (fromPos.y > toPos.y);
			break;
		case BELOW:
			result = (fromPos.y < toPos.y);
			break;
		case LEFT:
			result = (fromPos.x < toPos.x);
			break;
		case RIGHT:
			result = (fromPos.x > toPos.x);
			break;
		case FRONT:
			result = (fromPos.z < toPos.z);
			break;
		case BEHIND:
			result = (fromPos.z > toPos.z);
			break;
	}

	return result;

}