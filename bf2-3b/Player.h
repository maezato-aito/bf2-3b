#pragma once
#include "AbstractScene.h"

class Player : public AbstractScene
{
private:
	int InputX = 0, InputY = 0;
	int Playerimg[30];
	int Image;
public:
	int boxX=100, boxY=100, boxX2=150, boxY2=150;
	// �R���X�g���N�^
	Player();
	// �f�X�g���N�^
	~Player();

	//�`��ȊO�̏���
	AbstractScene* Update()override;

	//�`�揈��
	void Draw() const override;
};