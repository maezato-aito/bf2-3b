#pragma once
#include "AbstractScene.h"

class Enemy
{
private:
	int EnemyG_img[18];	// �G�i�΁j�̉摜
	int EnemyP_img[18];	// �G�i�s���N�j�̉摜
	int EnemyR_img[18];	// �G�i�ԁj�̉摜

	int InputX, InputY;
	float SpeedX, SpeedY;
	int Gvy;	// �d��
	int Cnt;	// ���ԃJ�E���g�p
	int Dflg;	// ���S�t���O

	float eSpeed[3] = { 1, 1.25, 2.5 };		// �G�̃X�s�[�h
	int EnemyWait[3] = { 3, 2, 1 };			// ���D���ӂ���܂��Ƃ��̑҂�����

	int EnemyPScore[3] = { 500, 1000, 750 };	// �G�i�s���N�j�̃X�R�A
	int EnemyGScore[3] = { 750, 1500, 1000 };	// �G�i�΁j�̃X�R�A
	int EnemyRScore[3] = { 1000, 2000, 1500 };	// �G�i�ԁj�̃X�R�A

	int Lv;			//�G�̃��x�� 

	int PointFlg;	// �X�R�A�t���O
	int AnimFlg;	// �A�j���[�V�����t���O
	float Count;	// ���ԃJ�E���g�p
	int Counter;	// ���ԃJ�E���^�[
	int AnimImg;	// �C���[�W�摜�p

	int WaitTime;	// �҂�����
	int NowTime;	// ���̎���
	
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
	void Wait();

	static int St_x, St_y;	// �X�^�[�g���̍��W
	static int Pr_x, Pr_y;	// �p���V���[�g���̍��W
	static int De_x, De_y;	// ���S���̍��W

	static int eBoxX, eBoxY, eBoxX2, eBoxY2;		// �G�̓����蔻��
	static int ebBoxX, ebBoxY, ebBoxX2, ebBoxY2;	// �G�̕��D�̓����蔻��

	static int Score;
};
