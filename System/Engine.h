#ifndef ENGINE_H
#define ENGINE_H


#include "GameState.h"
#include "BaseEngine/BaseEngine.h"


//********************************* INITIALIZATION *********************************

class Engine : public BaseEngine {
public:

	Engine::	Engine();
/*/ Purpose: default constructor /*/
	
	void Engine::		init(); 
/*/ Purpose: initialize members 
Triggers: menu.init(), env.init(), spawner.loadDebugBiomes();	
/*/

	void Engine::	quit(); 
/*/ Purpose: close engine 
Triggers: spawner.quit()
/*/


//********************************* LOADING *********************************

//********************************* SAVING *********************************

void Engine::		save();	
/*/ Purpose: save game data
Precondition(s): save files exist
Side Effects:  G->save = false
Triggers: H->saveHero(), G->saveState(), spawner.save();
/*/

//********************************* UPDATES *********************************

	void Engine::		physicsUpdate();
/*/ Purpose: update highp game data at 30 times per second
Side Effects: G->action = false, G->decPhysLag()
Triggers: H->physUpdate(), spawner.collisionDetection()
/*/

	void Engine::		rapidUpdate();
/*/ Purpose: update data at 4 times per second
Side Effects: 	G->decAILag(), freqUpdate()
Triggers: env.aiUpdate()
/*/
	void Engine::	skipTime();
		
//************************************************** MEMBERS ***************************************************
	
};
#endif