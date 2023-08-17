#pragma once
#include "AbstractScene.h"

class Player : public AbstractScene
{
private:
	
	int InputX = 0, InputY = 0;
	int Playerimg[30];
	int Image;
	int BGM;
	float vx, vy;		//�x�N�g��
	float e;			// �����W��
	int eBoxX, eBoxY, eBoxX2, eBoxY2; //�G�̔���
	int ebBoxX, ebBoxY, ebBoxX2, ebBoxY2; //�G�̕��D�̔���
	int fall;
	int AnimCount;
	int add;
	int fBoxY;
	int death;
	float a;

	int Count;
public:
	static float playerX, playerY;
	static int Time; // �ҋ@����
	
	static int Life;	// �c�@
	static int PlayerFlg; //�n�ʂ̏�Ԃ�0�@�󒆂Ȃ�1�������
	int HitFlg = 0;	//���ɐG��Ă�����0 �G��Ă��Ȃ�������P
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
	int gCount;
	int buttonC;

	float UpNum;
	int UpFlg;

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

	void backlash();

	void life();

	void balloon();
};