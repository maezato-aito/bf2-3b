#pragma once
class UI
{
private:
	int Iimg;
	int Topimg;
	int Numberimg[10];
	int INumber[6];
	int TopNumber[6];
	int Ballonimg;

	int FontHandle;
	int CharGrHandle[10][1];
	int i;
	int j;

public:
	// �R���X�g���N�^
	UI();
	// �f�X�g���N�^
	~UI();
	//�`��ȊO�̏���
	void Update();
	//�`�揈��
	void Draw() const;

	static int BestScore;
	static int NowScore;
};

