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

	//�v���C���[�R���W����
	int pBoxX;
	int pBoxY;
	int pBoxX2;
	int pBoxY2;

	//���D�R���W����
	int bBoxX;
	int bBoxY;
	int bBoxX2;
	int bBoxY2;

	float Gvy;
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