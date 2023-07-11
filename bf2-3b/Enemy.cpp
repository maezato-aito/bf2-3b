#include "Enemy.h"
#include "DxLib.h"

Enemy::Enemy() {
	LoadDivGraph("x64/Release/images/Enemy/Enemy_G_Animation.png", 18, 6, 3, 64, 64, EnemyG_img);
	LoadDivGraph("x64/Release/images/Enemy/Enemy_P_Animation.png", 18, 6, 5, 64, 64, EnemyP_img);
	LoadDivGraph("x64/Release/images/Enemy/Enemy_R_Animation.png", 18, 6, 5, 64, 64, EnemyR_img);
}

Enemy::~Enemy() {
	
}

void Enemy::Update() {

}

void Enemy::Draw() const {
	DrawGraph(0, 0, EnemyG_img[0], TRUE);
	DrawFormatString(320, 0, 0xffffff, "Enemy");
}