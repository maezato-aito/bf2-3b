#include "UI.h"
#include "DxLib.h"
#include "Enemy.h"

int UI::BestScore;
int UI::NowScore;

UI::UI() {
	NowScore = 0;
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

	DrawFormatString(100, 10, 0xc71585, "IE", NowScore, TRUE);
	DrawFormatString(130, 10, 0xffffff, "%06d", NowScore, TRUE);
	DrawFormatString(250, 10, 0xffd700, "TOPE", NowScore, TRUE);
	DrawFormatString(300, 10, 0xffffff, "%06d", BestScore, TRUE);
}