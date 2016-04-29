//********************************* INITIALIZATION *********************************
#include "InputManager.h"
#include "../Nodes/Hero.h"
//********************************* KEY CYCLE *********************************


//********************************* INPUT RESPONSES *********************************

void InputManager::		checkToggles(){
	if (keyPressed[SDLK_ESCAPE])
		G->gameActive = false; 
	if (keyPressed[SDLK_TAB]) 	{
		if (G->screen != PLAY) 
			G->enterMenu(PLAY);
		else
			G->enterMenu(TITLE);
		off(SDLK_TAB); 
	}	
}

Command * InputManager::		mouseInput(){
	lasercmd.set(mouseL);
	return &lasercmd;
}
//
void InputManager::		cameraInput(){
	/*/UDLR - > camera pan keys
	if (!G->paused){
		if (C->mode == 0){
			float f = G->physDelta;
			if (specialKeyPressed[UP])		C->zoom(-f);
			if (specialKeyPressed[DOWN])	C->zoom(f);
			if (specialKeyPressed[LEFT])	C->pan(f);	 	
			if (specialKeyPressed[RIGHT])	C->pan(-f);		
		}
	}
//*/
}