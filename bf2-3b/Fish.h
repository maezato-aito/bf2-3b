#pragma once

class Fish
{
private:
	int fishBox;
	int pBoxX;
public:

	//�摜�p
	int fishImg[10];
	//	�R���X�g���N�^
	Fish();
	//�f�X�g���N�^
	~Fish();
	//�A�b�v�f�[�g
	void Update();
	//�`��
	void Draw();
};