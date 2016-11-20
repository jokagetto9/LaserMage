//********************************* INITIALIZATION *********************************
#include "EnemyWave.h"
#include "../Entities/MonsterBook.h"

EnemyWave::			EnemyWave(){
	glm::vec3 z(32, 0, 0);
	origin = z;
	type = 0;
	mirrored = false;
	quantity = 1;
	centerTheta = 0;
	spacing = 10;
	dist = 50;
}


void EnemyWave::	init(int q, float d){	
	dist = d; 
	quantity = q;

}

void EnemyWave::	configure(float c, float t){
	spacing = c;
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

void EnemyWave ::		generate(EntityList& enemies){
	//Enemy e; e.init(enemy); 
	ID tex = monBook.getProfile(type).tex;
	Rendering r(tex, 0); //set stats and anims
	Animation a = monBook.anim[type];
	Motion m = Motion(monBook.max[type]);
	Location l; 
	glm::vec3 v;
	float tempTheta = tempTheta = centerTheta - (quantity-1)* spacing/2;   
	for (int i = 0; i < quantity; i++){
		a.randomTick();
		float theta = tempTheta+i*spacing;
		v = radialOffset(origin, theta, dist);
		l.place(v.x, v.z); 
		enemies.createActor(type, r, l, m, a);

		if (mirrored && theta >= 0){
			theta = -tempTheta-i*spacing;
			v = radialOffset(origin, theta, dist);
			l.place(v.x, v.z); enemies.createActor(type, r, l, m, a);
		}
	}
}

void EnemyWave ::		generate(Actors& enemies){
	//Enemy e; e.init(enemy); 
	ID tex = monBook.getProfile(type).tex;
	Rendering r(tex, 0); //set stats and anims
	Animation a = monBook.anim[type];
	Motion m = Motion(monBook.max[type]);
	Location l; 
	glm::vec3 v;
	float tempTheta = tempTheta = centerTheta - (quantity-1)* spacing/2;   
	for (int i = 0; i < quantity; i++){
		a.randomTick();
		float theta = tempTheta+i*spacing;
		v = radialOffset(origin, theta, dist);
		l.place(v.x, v.z); 
		enemies.createActor(type, r, l, m, a);

		if (mirrored && theta >= 0){
			theta = -tempTheta-i*spacing;
			v = radialOffset(origin, theta, dist);
			l.place(v.x, v.z); enemies.createActor(type, r, l, m, a);
		}
	}
}
