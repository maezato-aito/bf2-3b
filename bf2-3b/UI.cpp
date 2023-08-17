#include "UI.h"
#include "DxLib.h"
#include "Enemy.h"
#include "Player.h"

int UI::BestScore;
int UI::NowScore;

UI::UI() {
	NowScore = 0;
	Iimg = LoadGraph("images/UI/UI_Score.png");
	Topimg = LoadGraph("images/UI/UI_HiScore.png");
	Ballonimg = LoadGraph("images/UI/UI_Stock.png");
	LoadDivGraph("images/UI/UI_NumAnimation.png", 10, 10, 1, 32, 32, Numberimg);

	
}

UI::~UI() {

}

void UI::Update() {
	NowScore = Enemy::Score;
	if (BestScore <= NowScore) {
		BestScore = NowScore;
	}


}

void UI::Draw() const {
	/*SetFontSize(30);*/
	DrawGraph(60, 14, Iimg, TRUE);
	SetFontSize(24);
	DrawFormatString(85, 8, 0xffffff, "%06d", NowScore, TRUE);
	DrawGraph(240, 14, Topimg, TRUE);
	DrawFormatString(285, 8, 0xffffff, "%06d", BestScore, TRUE);

	if (Player::Life == 2) {
		DrawGraph(145, 34, Ballonimg, TRUE);
	}
	if (Player::Life >= 1) {
		DrawGraph(165, 34, Ballonimg, TRUE);
	}
	
}