//********************************* INITIALIZATION *********************************
#include "Stage.h"
#include "../Entities/MonsterBook.h"

Stage::Stage(){
	name = "___";
	baseTile = 0;
	curSpawn = 0;
	curWave = 0;
	Book::entities.setGridSize(6, 5);
	atSpawn = false; 
	spawnLoaded = false;
}

void Stage:: init(){
	if (Book::entities.death.observers.size() < 1){
		Book::entities.death.addObserver(&wTracker);
		Book::entities.reserve(300);
	}
	curSpawn = 0;
	
	atSpawn = false;
	spawnLoaded = false;
	Book::entities.clear();	
	Book::entities.clearGrid();
	p1 = Book::entities.nextFree();
	EntityBuilder::createHero();
	//createPlayer();

	enemyPool.init(&Book::enemies);
	propPool.init(&Book::props);
	particlePool.init(&Book::particles);
	loadMap();
	update();
}

bool Stage::	validate(){

	return true;
}

void Stage::		loadMap(){
	Location l; 	Rendering r; EntityXZ e;
	for (ID i = 0; i < map.size(); i++){
		EntityBuilder::createProp(map[i]);
	}
	//test
}


void Stage::createPlayer(){
	Rendering r; //set stats and anims
	Animation a; 
	Motion m;
	Location l; 
	p1 = Book::entities.nextFree();
	Identity i = {"LaserMage", p1, 0, 4};
	//EntityBuilder::createActor(i, r, l, m, a);

	//EntityXZ e = {1, 0, 0};
	//p1 = Book::entities.nextFree();
	//Book::entities.createActor(Book::enemies, e);
	//Book::entities.gData[p1].ent = 4;
}


void Stage::addParticle(ID type, XZI targ){
	glm::vec3 pos = Book::entities.getPos(p1);
	EntityXZ ent = {type, pos.x, pos.z+0.5};		//create at hero position
	ID pa = EntityBuilder::createParticle(ent);

	glm::vec3 targV(targ.x, 0, targ.z);
	Book::entities.scaleMotion(pa, targV);		//target targ
}

//void Stage::add(EntityXZ e){map.push_back(e);}

//********************************* UPDATES *********************************

void Stage::update(){
	EntityList& e = Book::entities;
	if ( curSpawn >= 0 && curSpawn < spawns.size()){
		SpawnPoint & sp = spawns[curSpawn];
		glm::vec3 pos = e.getPos(p1);

		if (!spawnLoaded){
			if (curSpawn == 0)
				e.location[p1].place(sp.pos());

			int w = sp.waves.size();
			for(int j = 0; j < w; j++){
				ID cw = sp.waves[j];
				wTracker.waves[cw].origin = sp.pos(); 
				wTracker.waves[cw].generate();
			}
			spawnLoaded = true;
		}
		if (!atSpawn){
			glm::vec3 v = sp.pos();
			if (pos.z < v.z-0.25){
				e.target[p1].setTarget(v);
			} else {	
				atSpawn = true;	
				e.target[p1].noTarget();	
			}
		}
		
		if (atSpawn ){
			updateWave();
		}
	}
}
//sp0 feeds into hero origin
//check sp for waves -> spawn all
//if hero at target // trigger waves
//check wave triggers
//if trigger waves = -1 
	//count down - activate wave
//else return trigger wave->check killed -> activate

//when death remove from wave


void Stage::updateWave(){
	EntityList& e = Book::entities;
	bool wavesComplete = true;
	SpawnPoint & sp = spawns[curSpawn];
	glm::vec3 pos = e.getPos(p1);
	for( ID i = 0; i < sp.waves.size(); i++){
		ID waveInd = sp.waves[i];
		EnemyWave &ew = getWave(waveInd);
		if (!ew.activated){
			if (ew.waveCriteria(wTracker.waves)){
				int s = ew.size();
				for (ID j = 0; j < s; j++){
					curWave++;
					ID entInd = ew.members[j]; 

					e.setTarget(entInd, pos);
					e.gData[entInd].setGroup(waveInd);
				}
				ew.activated = true;
			}
		}
		if (ew.activated && ew.size()){			
			wavesComplete = false;
		}
		
	}
	if (wavesComplete) {
		atSpawn = false;
		spawnLoaded = false;
		curSpawn++;
	}
}

void Stage::		physUpdate(float delta){
	update();
	PhysicsSystem::update(delta);
	//entities.printGrid ();
	CollisionSystem::checkCollisions();
	CollisionSystem::applyCollisions();
}
void Stage::		rapidUpdate(float delta){
	Book::entities.delta = delta;
	ID s = Book::entities.state.size();
	for (ID i = 0; i < s; i++){
		if (Book::entities.state[i]->on()){
			AISystem::aiUpdate(i);
			AISystem::healthUpdate(i);
		}
	}
}

//********************************* DRAW *********************************
void Stage::		draw(float delta){	
	//terr.draw();	
	//M->gridBO.use();
	Book::entities.delta = delta;	
	glm::vec3 pos = Book::entities.getPos(p1);
	C->update(pos);		
	drawTerrain();  
	drawPlayer();
	propPool.batch(&Book::entities);
	propPool.draw(&Book::entities);
	particlePool.batch(&Book::entities, delta);
	particlePool.draw(&Book::entities);
 	enemyPool.batch(&Book::entities, delta);
	enemyPool.draw(&Book::entities);
	drawHealthBars();
	
	C->drawCursor();
}

//healthbars
void Stage::		drawHealthBars(){
	ID s = Book::entities.state.size();
	for (ID i = 0; i < s; i++){
		if (Book::entities.state[i]->on() && Book::entities.gData[i].ent == 3){
			int hi = ceil(Book::entities.health[i].percent()*10); 
			if (hi > 0 && hi < 10){					
				Book::entities.location[i].translate();
					float scale = Book::enemies.getProfile(Book::entities.gData[i].type).scale * 2;
					M->gridBO.prep(Book::enemies.getProfile(0)); 
					M->gridBO.offsetTexture(0, scale+2);	
					M->gridBO.drawGrid(hi);		
				glPopMatrix(); //}	
			}
		}
	}	 


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
	Book::entities.draw(p1);	
}



		
//********************************* MEMBER FUNCTIONS *********************************
 




EnemyWave& Stage::		getWave(ID id){
	try{
		return wTracker.waves.at(id);
	}catch(...){
		cout << "Broken Wave  ";
	}
}