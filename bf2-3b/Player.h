#pragma once
#include "AbstractScene.h"

class Player : public AbstractScene
{
private:
	float playerX, playerY;
	int InputX = 0, InputY = 0;
	int Playerimg[30];
	int Image;
	float vx, vy;		//�x�N�g��
	float e;			// �����W��
public:

	int PlayerStus=0; //�n�ʂ̏�Ԃ�0�@�󒆂Ȃ�1�������

	float boxX=100, boxY=100, boxX2=boxX+50, boxY2=boxY+50;

	float Speed;
	int playerLR;
	// �R���X�g���N�^
	Player();
	// �f�X�g���N�^
	~Player();

	//�`��ȊO�̏���
	AbstractScene* Update()override;

	//�`�揈��
	void Draw() const override;
};