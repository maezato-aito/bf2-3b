#pragma once

#include "Player.h"

class GameOver
{
private:
	Player* player;
	int Gameover;
	int pBoxX, pBoxY, pBoxX2, pBoxY2;
	int SEGameOver;
public:

	
	//	�R���X�g���N�^
	GameOver();
	//�f�X�g���N�^
	~GameOver();
	//�A�b�v�f�[�g
	void Update();
	//�`��
	void Draw();
};

