#pragma once
class UI
{
private:

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

