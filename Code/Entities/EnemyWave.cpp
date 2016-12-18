//********************************* INITIALIZATION *********************************
#include "EnemyWave.h"

EnemyWave::			EnemyWave(){
	glm::vec3 z(32, 0, 0);
	origin = z;
	type = 0;
	mirrored = false;
	quantity = 1;
	centerTheta = 0;
	spacing = 10;
	dist = 50;
	trigInd = -1;
	trigTime = 0;
	trigRat = 100;

	activated = false;
	count = 0;
	members.reserve(10);
}


void EnemyWave::	init(int q, float d){	
	dist = d; 
	quantity = q;

}

void EnemyWave::	configure(float c, float t){
	spacing = c;
	centerTheta = t;
}



void EnemyWave::	reset(){
	activated = false;
	count = 0;
	members.clear();
}


void EnemyWave::	initRegion(bool left, int reg){
	centerTheta = 0; 
	//region presets
	if (reg == -1 ){
		centerTheta = (rand() % 13) * 5;
	}else if (reg == 1){
		centerTheta = 25;
	}else if (reg == 2){ 
		centerTheta = 65;
	}else if (reg == 3){
		centerTheta = 120;
	}
	if (!left) centerTheta *= -1; 
}

void EnemyWave ::		generate(){
	reset();
	EntityXZ e = {type, 0, 0};
	glm::vec3 v;
	float tempTheta = tempTheta = centerTheta - (quantity-1)* spacing/2;   
	for (int i = 0; i < quantity; i++){
		float theta = tempTheta+i*spacing;
		v = radialOffset(origin, theta, dist);
		e.x = v.x, e.z = v.z; 
		trackMembers(EntityBuilder::createActor(e));

		if (mirrored && theta >= 0){
			theta = -tempTheta-i*spacing;
			v = radialOffset(origin, theta, dist);
			e.x = v.x, e.z = v.z; 
			trackMembers(EntityBuilder::createActor(e));
		}
	}
}


bool EnemyWave:: waveCriteria(vector<EnemyWave>& enemies){
	if ( trigInd < 0){
		return trigTime <= 0;
	}else {
		try{
			return enemies.at(trigInd).isComplete(trigRat);
		}catch(...){
			cout << "Broken Wave  ";
		}
	}
}

void EnemyWave::	trackMembers(ID ind){
	members.push_back(ind);
	count ++;
}


bool EnemyWave:: isComplete(float rat){	
	float s = size();
	float perc = (float)(s/count);
	float goal = (float)(1 - rat/100);
	if ( perc <= goal){
		return true;
	}else
		return false;
}