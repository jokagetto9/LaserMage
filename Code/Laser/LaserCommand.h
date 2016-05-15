#ifndef LASERCOMMAND_H
#define LASERCOMMAND_H
#include "../BaseEngine/Utility/Command.h"
#include "../BaseEngine/Entities/Players.h"

//********************************* CONSTANTS *********************************

//********************************* INITIALIZATION *********************************

class LaserCommand : public Command {
public: 
	void LaserCommand::	set(bool b){on = b;}
	void LaserCommand::	exec(Players& P){
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