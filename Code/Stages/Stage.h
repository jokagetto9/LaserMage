#ifndef STAGE_H
#define STAGE_H


#include "Population.h"


//********************************* CONSTANTS *********************************


//********************************* EXTERNALS  *********************************


//********************************* INITIALIZATION *********************************
class Stage {
	public: 
	// constructors
	Stage::	Stage ();
	
	virtual void Stage:: init(Hero * h);

	void Stage::	addSpawnPoint(SpawnPoint & sp);
	bool Stage::	validate();


	virtual void Stage::		save(ofstream &saveFile){	}
	virtual void Stage::		saveMap(ofstream &saveFile){	}
	virtual void Stage::		load(ifstream &saveFile){}	
	virtual void Stage::		loadMap(ifstream &saveFile){ }

		
//************************************************** DRAW ***************************************************
		
	void Stage::update();
virtual void Stage::		physUpdate(float delta);
virtual void Stage::		rapidUpdate(float delta);


//************************************************** DRAW ***************************************************
		void Stage::		draw(float delta);
		void Stage::		drawTerrain();
		
//************************************************** MEMBERS ***************************************************
		vector<SpawnPoint> spawns;
		//Terrain terr;


		Population pop;
		//Vegetation * veg;
		//Structures * structs;
		string name;
		int baseTile;
		Hero * H;

//********************************* MEMBER FUNCTIONS *********************************
		
};
#endif