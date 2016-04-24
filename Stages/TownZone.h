#ifndef TOWNZONE_H
#define TOWNZONE_H

#include "FieldZone.h"

//********************************* CONSTANTS *********************************


//********************************* INITIALIZATION *********************************
class TownZone : public FieldZone{
	public: 
	TownZone::		TownZone();
	TownZone::		TownZone(int i, int j, char c);
	void TownZone:: init();
	void TownZone::	save(ofstream &saveFile);
	void TownZone::	load(ifstream &saveFile);

	void TownZone::		randomize();	
	void TownZone::		createSecret();	

	void TownZone::genInteractions();
	void TownZone::generateNubs();
	NUBS TownZone::nubChance(Biome b) {return GREATTREE;}




	// draw functions
	void TownZone::		drawTerrain();
	void TownZone::		drawTrees(){}
	//void TownZone::		drawObj();
	void TownZone::		drawPeople(){}
	//void TownZone::		drawHouses();

/*/ Purpose: 
Side Effects:  
Triggers: 
/*/

//************************************************** MEMBERS ***************************************************
	


	//content


};
#endif