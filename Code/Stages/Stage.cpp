//********************************* INITIALIZATION *********************************
#include "Stage.h"

Stage::Stage(){
	name = "";
	baseTile = 0;
}

void Stage:: init(Hero * h){
	H = h;
	h->place(32, 12);
	//terr.init();	
	pop.enemies.clear();
	for (int i = 0; i < spawns.size(); i++){ 
		int waves = spawns[i].waves.size();
		for(int j = 0; j < waves; j++){
			spawns[i].waves[j].origin = spawns[i].pos();
			spawns[i].waves[j].generate(pop.enemies);
		}
	}
	
	//veg->init();
}

void Stage::	addSpawnPoint(SpawnPoint & sp){
	spawns.push_back(sp);
}

bool Stage::	validate(){

	return true;

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
	pop.aiUpdate(delta, H->pos());
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