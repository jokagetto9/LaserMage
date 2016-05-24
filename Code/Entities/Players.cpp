#include "Players.h"

void Players:: P1Update(float physDelta){
	delta = physDelta;
	update(P1);
}

void Players:: P1aiUpdate(float aiDelta){	
	delta = aiDelta;
	aiUpdate(P1);
}


void Players:: drawP1(float frameDelta){	 
	delta = frameDelta;
	M->gridBO.prepHero();
	refresh(P1);  
	draw(P1);	
}