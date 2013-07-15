#pragma once

#include "Skeleton.h"

//�֐߈ʒu�ɂ�鑊�ΓI�Ȕ�r���s���N���X
class PoseRule
{
private:

	int fromJoint;
	int toJoint;
	//
	//�@���@�@�F0
	//�@��@�@�F1
	//�@�����@�F2
	//�@�E���@�F3
	//�@���I�@�F4
	//�@�E�I�@�F5
	//�@����@�F6
	//�@�E��@�F7
	//�@���@�@�F8
	//�@���K�@�F9
	//�@�E�K�@�F10
	//�@���G�@�F11
	//�@�E�G�@�F12
	//�@������F13
	//�@�E����F14
	//

	
	
	int jointRelation; //�֐߂̈ʒu�֌W�ɂ���Ĉȉ��̒l���Ƃ�
	static const int ABOVE  = 1;//��
	static const int BELOW  = 2;//��
	static const int LEFT   = 3;//��
	static const int RIGHT  = 4;//�E
	static const int FRONT  = 5;//�O
	static const int BEHIND = 6;//��

public:
	//PoseRule(void);
	PoseRule(int tempFromJoint, int tempJointRelation, int tempToJoint);
	~PoseRule(void);

	bool check(Skeleton skeleton);
};

