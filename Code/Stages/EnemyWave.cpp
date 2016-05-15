//********************************* INITIALIZATION *********************************
#include "EnemyWave.h"
EnemyWave::			EnemyWave(){
	glm::vec3 z(32, 0, 0);
	origin = z;
	enemy = CHUCKY;
	mirrored = false;
	quantity = 1;
	centerTheta = 0;
	clustering = 10;
	dist = 50;
}

void EnemyWave::	init(int q, float d){	
	dist = d; 
	quantity = q;

}

void EnemyWave::	configure(float c, float t){
	clustering = c;
	centerTheta = t;
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

void EnemyWave ::		generate(Actors& enemies){
	//Enemy e; e.init(enemy); 
	Rendering r; //set stats and anims
	Translation t; 
	glm::vec3 v;
	float tempTheta = tempTheta = centerTheta + (quantity-1)* clustering/2;   
	for (int i = 0; i < quantity; i++){
		float theta = tempTheta-i*clustering;
		v = calcThetaV(theta);
		v *= dist; 		v += origin;
		t.place(v.x, v.z); 
		enemies.add(r, t);

		if (mirrored && theta >= 0){
			theta = -tempTheta-i*clustering;
			v = calcThetaV(theta);
			v *= dist; v += origin;
			t.place(v.x, v.z); enemies.add(r, t);
		}
	}
}
