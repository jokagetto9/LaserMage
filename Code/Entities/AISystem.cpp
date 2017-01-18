#include "AISystem.h"

SepFunction AISystem ::sep;
TargFunction AISystem ::targ;


void AISystem ::	applyDefault (AIBrain& ai){	
	AIV targAIV = {1};
	ai.vectors.push_back(targAIV);
	ai.movement.push_back(&targ);
	AIV sepAIV = {0.04};
	ai.vectors.push_back(sepAIV);
	ai.movement.push_back(&sep);



}

void AISystem ::	aiUpdate (float aiDelta){
	EntityList& e = Book::entities;
	e.delta = aiDelta;
	ID s = e.state.size();
	for (ID i = 0; i < s; i++){
		if (e.state[i]->on()){
			aiUpdate(i);
			healthUpdate(i);
		}
	}
}
	
void AISystem ::	aiUpdate (ID id){
	EntityList& e = Book::entities;

	if (notZero(e.target[id].targetP)){
		//if  (e.gData[id].ent != 2){	//update target if not !!!targetlocked!!!
		//	glm::vec3 tempV = scaleVector(e.location[id].pos(), e.target[id].targetP, 0.1);
		//	e.motion[id].setTarget(tempV);
		//}
		//check set still 

		AIBrain& ai = e.ai[id];
		ID s = ai.movement.size();
		for (ID i = 0; i < s; i++){
			glm::vec3 iv(0);
			ai.vectors[i].v = ai.movement[i]->calc(id, iv);
			ai.movement[i]->apply(id, ai.vectors[i]);
		}

		//applyAIInteractions(id); //apply without target? !!!wary!!!
	}else if (e.gData[id].ent != 2){
		e.state[id] = &e.still;
	}
}


void AISystem ::	healthUpdate (ID id){
	EntityList& e = Book::entities;
	//!!!DEATH!!!
	e.health[id].update(1);
	if (e.health[id].isDead()){
		e.death.notify(e.gData[id]);
		e.state[id] = &e.off;
		e.gData[id].disableData(e.grid);
	}
}

void AISystem:: applyAIInteractions(ID id){
	//
	EntityList& e = Book::entities;
	if( e.getEnt(id) == 3){ 
		float sepRad = 2;
		e.swarm[id].reset();
		ID s = e.collide[id].size();
		for (ID i = 0; i < s; i++){	
			CollisionData cd = e.collide[id].getCollisionData(i);	

			if (e.gData[cd.obj2].enabled){ 				// in case of deleted entities
				sepRad = e.getInnerRad(e.gData[cd.obj2].index);
				sepRad += e.getInnerRad(e.gData[id].index);
				sepRad /= 2;

				e.swarm[id].calcSep(sepRad, cd.dist, cd.distV);	
			}
		}
		e.swarm[id].normalizeVectors();



		if (notZero(e.swarm[id].sep.v)){
			glm::vec3 v = e.motion[id].targetV;
			v *= 0.04;
			e.motion[id].targetV = e.swarm[id].sep.v;	
			e.motion[id].targetV += v;
		}
	}
		
	//*/
	
}


