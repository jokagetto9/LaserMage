//********************************* INITIALIZATION *********************************
#include "SpawnPoint.h"
SpawnPoint::SpawnPoint(){	
	
	x_ = 0; 	z_ = 0; 	y_ = 0;	
}


void SpawnPoint::	addWave(ID w){
	waves.push_back(w);
}

bool SpawnPoint::	validate(){
	return true;
}



