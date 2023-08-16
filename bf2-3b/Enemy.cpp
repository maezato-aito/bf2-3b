#include "Enemy.h"
#include "DxLib.h"
#include "common.h"
#include "PadInput.h"
#include "Player.h"
#include "fish.h"
#include "Stage.h"

int Enemy::eBoxX;
int Enemy::eBoxY;
int Enemy::eBoxX2;
int Enemy::eBoxY2;

int Enemy::ebBoxX;
int Enemy::ebBoxY;
int Enemy::ebBoxX2;
int Enemy::ebBoxY2;

int Enemy::St_x;
int Enemy::St_y;
int Enemy::Pr_x;
int Enemy::Pr_y;
int Enemy::De_x;
int Enemy::De_y;

int Enemy::Score;

int Enemy::enemyFlg;

int Enemy::Lv;

Enemy::Enemy() {
	LoadDivGraph("images/Enemy/Enemy_G_Animation.png", 18, 6, 3, 64, 64, EnemyG_img);
	LoadDivGraph("images/Enemy/Enemy_P_Animation.png", 18, 6, 5, 64, 64, EnemyP_img);
	LoadDivGraph("images/Enemy/Enemy_R_Animation.png", 18, 6, 5, 64, 64, EnemyR_img);

	EnemyInit();
}

Enemy::~Enemy() {

}

