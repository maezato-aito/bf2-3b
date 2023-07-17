#include "Stage.h"
#include "DxLib.h"
#include"common.h"

Stage::Stage() {

	// 空中床の画像読込
	FlootingImg[0] = LoadGraph("images/Stage/Stage_Footing01.png");
	FlootingImg[1] = LoadGraph("images/Stage/Stage_Footing02.png");
	FlootingImg[2] = LoadGraph("images/Stage/Stage_Footing03.png");
	FlootingImg[3] = LoadGraph("images/Stage/Stage_Footing04.png");
	FlootingImg[4] = LoadGraph("images/Stage/Stage_Footing05.png");
	FlootingImg[5] = LoadGraph("images/Stage/Stage_Footing06.png");
	FlootingImg[6] = LoadGraph("images/Stage/Stage_Footing07.png");

	// 地面の画像読込
	LandImg[0] = LoadGraph("images/Stage/Stage_Land_left01.png");
	LandImg[1] = LoadGraph("images/Stage/Stage_Land_left02.png");
	LandImg[2] = LoadGraph("images/Stage/Stage_Land_right01.png");
	LandImg[3] = LoadGraph("images/Stage/Stage_Land_right02.png");

	// 海の画像読込
	SeaImg = LoadGraph("images/Stage/Stage_Sea01.png");

	// 雲の画像分割読込
	LoadDivGraph("images/stage/Stage_CloudAnimation.png", 3, 3, 1, 128, 64, CloudImg);
	
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

	DeleteGraph(CloudImg[0]);
}

void Stage::Update() {

}

void Stage::Draw() const {
	
}

void Stage::Stage1() {
	// 空中床の描画
	DrawGraph(S1_Flooting_X, S1_Flooting_Y, FlootingImg[0], TRUE);
	DrawBox(S1_Flooting_X, S1_Flooting_Y, S1_Flooting_Width, S1_Flooting_height, 0xff2255, FALSE);
	// 海の描画
	DrawGraph(Searight_X, Searight_Y, SeaImg, TRUE);
	DrawGraph(Sealeft_X, Sealeft_Y, SeaImg, TRUE);

	// 地面の描画
	DrawGraph(S1_Landright_X, S1_Landright_Y, LandImg[0], TRUE);
	DrawBox(S1_Landright_X, S1_Landright_Y, S1_Landright_Width, S1_Landright_height, 0xff2255, FALSE);
	DrawGraph(S1_Landleft_X, S1_Landleft_Y, LandImg[2], TRUE);
	DrawBox(S1_Landleft_X, S1_Landleft_Y, S1_Landleft_Width, S1_Landleft_height, 0xff2255, FALSE);

	// 地面間の空間の当たり判定
	DrawBox(S1_Landleft_Width, S1_Landleft_height+30, S1_Landright_X, S1_Landright_Y, 0xff2255, FALSE);
	// 雲の描画
	DrawGraph(S1_Cloud_X, S1_Cloud_Y, CloudImg[0], TRUE);
}