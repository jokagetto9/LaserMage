#ifndef STAGE_H
#define STAGE_H


#include "../Collections/Terrain.h"
#include "../Collections/TownStructures.h"
#include "../Collections/SparseVegetation.h"
#include "../Collections/DenseVegetation.h"


//********************************* CONSTANTS *********************************


struct ADJStageDetails {
	XZI xz, t;
	bool shift;
};

//********************************* EXTERNALS  *********************************
XZI findStage(glm::vec3 pos);
int getPlot(int sectX, int sectY, int plotX, int plotY);
DrawKey createDrawKey(int viewX, int viewZ, Drctn d, float fog); 

// model objects and quads

//********************************* INITIALIZATION *********************************
class Stage {
	public: 
	// constructors
	Stage::	Stage ();
	
	virtual void Stage:: init();
	void Stage:: attachGrid();

	virtual void Stage::		save(ofstream &saveFile){	saveFile << endl << "ZONE_" << zoneX() << ", " << zoneZ() << endl;}
	virtual void Stage::		saveMap(ofstream &saveFile){	saveFile << endl << "IGNORE  " << grid.bio << " " << (int)grid.cntx << " " << zoneX() << ", " << zoneZ() << endl << "000";}
	virtual void Stage::		load(ifstream &saveFile){}	
	virtual void Stage::		loadMap(ifstream &saveFile){ string temp; getline (saveFile, temp); getline (saveFile, temp);}


virtual	void Stage::		randomize(){}
virtual	void Stage::		createSecret(){}
	bool Stage:: addTreasure(int pr);
	
		void Stage:: determinePOI(int t);

		//creation
		XZI Stage::		genPOIPlot();
	
//************************************************** DRAW ***************************************************
		
	void Stage::update();
virtual void Stage::		physUpdate();
virtual void Stage::		rapidUpdate();
virtual void Stage::		slowUpdate();
virtual void Stage::		dailyUpdate();






//************************************************** DRAW ***************************************************
	virtual	void Stage::		drawTerrain(){	terr.draw(); }
	void Stage::		drawNubs(NUBS n){veg->drawNubs(n);}
	void Stage::		drawMiniNubs(){veg->drawMiniNubs();}
virtual	void Stage::		drawTrees();
virtual	void Stage::		drawObj(){structs->drawObj();}
virtual	void Stage::		drawPeople(){structs->pop.draw();}
virtual	void Stage::		drawHouses(){structs->drawHouses();}//fix later



	void Stage::		drawMininubs();


		void Stage::		drawAdjStage(DrawKey &dKey);

		void Stage::		drawNubs(int xStart, int xEnd, int zStart, int zEnd);
		void Stage::		drawMiniNubs(int xStart, int xEnd, int zStart, int zEnd);

		void Stage::		drawNub(Nub &n);
		void Stage::		drawMiniNub(Nub &n);
		
		
	// model functions
/*/ Purpose: 
Side Effects:  
Triggers: 
/*/

//************************************************** MEMBERS ***************************************************
	
			
		Grid grid;
		Terrain terr;
		Population pop;
		Vegetation * veg;
		Structures * structs;
		
		bool loaded;
		
		//tile index, nub types
		/*/
		Biome bio;	
		BiomeContext cntx;
		XZI zone;
		int tile;//*/

//********************************* MEMBER FUNCTIONS *********************************
		
		void Stage::		translate(float x, float z);
		Plot * Stage::getHeroPlot(){ return grid.plot(H->plot);}
		XZI Stage::zone(){ return grid.zone;}
		int Stage::zoneX(){ return grid.zone.x;}
		int Stage::zoneZ(){ return grid.zone.z;}
		Biome Stage::biome(){ return grid.bio;}
		BiomeContext Stage::context(){ return grid.cntx;}
			
		POI * Stage::getPOI (int i){return &grid.poi[i];}
};
#endif