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

void Laser::draw(){
	glDisable(GL_TEXTURE_2D); glUseProgram(NULL);
	float tX; float tY;
	//tX = (G->mX+1)*0.3125-40;
	//tY = (G->mY+1)*0.3125-20;
	int max = 100;
	if (active){
		flicker += 0.4 * G->avgFrameDelta;
		if (flicker >= max) flicker -= max;
		float r = flicker/max;
		glColor4f(.3+r*.7, .8+r*.2, .5+r*.5, 1.0-r/4);
		glLineWidth(PIXELSCALE*2); 	
		
		float xo = 0.5625, yo = 2;
		glBegin(GL_LINES);
			glVertex3f(xo, 3, yo);
			glVertex3f(tX*10, 0, tY*10);
		glEnd();//*/
		glEnable(GL_TEXTURE_2D);
	}

	drawCursor(tX, tY);

}

void Laser::		drawCursor(float x, float y){
	/*/cursor
	//M->qBO.use();
	glBindTexture(GL_TEXTURE_2D, M->cursorBO.cursorT[0]);	
	glUniform1f(M->qBO.texsUni, 0.25);	
	glPushMatrix();
		glTranslatef(x, 0, y);
		//M->qBO.draw();
	glPopMatrix();
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

