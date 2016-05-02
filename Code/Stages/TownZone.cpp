//********************************* INITIALIZATION *********************************
#include "TownZone.h"


TownZone::TownZone(int i, int j, char c){
	grid.setZone(i, j);
	grid.setBiome(TOWN, 1);
	structs = new TownStructures();
	veg = new Vegetation();
	attachGrid();
}

void TownZone:: init(){
	terr.init();
	structs->init();
	generateNubs();
}

void TownZone::		save(ofstream &saveFile){
	int s = veg->mininubs.size();
	for (int k = 0; k < s; k++){
		Nub * n = &veg->mininubs[k];
		saveFile << n->growth << " " << n->bloomTime << " ";		
	}
	saveFile << endl << "ZONE_" << zoneX() << ", " << zoneZ() << endl;

}
void TownZone::		load(ifstream &saveFile){
	string inputLine; 

	getline (saveFile, inputLine); 
	//veg->sortNubs();
	getline (saveFile, inputLine);
}

void TownZone::		randomize(){
}
void TownZone::		createSecret(){
}
//********************************* DRAW *********************************

void TownZone::		drawTerrain(){	
	terr.draw();	
	glPushMatrix();
		glTranslatef(zoneX()*ZONE, 0, zoneZ()*ZONE);	
		M->roadBO.drawTownSquare();	
	glPopMatrix();

}

//********************************* TOWN *********************************


void TownZone::generateNubs(){
	for (int i = 6; i < 10; i++){
		veg->fillPlot(i, 0);
	}
	for (int i = 4; i < 6; i++){
		veg->fillPlot(0, i);
		veg->fillPlot(1, i);
	}
	for (int i = 1; i < 9; i++){
		veg->fillPlot(9, i);
	}
	
	for (int i = 0; i < 10; i++){		
		if (i == 1) i = 3;
		if (i == 4) i = 6;
		else if (i == 7) i = 9;
		veg->fillPlot(i, 8);
		veg->fillPlot(i, 9);
	}
	veg->fillPlot(1, 9);
	veg->fillPlot(2, 9);
	
	veg->genInteractions();
}