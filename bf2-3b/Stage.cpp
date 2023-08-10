#include "Stage.h"
#include "DxLib.h"
#include"common.h"

Stage::Stage() {

	// ‹ó’†°‚Ì‰æ‘œ“Ç
	FlootingImg[0] = LoadGraph("images/Stage/Stage_Footing01.png");
	FlootingImg[1] = LoadGraph("images/Stage/Stage_Footing02.png");
	FlootingImg[2] = LoadGraph("images/Stage/Stage_Footing03.png");
	FlootingImg[3] = LoadGraph("images/Stage/Stage_Footing04.png");
	FlootingImg[4] = LoadGraph("images/Stage/Stage_Footing05.png");
	FlootingImg[5] = LoadGraph("images/Stage/Stage_Footing06.png");
	FlootingImg[6] = LoadGraph("images/Stage/Stage_Footing07.png");

	// ’n–Ê‚Ì‰æ‘œ“Ç
	LandImg[0] = LoadGraph("images/Stage/Stage_Land_left01.png");
	LandImg[1] = LoadGraph("images/Stage/Stage_Land_left02.png");
	LandImg[2] = LoadGraph("images/Stage/Stage_Land_right01.png");
	LandImg[3] = LoadGraph("images/Stage/Stage_Land_right02.png");

	// ŠC‚Ì‰æ‘œ“Ç
	SeaImg = LoadGraph("images/Stage/Stage_Sea01.png");

	// ‰_‚Ì‰æ‘œ•ªŠ„“Ç
	LoadDivGraph("images/stage/Stage_CloudAnimation.png", 3, 3, 1, 128, 64, CloudImg);
	
	Stage2Sample = LoadGraph("images/StageSample/Stage_2.png");

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
	// ‹ó’†°‚Ì•`‰æ
	DrawGraph(S1_Flooting_X, S1_Flooting_Y, FlootingImg[0], TRUE);
	DrawBox(S1_Flooting_X, S1_Flooting_Y, S1_Flooting_w, S1_Flooting_h, 0xff2255, FALSE);
	// ŠC‚Ì•`‰æ
	DrawGraph(Searight_X, Searight_Y, SeaImg, TRUE);
	DrawGraph(Sealeft_X, Sealeft_Y, SeaImg, TRUE);

	// ’n–Ê‚Ì•`‰æ
	DrawGraph(S1_Landright_X, S1_Landright_Y, LandImg[0], TRUE);
	DrawBox(S1_Landright_X, S1_Landright_Y, S1_Landright_w, S1_Landright_h, 0xff2255, FALSE);
	DrawGraph(S1_Landleft_X, S1_Landleft_Y, LandImg[2], TRUE);
	DrawBox(S1_Landleft_X, S1_Landleft_Y, S1_Landleft_w, S1_Landleft_h, 0xff2255, FALSE);

	
	// ‰_‚Ì•`‰æ
	DrawGraph(S1_Cloud_X, S1_Cloud_Y, CloudImg[0], TRUE);
}

void Stage::Stage2() {
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 122);
	DrawGraph(0, 0, Stage2Sample, TRUE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	// DrawGraph();
	// ‹ó’†°‚Ì•`‰æ
	DrawGraph(S1_Flooting_X, S1_Flooting_Y, FlootingImg[0], TRUE);
	DrawGraph(100, 165, FlootingImg[1], TRUE);
	DrawGraph(457, 150, FlootingImg[1], TRUE);


	// ŠC‚Ì•`‰æ
	DrawGraph(Searight_X, Searight_Y, SeaImg, TRUE);
	DrawGraph(Sealeft_X, Sealeft_Y, SeaImg, TRUE);

	// ’n–Ê‚Ì•`‰æ
	DrawGraph(S1_Landright_X, S1_Landright_Y, LandImg[0], TRUE);
	DrawGraph(S1_Landleft_X, S1_Landleft_Y, LandImg[2], TRUE);
}