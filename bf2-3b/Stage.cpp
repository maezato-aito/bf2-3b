#include "Stage.h"
#include "DxLib.h"
#include"common.h"

int Stage::NowStage;

Stage::Stage() {

	NowStage = 1;

	// ãÛíÜè∞ÇÃâÊëúì«çû
	FlootingImg[0] = LoadGraph("images/Stage/Stage_Footing01.png");
	FlootingImg[1] = LoadGraph("images/Stage/Stage_Footing02.png");
	FlootingImg[2] = LoadGraph("images/Stage/Stage_Footing03.png");
	FlootingImg[3] = LoadGraph("images/Stage/Stage_Footing04.png");
	FlootingImg[4] = LoadGraph("images/Stage/Stage_Footing05.png");
	FlootingImg[5] = LoadGraph("images/Stage/Stage_Footing06.png");
	FlootingImg[6] = LoadGraph("images/Stage/Stage_Footing07.png");
	FlootingImg[7] = LoadGraph("images/Stage/Stage_Footing08.png");

	// ínñ ÇÃâÊëúì«çû
	LandImg[0] = LoadGraph("images/Stage/Stage_Land_left01.png");
	LandImg[1] = LoadGraph("images/Stage/Stage_Land_left02.png");
	LandImg[2] = LoadGraph("images/Stage/Stage_Land_right01.png");
	LandImg[3] = LoadGraph("images/Stage/Stage_Land_right02.png");

	// äCÇÃâÊëúì«çû
	SeaImg = LoadGraph("images/Stage/Stage_Sea01.png");

	// â_ÇÃâÊëúï™äÑì«çû
	LoadDivGraph("images/stage/Stage_CloudAnimation.png", 3, 3, 1, 128, 64, CloudImg);
	
	// ÉTÉìÉvÉãâÊëúÇÃì«çû
	Stage1Sample = LoadGraph("images/StageSample/Stage_1.png");
	Stage2Sample = LoadGraph("images/StageSample/Stage_2.png");
	Stage3Sample = LoadGraph("images/StageSample/Stage_3.png");
	Stage4Sample = LoadGraph("images/StageSample/Stage_4.png");
	Stage5Sample = LoadGraph("images/StageSample/Stage_5.png");
}

Stage::~Stage() {
	DeleteGraph(FlootingImg[0]);
	DeleteGraph(FlootingImg[1]);
	DeleteGraph(FlootingImg[2]);
	DeleteGraph(FlootingImg[3]);
	DeleteGraph(FlootingImg[4]);
	DeleteGraph(FlootingImg[5]);
	DeleteGraph(FlootingImg[6]);
	DeleteGraph(FlootingImg[7]);
	
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

	/*SetDrawBlendMode(DX_BLENDMODE_ALPHA, 122);
	DrawGraph(0, 0, Stage1Sample, TRUE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);*/

	// ãÛíÜè∞ÇÃï`âÊ
	DrawGraph(S1_Flooting_X, S1_Flooting_Y, FlootingImg[0], TRUE);
	DrawBox(S1_Flooting_X, S1_Flooting_Y, S1_Flooting_Width, S1_Flooting_height, 0xff2255, FALSE);
	// äCÇÃï`âÊ
	DrawGraph(Searight_X, Searight_Y, SeaImg, TRUE);
	DrawGraph(Sealeft_X, Sealeft_Y, SeaImg, TRUE);

	// ínñ ÇÃï`âÊ
	DrawGraph(S1_Landright_X, S1_Landright_Y, LandImg[0], TRUE);
	DrawBox(S1_Landright_X, S1_Landright_Y, S1_Landright_Width, S1_Landright_height, 0xff2255, FALSE);
	DrawGraph(S1_Landleft_X, S1_Landleft_Y, LandImg[2], TRUE);
	DrawBox(S1_Landleft_X, S1_Landleft_Y, S1_Landleft_Width, S1_Landleft_height, 0xff2255, FALSE);
}

void Stage::Stage2() {

	/*SetDrawBlendMode(DX_BLENDMODE_ALPHA, 122);
	DrawGraph(0, 0, Stage2Sample, TRUE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);*/

	// ãÛíÜè∞ÇÃï`âÊ
	DrawGraph(S1_Flooting_X, S1_Flooting_Y, FlootingImg[0], TRUE);
	DrawGraph(S2_Flooting_X, S2_Flooting_Y, FlootingImg[1], TRUE);
	DrawGraph(S2_2Flooting_X, S2_2Flooting_Y, FlootingImg[1], TRUE);

	// äCÇÃï`âÊ
	DrawGraph(Searight_X, Searight_Y, SeaImg, TRUE);
	DrawGraph(Sealeft_X, Sealeft_Y, SeaImg, TRUE);

	// ínñ ÇÃï`âÊ
	DrawGraph(S1_Landright_X, S1_Landright_Y, LandImg[0], TRUE);
	DrawGraph(S1_Landleft_X, S1_Landleft_Y, LandImg[2], TRUE);
}

