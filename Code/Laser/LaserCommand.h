#ifndef LASERCOMMAND_H
#define LASERCOMMAND_H
#include "../BaseEngine/Template/Command.h"
#include "../Entities/Book.h"

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



class RotationRefresh: public Command{
public:
  void exec(Entity& e) {
		int tweak = 0;
		if (!e.st->still() && notZero(e.mot_.speed)) 
			tweak = e.ani_.frameTick(delta);


		camTheta = C->getCameraTheta(e.loc_.pos(), false);	
		camTheta -= e.loc_.theta;
		tweak += e.ani_.getThetaIndex(camTheta);
		e.ren_.texIndex = tweak;
  }

  float delta, camTheta;

};


#endif