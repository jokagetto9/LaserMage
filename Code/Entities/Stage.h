#ifndef STAGE_H
#define STAGE_H


#include "../BaseEngine/Entities/DrawPool.h"
#include "../Event/WaveTracker.h"

#include "EntityBuilder.h"
#include "AISystem.h"
#include "PhysicsSystem.h"
#include "CollisionSystem.h"
#include "StateChanger.h"
#include "SpawnPoint.h"
#include "EnemyWave.h"

//********************************* CONSTANTS *********************************

//********************************* EXTERNALS  *********************************


//********************************* INITIALIZATION *********************************
class Stage {
	public: 
	// constructors
	Stage::	Stage ();
	
	virtual void Stage:: init();

	bool Stage::	validate();


	//virtual void Stage::		save(ofstream &saveFile){	}
	//virtual void Stage::		saveMap(ofstream &saveFile){	}
	//virtual void Stage::		load(ifstream &saveFile){}	
	//virtual void Stage::		loadMap(ifstream &saveFile){ }
	
	void Stage::		loadMap();

	
	void Stage::createPlayer();
	void Stage::addParticle(ID type, XZI targ);

	void Stage::add(EntityXZ e){map.push_back(e);}
	void Stage::addSpawnPoint(SpawnPoint sp){spawns.push_back(sp);}
	ID Stage::addWave(EnemyWave w){wTracker.waves.push_back(w); return wTracker.waves.size()-1;}
		
//************************************************** UPDATE ***************************************************
		
	void Stage::update();
	void Stage::updateWave();
virtual void Stage::		physUpdate(float delta);
virtual void Stage::		rapidUpdate(float delta);


//************************************************** DRAW ***************************************************
		void Stage::		draw(float delta);	
		void Stage::		drawPlayer();
		void Stage::		drawTerrain();
		void Stage::		drawHealthBars();
		
//************************************************** MEMBERS ***************************************************
		bool atSpawn;
		bool spawnLoaded;
		vector<EntityXZ> map;
		vector<SpawnPoint> spawns;
		WaveTracker wTracker;
		int curSpawn;
		int curWave;
		//Terrain terr;
		ID p1;

		DrawPool enemyPool;
		DrawPool propPool;
		DrawPool particlePool;
		//Vegetation * veg;
		//Structures * structs;
		string name;
		ID baseTile;

		
//********************************* MEMBER FUNCTIONS *********************************

		
	EnemyWave& Stage::		getWave(ID id);


};

#endif