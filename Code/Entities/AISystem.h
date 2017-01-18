#ifndef AISYSTEM_H
#define AISYSTEM_H

#include "AIBehaviours.h"
#include "Book.h"

//********************************* CONSTANTS *********************************


//********************************* INITIALIZATION *********************************

class AISystem  { 
public:
	
	static void AISystem ::	applyDefault (AIBrain& ai);

	static void AISystem ::	aiUpdate (float aiDelta);
	
	static void AISystem ::	aiUpdate (ID id);
	
	static void AISystem ::	healthUpdate (ID id);

	static void AISystem:: applyAIInteractions(ID id);

	static SepFunction sep;
	static TargFunction targ;
		
};
#endif