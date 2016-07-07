//********************************* INITIALIZATION *********************************
#include "Laser.h"

Laser::	Laser(){
	active = false;
	flicker = 0;
	flickSign = 1;
}



//********************************* LOADING *********************************

void Laser::	loadLaser(){


}
//********************************* DRAW *********************************


void Laser::draw(float delta){
	//
	//glDisable(GL_TEXTURE_2D); glUseProgram(NULL);
	float tX; float tY;

	int max = 100;
	if (active){
		flicker += 0.4 * delta;
		if (flicker >= max) flicker -= max;
		float r = flicker/max;
		glColor4f(.3+r*.7, .8+r*.2, .5+r*.5, 1.0-r/4);
		glLineWidth(PIXELSCALE*2); 	
		
		float xo = 0.5625, yo = 2;
		glBegin(GL_LINES);
			glVertex3f(xo, 3, yo);
			glVertex3f(tX*10, 0, tY*10);
		glEnd();
		glEnable(GL_TEXTURE_2D);
	}

	//*/

}



//********************************* UPDATES *********************************

void Laser::physUpdate(float physDelta){	

}





void Laser::		rapidUpdate(float aiDelta){

}



void Laser::		slowaiUpdate(){

}
//********************************* ACTIONS *********************************


//********************************* MEMBER FUNCTIONS *********************************




//********************************* TEST FUNCTIONS *********************************

