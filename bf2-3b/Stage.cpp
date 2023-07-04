#include "Stage.h"
#include "DxLib.h"

Stage::Stage() {

	// ãÛíÜè∞ÇÃâÊëúì«çû
	FlootingImg[0] = LoadGraph("images/Stage/Stage_Footing01.png");
	FlootingImg[1] = LoadGraph("images/Stage/Stage_Footing02.png");
	FlootingImg[2] = LoadGraph("images/Stage/Stage_Footing03.png");
	FlootingImg[3] = LoadGraph("images/Stage/Stage_Footing04.png");
	FlootingImg[4] = LoadGraph("images/Stage/Stage_Footing05.png");
	FlootingImg[5] = LoadGraph("images/Stage/Stage_Footing06.png");
	FlootingImg[6] = LoadGraph("images/Stage/Stage_Footing07.png");
	

	//	ínñ ÇÃâÊëúì«çû
	LandImg[0] = LoadGraph("images/Stage/Stage_Land_left01.png");
	LandImg[1] = LoadGraph("images/Stage/Stage_Land_left02.png");
	LandImg[2] = LoadGraph("images/Stage/Stage_Land_right01.png");
	LandImg[3] = LoadGraph("images/Stage/Stage_Land_right02.png");

	SeaImg = LoadGraph("images/Stage/Stage_Sea01.png");
}

Stage::~Stage() {
	DeleteGraph(FlootingImg[0]);
	DeleteGraph(FlootingImg[1]);
	DeleteGraph(FlootingImg[2]);
	DeleteGraph(FlootingImg[3]);
	DeleteGraph(FlootingImg[4]);
	DeleteGraph(FlootingImg[5]);
	DeleteGraph(FlootingImg[6]);
	

	DeleteGraph(LandImg[0]);
	DeleteGraph(LandImg[1]);
	DeleteGraph(LandImg[2]);
	DeleteGraph(LandImg[3]);
}

void Stage::Update() {

}

void Stage::Draw() const {
	
}

void Stage::Stage1() {
	DrawGraph(350, 400, FlootingImg[0], TRUE);
	DrawGraph(400, 400, FlootingImg[0], TRUE);
	DrawGraph(650, 400, FlootingImg[0], TRUE);
	
	DrawGraph(300, 680, SeaImg, TRUE);
	DrawGraph(600, 680, SeaImg, TRUE);
	DrawGraph(900, 680, SeaImg, TRUE);

	DrawGraph(0, 655, LandImg[0], TRUE);
	DrawGraph(150, 655, LandImg[0], TRUE);
	DrawGraph(975, 655, LandImg[2], TRUE);
	DrawGraph(1130, 655, LandImg[2], TRUE);
}