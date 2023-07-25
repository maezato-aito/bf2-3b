#include "Enemy.h"
#include "DxLib.h"
#include "common.h"
#include "PadInput.h"


Enemy::Enemy() {
	LoadDivGraph("images/Enemy/Enemy_G_Animation.png", 18, 6, 3, 64, 64, EnemyG_img);
	LoadDivGraph("images/Enemy/Enemy_P_Animation.png", 18, 6, 5, 64, 64, EnemyP_img);
	LoadDivGraph("images/Enemy/Enemy_R_Animation.png", 18, 6, 5, 64, 64, EnemyR_img);

	enemy[0].x = S1_Flooting_X;
	enemy[0].y = S1_Flooting_Y - 65;

	AnimImg = 0;
	Count = 10;
	Counter = 0;
	Gvy = 0;
	Speed = 0;
}

Enemy::~Enemy() {

}

void Enemy::Update() {
	
	if ((PAD_INPUT::OnPressed(XINPUT_BUTTON_B)/* && Speed < 5.0f*/))
	{
		if (enemy[0].y > 4)
		{
		/*	Gvy = 1;*/
			// 押されている
			Speed += 0.05f;
			enemy[0].y -= Speed;
			enemy[0].h -= Speed;
		}
	}
	else if (Speed > 0.05f) {
		Speed -= 0.5f;
		enemy[0].y += Speed;
		enemy[0].h += Speed;
	}
	


	if ((PAD_INPUT::OnButton(XINPUT_BUTTON_A)))
	{
		if (enemy[0].y > 4)
		{
			Gvy = 1 * 2;
			// 押されている
			enemy[0].y -= Gvy * 10;
	
		}
	}


	if ((S1_Landright_X <= enemy[0].x + 32 && S1_Landright_Width >= enemy[0].x) && S1_Landright_Y <= enemy[0].y + 64) {
		Gvy = 0;
	/*	Speed = 0;*/
	}
	// 右地面左側面
	else if (S1_Landright_X <= enemy[0].x + 64 && S1_Landright_Y < enemy[0].y + 64) {
		/*vx -= vx*e;*/
		Gvy = 1;
		
		enemy[0].y += Gvy;
	
	}
	//左地面
	else if (S1_Landleft_X <= enemy[0].x + 64 && S1_Landleft_Width >= enemy[0].x + 64 && S1_Landleft_Y <= enemy[0].y + 64) {
		Gvy = 0;
	}
	// 左地面右側面
	else if (S1_Landleft_Width >= enemy[0].x && S1_Landleft_Y < enemy[0].h) {
		Gvy = 1;
		enemy[0].x = Gvy;
		
		enemy[0].y += Gvy;
	

	}
	//空中床
	else if (S1_Flooting_X <= enemy[0].x + 32 && S1_Flooting_Width >= enemy[0].x + 32 && S1_Flooting_Y <= enemy[0].y + 64 ) {
		Gvy = 0;
	}
	else {
		// ジャンプが押されていない
		Gvy = 1;
		enemy[0].y += Gvy;
		enemy[0].h += Gvy;
		/*	Speed = 0;*/
	}

	// 画面端ワープ
	if (enemy[0].x < -64)	// 左から右
	{
		enemy[0].x = 576;

	}
	if (enemy[0].x > 620)	// 右から左
	{
		enemy[0].x = -10;

	}

	GetJoypadAnalogInput(&InputX, &InputY, DX_INPUT_PAD1);
	if (InputX < -1)	// 左移動
	{
		enemy[0].x -= 3;
		
	}

	if (InputX > 1)		// 右移動
	{
		enemy[0].x += 3;
	
	}

	EnemyStart();

}

void Enemy::Draw() const {

	
	DrawGraph(enemy[0].x, enemy[0].y, EnemyG_img[AnimImg], TRUE);
	// 画面端ワープ用
	DrawGraph(640 + enemy[0].x, enemy[0].y, EnemyG_img[AnimImg], TRUE);
	DrawGraph(enemy[0].x - 640, enemy[0].y, EnemyG_img[AnimImg], TRUE);
	/*DrawBox(enemy[0].x, enemy[0].y, enemy[0].x + 64, enemy[0].y + 64, 0xffffff, FALSE);*/

	/*DrawFormatString(100, 100, 0xffffff, "%d", Counter, TRUE);
	DrawFormatString(50, 100, 0xffffff, "%d", Count, TRUE);*/

}

void Enemy::EnemyStart() {
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
			}
		}
		Counter = 0;
	}
}