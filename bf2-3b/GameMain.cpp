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
}

GameMain::~GameMain()
{
	delete stage;
	delete PlayChar;
	delete EnemyChar;
	delete Thunder;
	delete bubble;
	delete fish;
}

AbstractScene* GameMain::Update()
{
	Thunder->Circle();
	Thunder->Anim();
	Thunder->Update();
	PlayChar->Update();
	EnemyChar->Update();
	bubble->Update();
	fish->Update();
	return this;
}

void GameMain::Draw() const
{
	Thunder->D_thunder();
	stage->Stage1();
	PlayChar->Draw();
	EnemyChar->Draw();
	bubble->Draw();
	fish->Draw();
	DrawFormatString(640, 360, 0xffffff, "GameMain");
	gameover->Draw();
}

