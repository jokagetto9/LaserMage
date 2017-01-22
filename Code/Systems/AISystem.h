#ifndef AISYSTEM_H
#define AISYSTEM_H

#include "../Entities/AIBehaviours.h"
#include "../Entities/Book.h"

//********************************* CONSTANTS *********************************

//********************************* INITIALIZATION *********************************

class AISystem  { 
public:
	
	static void AISystem ::	initStates();
	static void AISystem ::	applyDefault (AIBrain& ai);

	static void AISystem ::	aiUpdate (float aiDelta);
	
	static void AISystem ::	aiUpdate (ID id);
	
	static void AISystem ::	healthUpdate (ID id);

	static void AISystem:: applyAIInteractions(ID id);
	static void AISystem:: registerSub(Subject& sub);
	
	static int AISystem ::	getStateID(string s);
	
	static vector<Subject *> states;
	static Subject off;
	static Subject stop;
	static Subject walk;
	static Subject run;
	static Subject hurt;
	static Subject death;

	static SepFunction sep;
	static TargFunction targ;
	
		
};
#endif