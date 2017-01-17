#include "PhysicsSystem.h"





void PhysicsSystem ::	update(){
	EntityList& e = Book::entities;
	ID s = e.state.size();
	for (ID i = 0; i < s; i++){ //!!!LIST!!! of unmovables
		if (e.gData[i].enabled) 
			updateGrid(i);
	}
}
void PhysicsSystem ::	update (float physDelta){	
	EntityList& e = Book::entities;
	e.delta = physDelta;
	ID s = e.state.size();
	e.clearGrid();
	for (ID i = 0; i < s; i++){ //!!!LIST!!! of movables
		update(i);
	}
}

void PhysicsSystem ::	update (ID id){
	EntityList& e = Book::entities;
	e.motion[id].updateSpeed(e.delta);
	if (!e.state[id]->still()){
		
		//TODO if stopped change to still
		e.motion[id].move(e.location[id]);		
		
	}
	if(e.gData[id].enabled){
		updateGrid(id);

	}
	//TODO world wrap	
	//NEWBRANCH quadtree
}

void PhysicsSystem::updateGrid(ID id){
	EntityList& e = Book::entities;
	e.collide[id].clear();
	glm::vec3 pos = e.location[id].pos() - C->corner();
	if(e.gData[id].setGrid(e.getGridXZ(pos)))
		e.gData[id].updateData(e.grid);
}


//*/