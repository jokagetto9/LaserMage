#include "Population.h"

Population ::		Population (){
	enemies.reserve(30);
}


void Population ::		init (Hero& h){
	//float d = 40;
	//wave.init(1, d);	wave.generate(enemies); d+=7.5;
	//wave.init(5, d);	wave.generate(enemies); d+=7.5;
	//wave.init(9, d);	wave.generate(enemies); d+=7.5;

}




vector <Enemy*> * Population::		getRegion(int i){
	return &regL1;
}


void Population ::		genInteractions(){
	int s = enemies.size();
	for (int i = 0; i < s; i++){
		//grid->addBoundingRadius(enemies[i]);
		//grid->addActionRadius(enemies[i]);
	}
}


void Population::		physUpdate(float delta){
	int s = enemies.size();
	for (int i = 0; i < s; i++){
		if(!enemies[i].dead)
			enemies[i].physUpdate(500, delta);
	}
}
void Population::		aiUpdate(float delta, glm::vec3 target){

	int s = enemies.size();
	for (int i = 0; i < s; i++){
		if(!enemies[i].dead){
			enemies[i].setTarget(target);
			enemies[i].aiUpdate(delta);
		}
	}
}
void Population::		slowaiUpdate(){
	int s = enemies.size();
	for (int i = 0; i < s; i++){
		enemies[i].slowaiUpdate();
	}
	purge();
}

void Population ::		interact (int pid){

}

void Population::		purge(){
	int s = enemies.size();
	for (int i = 0; i < s; i++){
		if(enemies[i].dead){
			enemies.erase(enemies.begin() + i);
			i -= 1;
			s = enemies.size();
		}
	}	

}
//********************************* DRAW *********************************


void Population ::		draw (float delta){
	int s = enemies.size();
	for (int i = 0; i < s; i++){
		if(!enemies[i].dead)
			enemies[i].draw(delta);
	}

}



	/*/int s = market->shops.size();
	float mx, mz, offs;
	for (int i = 0; i < s; i++){
		mx = market->shops[i].xPos;
		mz = market->shops[i].zPos;
		if (market->shops[i].dir == WEST) offs = 5;
		if (market->shops[i].dir == EAST) offs = -5;
		n.init(NPCType(i), zone(), 0, 0);
		n.xzy(mx + offs, mz, 0);
		npc.push_back(n);

	}//*/