//********************************* INITIALIZATION *********************************
#include "Stage.h"
#include "../Entities/MonsterBook.h"

Stage::Stage(){
	name = "___";
	baseTile = 0;
	curSpawn = 0;
	entities.setGridSize(6, 5);
	atSpawn = false; 
}

void Stage:: init(){
	if (entities.state.size() != 300){
		entities.reserve(300);
	}
	curSpawn = 0;
	 
	atSpawn = false;
	entities.clear();	
	entities.clearGrid();
	createPlayer(32, 10);

	enemyPool.init(&monBook);
	propPool.init(&propList);
	particlePool.init(&particleList);
	loadMap();
	for (int i = 0; i < spawns.size(); i++){ 
		int waves = spawns[i].waves.size();
		for(int j = 0; j < waves; j++){
			spawns[i].waves[j].origin = spawns[i].pos(); //NEWBRANCH SPAWNTRIGGERS
			spawns[i].waves[j].generate(entities);
		}
	}	
}

bool Stage::	validate(){

	return true;
}

void Stage::		loadMap(){
	Location l; 	Rendering r; EntityXZ e;
	for (ID i = 0; i < map.size(); i++){
		entities.createProp(propList, map[i]);
	}
	//test
}


void Stage::createPlayer(int x, int z){
	Rendering r; //set stats and anims
	Animation a;
	Motion m;
	Location l; 
	l.place(x, z);
	p1 = entities.nextFree();
	Identity i = {"LaserMage", p1, 0, 4};
	entities.createActor(i, r, l, m, a);
}


void Stage::addParticle(ID type, XZI targ){
	glm::vec3 pos = entities.getPos(p1);
	EntityXZ ent = {type, pos.x, pos.z};
	ID p = entities.createParticle(particleList, ent);
	glm::vec3 targV(targ.x, 0, targ.z);
	entities.chargeParticle(p, targV);
}

//void Stage::add(EntityXZ e){map.push_back(e);}

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
	entities.update(delta);
	//entities.printGrid ();
	//particles.update(delta); 
	entities.checkCollisions();
	entities.applyCollisions();
}
void Stage::		rapidUpdate(float delta){
	glm::vec3 pos = entities.getPos(p1);
	glm::vec3 v = spawns[curSpawn].pos();
	if (pos.z < v.z-0.25){
		entities.target[p1].setTarget(v);
	} else if (!atSpawn){		
		entities.target[p1].noTarget();
		//getSpawncount;
		//actors.activate(14, P->pos());
		//actors.activateAll(P->pos());
		entities.activateAll(p1);
		atSpawn = true;
	}
	entities.aiUpdate(delta);
	//actors.aiUpdate(delta);
	//collisions.applyAdjustments(0); // need to disable above


}

//********************************* DRAW *********************************
void Stage::		draw(float delta){	
	//terr.draw();	
	//M->gridBO.use();
	entities.delta = delta;	
	glm::vec3 pos = entities.getPos(p1);
	C->update(pos);		
	drawTerrain();  
	drawPlayer();
	propPool.batch(&entities);
	propPool.draw(&entities);
	particlePool.batch(&entities, delta);
	particlePool.draw(&entities);
 	enemyPool.batch(&entities, delta);
	enemyPool.draw(&entities);
	
	C->drawCursor();
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
void Stage::		drawPlayer(){	
	M->gridBO.prepHero();
	//refresh(P1);  
	entities.draw(p1);	
}