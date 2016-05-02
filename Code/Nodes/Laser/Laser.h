#ifndef LASER_H
#define LASER_H

#include "../../BaseEngine/lib.h"


//********************************* CONSTANTS *********************************


//********************************* INITIALIZATION *********************************



class Laser{
public:

//********************************* LOADING *********************************

	Laser::	Laser();
	void Laser::	loadLaser();



//********************************* DRAW *********************************

	void Laser::		draw();	


	void Laser::		drawCursor(float x, float y);	

//********************************* UPDATES *********************************

	void Laser::		physUpdate(float physDelta);


void Laser::		rapidUpdate(float aiDelta);


void Laser::		slowaiUpdate();


//********************************* ACTIONS *********************************


//************************************************** MEMBERS ***************************************************
		bool active;
		float flicker;
		int flickSign;

//********************************* MEMBER FUNCTIONS *********************************



//********************************* DEBUG *********************************


//********************************* SINGLETON *********************************

};

#endif