//********************************* INITIALIZATION *********************************
#include "AIBehaviours.h"


glm::vec3 SepFunction::calc(ID eIndex, glm::vec3 v){
	EntityList * e = &Book::entities;
	glm::vec3 sepV = glm::vec3(0);
	ID s = e->collide[eIndex].size();
	float sepRad = 2;
	for (ID i = 0; i < s; i++){	
		CollisionData cd = e->collide[eIndex].getCollisionData(i);	
		ID eIndex2 = cd.obj2;
		if (e->gData[eIndex2].enabled){ 				// in case of deleted entities
			sepRad = e->getInnerRad(e->gData[eIndex2].index);
			sepRad += e->getInnerRad(e->gData[eIndex].index);
			sepRad /= 2;
			sepV += calcSep(sepRad, cd.dist, cd.distV);	
		}
	}
	truncate(sepV, 10);
	return sepV;
}



glm::vec3 SepFunction::calcSep(float rad, float d, glm::vec3 dv){
	//dv *= d/(d+col.rad); 
	glm::vec3 sep = glm::vec3(0);
	if (d <= rad){
		float c = (rad - d)/ rad;
		sep = c * dv/d;
	}
	return sep;
}


void SepFunction::apply(ID eIndex, AIV &aiv) {
	EntityList * e = &Book::entities;
	if (notZero(aiv.v)){
		glm::vec3 tempV = e->motion[eIndex].targetV;
		tempV *= aiv.rat;
		e->motion[eIndex].targetV = aiv.v;	
		e->motion[eIndex].targetV += tempV;
	}
};
