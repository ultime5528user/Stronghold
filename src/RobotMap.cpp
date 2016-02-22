// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "RobotMap.h"
#include "LiveWindow/LiveWindow.h"


// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=ALLOCATION
std::shared_ptr<SpeedController> RobotMap::catapulteMonte;
std::shared_ptr<SpeedController> RobotMap::shooterConv;
std::shared_ptr<SpeedController> RobotMap::shooterSpin;
std::shared_ptr<SpeedController> RobotMap::bouffeurAvantspin;
std::shared_ptr<SpeedController> RobotMap::bouffeurAvantmonte;
std::shared_ptr<AnalogPotentiometer> RobotMap::bouffeurAvantpot;
std::shared_ptr<DoubleSolenoid> RobotMap::rouesPivotpistonGauche;
std::shared_ptr<DoubleSolenoid> RobotMap::rouesPivotpistonDroit;
std::shared_ptr<SpeedController> RobotMap::basePilotabledriveGauche;
std::shared_ptr<SpeedController> RobotMap::basePilotabledriveDroite;
std::shared_ptr<RobotDrive> RobotMap::basePilotableDrive;
std::shared_ptr<Encoder> RobotMap::basePilotableencoGauche;
std::shared_ptr<Encoder> RobotMap::basePilotableencoDroite;
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=ALLOCATION

std::shared_ptr<AnalogPotentiometer> RobotMap::catapultepot;
std::shared_ptr<ADXRS450_Gyro> RobotMap::basePilotableGyro;
std::shared_ptr<USBCamera> RobotMap::cameraCam;
std::shared_ptr<DigitalInput> RobotMap::shooterLimit;
std::shared_ptr<DigitalInput> RobotMap::bouffeurAvantlimit;


void RobotMap::init() {
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
    LiveWindow *lw = LiveWindow::GetInstance();


    catapulteMonte.reset(new VictorSP(8));
    lw->AddActuator("Catapulte", "Monte", std::static_pointer_cast<VictorSP>(catapulteMonte));
    
    bouffeurAvantspin.reset(new VictorSP(5));
    lw->AddActuator("BouffeurAvant", "spin", std::static_pointer_cast<VictorSP>(bouffeurAvantspin));
    
    bouffeurAvantmonte.reset(new VictorSP(4));
    lw->AddActuator("BouffeurAvant", "monte", std::static_pointer_cast<VictorSP>(bouffeurAvantmonte));
    
    bouffeurAvantpot.reset(new AnalogPotentiometer(1, 1.0, 0.0));
    lw->AddSensor("BouffeurAvant", "pot", bouffeurAvantpot);
    
    rouesPivotpistonGauche.reset(new DoubleSolenoid(0, 1));
    LiveWindow::GetInstance()->AddActuator("RouesPivot", "Piston gauche", rouesPivotpistonGauche);
    
    rouesPivotpistonDroit.reset(new DoubleSolenoid(2, 3));
    LiveWindow::GetInstance()->AddActuator("RouesPivot", "Piston droit", rouesPivotpistonDroit);
    
    basePilotabledriveGauche.reset(new VictorSP(0));
    lw->AddActuator("BasePilotable", "driveGauche", std::static_pointer_cast<VictorSP>(basePilotabledriveGauche));
    
    basePilotabledriveDroite.reset(new VictorSP(1));
    lw->AddActuator("BasePilotable", "driveDroite", std::static_pointer_cast<VictorSP>(basePilotabledriveDroite));
    
    basePilotableDrive.reset(new RobotDrive(basePilotabledriveGauche, basePilotabledriveDroite));
    basePilotableDrive->SetInvertedMotor(RobotDrive::MotorType::kRearLeftMotor, true);
    basePilotableDrive->SetInvertedMotor(RobotDrive::MotorType::kRearRightMotor, true);
    basePilotableDrive->SetSafetyEnabled(true);
    basePilotableDrive->SetExpiration(0.1);
    basePilotableDrive->SetSensitivity(0.5);
    basePilotableDrive->SetMaxOutput(1);

    basePilotableencoGauche.reset(new Encoder(0, 1, false, Encoder::k4X));
    lw->AddSensor("BasePilotable", "encoGauche", basePilotableencoGauche);
    basePilotableencoGauche->SetDistancePerPulse(1.0);
    basePilotableencoGauche->SetPIDSourceType(PIDSourceType::kRate);

    basePilotableencoDroite.reset(new Encoder(2, 3, false, Encoder::k4X));
    lw->AddSensor("BasePilotable", "encoDroite", basePilotableencoDroite);
    basePilotableencoDroite->SetDistancePerPulse(1.0);
    basePilotableencoDroite->SetPIDSourceType(PIDSourceType::kRate);
/*
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
    basePilotableGyro.reset(new ADXRS450_Gyro(SPI::Port::kOnboardCS0));
    lw->AddSensor("BasePilotable", "Gyro", basePilotableGyro);
*/

    shooterConv.reset(new VictorSP(6));
    lw->AddActuator("Shooter", "Convoyeur", std::static_pointer_cast<VictorSP>(shooterConv));

    shooterSpin.reset(new VictorSP(7));
    lw->AddActuator("Shooter", "Monte", std::static_pointer_cast<VictorSP>(shooterSpin));

    catapultepot.reset(new AnalogPotentiometer(0, 1.0, 0.0));
    lw->AddSensor("Catapulte", "pot", catapultepot);

    //cameraCam.reset(new USBCamera("cam0", true));

    shooterLimit.reset(new DigitalInput(4));
    lw->AddSensor("Shooter", "Switch", shooterLimit);

    bouffeurAvantlimit.reset(new DigitalInput(5));
    lw->AddSensor("BouffeurAvant", "Switch", bouffeurAvantlimit);

}
