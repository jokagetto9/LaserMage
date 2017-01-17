#ifndef PHYSISCSSYSTEM_H
#define PHYSISCSSYSTEM_H

#include "Book.h"

//********************************* CONSTANTS *********************************


//********************************* INITIALIZATION *********************************

class PhysicsSystem  { 
public:
	
	static void PhysicsSystem ::	update();

	static void PhysicsSystem ::	update (float physDelta);

	static void PhysicsSystem ::	update (ID id);

	static void PhysicsSystem::updateGrid(ID id);

		
};
#endif