#pragma once

#include"backlash.h"

class backlash
{
private:
	
public:

	// �R���X�g���N�^
	backlash();
	// �f�X�g���N�^
	~backlash();

	//�`��ȊO�̏���
	void Update()override;

	//�`�揈��
	void Draw() const override;
};
