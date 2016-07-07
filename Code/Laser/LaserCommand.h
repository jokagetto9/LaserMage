#ifndef LASERCOMMAND_H
#define LASERCOMMAND_H
#include "../BaseEngine/Command.h"
#include "../BaseEngine/Entities/Actors.h"

//********************************* CONSTANTS *********************************

//********************************* INITIALIZATION *********************************

class LaserCommand {
public: 
	void LaserCommand::	set(bool b){on = b;}
	void LaserCommand:: updateCursor(int x, int y){mX=x; mY=y;}
	void LaserCommand::	exec(Particles * p){
		if (on){
			//h.laserOn();
		}else{
			//h.laserOff();
		}
	}
private:
	bool on;
	int mX, mY;
};



#endif