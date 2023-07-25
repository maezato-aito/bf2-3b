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

	int Score_g[3] = { 500, 1000, 750 };
	int Score_p[3] = { 750, 1500, 1000 };
	int Score_r[3] = { 1000, 2000, 1500 };

	int PointFlg;
	int AnimFlg;
	float Count;
	int Counter;
	int AnimImg;

	

	// �G�̍\����
	struct ENEMY
	{
		int flg;			// �g�p�t���O
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

	static int EnemyScore[3];	// �G�̃X�R�A
	static int eBoxX, eBoxY, eBoxX2, eBoxY2;	// �G�̓����蔻��
};
