#pragma once
#include "AbstractScene.h"
#include "Stage.h"
#include"Player.h"
#include "Enemy.h"
#include "thunder.h"
#include"bubble.h"
#include"fish.h"
#include "GameOver.h"
class GameMain :
    public AbstractScene
{
private:
    Stage* stage;
    Player* PlayChar;
    Enemy* EnemyChar;
    thunder* Thunder;
    Bubble* bubble;
    Fish* fish;
    GameOver* gameover;
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


