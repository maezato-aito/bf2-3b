#include "Pause.h"
#include "Anim.h"
#include "DxLib.h"

Anim::Anim()
{

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
	AnimWork = 0;
	AnimFlg = 0b0000;
	UpdateTime = 0;
	balloon = 0;
}
void Anim::LoadImages() {
	LoadDivGraph("Player_Animation.png", 32, 8, 4, 64, 64, PlayerImage);
}
AbstractScene* Anim::Update()
{
	switch(state) {
	 case STATE::stay:
			if (AnimFlg == 0b0000) {
				if (balloon == 2) {
					PlayerImage = 1;
				}
				if (balloon == 1) {
					PlayerImage = 1 + 4;
				}
				UpdateTime = 0;
				AnimFlg = 0b0100;
			}
	 case STATE::walk:
		if (AnimFlg == 0b0000) {
			if () {

			}
		}
		break;
	 case STATE::fly:
		 if(AnimFlg == 0b0000)
}
	return this;
}

void Anim::Draw() const
{
	
}
