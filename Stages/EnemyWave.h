#ifndef ENEMYWAVE_H
#define ENEMYWAVE_H


#include "../Nodes/Enemy.h"

//********************************* CONSTANTS *********************************


//********************************* INITIALIZATION *********************************
class EnemyWave {
	public: 
	EnemyWave::			EnemyWave(EnemyType et);
	void EnemyWave::	init(int q, float d);
	void EnemyWave::	configure(float c, float t);
	void EnemyWave::	initRegion(float theta){centerTheta = theta;}
	void EnemyWave::	initRegion(bool left, int reg);
	void EnemyWave::	initMirrored(bool back, int reg);



//********************************* MEMEBERS *********************************	
	EnemyType enemy;
	bool mirrored;
	float centerTheta;
	float clustering;
	float dist;
	int quantity;

};
#endif