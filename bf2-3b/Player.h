#pragma once
#include "AbstractScene.h"

class Player : public AbstractScene
{
private:
	int InputX = 0, InputY = 0;
	
public:
	int boxX, boxY, boxX2, boxY2;
	// �R���X�g���N�^
	Player();
	// �f�X�g���N�^
	~Player();

	//�`��ȊO�̏���
	AbstractScene* Update()override;

	//�`�揈��
	void Draw() const override;
};