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
	return this;
}

void GameMain::Draw() const
{
	Thunder->D_thunder();
	stage->Stage2();
	PlayChar->Draw();
	EnemyChar->Draw();
	bubble->Draw();
	fish->Draw();
	ui->Draw();
	DrawFormatString(640, 360, 0xffffff, "GameMain");
	gameover->Draw();
}

