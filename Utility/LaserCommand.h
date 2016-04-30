#ifndef LASERCOMMAND_H
#define LASERCOMMAND_H
#include "HeroCommand.h"

//********************************* CONSTANTS *********************************

//********************************* INITIALIZATION *********************************

class LaserCommand : public Command {
public: 
	void LaserCommand::	set(bool b){on = b;}
	void LaserCommand::	exec(Hero &h){
		if (on){
			h.laserOn();
		}else{
			h.laserOff();
		}
	}
private:
	bool on;
};
#endif