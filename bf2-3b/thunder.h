#pragma once
#include "AbstractScene.h"
#define S1_Thunder_X (200)
#define S1_Thunder_Y (100)

class thunder
{
private:
	int ThunderImg[3];	//���摜
	int T_AnimImg;      //���A�j���摜
public:

	// �R���X�g���N�^
	thunder();
	// �f�X�g���N�^
	~thunder();

	//�`��ȊO�̏���
	void Update();

	//�`�揈��
	void D_thunder();
};
