#pragma once
#include "AbstractScene.h"
#include "Stage.h"
#include"Player.h"
#include "Enemy.h"

class GameMain :
    public AbstractScene
{
private:
    Stage* stage;
    Player* PlayChar;
    Enemy* EnemyChar;
public:
    //�R���X�g���N�^
    GameMain();

    //�f�X�g���N�^
    ~GameMain();

    //�`��ȊO�̏���
    AbstractScene* Update()override;

    //�`�揈��
    void Draw()const override;
};


