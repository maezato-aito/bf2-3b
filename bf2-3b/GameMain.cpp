#include "GameMain.h"
#include "DxLib.h"
GameMain::GameMain()
{
	stage = new Stage();
	PlayChar = new Player();
	EnemyChar = new Enemy();
	Thunder = new thunder();
	bubble = new Bubble(); 
	fish = new Fish(); 
	ui = new UI();
	splash = new Splash();
}

GameMain::~GameMain()
{
	delete stage;
	delete PlayChar;
	delete EnemyChar;
	delete Thunder;
	delete bubble;
	delete fish;
	delete ui;
	delete splash;
}

AbstractScene* GameMain::Update()
{
	Thunder->Ball();
	Thunder->Circle();
	Thunder->Anim();
	Thunder->Update();
	PlayChar->Update();
	EnemyChar->Update();
	bubble->Update();
	fish->Update();
	ui->Update();
	splash->Update();
	gameover->Update();
	if (Enemy::enemyFlg == 0) {
		WaitTimer(2000);
		Stage::NowStage += 1;
		EnemyChar->EnemyInit();
	}

	return this;
}

void GameMain::Draw() const
{
	Thunder->D_thunder();
	fish->Draw();
	PlayChar->Draw();
	EnemyChar->Draw();
	switch (Stage::NowStage)
	{
	case 1:
		stage->Stage1();
		break;
	case 2:
		stage->Stage2();
		break;
	case 3:
		stage->Stage3();
		break;
	case 4:
		stage->Stage4();
		break;
	case 5:
		stage->Stage5();
		break;
	case 6:
		Stage::NowStage = 1;
		stage->Stage1();
		break;
	}
	splash->Draw();
	
	bubble->Draw();
	
	ui->Draw();
	DrawFormatString(640, 360, 0xffffff, "GameMain");
	gameover->Draw();
}

