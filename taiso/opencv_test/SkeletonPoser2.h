#pragma once

#include <vector>
#include <iostream>

#include "PoseRule2.h"

class SkeletonPoser2
{
private:
	std::vector<PoseRule2> rules;

public:
	SkeletonPoser2(void);
	~SkeletonPoser2(void);

	void addRule(int jointNumber, int jointRelation);
	bool check(Skeleton user, Skeleton model);

};

