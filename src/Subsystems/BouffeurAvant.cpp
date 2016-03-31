// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.




#include "BouffeurAvant.h"
#include "../RobotMap.h"
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
#include "../Commands/BSpinAvant.h"
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS

double BouffeurAvant::potBas(0.4);
double BouffeurAvant::potHaut(0.045);
double BouffeurAvant::potLoad(0.538);
double BouffeurAvant::potLent(0.3);


BouffeurAvant::BouffeurAvant() : Subsystem("BouffeurAvant") {
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
    spin = RobotMap::bouffeurAvantspin;
    monte = RobotMap::bouffeurAvantmonte;
    pot = RobotMap::bouffeurAvantpot;
    limit = RobotMap::bouffeurAvantlimit;
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
    m_isGoingUp = false;
    m_reaching = false;
    m_setpoint = 0.34;
}

void BouffeurAvant::InitDefaultCommand() {


}

void BouffeurAvant::Up() {
	/*
	double valeur(pot->Get());

	if (valeur >= potHaut) {

		if(valeur > potLent)
			monte->Set(0.4);
		else
			monte->Set(0.2);
	}
	*/

	monte->Set(0.4);
}

void BouffeurAvant::Down() {
/*
	double valeur(pot->Get());

	if (valeur <= potBas) {

		if(valeur > potLent) {
			monte->Set(-0.1);
		}

		else {
			monte->Set(-0.2);
		}
	}
	*/
	monte->Set(-0.2);
}


void BouffeurAvant::Stop() {
	monte->Set(0);
	m_reaching = false;
}


void BouffeurAvant::Spin() {

	std::static_pointer_cast<VictorSP>(spin)->SetSafetyEnabled(false);
	spin->Set(1);

}

void BouffeurAvant::SpinLent() {
	std::static_pointer_cast<VictorSP>(spin)->SetSafetyEnabled(false);
	spin->Set(0.5);

}

void BouffeurAvant::StopSpin() {
	spin->Set(0);
	std::static_pointer_cast<VictorSP>(spin)->SetSafetyEnabled(true);
	std::static_pointer_cast<VictorSP>(spin)->StopMotor();
}
/*
void BouffeurAvant::Reach() {

	if(!HasReached()) {

		m_reaching = true;


		double point(pot->Get());

		if (point < m_setpoint){

				Down();

			m_isGoingUp = false;
		}
		else  {
			Up();
			m_isGoingUp = true;
		}
	}

}



void BouffeurAvant::ReachMaintien() {

	double point(pot->Get());


	if (point < m_setpoint - 0.008){

			monte->Set(-0.05);

		m_isGoingUp = false;
	}
	else if(point > m_setpoint + 0.008)  {
		monte->Set(0.3);
		m_isGoingUp = true;
	}
	else {
		Maintien();
	}



}

void BouffeurAvant::SetSetpoint(double setpoint){
	m_setpoint = setpoint;
}

void BouffeurAvant::SetSetpoint(Position setpoint){
	if (setpoint == Haut){
		m_setpoint = potHaut;
	}
	else if(setpoint == Bas){
		m_setpoint = potBas;
	}
	else if(setpoint == Load){
		m_setpoint = potLoad;
	}
}
void BouffeurAvant::Maintien() {
	if(pot->Get() > potHaut)
		monte->Set(0.1);
}


bool BouffeurAvant::HasReached() {

	if (m_reaching) {
		bool doneReaching;
		doneReaching = (m_isGoingUp == (pot->Get() <= m_setpoint));
		if (doneReaching)
			m_reaching = false;
		return doneReaching;
	}

	else {
		return (pot->Get() < m_setpoint + 0.01) && (pot->Get() > m_setpoint - 0.01);
	}


}

*/

bool BouffeurAvant::IsPressed() {

	return !limit->Get();
}
double BouffeurAvant::GetPot() {
	return pot->Get();
}
// Put methods for controlling this subsystem
// here. Call these from Commands.

