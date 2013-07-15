#pragma once

#include "Skeleton.h"

//���z�ʒu�Ƃ̔�r���s�����߂̃N���X
class PoseRule2
{
private:

	int jointNumber;
	
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
	PoseRule2(int tempJointNumber, int tempJointRelation);
	~PoseRule2(void);

	//�L�l�N�g���猩�ė��z���f���ɑ΂��Ẵ��[�U�[�̈ʒu���`�F�b�N
	bool check(Skeleton user, Skeleton model);
};

