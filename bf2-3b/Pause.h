#pragma once
#include "AbstractScene.h"
class Pause :
    public AbstractScene
{
public:
    //�R���X�g���N�^
    Pause();

    //�f�X�g���N�^
    ~Pause();

    //�`��ȊO�̏���
    AbstractScene* Update()override;

    //�`�揈��
    void Draw()const override;
};

