#include "Enemy.h"
#include "DxLib.h"
#include "common.h"
#include "PadInput.h"
#include "Player.h"

int Enemy::eBoxX;
int Enemy::eBoxY;
int Enemy::eBoxX2;
int Enemy::eBoxY2;

int Enemy::ebBoxX;
int Enemy::ebBoxY;
int Enemy::ebBoxX2;
int Enemy::ebBoxY2;


Enemy::Enemy() {
	LoadDivGraph("images/Enemy/Enemy_G_Animation.png", 18, 6, 3, 64, 64, EnemyG_img);
	LoadDivGraph("images/Enemy/Enemy_P_Animation.png", 18, 6, 5, 64, 64, EnemyP_img);
	LoadDivGraph("images/Enemy/Enemy_R_Animation.png", 18, 6, 5, 64, 64, EnemyR_img);

	enemy[0].x = S1_Flooting_X;
	enemy[0].y = S1_Flooting_Y - 65;

	enemy[0].flg = 0;

	AnimImg = 0;
	Count = 10;
	Counter = 0;
	Gvy = 0;
	SpeedX = 0;
	SpeedY = 0;
	Pr_y = 0;
}

Enemy::~Enemy() {

}

void Enemy::Update() {
	
	// �G�̕��D�̓����蔻��
	ebBoxX  = enemy[0].x + 6;
	ebBoxY  = enemy[0].y + 10;
	ebBoxX2 = enemy[0].x + 55;
	ebBoxY2 = enemy[0].y + 35;
	
	// �G�̓����蔻��
	eBoxX  = enemy[0].x + 6;
	eBoxY  = enemy[0].y + 35;
	eBoxX2 = enemy[0].x + 55;
	eBoxY2 = enemy[0].y + 64;


	// �G�̏㏸
	if (Player::bBoxY < eBoxY2 && enemy[0].flg == 1 && (Player::pBoxX > eBoxX2 || Player::pBoxX2 < eBoxX))
	{
		if (enemy[0].y > 4 && SpeedY <= 3)
		{
		/*	Gvy = 1;*/
			// ������Ă���
			SpeedY += 0.03f;
			enemy[0].y -= SpeedY;
		}
		else if (enemy[0].y > 4 && SpeedY > 3) {
			enemy[0].y -= SpeedY;
		}
	}
	else if (SpeedY > 0.05f && enemy[0].flg == 1) {
		SpeedY -= 0.5f;
		enemy[0].y += SpeedY;
		enemy[0].y += Gvy;

	}
	

	if (Player::pBoxX2 < eBoxX && enemy[0].flg == 1)	// ���ړ�
	{
		if (SpeedX > -1) {
			SpeedX -= 0.1f;
		}
	}
	else if (Player::pBoxX2 <= eBoxX && enemy[0].flg == 1) {
		if (SpeedX > -2) {
			SpeedX -= 0.4f;
			enemy[0].y -= SpeedY;
		}
	}


	if (Player::pBoxX > eBoxX2 && enemy[0].flg == 1)		// �E�ړ�
	{
		if (SpeedX < 1) {
			SpeedX += 0.1f;
		}
	}
	else if (Player::pBoxX >= eBoxX2 && enemy[0].flg == 1) {
		if (SpeedX > -2) {
			SpeedX -= 0.4f;
			enemy[0].y -= SpeedY;
		}
	}


	if (InputX == 0 && enemy[0].flg == 1) {
		//�����̍쐬
		SpeedX *= 0.99f;
	}

	enemy[0].x += SpeedX;

	
	// �E�n��
	if ((S1_Landright_X <= enemy[0].x + 32 && S1_Landright_Width >= enemy[0].x) && S1_Landright_Y <= enemy[0].y + 64 && enemy[0].flg != 4) {
		Gvy = 0;
		SpeedX = 0;
		if (enemy[0].flg == 2) {
			enemy[0].flg = 0;
			Count = 10;
			EnemyStart();
		}
	}
	// �E�n�ʍ�����
	else if (S1_Landright_X <= enemy[0].x + 64 && S1_Landright_Y < enemy[0].y + 64) {
		/*vx -= vx*e;*/
		Gvy = 1;
		
		enemy[0].y += Gvy;
	}

	//���n��
	else if (S1_Landleft_X <= enemy[0].x + 64 && S1_Landleft_Width >= enemy[0].x + 64 && S1_Landleft_Y <= enemy[0].y + 64 && enemy[0].flg != 4) {
		Gvy = 0;
		SpeedX = 0;
		if (enemy[0].flg == 2) {
			enemy[0].flg = 0;
			Count = 10;
			EnemyStart();
		}
	}
	// ���n�ʉE����
	else if (S1_Landleft_Width >= enemy[0].x && S1_Landleft_Y < enemy[0].h) {
		Gvy = 1;
		enemy[0].x = Gvy;		
		enemy[0].y += Gvy;
	}

	//�󒆏�
	else if (S1_Flooting_X <= enemy[0].x + 32 && S1_Flooting_Width >= enemy[0].x + 32 && S1_Flooting_Y <= enemy[0].y + 64 && enemy[0].flg != 4) {
		Gvy = 0;
		SpeedX = 0;
		if (enemy[0].flg == 2) {
			enemy[0].flg = 0;
			Count = 10;
			EnemyStart();
		}
	}
	else {
		// �W�����v��������Ă��Ȃ�
		Gvy = 1;
		enemy[0].y += Gvy;
		enemy[0].h += Gvy;
		/*	Speed = 0;*/
	}

	// ��ʒ[���[�v
	if (enemy[0].x < -64)	// ������E
	{
		enemy[0].x = 576;

	}
	if (enemy[0].x > 620)	// �E���獶
	{
		enemy[0].x = -10;

	}

	// ���D������ꂽ�Ƃ�
	if (Player::pBoxX < ebBoxX2 && Player::pBoxX2 > ebBoxX && Player::pBoxY < ebBoxY2 && Player::pBoxY2 > ebBoxY && enemy[0].flg == 1/* && ebBoxY && enemy[0].flg != 4*/) {
		enemy[0].flg = 2;
		Parachute();
	}
	
	// ���S����
	if (Player::pBoxX < eBoxX2 && Player::pBoxX2 > ebBoxX && Player::pBoxY < eBoxY2 && Player::pBoxY2 > ebBoxY && enemy[0].flg == 0) {
		enemy[0].flg = 4;
		Death();
	}

	EnemyStart();

}

