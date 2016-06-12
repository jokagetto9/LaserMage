//********************************* INITIALIZATION *********************************
#include "Stage.h"
#include "../Entities/MonsterBook.h"

Stage::Stage(){
	name = "___";
	baseTile = 0;
	curSpawn = 0;
	actors.reserve(200);
	props.reserve(30);
	atSpawn = false;
 	collisions.init(6, 5, 2);
}

void Stage:: init(Players& p){
	P = &p;
	curSpawn = 0;
	atSpawn = false;
	//terr.init();	
	//pop.enemies.clear();
	p.reset();
	p.placeP1(32, 0);
	actors.clear();
	for (int i = 0; i < spawns.size(); i++){ 
		int waves = spawns[i].waves.size();
		for(int j = 0; j < waves; j++){
			spawns[i].waves[j].origin = spawns[i].pos(); //NEWBRANCH SPAWNTRIGGERS
			spawns[i].waves[j].generate(actors);
		}
	}
	props.clear();
	loadMap();
	enemyPool.init(&monBook);
	propPool.init(&propList);
	//veg->init();
}

bool Stage::	validate(){

	return true;

}

void Stage::		loadMap(){
	Location l; 	Rendering r; EntityXZ e;
	for (ID i = 0; i < map.size(); i++){
		e = map[i];
		r = propList.rendering[e.id];
		l.place(e.x, e.z);
		props.add(r, l); 
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
	P->P1Update(delta);
	actors.update(delta);	
	//collisions.updateGrid(&props);
	collisions.setActiveEnt(&actors);
	collisions.updateGrid((ID)0);
	//collisions.setActiveEnt(&particles);
	//collisions.updateGrid((ID)0);

	collisions.updateObstacles(0);
	collisions.applyAdjustments(0);
}
void Stage::		rapidUpdate(float delta){
	glm::vec3 v = spawns[curSpawn].pos();
	if (P->pos().z < v.z-0.25){
		P->target[P1].setTarget(v);
	} else if (!atSpawn){		
		P->target[P1].noTarget();
		//getSpawncount;
		//actors.activate(14, P->pos());
		actors.activateAll(P->pos());
		atSpawn = true;
	}
	P->P1aiUpdate(delta);
	actors.aiUpdate(delta);
}

void Stage::		draw(float delta){	
	//terr.draw();	
	//M->gridBO.use();
	P->drawP1(delta);
	enemyPool.batch(&actors, delta);
	enemyPool.draw(&actors);
	propPool.batch(&props);
	propPool.draw(&props);
	
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