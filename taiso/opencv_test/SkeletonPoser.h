#pragma once

#include <vector>
#include <iostream>

#include "PoseRule.h"

class SkeletonPoser
{
private:
	std::vector<PoseRule> rules;

public:
	SkeletonPoser(void);
	~SkeletonPoser(void);

	void addRule(int fromJoint, int jointRelation, int toJoint);
	bool check(Skeleton skeleton);

};