void Stage::Stage3() {

	/*SetDrawBlendMode(DX_BLENDMODE_ALPHA, 122);
	DrawGraph(0, 0, Stage3Sample, TRUE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);*/

	// ãÛíÜè∞ÇÃï`âÊ
	DrawGraph(S3_Flooting_X, S3_Flooting_Y, FlootingImg[2], TRUE);
	DrawGraph(S3_2Flooting_X, S3_2Flooting_Y, FlootingImg[4], TRUE);

	// èﬂì˚êŒÇÃï`âÊ
	DrawGraph(S3_Flooting_X, S3_Flooting_Y, FlootingImg[3], TRUE);	// âE
	DrawGraph(S3_2Flooting_X, S3_2Flooting_Y, FlootingImg[3], TRUE);	// ê^ÇÒíÜ
	DrawGraph(S3_3Flooting_X, S3_3Flooting_Y, FlootingImg[3], TRUE);	// âE

	// äCÇÃï`âÊ
	DrawGraph(Searight_X, Searight_Y, SeaImg, TRUE);
	DrawGraph(Sealeft_X, Sealeft_Y, SeaImg, TRUE);

	// ínñ ÇÃï`âÊ
	DrawGraph(S1_Landright_X, S1_Landright_Y, LandImg[0], TRUE);
	DrawGraph(S1_Landleft_X, S1_Landleft_Y, LandImg[2], TRUE);
}

void Stage::Stage4() {
	/*SetDrawBlendMode(DX_BLENDMODE_ALPHA, 122);
	DrawGraph(0, 0, Stage4Sample, TRUE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);*/

	// ãÛíÜè∞ÇÃï`âÊ
	DrawGraph(S4_Flooting_X, S4_Flooting_Y, FlootingImg[5], TRUE);
	DrawGraph(S4_2Flooting_X, S4_2Flooting_Y, FlootingImg[5], TRUE);
	DrawGraph(S4_3Flooting_X, S4_3Flooting_Y, FlootingImg[5], TRUE);
	DrawGraph(S4_4Flooting_X, S4_4Flooting_Y, FlootingImg[5], TRUE);
	DrawGraph(S4_5Flooting_X, S4_5Flooting_Y, FlootingImg[5], TRUE);

	// äCÇÃï`âÊ
	DrawGraph(Searight_X, Searight_Y, SeaImg, TRUE);
	DrawGraph(Sealeft_X, Sealeft_Y, SeaImg, TRUE);

	// ínñ ÇÃï`âÊ
	DrawGraph(S1_Landright_X, S1_Landright_Y, LandImg[1], TRUE);
	DrawGraph(S1_Landleft_X, S1_Landleft_Y, LandImg[3], TRUE);
}

void Stage::Stage5() {
	//SetDrawBlendMode(DX_BLENDMODE_ALPHA, 122);
	//DrawGraph(0, 0, Stage5Sample, TRUE);
	//SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	// ãÛíÜè∞ÇÃï`âÊ
	DrawGraph(S5_Flooting_X, S5_Flooting_Y, FlootingImg[5], TRUE);
	DrawGraph(S5_2Flooting_X, S5_2Flooting_Y, FlootingImg[5], TRUE);
	DrawGraph(S5_3Flooting_X, S5_3Flooting_Y, FlootingImg[5], TRUE);

	// èﬂì˚êŒÇÃï`âÊ
	DrawGraph(S5_Stalactite_X, S5_Stalactite_Y, FlootingImg[6], TRUE);		// âE
	DrawGraph(S5_2Stalactite_X, S5_2Stalactite_Y, FlootingImg[6], TRUE);	// ê^ÇÒíÜ
	DrawGraph(S5_3Stalactite_X, S5_3Stalactite_Y, FlootingImg[7], TRUE);	// âE

	// äCÇÃï`âÊ
	DrawGraph(Searight_X, Searight_Y, SeaImg, TRUE);
	DrawGraph(Sealeft_X, Sealeft_Y, SeaImg, TRUE);

	// ínñ ÇÃï`âÊ
	DrawGraph(S1_Landright_X, S1_Landright_Y, LandImg[1], TRUE);
	DrawGraph(S1_Landleft_X, S1_Landleft_Y, LandImg[3], TRUE);
}