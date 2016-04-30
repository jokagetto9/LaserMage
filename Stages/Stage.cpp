//********************************* INITIALIZATION *********************************
#include "Stage.h"

Stage::Stage(){
	loaded = false;
}

void Stage:: init(Hero & h){
	if (!loaded){

		//terr.init();	
		//veg->init(); 
		pop.init(h);
		loaded = true;
	}
}


//********************************* UPDATES *********************************

void Stage::update(){
	if (true){//pop.empty() && !noSpawn){
	//	currSpawn++;
		//if (spawnPoints[currSpawn].transition == true)  {
			//H->updateTarget(spawnPoints[currSpawn+1]);

		//}
//	}
	//if (at target){
		//pop.loadSpawnPoint(spawnPoints[currSpawn]);
		//if (spawnPoints[currSpawn].transition == true)
	}
	//pop.update();
}


void Stage::		physUpdate(){
	pop.physUpdate();

}
void Stage::		rapidUpdate(){
	pop.aiUpdate();
}

void Stage::		draw(){	
	//terr.draw();	
	pop.draw(); 

}