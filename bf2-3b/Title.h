#pragma once
#include "AbstractScene.h"

class Title : public AbstractScene
{
private:
	int Titleimage;	// �^�C�g���摜

public:

	// �R���X�g���N�^
	Title();
	// �f�X�g���N�^
	~Title();

	//�`��ȊO�̏���
	AbstractScene* Update()override;

	//�`�揈��
	void Draw()const override;
};

