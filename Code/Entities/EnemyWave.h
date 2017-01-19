#ifndef ENEMYWAVE_H
#define ENEMYWAVE_H

#include "../Systems/EntityBuilder.h"
//********************************* CONSTANTS *********************************

//enum EnemyType {CHUCKY, MOSQUITO, TRUNKLING, LABOMBA, MIMIC }; 

//********************************* INITIALIZATION *********************************
class EnemyWave {
	public: 
	EnemyWave::			EnemyWave();
	EnemyWave::			EnemyWave(ID et, glm::vec3 p);
	void EnemyWave::	init(int q, float d);
	void EnemyWave::	reset();
	void EnemyWave::	configure(float c, float t);
	void EnemyWave::	initRegion(float theta){centerTheta = theta;}
	void EnemyWave::	initRegion(bool left, int reg);
	void EnemyWave::	initMirrored(bool back, int reg);  
	
	void EnemyWave::	generate();
	
	bool EnemyWave:: waveCriteria(vector<EnemyWave>& enemies);
	void EnemyWave:: trackMembers(ID ind);  
	bool EnemyWave:: isComplete(float rat);
	int EnemyWave:: size(){return members.size();}

//********************************* MEMEBERS *********************************	
	ID type;
	bool mirrored;
	float centerTheta;
	float spacing;
	float dist;
	int quantity;
	int trigInd;
	float trigRat;
	float trigTime;
	bool activated;
	int count;
	
	glm::vec3 origin;
	vector <ID> members;

};
#endif