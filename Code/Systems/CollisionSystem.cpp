#include "CollisionSystem.h"

void CollisionSystem:: checkCollisions(){
	EntityList& e = Book::entities;
	GridData * g1 = NULL;	
	GridData * g2 = NULL;
	bool actors;
	for (ID x = 0; x < e.gridSize.x; x++)
		for (ID z = 0; z < e.gridSize.z; z++){
			XZI xz;
			g1 = e.grid[x][z];
			while (g1){
				for (int adj = -2; adj < 8; adj+=2) {
					if (adj < 0){
						g2 = g1->next;
					}else{
						xz.x = x+ADJ_[adj].x;
						xz.z = z+ADJ_[adj].z;
						if (xz.x >= 0 && xz.z >= 0 && xz.x < e.gridSize.x && xz.z < e.gridSize.z)
							g2 = e.grid[xz.x][xz.z];
						else 
							g2 = NULL;
					}
					while(g2){		
						
						if ( g1 == g2){
							cout << "Train Wreck ";
							cout << g1->xz.x << ", " << g1->xz.z << "     " ;
							cout << g2->xz.x << ", " << g2->xz.z  ;
							cout << endl;
						}
						checkCollisions(g1->index, g2->index);
						g2 = g2->next;
					}
				}	
				g1 = g1->next;
			}
		}
}	

void CollisionSystem:: checkCollisions(ID g1, ID g2){
	EntityList& e = Book::entities;
	
	try{
		float d;
		glm::vec3 p1, p2, dv1, dv2;
		p1 = e.getPos(g1);
		p2 = e.getPos(g2);
		dv1 = p1 - p2;
		dv2 = p2 - p1;
		d = sqrt(getDistSq(p1, p2)); //-2
		if (d <= e.swarm[g2].coh.rad && g1 != g2) {
			e.collide[g1].add(g1, g2, d, dv1); 
			e.collide[g2].add(g2, g1, d, dv2); 
			//prevent double collisions
		}
	}catch(...){
		cout << g1 << ", " << g2 << "collision failure." ;
		cout << endl;
	}	
	/*// col, sep, avo, ali, coh
	
	glm::vec3 pos = ent->location[index].pos();
	glm::vec3 sep = ent->obstacles[index].calcSep(pos);
	if (notZero(sep)){
		if (ent->obstacles[index].collide(pos)){
			ent->motion[index].backTrack(ent->location[index]);
		}
		//truncate(sep, 1);
		ent->motion[index].targetV += sep;			
	}else {
		glm::vec3 coh = ent->obstacles[index].calcCoh(pos); 
		if (notZero(coh)){
			//truncate(coh, 0.001);
			ent->motion[index].targetV += coh;			
		}
	}	

//*/
}

void CollisionSystem:: applyCollisions(){
	EntityList& e = Book::entities;
	ID s = e.state.size();
	for (ID i = 0; i < s; i++){		
		if (e.state[i]->on()){
			applyCollisions(i);
		}
	}
}

//!!!COLLISION!!!SHIT!!!
void CollisionSystem:: applyCollisions(ID id){
	EntityList& e = Book::entities;
	float colRad = 1.2;
	ID s = e.collide[id].size();
	for (ID i = 0; i < s; i++){	
		CollisionData cd = e.collide[id].getCollisionData(i);	
		int damage = 0;		
		colRad = e.getOuterRad(e.gData[id].index);
		colRad += e.getOuterRad(e.gData[cd.obj2].index);
		colRad /= 2;
				
		if(cd.dist < colRad){
			/*/
			//if(e.health[id].damageable && e.damage[cd.obj2].damage
				e.health[id].health -= 3;
				AISystem::hurt.notify(e.gData[id]);
			//if(e.health[id].consuming && e.damage[cd.obj2].consumable) //crash?
				e.health[id].kill();
			//if(e.health[id].moveing && e.damage[cd.obj2].moveable)
				AISystem::stop.notify(e.gData[id]);
				AISystem::stop.notify(e.gData[id]);
			//crash type? 

			//*/
			if (e.getEnt(id) == 1 && e.gData[cd.obj2].ent == 2){
			//if(e.health[id].damageable && e.damage[cd.obj2].damaging)
				e.health[id].health -= 3;
				AISystem::hurt.notify(e.gData[id]);
				//1 and 3 /if damaging
			}else if (e.gData[id].ent == 2 && e.gData[cd.obj2].ent == 1){
				//if consuming and consumable
				e.health[id].kill();
				//AISystem::hurt.notify(e.gData[id]);
			}else if (e.gData[id].ent == 2 && e.gData[cd.obj2].ent == 2){ 
				// lasers cant hit lasers //bullets can though				
			}else if (e.gData[id].ent == 2 && e.gData[cd.obj2].ent == 3 ){
				//if consuming and consumablew
				e.health[id].kill();
			}else if (e.gData[id].ent == 2 && e.gData[cd.obj2].ent == 4) {
				//particle hits player - source dependent
		//3 and 1 //if damaging
			}else if (e.gData[id].ent == 3 && e.gData[cd.obj2].ent == 2){
				//e2 damaging and e1 damageable
				//damage calc - defense vs power
				//damage animation if powerful
				e.health[id].health -= 5;
				//target[id].noTarget();
				e.motion[id].backTrack(e.location[id], e.swarm[id].col.rat);
				glm::vec3 p = e.motion[cd.obj2].speed;
				//p *= 5;
				e.location[id].push(p);
		//3 and 3

			}else if (e.gData[id].ent == 3 && e.gData[cd.obj2].ent == 4){ 
				//damage++;
				//cout << damage << endl;
				//hero hits enemy - enemy dependent
		//4 and 1
			}else if (e.gData[id].ent == 4 && e.gData[cd.obj2].ent == 2){ 
				//hero hits particle - enemy dependent
			}else if (e.gData[id].ent == 4 && e.gData[cd.obj2].ent == 3){ 
				e.health[0].health--;
				//hero hits enemy - enemy dependent
			}else {		
				// if e2.halting and e1.haltable			
				e.motion[id].backTrack(e.location[id], e.swarm[id].col.rat);
			}
		}
	}	
}


//*/