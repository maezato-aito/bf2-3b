#include "Pause.h"
#include "Anim.h"
#include "DxLib.h"
#include "Player.h"

Anim::Anim()
{
	LoadDivGraph("Player_Animation.png", 32, 8, 4, 64, 64, PlayerImage);
	AnimWork = 0;
	AnimFlg = 0b0000;
	UpdateTime = 0;
	balloon = 0;
	AnimImg = 1;
}

Anim::~Anim()
{
	
}
enum class STATE {
	stay = 0,
	walk,
	fly,
	thunder,
	miss,
};
STATE state;

void Anim::PlayerInit() {
	
}
AbstractScene* Anim::Update()
{
	switch (state) {
	 case STATE::stay:
			if (AnimFlg == 0b0000) {
				if (balloon == 2) {
					AnimImg = 1;
				}
				if (balloon == 1) {
					AnimImg = 1 + 4;
				}
				UpdateTime = 0;
				AnimFlg = 0b0100;

			}
	 /*case STATE::walk:
		if (AnimFlg == 0b0000) {
			if () {

			}
		}
		break;
		case STATE::fly:
		 if(AnimFlg == 0b0000)*/
}
	return this;
}

void Anim::Draw() const
{
	//DrawRotaGraph(boxX, boxY, 4.0f, 0, PlayerImage[AnimImg], TRUE, FALSE);
}
