#ifndef AIBEHAVIOURS_H
#define AIBEHAVIOURS_H


#include "Book.h"
#include "../BaseEngine/Template/Functions.h"

//********************************* CONSTANTS *********************************


class DeathAction: public AIBehaviour {
public:


};


class SepFunction: public AIVBehaviour {
public:

	glm::vec3 calc(ID eIndex, glm::vec3 v) ;
	
	glm::vec3 SepFunction::calcSep(float rad, float d, glm::vec3 dv);
	//void SepFunction::normalizeVectors(){		truncate(sep.v, sep.rat);	};
	void apply(ID eIndex,  AIV &aiv) ;


};


class CohFunction: public AIVBehaviour {
public:

	glm::vec3 calc(ID eIndex, glm::vec3 v) {return glm::vec3(0);};
	void apply(ID eIndex, AIV &aiv) {};

};


class AvoFunction: public AIVBehaviour {
public:

	glm::vec3 calc(ID eIndex, glm::vec3 v) {return glm::vec3(0);};
	void apply(ID eIndex, AIV &aiv) {};

};


class AliFunction: public AIVBehaviour {
public:

	glm::vec3 calc(ID eIndex, glm::vec3 v) {return glm::vec3(0);};
	void apply(ID eIndex, AIV &aiv) {};

};

class ColFunction: public AIVBehaviour {
public:

	glm::vec3 calc(ID eIndex, glm::vec3 v) {return glm::vec3(0);};
	void apply(ID eIndex, AIV &aiv) {};

};









#endif