#ifndef ENGINE_H
#define ENGINE_H

#include "StackManager.h"
#include "ControllerInput.h"


//********************************* INITIALIZATION *********************************

class Engine {
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

	void Engine::update();
/*/ Purpose: update game data at 30 times per second
Side Effects: G->getCurrentTime()
Triggers: input.update(menu), save, 
	G->trackFPS(), G->trackAVG(), clockCycle()
/*/
	
	void Engine::		clockCycle();
/*/ Purpose: ensure phys and ai cycle run at expected cps
Side Effects: G->incLag(), G->prevTime = G->curTime;
Triggers: G->trackTime(), spawner.hourlyUpdate(),
	physicsUpdate(), rapidUpdate()
/*/

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

//********************************* DRAW *********************************

	void Engine::display();
/*/ Purpose: display all game elements -> altered by menus 
Precondition(s): once per frame
Side Effects: clear frame buffer bits
Triggers: env.update, env.refreshView(b), C->update(H->pos),
		spawner.drawZones(), H->drawHero(avgfr), menu.draw(),
/*/

	//void Engine::reshape(int w, int h);
	
	
	void Engine::	clearDisplay();
//************************************************** MEMBERS ***************************************************
	
		StackManager stack;		// root class to the menu system
		ControllerInput input;			// handle for managing input						// root class managing world objects
		//Spawner spawner;
		//World world;
		bool menuView;

};
#endif