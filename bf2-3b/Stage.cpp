#include "Stage.h"
#include "DxLib.h"

Stage::Stage() {
	// ƒXƒe[ƒW‚PE‚Q‚Ì‹ó’†°À•W
	S1_Flooting_X = 180;
	S1_Flooting_Y = 280;
	// ƒXƒe[ƒW‚PE‚Q‚Ì’n–ÊÀ•W
	S1_Landright_X = 480;
	S1_Landright_Y = 410;
	S1_Landleft_X = 0;
	S1_Landleft_Y = 410;
	// ƒXƒe[ƒW‚P‚Ì‰_À•W
	S1_Cloud_X = 300;
	S1_Cloud_Y = 100;
	// ŠC‚ÌÀ•W
	Searight_X = 0;
	Searight_Y = 440;
	Sealeft_X = 320;
	Sealeft_Y = 440;

	// ‹ó’†°‚Ì‰æ‘œ“Ç
	FlootingImg[0] = LoadGraph("x64/Release/images/Stage/Stage_Footing01.png");
	FlootingImg[1] = LoadGraph("x64/Release/images/Stage/Stage_Footing02.png");
	FlootingImg[2] = LoadGraph("x64/Release/images/Stage/Stage_Footing03.png");
	FlootingImg[3] = LoadGraph("x64/Release/images/Stage/Stage_Footing04.png");
	FlootingImg[4] = LoadGraph("x64/Release/images/Stage/Stage_Footing05.png");
	FlootingImg[5] = LoadGraph("x64/Release/images/Stage/Stage_Footing06.png");
	FlootingImg[6] = LoadGraph("x64/Release/images/Stage/Stage_Footing07.png");
	
	// ’n–Ê‚Ì‰æ‘œ“Ç
	LandImg[0] = LoadGraph("x64/Release/images/Stage/Stage_Land_left01.png");
	LandImg[1] = LoadGraph("x64/Release/images/Stage/Stage_Land_left02.png");
	LandImg[2] = LoadGraph("x64/Release/images/Stage/Stage_Land_right01.png");
	LandImg[3] = LoadGraph("x64/Release/images/Stage/Stage_Land_right02.png");

	// ŠC‚Ì‰æ‘œ“Ç
	SeaImg = LoadGraph("x64/Release/images/Stage/Stage_Sea01.png");

	// ‰_‚Ì‰æ‘œ•ªŠ„“Ç
	LoadDivGraph("x64/Release/images/stage/Stage_CloudAnimation.png", 3, 3, 1, 128, 64, CloudImg);
	
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
	
	// ŠC‚Ì•`‰æ
	DrawGraph(Searight_X, Searight_Y, SeaImg, TRUE);
	DrawGraph(Sealeft_X, Sealeft_Y, SeaImg, TRUE);

	// ’n–Ê‚Ì•`‰æ
	DrawGraph(S1_Landright_X, S1_Landright_Y, LandImg[0], TRUE);
	DrawGraph(S1_Landleft_X, S1_Landleft_Y, LandImg[2], TRUE);

	// ‰_‚Ì•`‰æ
	DrawGraph(S1_Cloud_X, S1_Cloud_Y, CloudImg[0], TRUE);
}