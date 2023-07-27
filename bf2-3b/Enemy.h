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

	// �G�̃X�R�A
	int Score_g[3] = { 500, 1000, 750 };
	int Score_p[3] = { 750, 1500, 1000 };
	int Score_r[3] = { 1000, 2000, 1500 };

	int eSpeed[3] = { 1000, 2000, 1500 };

	int Lv;

	int PointFlg;
	int AnimFlg;
	float Count;
	int Counter;
	int AnimImg;

	// �X�^�[�g���̍��W
	int St_x;
	int St_y;

	// �p���V���[�g���̍��W
	int Pr_x;	
	int Pr_y;

	// ���S���̍��W
	int De_x;
	int De_y;

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

	void EnemyStart();
	void Parachute();
	void Death();

	static int EnemyScore[3];	// �G�̃X�R�A

	static int eBoxX, eBoxY, eBoxX2, eBoxY2;		// �G�̓����蔻��
	static int ebBoxX, ebBoxY, ebBoxX2, ebBoxY2;	// �G�̕��D�̓����蔻��
};
