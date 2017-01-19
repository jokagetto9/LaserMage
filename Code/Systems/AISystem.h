#ifndef AISYSTEM_H
#define AISYSTEM_H

#include "../Entities/AIBehaviours.h"
#include "../Entities/Book.h"

//********************************* CONSTANTS *********************************


//********************************* INITIALIZATION *********************************

class AISystem  { 
public:
	
	static void AISystem ::	applyDefault (AIBrain& ai);

	static void AISystem ::	aiUpdate (float aiDelta);
	
	static void AISystem ::	aiUpdate (ID id);
	
	static void AISystem ::	healthUpdate (ID id);

	static void AISystem:: applyAIInteractions(ID id);
	
	static Subject death;
	static Subject hurt;
	static Subject stop;
	static Subject walk;
	static Subject run;

	static SepFunction sep;
	static TargFunction targ;
		
};
#endif