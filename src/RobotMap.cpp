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
std::shared_ptr<SpeedController> RobotMap::catapulteshoot;
std::shared_ptr<DigitalInput> RobotMap::catapultelimit;
std::shared_ptr<SpeedController> RobotMap::bouffeurAvantspin;
std::shared_ptr<SpeedController> RobotMap::bouffeurAvantmonte;
std::shared_ptr<AnalogPotentiometer> RobotMap::bouffeurAvantpot;
std::shared_ptr<SpeedController> RobotMap::bouffeurArrierespin;
std::shared_ptr<SpeedController> RobotMap::bouffeurArrieremonte;
std::shared_ptr<AnalogPotentiometer> RobotMap::bouffeurArrierepot;
std::shared_ptr<DoubleSolenoid> RobotMap::rouesPivotpistonGauche;
std::shared_ptr<DoubleSolenoid> RobotMap::rouesPivotpistonDroit;
std::shared_ptr<SpeedController> RobotMap::basePilotabledriveGauche;
std::shared_ptr<SpeedController> RobotMap::basePilotabledriveDroite;
std::shared_ptr<RobotDrive> RobotMap::basePilotableDrive;
std::shared_ptr<Encoder> RobotMap::basePilotableencoGauche;
std::shared_ptr<Encoder> RobotMap::basePilotableencoDroite;
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=ALLOCATION
std::shared_ptr<AnalogGyro> RobotMap::basePilotableGyro;


void RobotMap::init() {
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
    LiveWindow *lw = LiveWindow::GetInstance();

    catapulteshoot.reset(new Talon(0));
    lw->AddActuator("Catapulte", "shoot", (Talon&) catapulteshoot);
    
    catapultelimit.reset(new DigitalInput(0));
    lw->AddSensor("Catapulte", "limit", catapultelimit);
    
    bouffeurAvantspin.reset(new Talon(1));
    lw->AddActuator("BouffeurAvant", "spin", (Talon&) bouffeurAvantspin);
    
    bouffeurAvantmonte.reset(new Talon(2));
    lw->AddActuator("BouffeurAvant", "monte", (Talon&) bouffeurAvantmonte);
    
    bouffeurAvantpot.reset(new AnalogPotentiometer(0, 1.0, 0.0));
    lw->AddSensor("BouffeurAvant", "pot", bouffeurAvantpot);
    
    bouffeurArrierespin.reset(new Talon(3));
    lw->AddActuator("BouffeurArriere", "spin", (Talon&) bouffeurArrierespin);
    
    bouffeurArrieremonte.reset(new Talon(4));
    lw->AddActuator("BouffeurArriere", "monte", (Talon&) bouffeurArrieremonte);
    
    bouffeurArrierepot.reset(new AnalogPotentiometer(1, 1.0, 0.0));
    lw->AddSensor("BouffeurArriere", "pot", bouffeurArrierepot);
    
    rouesPivotpistonGauche.reset(new DoubleSolenoid(0, 0, 1));
    lw->AddActuator("RouesPivot", "pistonGauche", rouesPivotpistonGauche);
    
    rouesPivotpistonDroit.reset(new DoubleSolenoid(0, 2, 3));
    lw->AddActuator("RouesPivot", "pistonDroit", rouesPivotpistonDroit);
    
    basePilotabledriveGauche.reset(new Talon(5));
    lw->AddActuator("BasePilotable", "driveGauche", (Talon&) basePilotabledriveGauche);
    
    basePilotabledriveDroite.reset(new Talon(6));
    lw->AddActuator("BasePilotable", "driveDroite", (Talon&) basePilotabledriveDroite);
    
    basePilotableDrive.reset(new RobotDrive(basePilotabledriveGauche, basePilotabledriveDroite));
    
    basePilotableDrive->SetSafetyEnabled(true);
        basePilotableDrive->SetExpiration(0.1);
        basePilotableDrive->SetSensitivity(0.5);
        basePilotableDrive->SetMaxOutput(1.0);

    basePilotableencoGauche.reset(new Encoder(1, 2, false, Encoder::k4X));
    lw->AddSensor("BasePilotable", "encoGauche", basePilotableencoGauche);
    basePilotableencoGauche->SetDistancePerPulse(1.0);
    basePilotableencoGauche->SetPIDSourceType(PIDSourceType::kRate);
    basePilotableencoDroite.reset(new Encoder(3, 4, false, Encoder::k4X));
    lw->AddSensor("BasePilotable", "encoDroite", basePilotableencoDroite);
    basePilotableencoDroite->SetDistancePerPulse(1.0);
    basePilotableencoDroite->SetPIDSourceType(PIDSourceType::kRate);

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
    basePilotableGyro.reset(new AnalogGyro(2));
    lw->AddSensor("BasePilotable", "Gyro", basePilotableGyro);


}