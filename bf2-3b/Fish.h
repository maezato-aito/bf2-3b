#pragma once

class Fish
{
private:
	int fBoxX,fBoxY,fBoxX2,fBoxY2;
	int fishX, fishY;
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