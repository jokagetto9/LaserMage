#ifndef ENEMYWAVE_H
#define ENEMYWAVE_H

#include "../BaseEngine/Entities/Actors.h"
#include "../BaseEngine/Entities/EntityList.h"
//********************************* CONSTANTS *********************************

//enum EnemyType {CHUCKY, MOSQUITO, TRUNKLING, LABOMBA, MIMIC }; 

//********************************* INITIALIZATION *********************************
class EnemyWave {
	public: 
	EnemyWave::			EnemyWave();
	EnemyWave::			EnemyWave(ID et, glm::vec3 p);
	void EnemyWave::	init(int q, float d);
	void EnemyWave::	configure(float c, float t);
	void EnemyWave::	initRegion(float theta){centerTheta = theta;}
	void EnemyWave::	initRegion(bool left, int reg);
	void EnemyWave::	initMirrored(bool back, int reg);  
	 
	
	void EnemyWave ::		generate(EntityList& enemies);
	void EnemyWave ::		generate(Actors& enemies);

//********************************* MEMEBERS *********************************	
	ID type;
	bool mirrored;
	float centerTheta;
	float spacing;
	float dist;
	int quantity;
	glm::vec3 origin;

};
#endif