#pragma once

class Bubble
{
private:
	int bubbleFlg;
public:

	//�A�̈ʒu
	float bubbleX;
	float bubbleY;

	//�A�̏㏸��
	float bubbleUp;

	//�A�̉��̈ړ���
	float bubbleSide;

	//�A�̉E��
	float bX0;
	float bY0;

	//�A�̍���
	float bX1;
	float bY1;

	//�摜
	int bubbleImg[4];

	//�A�j���[�V�����p�J�E���^
	int bubbleC;
	int bubbleAC;

	//�A�̎�ނ̏���
	int bAv;

	int b;
	//�R���X�g���N�^
	Bubble();
	//�f�X�g���N�^
	~Bubble();
	//�A�b�v�f�[�g
	void Update();
	//�`��
	void Draw();

};