#ifndef COLLISIONSYSTEM_H
#define COLLISIONSYSTEM_H

#include "../Entities/Book.h"
#include "AISystem.h"

//********************************* CONSTANTS *********************************


//********************************* INITIALIZATION *********************************

class CollisionSystem  { 
public:
	

	static void CollisionSystem:: checkCollisions();

	static void CollisionSystem:: checkCollisions(ID g1, ID g2);

	static void CollisionSystem:: applyCollisions();

	static void CollisionSystem:: applyCollisions(ID id);


		
};
#endif