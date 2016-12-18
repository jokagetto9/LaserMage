#ifndef BOOK_H
#define BOOK_H

#include "../BaseEngine/Entities/Dictionaries.h"
#include "../BaseEngine/Entities/EntityList.h"

//********************************* CONSTANTS *********************************


//********************************* INITIALIZATION *********************************

class Book  { 
public:



	static Motion& Book::getMotion(ID eIndex){return entities.motion.at(eIndex);}
	static State* Book::getState(ID eIndex){return entities.state.at(eIndex);}


	static PropList props;
	static ParticleList particles;
	static ParticleList enemies;		
	static ParticleList player;		
	static EntityList entities;
		
};



#endif