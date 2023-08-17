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
	ebBoxX = enemy[0].x + 6;
	ebBoxY = enemy[0].y + 10;
	ebBoxX2 = enemy[0].x + 55;
	ebBoxY2 = enemy[0].y + 35;

	// 敵の当たり判定
	eBoxX = enemy[0].x + 6;
	eBoxY = enemy[0].y + 35;
	eBoxX2 = enemy[0].x + 55;
	eBoxY2 = enemy[0].y + 64;

	UpFlg = 0;

	if (enemy[0].flg != 4) {
		if (1 < Gvy)
		{
			Gvy = 1;
		}
	}


	// 重力の加算
	enemy[0].y += (Gvy - UpNum);

	// 重力
	if (enemy[0].flg == 2 || enemy[0].flg == 3)
	{
		Gvy += 0.01;
	}
	else if (enemy[0].flg == 4)
	{
		Gvy += 0.03;
	}

	// パラシュート状態の左右移動
	if (enemy[0].flg == 3)
	{
		enemy[0].x += MoveX;
		if (Pr_x + 40 <= enemy[0].x)
		{
			MoveX *= -1;
		}
		/*if (Pr_x + 35 < enemy[0].x < Pr_x + 40 || Pr_x - 40 < enemy[0].x < Pr_x - 35)
		{
			MoveX *= 0.3f;
		}*/
		if (enemy[0].x <= Pr_x - 40)
		{
			MoveX *= -1;
		}
	}


	// 左右移動
	if (enemy[0].flg == 2 || enemy[0].flg == 3)
	{
		enemy[0].x += Speed;
	}

	// 敵の上昇
	if (Player::bBoxY < eBoxY2 && enemy[0].flg == 2)
	{
		if (ebBoxY > 0)
		{
			UpNum = 1.4;
			UpFlg = 1;
		}
		else
		{
			UpNum = 0;
		}

		if (++AnimCount < 400.0f) {
			if (0 <= AnimCount)
			{
				AnimImg = 8;
			}
			if (3 <= AnimCount)
			{
				AnimImg = 9;
			}
			if (6 <= AnimCount)
			{
				AnimImg = 9;
			}
			if (9 <= AnimCount)
			{
				AnimImg = 9;
			}
			if (11 <= AnimCount)
			{
				AnimCount = 0;
			}
		}
	}
	else {

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

		EnemyLR = 2;

	}
	else if (Player::pBoxX2 <= eBoxX && enemy[0].flg == 2) {
		// 回避
		if (UpFlg == 1 && Speed < eSpeed2[Lv])
		{
			Speed += 0.2f;
			if (Speed > eSpeed2[Lv])Speed = eSpeed2[Lv];
		}
		EnemyLR = 2;
	}

	// 右移動
	if (Player::pBoxX > eBoxX2 && enemy[0].flg == 2)
	{
		if (UpFlg == 1 && Speed > -eSpeed[Lv])
		{
			Speed -= 0.1f;
			if (Speed > -eSpeed[Lv])Speed = -eSpeed[Lv];
		}
		EnemyLR = 1;
	}
	else if (Player::pBoxX >= eBoxX2 && enemy[0].flg == 2) {
		// 回避
		if (UpFlg == 1 && Speed > -eSpeed2[Lv])
		{
			Speed -= 0.2f;
			if (Speed > -eSpeed2[Lv])Speed = -eSpeed2[Lv];
		}
		EnemyLR = 1;
	}


	if (enemy[0].flg == 2) {
		//慣性の作成
		Speed *= 0.96f;
	}

	// 右地面（パラシュート状態）
	if ((S1_Landright_X <= enemy[0].x + 32 && S1_Landright_Width >= enemy[0].x) && S1_Landright_Y <= enemy[0].y + 64 && enemy[0].flg == 2) {
		UpNum = 1.4;
		UpFlg = 1;
	}
	// 右地面（パラシュート状態）
	if ((S1_Landright_X <= enemy[0].x + 32 && S1_Landright_Width >= enemy[0].x) && S1_Landright_Y <= enemy[0].y + 64 && enemy[0].flg == 3) {

		enemy[0].flg = 1;
		Gvy = 0;
		Count = 10;

		if (Lv < 2)
		{
			Lv += 1;
		}

		EnemyStart();

	}
	// 右地面左側面
	else if (S1_Landright_X <= enemy[0].x + 64 && S1_Landright_Y < enemy[0].y + 64 && S1_Landright_Width >= eBoxX && S1_Landright_height >= ebBoxY) {
		HitFlg = 2;
		Backlash();
	}

	//左地面（浮遊状態）
	else if (S1_Landleft_X <= enemy[0].x + 64 && S1_Landleft_Width >= enemy[0].x + 64 && S1_Landleft_Y - 10 <= enemy[0].y + 64 && enemy[0].flg == 2) {

		UpNum = 1.4;
		UpFlg = 1;

	}
	//左地面（パラシュート状態）
	else if (S1_Landleft_X <= enemy[0].x + 64 && S1_Landleft_Width >= enemy[0].x + 64 && S1_Landleft_Y <= enemy[0].y + 64 && enemy[0].flg == 3) {


		enemy[0].flg = 1;
		Gvy = 0;
		Count = 10;
		if (Lv < 2)
		{
			Lv += 1;
		}

		EnemyStart();

	}
	// 左地面右側面
	else if (S1_Landleft_Width >= enemy[0].x && S1_Landleft_Y < enemy[0].y + 64 && S1_Flooting_X <= eBoxX2 && S1_Flooting_height >= eBoxY) {
		HitFlg = 1;
		Backlash();
	}


	//空中床（浮遊状態）
	else if (S1_Flooting_X <= enemy[0].x + 32 && S1_Flooting_Width >= enemy[0].x + 32 && S1_Flooting_Y - 10 <= enemy[0].y + 64 && S1_Flooting_Y + 20 >= enemy[0].y && enemy[0].flg == 2) {
		UpNum = 1.4;
		UpFlg = 1;
	}

	//空中床（パラシュート状態）
	else if (S1_Flooting_X <= enemy[0].x + 32 && S1_Flooting_Width >= enemy[0].x + 32 && S1_Flooting_Y <= enemy[0].y + 64 && S1_Flooting_Y + 20 >= enemy[0].y && enemy[0].flg == 3) {


		enemy[0].flg = 1;
		Gvy = 0;
		Count = 15;

		if (Lv < 2)
		{
			Lv += 1;
		}
		EnemyStart();

	}
	// 空中床左側面
	if (S1_Flooting_X <= eBoxX2 && S1_Flooting_Width >= eBoxX && S1_Flooting_Y + 1 < eBoxY2 && S1_Flooting_height - 1 >= eBoxY && Speed > eSpeed[Lv]) {
		HitFlg = 2;
		Backlash();
	}
	// 空中床右側面
	if (S1_Flooting_X <= eBoxX2 && S1_Flooting_Width >= eBoxX && S1_Flooting_Y + 1 < eBoxY2 && S1_Flooting_height - 1 >= eBoxY && Speed < -eSpeed[Lv]) {
		HitFlg = 1;
		Backlash();
	}
	// 空中床下
	if (S1_Flooting_X <= eBoxX2 && S1_Flooting_Width >= eBoxX && S1_Flooting_height - 1 < eBoxY && S1_Flooting_height >= eBoxY) {
		/*Gvy += 0.02;*/
	}


	// 海に落ちたら死亡
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

	// 敵の左側に当たったとき
	// 敵の半分より上に当たったとき
	if (Player::pBoxX2 == ebBoxX && Player::pBoxY + 7 <= eBoxY + 7 && Player::pBoxY2 <= ebBoxY/* && Player::playerLR == 2*/) {
		HitFlg = 2;
		Backlash();
	}
	// 敵の半分より下に当たったとき
	if (Player::pBoxX2 == ebBoxX && Player::pBoxY + 7 >= eBoxY + 7 && Player::pBoxY2 >= ebBoxY/* && Player::playerLR == 2*/) {
		HitFlg = 2;
		Backlash();
	}
	// 敵と高さが同じ時
	if (Player::pBoxX2 == ebBoxX && Player::bBoxY == ebBoxY && Player::pBoxY2 == eBoxY2/* && Player::playerLR == 2*/) {
		HitFlg = 2;
		Backlash();
	}
	// 敵の右側に当たったとき
	// 敵の半分より上に当たったとき
	if (Player::pBoxX == ebBoxX2 && Player::pBoxY + 7 <= eBoxY + 7 && Player::pBoxY2 <= ebBoxY/* && playerLR == 1*/) {
		HitFlg = 1;
		Backlash();
	}
	// 敵の半分より下に当たったとき
	if (Player::pBoxX == ebBoxX2 && Player::pBoxY + 7 >= eBoxY + 7 && Player::bBoxY >= eBoxY2/* && playerLR == 1*/) {
		HitFlg = 1;
		Backlash();
	}
	// 敵と高さが同じ時
	if (Player::pBoxX == ebBoxX2 && Player::bBoxY == ebBoxY && Player::pBoxY2 == eBoxY2) {
		HitFlg = 1;
		Backlash();
	}
	// 反発
	//
	//if (HitFlg == 1 || HitFlg == 2 && Speed > -0.5 && Speed < 0.5) {
	//	Gvy = 0.98f;
	//	Speed *= 0.8;
	//}


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

		if (EnemyLR == 1)
		{
			// 敵の描画
			DrawGraph(enemy[0].x, enemy[0].y, EnemyP_img[AnimImg], TRUE);
			// 画面端ワープ用
			DrawGraph(640 + enemy[0].x, enemy[0].y, EnemyP_img[AnimImg], TRUE);
			DrawGraph(enemy[0].x - 640, enemy[0].y, EnemyP_img[AnimImg], TRUE);

		}
		else
		{
			// 敵の描画
			DrawTurnGraph(enemy[0].x, enemy[0].y, EnemyP_img[AnimImg], TRUE);
			// 画面端ワープ用
			DrawTurnGraph(640 + enemy[0].x, enemy[0].y, EnemyP_img[AnimImg], TRUE);
			DrawTurnGraph(enemy[0].x - 640, enemy[0].y, EnemyP_img[AnimImg], TRUE);
		}

		// 当たり判定の範囲
		/*DrawBox(eBoxX, eBoxY, eBoxX2, eBoxY2, 0xffffff, FALSE);
		DrawBox(ebBoxX, ebBoxY, ebBoxX2, ebBoxY2, 0xff2255, FALSE);*/
	}

	// 敵（緑）の描画
	if (enemy[0].flg != 0 && enemy[0].type == 1) {

		if (EnemyLR == 1)
		{
			// 敵の描画
			DrawGraph(enemy[0].x, enemy[0].y, EnemyG_img[AnimImg], TRUE);
			// 画面端ワープ用
			DrawGraph(640 + enemy[0].x, enemy[0].y, EnemyG_img[AnimImg], TRUE);
			DrawGraph(enemy[0].x - 640, enemy[0].y, EnemyG_img[AnimImg], TRUE);
		}
		else
		{
			// 敵の描画
			DrawTurnGraph(enemy[0].x, enemy[0].y, EnemyG_img[AnimImg], TRUE);
			// 画面端ワープ用
			DrawTurnGraph(640 + enemy[0].x, enemy[0].y, EnemyG_img[AnimImg], TRUE);
			DrawTurnGraph(enemy[0].x - 640, enemy[0].y, EnemyG_img[AnimImg], TRUE);
		}

		// 当たり判定の範囲
		/*DrawBox(eBoxX, eBoxY, eBoxX2, eBoxY2, 0xffffff, FALSE);
		DrawBox(ebBoxX, ebBoxY, ebBoxX2, ebBoxY2, 0xff2255, FALSE);*/

		if (enemy[0].flg == 3) {
			DrawFormatString(Pr_x + 20, Pr_y - 10, 0xff0000, "%d", EnemyGScore[0], TRUE);
		}

		if (enemy[0].flg == 4) {
			DrawFormatString(De_x + 20, De_y - 10, 0xff0000, "%d", EnemyGScore[2], TRUE);
		}

	}

	// 敵（赤）の描画
	if (enemy[0].flg != 0 && enemy[0].type == 2) {

		if (EnemyLR == 1)
		{

			// 敵の描画
			DrawGraph(enemy[0].x, enemy[0].y, EnemyR_img[AnimImg], TRUE);
			// 画面端ワープ用
			DrawGraph(640 + enemy[0].x, enemy[0].y, EnemyR_img[AnimImg], TRUE);
			DrawGraph(enemy[0].x - 640, enemy[0].y, EnemyR_img[AnimImg], TRUE);
		}
		else
		{
			// 敵の描画
			DrawTurnGraph(enemy[0].x, enemy[0].y, EnemyR_img[AnimImg], TRUE);
			// 画面端ワープ用
			DrawTurnGraph(640 + enemy[0].x, enemy[0].y, EnemyR_img[AnimImg], TRUE);
			DrawTurnGraph(enemy[0].x - 640, enemy[0].y, EnemyR_img[AnimImg], TRUE);
		}

		// 当たり判定の範囲
		/*DrawBox(eBoxX, eBoxY, eBoxX2, eBoxY2, 0xffffff, FALSE);
		DrawBox(ebBoxX, ebBoxY, ebBoxX2, ebBoxY2, 0xff2255, FALSE);*/

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
	DrawFormatString(200, 170, 0xffffff, "%f", Speed, TRUE);
	DrawFormatString(200, 190, 0xffffff, "flg:%d", enemy[0].flg, TRUE);
	DrawFormatString(200, 210, 0xffffff, "Gvy:%f", Gvy, TRUE);
	DrawFormatString(200, 230, 0xffffff, "UpNum:%f", UpNum, TRUE);
	DrawFormatString(200, 250, 0xffffff, "Speed:%f", Speed, TRUE);

#endif _DEBUG
}

