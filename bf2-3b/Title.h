#pragma once
#include "AbstractScene.h"

class Title : public AbstractScene
{
private:
	int TitleLogoimage;	// �^�C�g�����S�摜
	int TitleOimage;	// options�i�I�����j
	int TitleNOCimage; //name of company�i�Ж�)

	int TitleBimage[4];//�^�C�g���̕��D

	int bCount;
	int animImage;

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

