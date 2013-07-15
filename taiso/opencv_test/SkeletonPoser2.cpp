#include "StdAfx.h"
#include "SkeletonPoser2.h"


SkeletonPoser2::SkeletonPoser2(void)
{
}



SkeletonPoser2::~SkeletonPoser2(void)
{
}


void SkeletonPoser2::addRule(int jointNumber, int jointRelation)
{
	PoseRule2* rule = new PoseRule2(jointNumber, jointRelation);
	rules.push_back(*rule);
}


bool SkeletonPoser2::check(Skeleton user, Skeleton model)
{
	bool result = true;
	for(int i = 0; i < rules.size(); i++){
		PoseRule2 rule = rules.at(i);
		result = (result && rule.check(user, model));

	}
	return result;
}