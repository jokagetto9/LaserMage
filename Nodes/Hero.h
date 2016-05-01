#ifndef HERO_H
#define HERO_H

#include "Mob.h"
#include "Laser/Laser.h"



//********************************* CONSTANTS *********************************


//********************************* INITIALIZATION *********************************



class Hero : public Mob {
public:

	Hero::Hero(){}
	void Hero::	init();	
/*/ Purpose: init inherited members  
Parameter(s): x, z - default zone, theta - facing direction -> 0 = SOUTH
Side Effects:  init tpf, default pos
/*/
	
/*/ Purpose: close hero 
Side Effects:  deletes instance
/*/


//********************************* LOADING *********************************

	void Hero::	loadHero();
/*/ Purpose: load hero data from hero.txt
Precondition(s): hero.txt has valid data
Side Effects: loads pos, col[8]
Triggers: loadInv
/*/
	void Hero::	loadInv();
//	void Hero::	loadInv(ITEMID id, stringstream &ss);
/*/ Purpose: load hero inventory data from hero.txt
Parameter(s): saveFile - hero.txt input stream
Precondition(s): hero.txt is open
Side Effects:  load seeds, food
/*/


//********************************* SAVING *********************************

	void Hero::	saveHero();
/*/ Purpose: save Hero data to hero.txt
Precondition(s): file exists
Side Effects:  Saves postion, col[8], seeds, food
/*/
	
	void Hero::	saveInv();

//********************************* DRAW *********************************

	void Hero::		drawHero(float delta);	
/*/ Purpose: draw hero -> sprite changes by theta and tpf
Parameter(s): frameDelta -> frameTick adjustment
Precondition(s): Once per frame
Side Effects:  draw debug
Triggers: findTheta
/*/

	
	void Hero::		drawLaser();
//********************************* UPDATES *********************************

	void Hero::		physUpdate(int WM, float physDelta);
/*/ Purpose: update vital hero members 30 cycles per second
Parameter(s): WM -> worldSize, physDelta -> ms of movement
Precondition(s): Triggered by physCycle
Triggers: updateSpeedMode, worldWrap, findPlotStage, updateStatus 
/*/




void Hero::		aiUpdate(float aiDelta);
/*/ Purpose: update less precise hero members 4 cycles per second
Parameter(s): aiDelta -> ms of change
Precondition(s): Triggered by aiCycle
Triggers:
/*/

void Hero::		slowaiUpdate();
/*/ Purpose: update slow members 
Precondition(s): Triggered by slow cycle
Triggers:
/*/

void Hero::		updateStatus();
/*/ Purpose: update life and stamina by sleepiness
Precondition(s): status change !!!updatelater!!!
Side Effects:  update life and stamina
/*/
//********************************* ACTIONS *********************************
 
	void Hero::toggleSpeedMode();
/*/ Purpose: toggle between def and turbo
Side Effects:  speedMode - 1 -> 2, !1 -> 1
Triggers: updateSpeedMode
/*/

	
	void Hero::		rest(); 

	void Hero::		move(Oriet o); 
/*/ Purpose: move based on cam theta and key direction
Parameter(s): o - direction relative to camera -> UPLR diagonals
Side Effects:  targetV is updated
Triggers: calcThetaV
/*/
//	void Hero:: collision(BoundingBox &b);
	

//************************************************** MEMBERS ***************************************************
		//hero inventory
		//Inventory inv;

		//Weapon weap; 
		//Crafting craft;	

		// inside a building
		bool inside;
		int plotType;

		// collection of colour gems
		int col[8];		

		int gold; 
		bool testGrid;
		bool unit;

		Laser laser;
		Animation laserAnim;
		

//********************************* MEMBER FUNCTIONS *********************************

	void Hero::laserOn(){laser.active = true;}
	void Hero::laserOff(){laser.active = false;}


	void Hero::		harvestColour(int c){	if ( c < 8) col[c]++; }
/*/ Purpose: add color gems
Parameter(s): color of gem -> 0-7
Precondition(s): action == true, nub.on == true
Side Effects:  increase col[8]
/*/
	
	void Hero::toggleInside();	
/*/ Purpose: inside to outside - outside to inside
Precondition(s): action == true, beside door
Side Effects:  enter building, camera shifts, boundary boxes shift
/*/


//********************************* DEBUG *********************************
	
	void Hero::toggleDebug();	




};

#endif