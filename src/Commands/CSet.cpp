#include "CSet.h"

CSet::CSet(Position setpoint)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(Robot::catapulte.get());

	m_setpoint = setpoint;
}

// Called just before this Command runs the first time
void CSet::Initialize()
{
	if(m_setpoint == Shoot)
		Robot::catapulte->SetAtShoot();
	else if (m_setpoint == Min)
		Robot::catapulte->SetAtMin();
}

// Called repeatedly when this Command is scheduled to run
void CSet::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool CSet::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void CSet::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CSet::Interrupted()
{

}