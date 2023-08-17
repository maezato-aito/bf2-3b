#pragma once
#include "AbstractScene.h"
#include "fish.h"

class Enemy
{
private:
	int EnemyG_img[18];
	int EnemyP_img[18];
	int EnemyR_img[18];

	int InputX = 0, InputY = 0;
	float Speed, SpeedY;
	float Gvy;
	float MoveX;

	float eSpeed[3] = { 0.3, 0.6, 0.9 };		// �G�̃X�s�[�h
	float eSpeed2[3] = { 1.0, 1.5, 2.0 };		// �G�̃X�s�[�h�i����j

	int EnemyPScore[3] = { 500, 1000, 750 };	// �G�̃X�R�A
	int EnemyGScore[3] = { 750, 1500, 1000 };	// �G�̃X�R�A
	int EnemyRScore[3] = { 1000, 2000, 1500 };	// �G�̃X�R�A

	
	int PointFlg;	// �|�C���g�t���O
	int AnimFlg;	// �A�j���[�V�����t���O
	float Count;
	int Counter;
	int AnimImg;	// �A�j���[�V�����摜�p
	float AnimCount;
	int EnemyLR;
	int rand;		// �����p
	int e;			// �����W��
	int HitFlg;
	int vx, vy;
	float UpNum;
	int UpFlg;
	int Time;

	// �G�̍\����
	static struct ENEMY
	{
		int flg;			// �g�p�t���O �i 0:�\���Ȃ��@1:�����@2:���V�@3:�p���V���[�g�@4:���S �j
		int type;			// �^�C�v
		int img;			// �摜
		float x, y, w, h;	// ���W�A���A����
		float speed;		// ���x
		int score;			// �X�R�A���Z�|�C���g
	};
	struct ENEMY enemy[3];
	
	Fish* fish;

public:
	static int Lv;

	static int enemyFlg;
	// �R���X�g���N�^
	Enemy();
	// �f�X�g���N�^
	~Enemy();
	//�`��ȊO�̏���
	void Update();
	//�`�揈��
	void Draw() const;

	void EnemyInit();	// �G����������
	void EnemyStart();	// ������ԏ���
	void Parachute();	// �p���V���[�g����
	void Death();		// ���S����
	void Backlash();	// ��������

	static int St_x, St_y;	// �X�^�[�g���̍��W
	static int Pr_x, Pr_y;	// �p���V���[�g���̍��W
	static int De_x, De_y;	// ���S���̍��W

	static int eBoxX, eBoxY, eBoxX2, eBoxY2;		// �G�̓����蔻��
	static int ebBoxX, ebBoxY, ebBoxX2, ebBoxY2;	// �G�̕��D�̓����蔻��

	static int Score;

	static int EnemyDeath();

};
