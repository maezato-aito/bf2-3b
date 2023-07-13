#include "GameMain.h"
#include "DxLib.h"
GameMain::GameMain()
{
	stage = new Stage();
	PlayChar = new Player();
	//EnemyChar = new Enemy();
}

GameMain::~GameMain()
{
	delete stage;
	delete PlayChar;
	//delete EnemyChar;
}

AbstractScene* GameMain::Update()
{
	PlayChar->Update();
	return this;
}

void GameMain::Draw() const
{
	
	stage->Stage1();
	PlayChar->Draw();
	//EnemyChar->Draw();
	DrawFormatString(640, 360, 0xffffff, "GameMain");
}

