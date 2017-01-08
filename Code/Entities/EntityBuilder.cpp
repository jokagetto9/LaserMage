
//********************************* INITIALIZATION *********************************
#include "EntityBuilder.h"



//********************************* INSERT *********************************

ID EntityBuilder ::	createProp (EntityXZ ent){
	EntityList& e = Book::entities;
	PropList & pr = Book::props;
	ID newIndex = e.nextFree(); 
	if (newIndex < MAX_COMPONENTS){
		Animation a;
		e.setDrawFeatures(newIndex, pr.rendering[ent.id], a);

		e.setSize(newIndex, pr.getSize(ent.id));
		e.place(newIndex, ent.x, ent.z);
		//entities.setMotion(newIndex, Motion(Book::particles.max[ent.id]));
		
		Identity iden = pr.getID(ent.id);
		iden.index = newIndex;
		e.setGridData(iden);

		
		e.setState(newIndex, &EntityList::still);
		e.target[newIndex] = Target();

		Health h = pr.health[ent.id];
		e.setHealth(newIndex, h);

		e.count++;
		return newIndex;
	}
	return MAX_COMPONENTS;
}

ID EntityBuilder ::	createParticle (EntityXZ ent){
	EntityList& e = Book::entities;
	ParticleList & pa = Book::particles;
	ID newIndex = e.nextFree();
	if (newIndex < MAX_COMPONENTS){

		Rendering r; r.tex = pa.getProfile(ent.id).tex;
		e.setDrawFeatures(newIndex, r, pa.anim[ent.id]);
		
		e.setSize(newIndex, pa.getSize(ent.id));		
		e.place(newIndex, ent.x, ent.z);
		e.setMotion(newIndex, Motion(pa.max[ent.id]));
		
		Identity iden = pa.getID(ent.id);
		iden.index = newIndex;
		e.setGridData(iden);
		
		e.setState(newIndex, &EntityList::charge);
		e.target[newIndex] = Target();


		Health h = pa.health[ent.id];
		h.setRate(-1);
		e.setHealth(newIndex, h);

		e.count++;
		return newIndex;
	}
	return MAX_COMPONENTS;
}

ID EntityBuilder:: createActor(EntityXZ ent){
	EntityList& e = Book::entities;
	ParticleList & en = Book::enemies;
	ID newIndex = e.nextFree();
	if (newIndex < MAX_COMPONENTS){
		Rendering r; r.tex = en.getProfile(ent.id).tex;
		Animation a = en.anim[ent.id]; 
		a.randomTick();
		e.setDrawFeatures(newIndex, r, a);
		
		e.setSize(newIndex, en.getSize(ent.id));
		e.place(newIndex, ent.x, ent.z);
		e.setMotion(newIndex, Motion(en.max[ent.id]));
		
		Identity iden = en.getID(ent.id);
		iden.index = newIndex;
		e.setGridData(iden);
		
		e.setState(newIndex, &EntityList::still);
		e.target[newIndex] = Target();


		Health h = en.health[ent.id];
		e.setHealth(newIndex, h);
		e.count++;
		return newIndex;
	}
	return MAX_COMPONENTS;
}

ID EntityBuilder:: createHero(){
	EntityList& e = Book::entities;
	ID newIndex = e.nextFree();
	if (newIndex < MAX_COMPONENTS){
		Rendering r; Animation a;
		e.setDrawFeatures(newIndex, r, a);
	
		e.place(newIndex, 0, 0);
		e.setMotion(newIndex, Motion());
		
		Identity iden = {"LaserMage", newIndex, 0, 4};
		e.setGridData(iden);
		
		e.setState(newIndex, &EntityList::still);
		e.target[newIndex] = Target();


		Health h; h.set(40);
		e.setHealth(newIndex, h);
		e.count++;
		return newIndex;
	}
	return MAX_COMPONENTS;
}
