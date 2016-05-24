#ifndef PLAYERS_H
#define PLAYERS_H

#include "../BaseEngine/Entities/Actors.h"
//********************************* CONSTANTS *********************************


//********************************* INITIALIZATION *********************************

class Players : public Actors{
	public: 
	Players::	Players(){reserve(1 );}
	
	
	void Players:: P1Update(float physDelta);
	void Players:: P1aiUpdate(float aiDelta);
	
	void Players:: drawP1(float frameDelta);



	glm::vec3 Players::pos(){ return translation[P1].pos();}
	void Players::place(float x, float z){ translation[P1].place(x, z);}



};
#endif