#ifndef ENTITYBUILDER_H
#define ENTITYBUILDER_H


#include "Book.h"
#include "AISystem.h"

//********************************* CONSTANTS *********************************



//********************************* INITIALIZATION *********************************

class EntityBuilder {
	public: 
	EntityBuilder::	EntityBuilder(){}


//********************************* INSERT *********************************
	
	static ID EntityBuilder ::	createProp (EntityXZ ent);
	static ID EntityBuilder ::	createParticle (EntityXZ ent);		
	static ID EntityBuilder:: createActor(EntityXZ ent);
	
	static ID EntityBuilder:: createHero();


};

#endif