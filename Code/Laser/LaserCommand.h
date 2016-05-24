#ifndef LASERCOMMAND_H
#define LASERCOMMAND_H
#include "../BaseEngine/Command.h"
#include "../BaseEngine/Entities/Actors.h"

//********************************* CONSTANTS *********************************

//********************************* INITIALIZATION *********************************

class LaserCommand : public Command {
public: 
	void LaserCommand::	set(bool b){on = b;}
	void LaserCommand::	exec(Actor& a){
		if (on){
			//h.laserOn();
		}else{
			//h.laserOff();
		}
	}
private:
	bool on;
};
#endif