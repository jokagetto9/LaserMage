//********************************* INITIALIZATION *********************************
#include "Stage.h"

Stage::Stage(){
	loaded = false;
}

void Stage:: init(){
	if (!loaded)
	//enter stage anim.
	//read from file
	//Hero Start point, spawnPoints (some empty)
	structs->init();	
	terr.init();	
	veg->init(); 
}


void Stage:: attachGrid(){
	terr.attachGrid(grid);
	structs->attachGrid(grid);
	structs->pop.attachGrid(grid);
	veg->attachGrid(grid);	
}






bool Stage:: addTreasure(int pr){
	if (getPOI(0)->_h == _NOTHING) {
		getPOI(0)->_h = _TREASURE;	
		getPOI(0)->_hRank = pr; }
	else return false;
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



void Stage::		physUpdate(){
	//structs->pop.physUpdate();
	pop.physUpdate();

}
void Stage::		rapidUpdate(){
	//structs->pop.aiUpdate();
	pop.aiUpdate();
}
void Stage::		slowUpdate(){	
	structs->pop.slowaiUpdate();
	veg->bloomNubs(1);
}
void Stage::		dailyUpdate(){
	veg->growNubs(1);
}













void Stage::		drawTrees(){
	veg->drawTrees(TALLTREE);
	veg->drawTrees(TALLDEADTREE);
	veg->drawTrees(DEADTREE);
	veg->drawTrees(WTFPLANT);
}


void Stage:: determinePOI(int t){
	int r, s;
	vector<XZI> openPlots;
	grid.gatherOpenPlots(openPlots, t);
	s = openPlots.size();
	if (s > 0){
		r = rand() % s; 
		XZI p = openPlots[r];
		Drctn d = grid.determinePOIDrctn(p);
		grid.setPOIPlot(p.x, p.z, d);
	}
}


//********************************* OTHER *********************************

XZI Stage::		genPOIPlot(){
	XZI i;
	i.x = rand() % 8 + 1;
	i.z = rand() % 8 + 1;
	return i;
}



void Stage::translate(float x, float z){
	x += ZONE*grid.zone.x; 	z += ZONE*grid.zone.z;
	glPushMatrix();
	glTranslatef(x, 0, z);
}
//********************************* EXTERNAL *********************************
//
XZI findStage(glm::vec3 pos){ //duplicate!!!!!
	// 500 rezo x 20 zo = 10000 fazo
	XZI xz;
	xz.x = floor(pos.x/ZONE); xz.z = floor(pos.z/ZONE);
	return xz;

}
/*/
XZI getPlot(glm::vec3 pos){
	XZI xz;
	xz.x = floor(pos.x/ZONE);				xz.z = floor(pos.z/ZONE);
	float x = pos.x - xz.x*ZONE;			float z = pos.z - xz.z*ZONE;
	XZI plot;
	plot.x = floor(x/PLOT);					plot.z = floor(z/PLOT);
	return plot;
}//*/



