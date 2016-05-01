//********************************* INITIALIZATION *********************************
#include "Stage.h"

Stage::Stage(){
}

void Stage:: init(Hero & h){
	h.place(32, 32);
	//terr.init();	
	//veg->init();
	pop.enemies.clear();
	pop.init(h);
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
	int x = 16;
	int z = 72;
	M->tileBO.draw(x, z, x*4, z*4);
	glEnable(GL_DEPTH_TEST);
}