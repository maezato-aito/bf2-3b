#pragma once

#include"Backlash.h"
#include"PadInput.h"
#include"Player.h"

class Backlash
{
private:
	int Speed;
	int BallAngle;
	int MoveX;
	int	MoveY;

public:

	// �R���X�g���N�^
	Backlash();
	// �f�X�g���N�^
	~Backlash();

	//�`��ȊO�̏���
	void Update();

	//�`�揈��
	void Draw();
	Player* player;
};