void Enemy::Draw() const {

	// �G�̕`��
	DrawGraph(enemy[0].x, enemy[0].y, EnemyG_img[AnimImg], TRUE);
	// ��ʒ[���[�v�p
	DrawGraph(640 + enemy[0].x, enemy[0].y, EnemyG_img[AnimImg], TRUE);
	DrawGraph(enemy[0].x - 640, enemy[0].y, EnemyG_img[AnimImg], TRUE);

	// �����蔻��͈̔�
	DrawBox(eBoxX, eBoxY, eBoxX2, eBoxY2, 0xffffff, FALSE);
	DrawBox(ebBoxX, ebBoxY, ebBoxX2, ebBoxY2, 0xff2255, FALSE);


	DrawFormatString(100, 100, 0xffffff, "%d", enemy[0].flg, TRUE);

}

// �������
void Enemy::EnemyStart() {
	if(enemy[0].flg == 0) {
		if (++Counter >= 15)
		{
			if (0 < Count)
			{
				--Count;
				if (Count == 9 && Count != 0)
				{
					AnimImg = 2;
				}
				if (Count == 8 && Count != 0)
				{
					AnimImg = 3;
				}
				if (Count == 7 && Count != 0)
				{
					AnimImg = 2;
				}
				if (Count == 6 && Count != 0)
				{
					AnimImg = 3;
				}
				if (Count == 5 && Count != 0)
				{
					AnimImg = 4;
				}
				if (Count == 4 && Count != 0)
				{
					AnimImg = 5;
				}
				if (Count == 3 && Count != 0)
				{
					AnimImg = 4;
				}
				if (Count == 2 && Count != 0)
				{
					AnimImg = 5;
				}
				if (Count == 1 && Count != 0)
				{
					AnimImg = 8;
					SpeedY += 0.05f;
					for (int i = 0; i < 10; i++) {
						enemy[0].flg = 1;
						enemy[0].y -= 0.1f;
					}
				}
			}
			Counter = 0;
		}
	}

	

}

// �p���V���[�g���
void Enemy::Parachute() {
	AnimImg = 17;
	Pr_y = eBoxX;

	/*if (Player::pBoxX < eBoxX2 && Player::pBoxX2 > ebBoxX && Player::pBoxY < eBoxY2 && Player::pBoxY2 > ebBoxY) {
		enemy[0].flg = 4;
		Death();
	}*/

	if (Pr_y + 5 > enemy[0].x) {
		enemy[0].x += SpeedX;
	}
	
	if (Pr_y - 5 < enemy[0].x) {
		enemy[0].x -= SpeedX;
	}	
}

// ���S����
void Enemy::Death() {
	AnimImg = 13;
	SpeedX = 0;
	De_y = enemy[0].y;

	if (enemy[0].y - 150 < De_y) {
		enemy[0].y -= SpeedY;
	}
	else {
		
		SpeedY += 1.0f;
		enemy[0].y += SpeedY;
		enemy[0].y += Gvy;
	}
}