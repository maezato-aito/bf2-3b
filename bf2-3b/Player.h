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

	int PlayerFlg=0; //�n�ʂ̏�Ԃ�0�@�󒆂Ȃ�1�������

	//�v���C���[�R���W����
	static int pBoxX;
	static int pBoxY;
	static int pBoxX2;
	static int pBoxY2;

	//���D�R���W����
	static int bBoxX;
	static int bBoxY;
	static int bBoxX2;
	static int bBoxY2;

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