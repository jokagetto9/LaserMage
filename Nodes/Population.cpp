#include "Population.h"

Population ::		Population (){}


void Population ::		init (){
	EnemyWave wave(MIMIC);
	float d = 60;
	wave.init(1, d);	loadWave(&wave); d+=7.5;
	wave.init(5, d);	loadWave(&wave); d+=7.5;
	wave.init(9, d);	loadWave(&wave); d+=7.5;
	/*/
	wave.init(35, d);	loadWave(&wave); d+=7.5;
	wave.init(36, d);	loadWave(&wave); d+=7.5;
	wave.init(35, d);	loadWave(&wave); d+=7.5;
	wave.init(36, d);	loadWave(&wave); d+=7.5;
	wave.init(35, d);	loadWave(&wave); d+=7.5;
	wave.init(36, d);	loadWave(&wave); d+=7.5;
	wave.init(35, d);	loadWave(&wave); d+=7.5;
	wave.init(36, d);	loadWave(&wave); d+=7.5;
	wave.init(35, d);	loadWave(&wave); d+=7.5;
	wave.init(36, d);	loadWave(&wave); d+=7.5;
	wave.init(35, d);	loadWave(&wave); d+=7.5;
	//*/
}


void Population ::	loadWave(EnemyWave * w){
	Enemy e;
	float theta = w->centerTheta;
	float tempTheta = tempTheta = theta + (w->quantity-1)* w->clustering/2;   
	for (int i = 0; i < w->quantity; i++){
		if (w->mirrored && theta >= 0){
			e.init(tempTheta-i*w->clustering, w->dist); 	enemies.push_back(e);
			e.init(-tempTheta-i*w->clustering, w->dist); 	enemies.push_back(e);
		} else {
			e.init(tempTheta-i*w->clustering, w->dist); 	enemies.push_back(e);
		}
	}
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


void Population::		physUpdate(){
	int s = enemies.size();
	for (int i = 0; i < s; i++){
		if(!enemies[i].dead)
			enemies[i].physUpdate(10000, G->physDelta);
	}
}
void Population::		aiUpdate(){

	int s = enemies.size();
	for (int i = 0; i < s; i++){
		if(!enemies[i].dead)
			enemies[i].aiUpdate(G->aiDelta);
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


void Population ::		draw (){
	int s = enemies.size();
	for (int i = 0; i < s; i++){
		if(!enemies[i].dead)
			enemies[i].draw(G->avgFrameDelta);
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