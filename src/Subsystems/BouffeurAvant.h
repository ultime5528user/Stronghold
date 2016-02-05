// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#ifndef BOUFFEURAVANT_H
#define BOUFFEURAVANT_H
#include "Commands/Subsystem.h"
#include "WPILib.h"

/**
 *
 *
 * @author ExampleAuthor
 */
class BouffeurAvant: public Subsystem {
private:
	// It's desirable that everything possible is private except
	// for methods that implement subsystem capabilities
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	std::shared_ptr<SpeedController> spin;
	std::shared_ptr<SpeedController> monte;
	std::shared_ptr<AnalogPotentiometer> pot;
	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS

	bool m_isGoingUp;
	bool m_reaching;
	double m_setpoint;

public:

	static double potMax;
	static double potMin;//jsuis bo af -�mile, 2016
	static double potLoad;

	BouffeurAvant();
	void InitDefaultCommand();
	void Up();
	void Down();
	void Stop();
	void Spin();
	void StopSpin();
	void SetSetpoint(double setpoint);
	void Reach();
	bool MaxAtteint();
	bool MinAtteint();
	bool HasReached();

	double GetPot();

	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS
	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS
};

#endif
