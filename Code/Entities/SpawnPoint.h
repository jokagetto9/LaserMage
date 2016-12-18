#ifndef SPAWNPOINT_H
#define SPAWNPOINT_H


#include "../BaseEngine/Components/Location.h"

//********************************* CONSTANTS *********************************


//********************************* INITIALIZATION *********************************
class SpawnPoint : public Location {
	public: 
	SpawnPoint::			SpawnPoint();
	void SpawnPoint::		addWave(ID w);
	bool SpawnPoint::	validate();

	
//********************************* MEMBERS *********************************
	vector <ID> waves;



//********************************* MEMBER FUNCTIONS *********************************

};
#endif