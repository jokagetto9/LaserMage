#include "Players.h"

void Players:: P1Update(float physDelta){
	delta = physDelta;
	update((ID)P1);
}

void Players:: P1aiUpdate(float aiDelta){	
	delta = aiDelta;
	aiUpdate((ID)P1);
}


void Players:: drawP1(float frameDelta){	 
	delta = frameDelta;
	M->gridBO.prepHero();
	refresh(P1);  
	draw(P1);	
}

void Players:: drawP2(float frameDelta){	 
	delta = frameDelta;
	M->gridBO.prepHero();
	refresh(P2);  
	draw(P2);	
}