// 敵初期化処理
void Enemy::EnemyInit() {
	enemy[0].x = S1_Flooting_X;
	enemy[0].y = S1_Flooting_Y - 62;

	enemy[0].flg = 1;
	enemy[0].type = 0;
	enemyFlg = 1;
	Lv = 0;
	EnemyLR = 1;
	AnimImg = 0;
	Count = 15;
	Counter = 0;
	Gvy = 0;
	Speed = 0;
	SpeedY = 0;
	Pr_y = 0;
	UpFlg = 0;
	UpNum = 0;
	Time = 0;
	MoveX = 0.4f;
}

// 反発処理
void Enemy::Backlash() {
	// 左側に触れた時
	if (HitFlg == 1 && Speed < -eSpeed[Lv]) {
		Speed *= -1.0;
	}
	
	// 右側に触れた時
	if (HitFlg == 2 && Speed > eSpeed[Lv]) {
		Speed += -1.0;
	}
	
}

// 初期状態
void Enemy::EnemyStart() {

	if (enemy[0].flg == 1) {
		Time++;
		if (Time >= 60) {
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

						enemy[0].flg = 2;

						if (0 < Lv && Lv <= 1) {
							enemyFlg = 2;
							enemy[0].type = 1;
						}
						else if (Lv == 2) {
							enemyFlg = 3;
							enemy[0].type = 2;
						}
						AnimImg = 8;
						Time = 0;
					}
				}
				Counter = 0;
			}
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