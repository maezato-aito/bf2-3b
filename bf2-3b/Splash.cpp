#include "Splash.h"
#include "DxLib.h"
#include "Player.h"
#include "Enemy.h"
int Splash::SplashAnimCount;
Splash::Splash()
{
	LoadDivGraph("images/Stage/Stage_SplashAnimation.png", 4, 4, 1, 64, 32, Splashimg);//プレイヤー画像
	SplashAnimCount = 0;
	SplashAnim = 0;
}

Splash::~Splash()
{

}

void Splash::Update()
{
	// 水しぶきのアニメーション

	if (Player::bBoxY > 480 || Enemy::enemyFlg == 0) {

		SplashAnimCount++;
		if (SplashAnimCount >= 0 && SplashAnimCount < 3) {
			SplashAnim = 0;
		}
		if (SplashAnimCount >= 3 && SplashAnimCount < 6) {
			SplashAnim = 1;
		}
		if (SplashAnimCount >= 6 && SplashAnimCount < 9) {
			SplashAnim = 2;
		}
		if (SplashAnimCount >= 9 && SplashAnimCount < 12) {
			SplashAnim = 3;
		}
		if (Player::PlayerFlg == 0 && SplashAnimCount >= 70) {
			SplashAnimCount = 0;
		}
	}
}

void Splash::Draw()
{
#if _DEBUG
	DrawFormatString(0, 300, 0xffffff, "カウント%d", SplashAnimCount, TRUE);
#endif _DEBUG
	// 水しぶき
	if (Player::bBoxY > 448 && Player::PlayerFlg == 0 && SplashAnimCount < 12) {
		DrawGraph(Player:: playerX, 412, Splashimg[SplashAnim], TRUE);
	}
	if (Enemy::ebBoxY > 458 && Enemy::enemyFlg == 0 && SplashAnimCount < 12) {
		DrawGraph(Enemy::eBoxX-5,412, Splashimg[SplashAnim], TRUE);
	}
}