//********************************* INITIALIZATION *********************************
#include "SpawnPoint.h"
SpawnPoint::SpawnPoint(){	

	currWave = 0;
	empty = true;

	id = -1;
	xPos = 0; 	zPos = 0;
	yPos = 0;
	scale = 1; theta = 0;
	dir = DUNNO;
	type = _n;
}


void SpawnPoint::	loadWave(){

}