#ifndef STAGE_H
#define STAGE_H


#include "../BaseEngine/Entities/Players.h"
#include "SpawnPoint.h"


//********************************* CONSTANTS *********************************


//********************************* EXTERNALS  *********************************


//********************************* INITIALIZATION *********************************
class Stage {
	public: 
	// constructors
	Stage::	Stage ();
	
	virtual void Stage:: init(Players & p);

	void Stage::	addSpawnPoint(SpawnPoint & sp);
	bool Stage::	validate();


	virtual void Stage::		save(ofstream &saveFile){	}
	virtual void Stage::		saveMap(ofstream &saveFile){	}
	virtual void Stage::		load(ifstream &saveFile){}	
	virtual void Stage::		loadMap(ifstream &saveFile){ }

		
//************************************************** UPDATE ***************************************************
		
	void Stage::update();
virtual void Stage::		physUpdate(float delta);
virtual void Stage::		rapidUpdate(float delta);


//************************************************** DRAW ***************************************************
		void Stage::		draw(float delta);
		void Stage::		drawTerrain();
		
//************************************************** MEMBERS ***************************************************
		bool atSpawn;
		vector<SpawnPoint> spawns;
		ID curSpawn;
		//Terrain terr;
		Players * P;

		Actors actors;
		//Vegetation * veg;
		//Structures * structs;
		string name;
		ID baseTile;

//********************************* MEMBER FUNCTIONS *********************************
		
};
#endif