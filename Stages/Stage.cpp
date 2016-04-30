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


void Stage::		physUpdate(float delta){
	pop.physUpdate(delta);

}
void Stage::		rapidUpdate(float delta){
	pop.aiUpdate(delta);
}

void Stage::		draw(float delta){	
	//terr.draw();	
	pop.draw(delta); 

}
void Stage::		drawTerrain(){	
	glDisable(GL_DEPTH_TEST);
	M->tileBO.use();	
	glBindTexture(GL_TEXTURE_2D, M->tileBO.terrainT1[0]);
	M->tileBO.draw(16, 36, 64, 144);
	glEnable(GL_DEPTH_TEST);
}