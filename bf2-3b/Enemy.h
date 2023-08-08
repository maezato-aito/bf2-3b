#pragma once
#include "AbstractScene.h"

class Enemy
{
private:
	int EnemyG_img[18];
	int EnemyP_img[18];
	int EnemyR_img[18];

	int InputX, InputY;
	float SpeedX, SpeedY;
	int Gvy;

	int eSpeed[3] = { 1000, 2000, 1500 };

	int EnemyPScore[3] = { 500, 1000, 750 };	// �G�̃X�R�A
	int EnemyGScore[3] = { 750, 1500, 1000 };	// �G�̃X�R�A
	int EnemyRScore[3] = { 1000, 2000, 1500 };	// �G�̃X�R�A

	int Lv;

	int PointFlg;
	int AnimFlg;
	float Count;
	int Counter;
	int AnimImg;

	
	// �G�̍\����
	struct ENEMY
	{
		int flg;			// �g�p�t���O �i 0:�\���Ȃ��@1:�����@2:���V�@3:�p���V���[�g�@4:���S �j
		int type;			// �^�C�v
		int img;			// �摜
		float x, y, w, h;	// ���W�A���A����
		float speed;		// ���x
		int score;			// �X�R�A���Z�|�C���g
	};
	struct ENEMY enemy[3];

public:
	// �R���X�g���N�^
	Enemy();
	// �f�X�g���N�^
	~Enemy();
	//�`��ȊO�̏���
	void Update();
	//�`�揈��
	void Draw() const;

	void EnemyStart();	// ������ԏ���
	void Parachute();	// �p���V���[�g����
	void Death();		// ���S����

	static int St_x, St_y;	// �X�^�[�g���̍��W
	static int Pr_x, Pr_y;	// �p���V���[�g���̍��W
	static int De_x, De_y;	// ���S���̍��W

	static int eBoxX, eBoxY, eBoxX2, eBoxY2;		// �G�̓����蔻��
	static int ebBoxX, ebBoxY, ebBoxX2, ebBoxY2;	// �G�̕��D�̓����蔻��

	static int Score;
};
