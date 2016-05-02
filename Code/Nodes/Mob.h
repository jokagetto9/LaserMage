#ifndef MOB_H
#define MOB_H

#include "Node.h"
#include "Health.h"
#include "../Display/Animation.h"
//********************************* CONSTANTS *********************************

const float TURBO_SPEED = 0.2f;  // m/ms
const float TURBO_ACCEL = 0.0005f;  // m/ms^2
const float WALK_MAX_SPEED = 0.01f;  // m/ms
const float RUN_MAX_SPEED = 0.0125f;//0.00625f;  // m/ms
const float RUN_MAX_ACCEL = RUN_MAX_SPEED;//0.00625f;  // m/ms^2


// reqxp(1) = 1;
//	reqxp(lv+1) = prxp + rxp;

/*
struct Stats		{Level strength, constitution, intel, agility;}; 
const Stats BASESTATS = {z3r0,z3r0,z3r0,z3r0};
struct Weapon		{Level dagger, sword, axe, spear, halberd, staff, bow; }; 
const Weapon BASEWEAPON = {z3r0,z3r0,z3r0,z3r0,z3r0,z3r0,z3r0};
struct Crafting		{Level gardening, ranching, trapping, cooking, needlework, woodwork, smithing, alchemy, enchanting ; }; 
const Crafting BASECRAFTING = {z3r0,z3r0,z3r0,z3r0,z3r0,z3r0,z3r0,z3r0,z3r0};
struct Movement		{Level running, climbing, dodging, deflecting, struggling, blocking, countering;};
const Movement BASEMOVEMENT = {z3r0,z3r0,z3r0,z3r0,z3r0,z3r0,z3r0};
//*/
//enum Alignmt {LWFLGOOD, NTRLGOOD, CHTCGOOD, NTRL, LWFLEVIL, NTRLEVIL, CHTCEVIL};
//********************************* EXTERNAL *********************************

void truncate(glm::vec3 &v, float max);
/*/ Purpose: scale vector to max
Parameter(s):  v - vector, max - max length of vector
Side Effects:  v is normalized and scaled
/*/




//********************************* INITIALIZATION *********************************

class Mob : public Node {
public:

	Mob::Mob(){}
	//Mob:: Node(_sprite);
/*/ Purpose: default constructor /*/

	void Mob::init();
/*/ Purpose: init inherited members  
Side Effects: init tpf, theta - facing direction -> 0 = SOUTH
/*/
	
//********************************* DRAW *********************************

	void Mob::	draw(float frameDelta);
/*/ Purpose: draw sprite -> changes by theta and tpf
Parameter(s): camTheta -> camera theta, frameDelta -> frameTick adjustment
Precondition(s): Once per frame
Triggers: getDirection, if moving -> frameTick 
/*/


//********************************* UPDATES *********************************

	void Mob::		physUpdate(int WM, float physDelta);
/*/ Purpose: update vital members 30 cycles per second
Parameter(s): WM -> worldSize, physDelta -> ms of movement
Precondition(s): Triggered by physCycle
Triggers: worldWrap, findSpeedTheta
/*/

	void Mob::		updatePosVel(float physDelta);
/*/ Purpose: update position by speed, maxS, targetV 
Parameter(s): physDelta -> ms of movement
Side Effects:  sets prevPos
/*/		
		void Mob::		updateSpeedMode(int u);
/*/ Purpose: update Hero's speedMode -> 0-2
Parameter(s): u - new speedMode -> -1 does nothing
Side Effects:  alters ticks per frame and max speed
/*/
	
	void Mob::		worldWrap(int WM);
/*/ Purpose: update position by speed
Parameter(s):  WM -> worldSize
Side Effects:  position can loop around world
/*/
	virtual void Mob::		aiUpdate(float aiDelta);	
/*/ Purpose: update less precise hero members 4 cycles per second
Parameter(s):aiDelta -> ms of change
Precondition(s): Triggered by aiCycle
Triggers:
/*/

void Mob::		slowaiUpdate();
/*/ Purpose: update slow members 
Precondition(s): Triggered by slow cycle
Triggers:
/*/
	void Mob::		updateStatus();
/*/ Purpose: update life and stamina by sleepiness
Precondition(s): status change !!!updatelater!!!
Side Effects:  update life and stamina
/*/

//********************************* ACTIONS *********************************
	void Mob::eat(int id);


//************************************************** MEMBERS ***************************************************
		float prevTheta;

		glm::vec3 speed, targetV, prevPos;	

		XZI zone;
		
		float maxS;
		//speed mode turbo or slow
		int speedMode;

		Health health;
		Animation walkAnim;
		
		bool dead;

		// health stamina etc
		//Stats stats; 
		//Movement move;

//********************************* MEMBER FUNCTIONS *********************************



	glm::vec3 Mob::	pos(){ return glm::vec3(xPos, yPos, zPos);}
/*/ Purpose: get position
Returns: glm::vec3(xPos, yPos, zPos);
/*/

	void Mob::	place(float x, float z){xPos = x; zPos = z;}
/*/ Purpose::: alter position
/*/	

	void Mob::		stop(){targetV = glm::vec3(0.0);}
/*/ Purpose: slow to stop
Side Effects: disable target vector
/*/

	void Mob::		previous();
/*/ Purpose: set previous position
Side Effects: set position to prevPos, abrupt stop
/*/

glm::vec3 Mob::randomDirection(float s);
/*/ Purpose: get random x z vector
Parameter(s):  s - scale for vector
Returns: random vector scaled to max 
/*/

	void Mob::findSpeedTheta();
/*/ Purpose: get theta using speed
Side Effects: theta is according to speed, if stopped do nothing
Triggers: findTheta
/*/


	float Mob::		getDistSQ(glm::vec3 p){	return distSQ(pos(), p);}
/*/ Purpose: get dist squared from sprite
Side Effects: p - another pos
Returns: glm::vec3(xPos, yPos, zPos);
Triggers: distSQ
/*/
		
	void Mob::findPlotStage(){	zone = find(); }
/*/ Purpose: update zone and plot by position
Side Effects:  plot and zone are updated
/*/




	
};
#endif