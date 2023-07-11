#include"DxLib.h"
#include"PadController.h"


PadController::PadController()
{
	GetJoypadAnalogInput(&InputX, &InputY, DX_INPUT_PAD1);
}
PadController::~PadController()
{

}
AbstractScene* PadController::Update()
{
	return this;
}

void PadController::Draw() const
{
	
}