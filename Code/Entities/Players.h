#ifndef PLAYERS_H
#define PLAYERS_H

#include "../BaseEngine/Entities/Actors.h"
//********************************* CONSTANTS *********************************
const ID P1 = 0;
const ID P2 = 1; 

//********************************* INITIALIZATION *********************************

class Players : public Actors{
	public: 
	Players::	Players(){reserve(2);}
	
	
	void Players:: P1Update(float physDelta);
	void Players:: P1aiUpdate(float aiDelta);
	
	void Players:: drawP1(float frameDelta);
	void Players:: drawP2(float frameDelta);



	glm::vec3 Players::pos(){ return location[P1].pos();}
	void Players::placeP1(float x, float z){ location[P1].place(x, z);}
	void Players::placeP2(float x, float z){ location[P2].place(x, z);}



};
#endif