#include "Enemy.h"
#include "DxLib.h"
#include "common.h"
#include "PadInput.h"



Enemy::Enemy() {
	LoadDivGraph("x64/Release/images/Enemy/Enemy_G_Animation.png", 18, 6, 3, 64, 64, EnemyG_img);
	LoadDivGraph("x64/Release/images/Enemy/Enemy_P_Animation.png", 18, 6, 5, 64, 64, EnemyP_img);
	LoadDivGraph("x64/Release/images/Enemy/Enemy_R_Animation.png", 18, 6, 5, 64, 64, EnemyR_img);

	enemy[0].x = 200;
	enemy[0].y = 100;
	
	Enemy2_x = enemy[0].x;
	Enemy2_y = enemy[0].y;

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
	if (InputX < -1)
	{
		enemy[0].x -= 3;
		
	}

	if (InputX > 1)
	{
		enemy[0].x += 3;
	
	}

}

void Enemy::Draw() const {

	
	DrawGraph(enemy[0].x, enemy[0].y, EnemyG_img[8], TRUE);

	DrawGraph(640 + enemy[0].x, enemy[0].y, EnemyG_img[8], TRUE);
	DrawGraph(enemy[0].x - 640, enemy[0].y, EnemyG_img[8], TRUE);	// 画面端ワープ用
	DrawFormatString(320, 0, 0xffffff, "%f", enemy[0].x);
}
