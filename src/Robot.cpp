	// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "Robot.h"

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INITIALIZATION
std::shared_ptr<Catapulte> Robot::catapulte;
std::shared_ptr<BouffeurAvant> Robot::bouffeurAvant;
std::shared_ptr<RouesPivot> Robot::rouesPivot;
std::shared_ptr<BasePilotable> Robot::basePilotable;
std::unique_ptr<OI> Robot::oi;
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INITIALIZATION
std::shared_ptr<Camera> Robot::camera;
std::shared_ptr<Shooter> Robot::shooter;


void Robot::RobotInit() {
	RobotMap::init();
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
    catapulte.reset(new Catapulte());
    bouffeurAvant.reset(new BouffeurAvant());
    rouesPivot.reset(new RouesPivot());
    basePilotable.reset(new BasePilotable());
	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
	// This MUST be here. If the OI creates Commands (which it very likely
	// will), constructing it during the construction of CommandBase (from
	// which commands extend), subsystems are not guaranteed to be
	// yet. Thus, their requires() statements may grab null pointers. Bad
	// news. Don't move it.
	oi.reset(new OI());
	camera.reset(new Camera());
	shooter.reset(new Shooter());
	// instantiate the command used for the autonomous period
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=AUTONOMOUS
	autonomousCommand.reset(new Autonomous());
	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=AUTONOMOUS
  }

/**
 * This function is called when the disabled button is hit.
 * You can use it to reset subsystems before shutting down.
 */
void Robot::DisabledInit(){

}

void Robot::DisabledPeriodic() {
	Scheduler::GetInstance()->Run();
}

void Robot::AutonomousInit() {
	if (autonomousCommand.get() != nullptr)
		autonomousCommand->Start();
}

void Robot::AutonomousPeriodic() {
	Scheduler::GetInstance()->Run();
}

void Robot::TeleopInit() {
	// This makes sure that the autonomous stops running when
	// teleop starts running. If you want the autonomous to
	// continue until interrupted by another command, remove
	// these lines or comment it out.
	if (autonomousCommand.get() != nullptr)
		autonomousCommand->Cancel();
/*
	BouffeurAvant::potMax = prefs->GetDouble("MaximumAvant", 0.34);
	BouffeurAvant::potMin = prefs->GetDouble("MinimumAvant", 0);

	Catapulte::potMax = prefs->GetDouble("MaximumCatapulte", 0.4);
	Catapulte::potMin = prefs->GetDouble("MinimumCatapulte", 0.275);
	Catapulte::potShoot = prefs->GetDouble("ShootCatapulte", 0.280);*/
/*
 *
 *
	Camera::hueMin = prefs->GetDouble("HueMin", 31);
	Camera::hueMax = prefs->GetDouble("HueMax", 74);
	Camera::satMin = prefs->GetDouble("SatMin", 7);
	Camera::satMax = prefs->GetDouble("SatMax", 64);
	Camera::valMin = prefs->GetDouble("ValMin", 39);
	Camera::valMax = prefs->GetDouble("ValMax", 116);*/



}

void Robot::TeleopPeriodic() {
	Scheduler::GetInstance()->Run();

	SmartDashboard::PutNumber("PotAvant", Robot::bouffeurAvant->GetPot());
	SmartDashboard::PutNumber("PotArriere", Robot::bouffeurArriere->GetPot());

}

void Robot::TestPeriodic() {
	lw->Run();
}

START_ROBOT_CLASS(Robot);

