#ifndef SPAWNPOINT_H
#define SPAWNPOINT_H


#include "EnemyWave.h"

//********************************* CONSTANTS *********************************


//********************************* INITIALIZATION *********************************
class SpawnPoint : public Node {
	public: 
	SpawnPoint::			SpawnPoint();
	void SpawnPoint::		addWave(EnemyWave & w);
	bool SpawnPoint::	validate();

	
//********************************* MEMBERS *********************************
	vector <EnemyWave> waves;

	int currWave;
	bool empty; //starting point? ending point?
	//timer
	//enemies remaining

//********************************* MEMBER FUNCTIONS *********************************

};
#endif