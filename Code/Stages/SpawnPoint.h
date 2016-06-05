#ifndef SPAWNPOINT_H
#define SPAWNPOINT_H


#include "../BaseEngine/Components/Location.h"
#include "EnemyWave.h"

//********************************* CONSTANTS *********************************


//********************************* INITIALIZATION *********************************
class SpawnPoint : public Location {
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