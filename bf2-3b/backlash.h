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
	int HitBox;
	int x1, y1,x2,y2;
public:
	int Left, Right, North, South;
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
