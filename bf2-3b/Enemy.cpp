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
			Gvy = 1;
			// 押されている
			Speed += 0.05f;
			enemy[0].y -= Speed;
			enemy[0].h -= Speed;
		}
	}
	else if (Speed > 0.01f) {
		Speed -= 0.5f;
		enemy[0].y += Speed;
		enemy[0].h += Speed;
	}
	else {
		// ジャンプが押されていない
		Gvy = 1;
		enemy[0].y += Gvy;
		enemy[0].h += Gvy;
		/*	Speed = 0;*/
	}


	if ((PAD_INPUT::OnButton(XINPUT_BUTTON_A)))
	{
		if (enemy[0].y > 4)
		{
			Gvy = 1 * 2;
			// 押されている
			enemy[0].y -= Gvy * 10;
			enemy[0].h -= Gvy * 10;
		}
	}


	//地面に立っていないとき
	if (//右地面
		S1_Landright_X <= enemy[0].w && S1_Landright_X + 160 >= enemy[0].x &&
		S1_Landright_Y <= enemy[0].h && S1_Landright_Y + 90 >= enemy[0].y
		||
		//左地面
		S1_Landleft_X <= enemy[0].w && S1_Landleft_X + 160 >= enemy[0].x &&
		S1_Landleft_Y <= enemy[0].h && S1_Landleft_Y + 90 >= enemy[0].y
		||
		//空中床
		S1_Flooting_X <= enemy[0].w && S1_Flooting_X + 280 >= enemy[0].x &&
		S1_Flooting_Y <= enemy[0].h && S1_Flooting_Y + 20 >= enemy[0].y
		)
	{
	}
	else
	{
		// ジャンプが押されていない
		Gvy = 1;
		enemy[0].y += Gvy;
		enemy[0].h += Gvy;

	}
	GetJoypadAnalogInput(&InputX, &InputY, DX_INPUT_PAD1);
	if (InputX < -1)
	{
		enemy[0].x -= 6;
		enemy[0].w -= 6;
	}

	if (InputX > 1)
	{
		enemy[0].x += 6;
		enemy[0].w += 6;
	}

}

void Enemy::Draw() const {
	DrawGraph(enemy[0].x, enemy[0].y, EnemyG_img[0], TRUE);
	DrawGraph(640 + enemy[0].x, enemy[0].y, EnemyG_img[0], TRUE);
	DrawFormatString(320, 0, 0xffffff, "Enemy");
}
