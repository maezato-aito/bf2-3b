#pragma once
#include "AbstractScene.h"

class Enemy
{
private:
	int EnemyG_img[18];
	int EnemyP_img[18];
	int EnemyR_img[18];
public:
	// �R���X�g���N�^
	Enemy();
	// �f�X�g���N�^
	~Enemy();
	//�`��ȊO�̏���
	void Update();

	//�`�揈��
	void Draw() const;
};

