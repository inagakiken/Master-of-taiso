#include "StdAfx.h"
#include "SkeletonPoser.h"


SkeletonPoser::SkeletonPoser(void)
{
}



SkeletonPoser::~SkeletonPoser(void)
{
}


void SkeletonPoser::addRule(int fromJoint, int jointRelation, int toJoint)
{
	PoseRule* rule = new PoseRule(fromJoint, jointRelation, toJoint);
	rules.push_back(*rule);
}


bool SkeletonPoser::check(Skeleton skeleton)
{
	bool result = true;
	for(int i = 0; i < rules.size(); i++){
		PoseRule rule = rules.at(i);
		result = (result && rule.check(skeleton));

	}
	return result;
}