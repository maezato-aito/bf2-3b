#pragma once
#pragma once
#include "AbstractScene.h"

class Player : public AbstractScene
{
private:

public:

	// �R���X�g���N�^
	Player();
	// �f�X�g���N�^
	~Player();

	//�`��ȊO�̏���
	AbstractScene* Update()override;

	//�`�揈��
	void Draw() const override;
};