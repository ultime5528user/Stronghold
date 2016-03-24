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
#include "Commands/Viser.h"

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

    catapulte.reset(new Catapulte());
    bouffeurAvant.reset(new BouffeurAvant());
    rouesPivot.reset(new RouesPivot());
    basePilotable.reset(new BasePilotable());

	oi.reset(new OI());
	camera.reset(new Camera());
	shooter.reset(new Shooter());

	autonomousCommand.reset(new Autonomous());
  }

/**
 * This function is called when the disabled button is hit.
 * You can use it to reset subsystems before shutting down.
 */
void Robot::DisabledInit(){
	Scheduler::GetInstance()->RemoveAll();
	Robot::shooter->StopSpin();
	Robot::shooter->StopConv();
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

	Camera::hueMin = prefs->GetDouble("hueMin", 31);
	Camera::hueMax = prefs->GetDouble("hueMax", 74);
	Camera::satMin = prefs->GetDouble("satMin", 7);
	Camera::satMax = prefs->GetDouble("satMax", 64);
	Camera::valMin = prefs->GetDouble("valMin", 39);
	Camera::valMax = prefs->GetDouble("valMax", 116);
	Camera::aireMin = prefs->GetDouble("aireMin", 200);

	Viser::move = prefs->GetDouble("move", 0.5);
	Viser::rotation = prefs->GetDouble("rotation", 0.5);

	Viser::distance = prefs->GetDouble("distance", 1.2);
	Viser::offsetX = prefs->GetDouble("offsetX", 0.1);
	Viser::distanceOffset = prefs->GetDouble("distanceOffset", 0.1);

	SmartDashboard::PutNumber("AireMin", Camera::aireMin);

	Robot::basePilotable->GyroReset();

}

void Robot::TeleopPeriodic() {
	Scheduler::GetInstance()->Run();
	//SmartDashboard::PutNumber("Gyro", Robot::basePilotable->GetGyroAngle());
	//SmartDashboard::PutNumber("Enco Gauche", Robot::basePilotable->GetEncoGauche());

	/*
	SmartDashboard::PutBoolean("Switch shooter", Robot::shooter->IsLoaded());
	SmartDashboard::PutBoolean("Switch intake", Robot::bouffeurAvant->IsPressed());
	BouffeurAvant::potLoad = prefs->GetDouble("potLoad", 0.538);*/
}

void Robot::TestPeriodic() {
	lw->Run();
}

START_ROBOT_CLASS(Robot);

