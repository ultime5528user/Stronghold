// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.




#include "BouffeurArriere.h"
#include "../RobotMap.h"
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
#include "../Commands/BSpinArriere.h"
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS


double BouffeurArriere::potMax(0);
double BouffeurArriere::potMin(0);
double BouffeurArriere::potLoad(0);


BouffeurArriere::BouffeurArriere() : Subsystem("BouffeurArriere") {
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
    spin = RobotMap::bouffeurArrierespin;
    monte = RobotMap::bouffeurArrieremonte;
    pot = RobotMap::bouffeurArrierepot;
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
    isGoingUp = false;
}

void BouffeurArriere::InitDefaultCommand() {
    // Set the default command for a subsystem here.
    // SetDefaultCommand(new MySpecialCommand());
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND

        SetDefaultCommand(new BSpinArriere());
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
}


void BouffeurArriere::Up() {
	monte->Set(0.25);
}

void BouffeurArriere::Down() {
	monte->Set(-0.25);
}
void BouffeurArriere::Stop() {
	monte->Set(0);
}

void BouffeurArriere::SetLoad() {

	if (pot->Get() > potLoad){
		monte->Set(-0.25);
		isGoingUp = false;
	}
	else if (pot->Get() < potLoad) {
		monte->Set(0.25);
		isGoingUp = true;
	}
}

bool BouffeurArriere::IsLoaded() {
	return isGoingUp == (pot->Get() >= potLoad);
}

bool BouffeurArriere::MaxAtteint() {
	return pot->Get() >= potMax;
}

bool BouffeurArriere::MinAtteint() {
	return pot->Get() <= potMin;
}

double BouffeurArriere::GetPot() {
	return pot->Get();
}
// Put methods for controlling this subsystem
// here. Call these from Commands.

