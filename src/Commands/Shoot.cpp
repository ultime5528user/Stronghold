#include "Shoot.h"
#include "CSet.h"
#include "Analyse.h"
#include "Tourner.h"
#include "Avancer.h"
#include "CSpin.h"
#include "CShoot.h"


Shoot::Shoot()
{
	// Add Commands here:
	// e.g. AddSequential(new Command1());
	//      AddSequential(new Command2());
	// these will run in order.

	// To run multiple commands at the same time,
	// use AddParallel()
	// e.g. AddParallel(new Command1());
	//      AddSequential(new Command2());
	// Command1 and Command2 will run in parallel.

	// A command group will require all of the subsystems that each member
	// would require.
	// e.g. if Command1 requires chassis, and Command2 requires arm,
	// a CommandGroup containing them would require both the chassis and the
	// arm.
	AddSequential(new CSet(CSet::Position::Shoot));
	//AddSequential(new Analyse());
	//AddSequential(new Tourner(Camera::angle));
	//AddSequential(new Avancer(Camera::distance));
	AddSequential(new CSpin());
	AddSequential(new CShoot());
	AddSequential(new CSet(CSet::Position::Min));


}
