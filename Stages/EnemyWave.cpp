//********************************* INITIALIZATION *********************************
#include "EnemyWave.h"
EnemyWave::EnemyWave(EnemyType et){	
	enemy = et;
	mirrored = false;
	quantity = 1;
	centerTheta = 0;
	clustering = 10;
	dist = 60;
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

