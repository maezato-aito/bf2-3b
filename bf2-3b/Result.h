#pragma once
#include "AbstractScene.h"
class Result :
    public AbstractScene
{
public:
    //�R���X�g���N�^
    Result();

    //�f�X�g���N�^
    ~Result();

    //�`��ȊO�̏���
    AbstractScene* Update()override;

    //�`�揈��
    void Draw()const override;
};


