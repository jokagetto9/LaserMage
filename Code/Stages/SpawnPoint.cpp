//********************************* INITIALIZATION *********************************
#include "SpawnPoint.h"
SpawnPoint::SpawnPoint(){	

	currWave = 0;
	empty = true;
	
	x_ = 0; 	z_ = 0; 	y_ = 0;	
}


void SpawnPoint::	addWave(EnemyWave & w){
	waves.push_back(w);
}

bool SpawnPoint::	validate(){
	return true;
}