void Enemy::Update() {
	
	GetJoypadAnalogInput(&InputX, &InputY, DX_INPUT_PAD1);
	rand = GetRand(99);

	// 敵の風船の当たり判定
	ebBoxX  = enemy[0].x + 6;
	ebBoxY  = enemy[0].y + 10;
	ebBoxX2 = enemy[0].x + 55;
	ebBoxY2 = enemy[0].y + 35;
	
	// 敵の当たり判定
	eBoxX  = enemy[0].x + 6;
	eBoxY  = enemy[0].y + 35;
	eBoxX2 = enemy[0].x + 55;
	eBoxY2 = enemy[0].y + 64;

	UpFlg = 0;

	if (1 < Gvy)
	{
		Gvy = 1;
	}
	
	enemy[0].y += (Gvy - UpNum);

	// 重力
	if (enemy[0].flg == 2 || enemy[0].flg == 3 || enemy[0].flg == 4)
	{
		Gvy += 0.01;
	}

	// 左右移動
	if (enemy[0].flg == 2)
	{
		enemy[0].x += Speed;
	}

	// 敵の上昇
	if (Player::bBoxY < eBoxY2 && enemy[0].flg == 2/* && (Player::pBoxX > eBoxX2 || Player::pBoxX2 < eBoxX)*/)
	{
		if (ebBoxY > 0)
		{
			UpNum = 1.5;
			UpFlg = 1;
		}
		else
		{
			UpNum = 0;
		}
	}
	else{
	
		if (0.01 < UpNum) 
		{
			UpNum -= 0.1;
		}
	}
	
	// 左移動
	if (Player::pBoxX2 < eBoxX && enemy[0].flg == 2)
	{
		if (UpFlg == 1 && Speed < eSpeed[Lv])
		{
			Speed += 0.1f;
			if (Speed > eSpeed[Lv])Speed = eSpeed[Lv];
		}
	
	}
	else if (Player::pBoxX2 <= eBoxX && enemy[0].flg == 2) {
		// 回避
		if (UpFlg == 1 && Speed < eSpeed2[Lv])
		{
			Speed += 0.2f;
			if (Speed > eSpeed2[Lv])Speed = eSpeed2[Lv];
		}
	
	}

	// 右移動
	if (Player::pBoxX > eBoxX2 && enemy[0].flg == 2)
	{
		if (UpFlg == 1 && Speed > -eSpeed[Lv])
		{
			Speed -= 0.1f;
			if (Speed > -eSpeed[Lv])Speed = -eSpeed[Lv];
		}
		
	}
	else if (Player::pBoxX >= eBoxX2 && enemy[0].flg == 2) {
		// 回避
		if (UpFlg == 1 && Speed > -eSpeed2[Lv])
		{
			Speed -= 0.2f;
			if (Speed > -eSpeed2[Lv])Speed = -eSpeed2[Lv];
		}
	}


	if (InputX == 0 && enemy[0].flg == 2) {
		//慣性の作成
		Speed *= 0.96f;
	}

	
	
	// 右地面
	if ((S1_Landright_X <= enemy[0].x + 32 && S1_Landright_Width >= enemy[0].x) && S1_Landright_Y <= enemy[0].y + 64 && enemy[0].flg != 4) {
		
		if (enemy[0].flg == 3) {
			enemy[0].flg = 1;
			Count = 10;
			Gvy = 0;
			if (Lv < 2)
			{
				Lv += 1;
			}
			
			EnemyStart();
		}
	}
	// 右地面左側面
	else if (S1_Landright_X <= enemy[0].x + 64 && S1_Landright_Y < enemy[0].y + 64) {
		/*vx -= vx*e;*/
		/*Gvy = 1;
		
		enemy[0].y += Gvy;*/
	}

	//左地面
	else if (S1_Landleft_X <= enemy[0].x + 64 && S1_Landleft_Width >= enemy[0].x + 64 && S1_Landleft_Y <= enemy[0].y + 64 && enemy[0].flg != 4) {
		
		if (enemy[0].flg == 3) {
			enemy[0].flg = 1;
			Count = 10;
			Gvy = 0;
			if (Lv < 2)
			{
				Lv += 1;
			}
			
			EnemyStart();
		}
	}
	// 左地面右側面
	else if (S1_Landleft_Width >= enemy[0].x && S1_Landleft_Y < enemy[0].h) {
		
	/*	enemy[0].x = Gvy;		
		enemy[0].y += Gvy;*/
	}

	//空中床
	else if (S1_Flooting_X <= enemy[0].x + 32 && S1_Flooting_Width >= enemy[0].x + 32 && S1_Flooting_Y <= enemy[0].y + 64 && S1_Flooting_Y + 20 >= enemy[0].y && enemy[0].flg != 4) {
		
		if (enemy[0].flg == 3) {
			enemy[0].flg = 1;
			Count = 15;
			Gvy = 0;
			if (Lv < 2)
			{
				Lv += 1;
			}
			EnemyStart();
		}
	}
	
	
	
	

	// 海
	if (480 <= enemy[0].y) {
		enemy[0].flg = 0;
		enemyFlg = 0;
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

	// 風船を割られたとき
	if (Player::pBoxX < ebBoxX2 && Player::pBoxX2 > ebBoxX && Player::pBoxY < ebBoxY2 && Player::pBoxY2 > ebBoxY && enemy[0].flg == 2/* && ebBoxY && enemy[0].flg != 4*/) {
		enemy[0].flg = 3;
		Pr_x = eBoxX;
		Pr_y = eBoxY;
		if (enemy[0].type == 0) {
			Score += EnemyPScore[0];
		}
		else if (enemy[0].type == 1) {
			Score += EnemyGScore[0];
		}
		else {
			Score += EnemyRScore[0];
		}
		
		Parachute();
	}
	
	// 死亡判定
	if (Player::pBoxX < eBoxX2 && Player::pBoxX2 > ebBoxX && Player::pBoxY < eBoxY2 && Player::pBoxY2 > ebBoxY && enemy[0].flg == 1) {
		enemy[0].flg = 4;
		De_x = enemy[0].x;
		De_y = enemy[0].y;
		if (enemy[0].type == 0) {
			Score += EnemyPScore[2];
		}
		else if (enemy[0].type == 1) {
			Score += EnemyGScore[2];
		}
		else {
			Score += EnemyRScore[2];
		}
		Death();
	}
	if (enemyFlg == 0) {
		enemy[0].type == 0;
		enemy[0].flg = 0;
		enemyFlg = 0;
	}
	

	EnemyStart();

}

void Enemy::Draw() const {
	// 敵（ピンク）の描画
	if (enemy[0].flg != 0 && enemy[0].type == 0) {
		
		// 敵の描画
		DrawGraph(enemy[0].x, enemy[0].y, EnemyP_img[AnimImg], TRUE);
		// 画面端ワープ用
		DrawGraph(640 + enemy[0].x, enemy[0].y, EnemyP_img[AnimImg], TRUE);
		DrawGraph(enemy[0].x - 640, enemy[0].y, EnemyP_img[AnimImg], TRUE);

		// 当たり判定の範囲
		DrawBox(eBoxX, eBoxY, eBoxX2, eBoxY2, 0xffffff, FALSE);
		DrawBox(ebBoxX, ebBoxY, ebBoxX2, ebBoxY2, 0xff2255, FALSE);
	}

	// 敵（緑）の描画
	if (enemy[0].flg != 0 && enemy[0].type == 1) {
	
		// 敵の描画
		DrawGraph(enemy[0].x, enemy[0].y, EnemyG_img[AnimImg], TRUE);
		// 画面端ワープ用
		DrawGraph(640 + enemy[0].x, enemy[0].y, EnemyG_img[AnimImg], TRUE);
		DrawGraph(enemy[0].x - 640, enemy[0].y, EnemyG_img[AnimImg], TRUE);

		// 当たり判定の範囲
		DrawBox(eBoxX, eBoxY, eBoxX2, eBoxY2, 0xffffff, FALSE);
		DrawBox(ebBoxX, ebBoxY, ebBoxX2, ebBoxY2, 0xff2255, FALSE);

		if (enemy[0].flg == 3) {
			DrawFormatString(Pr_x + 20, Pr_y - 10, 0xff0000, "%d", EnemyGScore[0], TRUE);
		}

		if (enemy[0].flg == 4) {
			DrawFormatString(De_x + 20, De_y - 10, 0xff0000, "%d", EnemyGScore[2], TRUE);
		}

	}

	// 敵（赤）の描画
	if (enemy[0].flg != 0 && enemy[0].type == 2) {
		
		// 敵の描画
		DrawGraph(enemy[0].x, enemy[0].y, EnemyR_img[AnimImg], TRUE);
		// 画面端ワープ用
		DrawGraph(640 + enemy[0].x, enemy[0].y, EnemyR_img[AnimImg], TRUE);
		DrawGraph(enemy[0].x - 640, enemy[0].y, EnemyR_img[AnimImg], TRUE);

		// 当たり判定の範囲
		DrawBox(eBoxX, eBoxY, eBoxX2, eBoxY2, 0xffffff, FALSE);
		DrawBox(ebBoxX, ebBoxY, ebBoxX2, ebBoxY2, 0xff2255, FALSE);

		if (enemy[0].flg == 3) {
			DrawFormatString(Pr_x + 20, Pr_y - 10, 0xff0000, "%d", EnemyRScore[0], TRUE);
		}

		if (enemy[0].flg == 4) {
			DrawFormatString(De_x + 20, De_y - 10, 0xff0000, "%d", EnemyRScore[2], TRUE);
		}
	}

	if (enemy[0].flg == 3) {
		DrawFormatString(Pr_x + 20, Pr_y - 10, 0xff0000, "%d", EnemyPScore[0], TRUE);
	}

	if (enemy[0].flg == 4) {
		DrawFormatString(De_x + 20, De_y - 10, 0xff0000, "%d", EnemyPScore[2], TRUE);
	}

#if _DEBUG
	DrawFormatString(100, 100, 0xffffff, "%d", enemy[0].flg, TRUE);
	DrawFormatString(200, 150, 0xffffff, "%d", enemyFlg, TRUE);
	DrawFormatString(200, 170, 0xffffff, "UpNum:%d", UpNum, TRUE);
	DrawFormatString(200, 190, 0xffffff, "Gvy:%f", Gvy, TRUE);
	DrawFormatString(200, 210, 0xffffff, "a:%f", a, TRUE);
#endif _DEBUG
}

// 敵初期化処理
void Enemy::EnemyInit() {
	enemy[0].x = S1_Flooting_X;
	enemy[0].y = S1_Flooting_Y - 60;

	enemy[0].flg = 1;
	enemy[0].type = 0;
	enemyFlg = 1;
	Lv = 0;

	AnimImg = 0;
	Count = 15;
	Counter = 0;
	Gvy = 0;
	Speed = 0;
	SpeedY = 0;
	Pr_y = 0;
	a = 0;
}

// 初期状態
void Enemy::EnemyStart() {
	if(enemy[0].flg == 1) {
		if (++Counter >= 15)
		{
			if (0 <= Count)
			{
				--Count;
				if (Count == 14 && Count != 0)
				{
					AnimImg = 0;
				}
				if (Count == 13 && Count != 0)
				{
					AnimImg = 1;
				}
				if (Count == 12 && Count != 0)
				{
					AnimImg = 2;
				}
				if (Count == 11 && Count != 0)
				{
					AnimImg = 3;
				}
				if (Count == 10 && Count != 0)
				{
					AnimImg = 2;
				}
				if (Count == 9 && Count != 0)
				{
					AnimImg = 3;
				}
				if (Count == 8 && Count != 0)
				{
					AnimImg = 4;
				}
				if (Count == 7 && Count != 0)
				{
					AnimImg = 5;
				}
				if (Count == 6 && Count != 0)
				{
					AnimImg = 4;
				}
				if (Count == 5 && Count != 0)
				{
					AnimImg = 5;
				}
				if (Count == 4 && Count != 0)
				{
					AnimImg = 6;
				}
				if (Count == 3 && Count != 0)
				{
					AnimImg = 7;
				}
				if (Count == 2 && Count != 0)
				{
					AnimImg = 6;
				}
				if (Count == 1 && Count != 0)
				{
					AnimImg = 7;
				}
				if (Count == 0)
				{
					if (0 < Lv && Lv <= 1) {
						enemyFlg = 2;
						enemy[0].type = 1;
					}
					else if (Lv == 2) {
						enemyFlg = 3;
						enemy[0].type = 2;
					}

					AnimImg = 8;
					enemy[0].flg = 2;
				}
			}
			Counter = 0;
		}
	}
}

// パラシュート状態
void Enemy::Parachute() {
	AnimImg = 17;
	/*if (Player::pBoxX < eBoxX2 && Player::pBoxX2 > ebBoxX && Player::pBoxY < eBoxY2 && Player::pBoxY2 > ebBoxY) {
		enemy[0].flg = 4;
		Death();
	}*/

	if (Pr_x + 5 > enemy[0].x) {
		enemy[0].x += Speed;
	}
	
	if (Pr_x - 5 < enemy[0].x) {
		enemy[0].x -= Speed;
	}	
}

// 死亡処理
void Enemy::Death() {
	AnimImg = 13;
	Speed = 0;
	
	if (enemy[0].flg != 0) {

		if (enemy[0].y - 150 < De_y) {
			enemy[0].y -= SpeedY;
		}
		else if (enemy[0].y > 300 && enemy[0].y - 150 >= De_y) {

			SpeedY += 1.0f;
			enemy[0].y += SpeedY;
			enemy[0].y += Gvy;
		}
		else {
			enemy[0].flg = 0;
			enemyFlg = 0;
		}

	}
	
}

int Enemy::EnemyDeath() {
	enemyFlg = 0;
	return enemyFlg;
}