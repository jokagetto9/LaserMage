#ifndef LASERCOMMAND_H
#define LASERCOMMAND_H
#include "../BaseEngine/Command.h"

//********************************* CONSTANTS *********************************

//********************************* INITIALIZATION *********************************

class LaserCommand {
public: 
	void LaserCommand::	set(bool b){on = b;}
	void LaserCommand:: updateCursor(int x, int y){mX=x; mY=y;}
	void LaserCommand::	exec(){
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