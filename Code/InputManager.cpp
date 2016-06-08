//********************************* INITIALIZATION *********************************
#include "InputManager.h"
//********************************* KEY CYCLE *********************************
InputManager::InputManager(){
	zoomOut = false; 
	controls= false;
} 

//********************************* INPUT RESPONSES *********************************



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



void InputManager::		debugToggles(){	
	if (keyPressed[SDLK_c]) {
		off(SDLK_c);
		if (zoomOut){
			C->yPos /= 2;
			zoomOut = false;
		}else{
			C->yPos *= 2;
			zoomOut = true;
		}
	}	
	if (keyPressed[SDLK_0]) {
		off(SDLK_0);
		if (controls)
			controls = false;
		else
			controls = true;
		
	}
}