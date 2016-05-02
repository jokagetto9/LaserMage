//********************************* INITIALIZATION *********************************

#include "Hero.h"


// move player into middle of zone x, z 
void Hero::init(){

	speed = glm::vec3(0.0); prevPos = glm::vec3(0.0);	
	maxS = RUN_MAX_SPEED;
	
	testGrid  = false;
	unit = true;  inside = false;
	theta = 180;
	prevTheta = 180;
	place(32, 32);
	updateSpeedMode(1);
	walkAnim.init(WALK12);
	laserAnim.init(CYCLIC);
}

//********************************* LOADING *********************************

void Hero::	loadHero(){
	string inputLine; 
	float inputValue; 	int cntr = 0;

	ifstream saveFile ("hero.txt");
	if (saveFile.is_open())  {

		getline (saveFile, inputLine); stringstream ss(inputLine);
		while (cntr < 2 && ss >> inputValue) {
			if (cntr == 0) xPos = inputValue;
			else if (cntr == 1) zPos = inputValue;
			cntr++;
		}
		cntr = 0;
		getline (saveFile, inputLine);  ss = stringstream(inputLine);
		while (cntr < 5 && ss >> inputValue) {
			if (cntr == 0) health.maxLife = inputValue;
			else if (cntr == 1)  health.life = inputValue;
			else if (cntr == 2)  health.maxStamina = inputValue;
			else if (cntr == 3)  health.stamina = inputValue;
			else if (cntr == 4)  health.sleepiness = inputValue;
			cntr++;
		}

		saveFile.close();
	}

	//loadInv();

}
//********************************* SAVING *********************************

void Hero::	saveHero(){
	ofstream saveFile ("hero.txt");
	if (saveFile.is_open())  {
		// position
		saveFile << (int)xPos << " " << (int)zPos << endl;		
		saveFile << health.maxLife << " " << health.life << " " <<  health.maxStamina << " " << health.stamina << " " << health.sleepiness << endl;
		saveFile.close();
	}	
		
	
	saveInv();
}

void Hero::	saveInv(){
	ofstream saveFile ("inv.txt");
	if (saveFile.is_open())  {
			// colours
		for ( int i = 0 ; i < 8 ; i++)
			saveFile << col[i] << " ";
		saveFile << endl;
		
		/*/inventory
		Seed * seed; 
		int s = H->inv.itemCount(SEED_id);
		for (int i = 0; i < s; i++){
			seed = H->inv.getSeed(i);
			saveFile << seed->type << " " << seed->quantity << " ";		
		} 
		saveFile << endl;		
		Food * food; 
		s = H->inv.itemCount(FOOD_id);
		for (int i = 0; i < s; i++){
			food = H->inv.getFood(i);
			saveFile << food->type << " " << food->quantity << " " << food->quality << " ";		
		}    //*/
		saveFile.close();
	}else		cout << "Failed to save inventory." << endl;

}

//********************************* DRAW *********************************

void Hero::drawHero(float delta){
	M->gridBO.prepHero();
	float camTheta;
	camTheta =  C->getCameraTheta(pos(), false);	
	camTheta -= theta;
	
	translate();	
		if (!laser.active) 
			walkAnim.draw(speed, camTheta, delta);
		else {

			laserAnim.draw(delta);
			M->gridBO.drawx16(11);
		}
		laser.draw();

	glPopMatrix(); //}	

}


//********************************* UPDATES *********************************

void Hero::physUpdate(int WM, float physDelta){	
	updatePosVel(physDelta);
	worldWrap(WM); 
	findPlotStage();	
	findSpeedTheta();
	updateStatus();
}





void Hero::		aiUpdate(float aiDelta){
	health.update();
	laser.rapidUpdate(aiDelta);
}

void Hero::		updateStatus(){
	health.life = health.maxStamina - health.sleepiness;
	if ( health.life < health.stamina) health.stamina = health.life;
}

void Hero::		slowaiUpdate(){
	health.slowUpdate();

}
//********************************* ACTIONS *********************************
void Hero::toggleSpeedMode(){
	if (speedMode == 1) 	updateSpeedMode(2);
	else updateSpeedMode(1);	
}


void Hero::		rest(){
	health.sleepiness -= 18;
	if (health.sleepiness < 0) 
		health.sleepiness = 0;
}


// move hero according to the camera theta
void Hero::move(Oriet o){
	float tempTheta; glm::vec3 camV;
	if (C->mode == 0) tempTheta = C->theta + D_ROTATE[o];	
	if (C->mode == 1) {	
		camV =  pos() - C->lockPos;
		tempTheta = findTheta(camV) + D_ROTATE[o];
	}
	targetV = calcThetaV(tempTheta);
}

/*/
void Hero:: collision(BoundingBox &b){
	glm::vec3 v = pos(); glm::vec3 pv = prevPos;
	if(v.x > b.x1 && v.x < b.x2 && v.z > b.z1 && v.z < b.z2) {
		//test prev position
		if (pv.x > b.x1 && pv.x < b.x2)	{	
			if			(pv.z <= b.z1)		zPos = b.z1;
			else if		(pv.z >= b.z2)		zPos = b.z2;
		}else if (pv.z > b.z1 && pv.z < b.z2){
			if			(pv.x <= b.x1)		xPos = b.x1;
			else if		(pv.x >= b.x2)		xPos = b.x2;
		} else				
			previous();
	}
}
//*/


//********************************* MEMBER FUNCTIONS *********************************

void Hero::toggleInside(){
	if (inside) inside = false;
	else	inside = true;	
}


//********************************* TEST FUNCTIONS *********************************

void Hero::toggleDebug(){
	if (testGrid) 	testGrid = false;
	else testGrid = true;	
}

/*/
apple
brown, boulder
corn
dark
elephant
frog
grass
ice
jellybean
kite
lizard
melon
nut
oatmeal
pink, purple, plant
quilt
ring
snake
tan
urn
violet vase
water whale
xray
yam
zap
/*/