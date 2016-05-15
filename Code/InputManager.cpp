//********************************* INITIALIZATION *********************************
#include "InputManager.h"
//********************************* KEY CYCLE *********************************


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