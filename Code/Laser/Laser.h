#ifndef LASER_H
#define LASER_H

#include "../BaseEngine/Stack/Menu.h"


//********************************* CONSTANTS *********************************


//********************************* INITIALIZATION *********************************



class Laser{
public:

//********************************* LOADING *********************************

	Laser::	Laser();
	void Laser::	loadLaser();



//********************************* DRAW *********************************

	void Laser::		draw(float delta);	


//********************************* UPDATES *********************************

	void Laser::		physUpdate(float physDelta);


void Laser::		rapidUpdate(float aiDelta);


void Laser::		slowaiUpdate();


//********************************* ACTIONS *********************************
	

//************************************************** MEMBERS ***************************************************
		bool active;
		float flicker;
		int flickSign;

		//float coolDown;
		//float chargeUp;
		//complexity - beam, sparks, 
		//pattern
		//float damage
	

/*/
Laser Types
	Blaster - Rapid fire, rank 2 dmg - advance fire rate/mana usage
	Phaser - steady beam, rank 1 dmg - advance movement speed/beam duration

	flame thrower - fixed length wave - advance length/mana usage

1 - enemy force/laserforce = laser ratio

//*/
//********************************* MEMBER FUNCTIONS *********************************



//********************************* DEBUG *********************************


//********************************* SINGLETON *********************************

};

#endif