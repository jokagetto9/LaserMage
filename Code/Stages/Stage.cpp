//********************************* INITIALIZATION *********************************
#include "Stage.h"

Stage::Stage(){
	name = "";
	baseTile = 0;
	curSpawn = 0;
	actors.reserve(100);
	atSpawn = false;

}

void Stage:: init(Players& p){
	P = &p;
	p.place(32, 0);
	curSpawn = 0;
	atSpawn = false;
	//terr.init();	
	//pop.enemies.clear();
	p.reset();
	p.place(32, 0);
	actors.clear();
	for (int i = 0; i < spawns.size(); i++){ 
		int waves = spawns[i].waves.size();
		for(int j = 0; j < waves; j++){
			spawns[i].waves[j].origin = spawns[i].pos(); //NEWBRANCH SPAWNTRIGGERS
			spawns[i].waves[j].generate(actors);
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
	P->P1Update(delta);
	actors.update(delta);	
}
void Stage::		rapidUpdate(float delta){
	glm::vec3 v = spawns[curSpawn].pos();
	if (P->pos().z < v.z-0.25){
		P->ai[P1].setTarget(v);
	} else if (!atSpawn){		
		P->ai[P1].noTarget();
		//getSpawncount;
		actors.activate(10, P->pos());
		atSpawn = true;
	}
	P->P1aiUpdate(delta);
	actors.aiUpdate(delta);
}

void Stage::		draw(float delta){	
	//terr.draw();	
	//M->gridBO.use();
	P->drawP1(delta);
	drawPool.batch(&actors, delta);
	drawPool.draw(&actors);
	

	//actors.refresh(delta); 
	//actors.draw(); 

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