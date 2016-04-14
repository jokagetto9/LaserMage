#ifndef ENGINE_H
#define ENGINE_H

#include "ControllerInput.h"


//********************************* INITIALIZATION *********************************

class Engine {
public:

	Engine::	Engine();
/*/ Purpose: default constructor /*/

	bool initGLAttrib(); /*/
	Purpose: Load SDL_GL attributes 
	Returns: true if nothing fails
	Side Effects:  Initializes framebuffer, enables, depthbuffer, version, linear filtering 
	/*/
 
	bool initGLEW(); /*/
	Purpose: init GLEW  
	Returns: true if nothing fails
	Side Effects:  Initializes GL extensions
	/*/

	bool initSDL(); /*/
	Purpose: Load SDL window using OpenGL 
	Parameter(s): N/A
	Precondition(s): N/A
	Returns: true if nothing fails
	Side Effects:  Initializes SDL_Window, SDL_GL Context, SDL_image
	Triggers: initGLAttrib, initGLEW, displayVersion
	/*/


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
	
	void Engine::displayVersion(); /*/
	Side Effects: display opengl and graphics card versions  
	/*/
	

	void Engine::	clearDisplay();
	void Engine ::flush(){ glFlush(); SDL_GL_SwapWindow(sdlWindow); }

//************************************************** MEMBERS ***************************************************


	SDL_Window* sdlWindow;			//The window we'll be rendering to
	SDL_Renderer* sdlRenderer;		//The window renderer
	SDL_GLContext sdlContext;		//OpenGL context

	bool initW, initC;
						// root class managing world objects
		//Spawner spawner;
		//World world;
		bool menuView;

};
#endif