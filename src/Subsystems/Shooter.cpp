#include "Shooter.h"
#include "../RobotMap.h"

Shooter::Shooter() :
		Subsystem("Shooter")
{
	spin = RobotMap::shooterSpin;
	conv = RobotMap::shooterConv;
	limit = RobotMap::shooterLimit;
}

void Shooter::InitDefaultCommand()
{

}

void Shooter::StopConv() {
	conv->Set(0);
}


void Shooter::StopSpin(){
	std::static_pointer_cast<VictorSP>(spin)->SetSafetyEnabled(true);
	spin->Set(0);
}

void Shooter::ConvToBack() {
	if(!IsLoaded())
		conv->Set(0.14);
}

void Shooter::ConvThrow() {
	conv->Set(-1);
}

void Shooter::SpinToBack() {
	spin->Set(0.33);
}

void Shooter::Spin() {
	std::static_pointer_cast<VictorSP>(spin)->SetSafetyEnabled(false);
	spin->Set(-1);
}

bool Shooter::IsLoaded(){
	return !limit->Get();
}
