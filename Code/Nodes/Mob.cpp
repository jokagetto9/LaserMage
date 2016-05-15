//********************************* INITIALIZATION *********************************
#include "Mob.h"

void Mob::init(){
	speed = glm::vec3(0.0); prevPos = glm::vec3(0.0);	
	maxS = RUN_MAX_SPEED;
	targetV = randomDirection(RUN_MAX_ACCEL);
	walkAnim.init(WALK8);

	//stats = BASESTATS;
	//move = BASEMOVEMENT;

}

//********************************* DRAW *********************************

void Mob::draw(float frameDelta){

	float camTheta;
	camTheta =  C->getCameraTheta(pos(), false);	
	camTheta -= theta;
	
	translate();

	walkAnim.draw(camTheta, frameDelta);

	glPopMatrix(); //}	
}


//********************************* UPDATES *********************************

void Mob::physUpdate(int WM, float physDelta){
	updatePosVel(physDelta);
	//worldWrap(WM); 
	//findPlotStage();	
	findSpeedTheta();
	//updateStatus(); 
}

void Mob::		updatePosVel(float physDelta){
	float maxChange = maxS * physDelta;	// max speed change per physics frame

	if (notZero(targetV)){	
		if (false){//targetV.x != 0 && targetV.z != 0){	
			if (targetV.x > 0)	targetV.x = 1;
			else				targetV.x = -1;
			if (targetV.z > 0)	targetV.z = 1;
			else				targetV.z = -1;

			targetV *= maxChange; 
		}else 
		truncate (targetV, maxChange);
		speed = targetV;	
						
	}else{											// different rules for stopping
		speed = glm::vec3(0.0);
	}
	prevPos = glm::vec3(xPos, yPos, zPos);			// track last position for collision detection
	
	xPos += speed.x; zPos += speed.z;	//move according to speed for physDelta ms


	//round position!
}

void Mob::	updateSpeedMode(int u){
	if (u >= 0) speedMode = u;
	// change maxS and ticks per second
	if (speedMode == 1) {
		walkAnim.setTPF(100); maxS = RUN_MAX_SPEED; 
	}else if (speedMode == 2) {
		walkAnim.setTPF(60); maxS = TURBO_SPEED; 
	}else if (speedMode == 0){	
		walkAnim.setTPF(140); maxS = WALK_MAX_SPEED; 
	}else maxS = RUN_MAX_SPEED;;
}


void Mob::		worldWrap(int WM){
	//check boundaries WRAP world coordinates!!
	if (xPos >= WM)		{xPos -= WM; }
	if (xPos < 0)		{xPos += WM; }
	if (zPos >= WM)		{zPos -= WM; }
	if (zPos < 0)		{zPos += WM; }//*/
}



void Mob::aiUpdate(float aiDelta){
	health.update()	;

	/*
	float maxChange = RUN_MAX_ACCEL * aiDelta;
	truncate (targetV, maxChange);	//scale motion to accel rate
	speed += targetV;
	truncate(speed,  RUN_MAX_SPEED);//*/
	

}

void Mob::slowaiUpdate(){
	targetV = randomDirection(RUN_MAX_ACCEL);	
}

void Mob::		updateStatus(){
	
	//status.life = status.maxStamina - health.sleepiness;
	//if ( status.life < status.stamina) status.stamina = status.life;
}


void Mob::eat(int id){
	health.digest(id);

}




//********************************* MEMBER FUNCTIONS *********************************

void Mob::previous(){
	xPos = prevPos.x;
	yPos = prevPos.y;
	zPos = prevPos.z;
	speed = glm::vec3(0.0);
}

void Mob::findSpeedTheta(){ 
	if (speed.x == 0 && speed.z == 0){}
	else theta = findTheta(speed);
	
}

glm::vec3 Mob::randomDirection(float s){		
	glm::vec3 v;
	v.x = rand() % 11 - 5;	
	v.z = rand() % 11 - 5;
	v.y = 0;
	glm::normalize(v); 
	v *=  s;
	return v;
}













//********************************* EXTERNAL *********************************

void truncate(glm::vec3 &v, float max){	

	if (glm::length2(v) > max * max){ 		
		v = glm::normalize(v); 
		v *= max;
	}
}

