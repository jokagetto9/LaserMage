#ifndef STAGE_H
#define STAGE_H


#include "../BaseEngine/Entities/DrawPool.h"
#include "../BaseEngine/Entities/CollisionGrid.h"
#include "../Entities/Players.h"
#include "SpawnPoint.h"


//********************************* CONSTANTS *********************************

//********************************* EXTERNALS  *********************************


//********************************* INITIALIZATION *********************************
class Stage {
	public: 
	// constructors
	Stage::	Stage ();
	
	virtual void Stage:: init(Players & p);

	bool Stage::	validate();


	//virtual void Stage::		save(ofstream &saveFile){	}
	//virtual void Stage::		saveMap(ofstream &saveFile){	}
	//virtual void Stage::		load(ifstream &saveFile){}	
	//virtual void Stage::		loadMap(ifstream &saveFile){ }

	void Stage::		loadMap();

	void Stage::add(EntityXZ e){map.push_back(e);}
	void Stage::addSpawnPoint(SpawnPoint & sp){spawns.push_back(sp);}
		
//************************************************** UPDATE ***************************************************
		
	void Stage::update();
virtual void Stage::		physUpdate(float delta);
virtual void Stage::		rapidUpdate(float delta);


//************************************************** DRAW ***************************************************
		void Stage::		draw(float delta);
		void Stage::		drawTerrain();
		
//************************************************** MEMBERS ***************************************************
		bool atSpawn;
		vector<EntityXZ> map;
		vector<SpawnPoint> spawns;
		ID curSpawn;
		//Terrain terr;
		Players * P;

		Actors actors;
		Props props;
		Particles particles;
		DrawPool enemyPool;
		DrawPool propPool;
		DrawPool particlePool;
		CollisionGrid collisions;
		//Vegetation * veg;
		//Structures * structs;
		string name;
		ID baseTile;

//********************************* MEMBER FUNCTIONS *********************************
		
};
#endif