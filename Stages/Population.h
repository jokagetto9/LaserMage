#ifndef POPULATION_H
#define POPULATION_H

#include "../lib.h"
#include "../Stages/SpawnPoint.h"
//********************************* CONSTANTS *********************************


//********************************* INITIALIZATION *********************************

class Population {
	public: 
	Population::		Population();
	void Population ::		init (Hero& h);
	void Population ::		genInteractions();	
	void Population ::		trackInteractions();
		

	
	vector <Enemy*> * Population::		getRegion(int i);
	
	void Population::		physUpdate(float delta);
	void Population::		aiUpdate(float delta);
	void Population::		slowaiUpdate();
	void Population ::		interact (int pid);


	void Population ::		draw (float delta);
/*/ Purpose: 
Side Effects:  
Triggers: 
/*/
	
	void Population::		purge();
//************************************************** MEMBERS ***************************************************
	
	//vector<NPC> npc;
	vector<Enemy> enemies;
	vector <Enemy*> regL1;
	vector <Enemy*> regL2;
	vector <Enemy*> regL3;
	vector <Enemy*> regR1;
	vector <Enemy*> regR2;
	vector <Enemy*> regR3;

};
#endif