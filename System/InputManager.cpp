//********************************* INITIALIZATION *********************************
#include "InputManager.h"

//********************************* KEY CYCLE *********************************


void InputManager::pollKeyEvents(){
	SDL_Keycode key;
	while(SDL_PollEvent(&ev)){
		key = ev.key.keysym.sym;
		switch (ev.type){
			case SDL_QUIT: G->gameActive = false; break;
			case SDL_KEYDOWN: keyDown(key); break; // Handle key presses     
			case SDL_KEYUP: keyUp(key); break;
}	}	}


// Cycle through key presses and set the key event to true
void InputManager::keyDown(SDL_Keycode key){
	//quick actions 
	if (key == SDLK_w || key == SDLK_s || key == SDLK_a || key == SDLK_d) on(key);
	else switch (key){		
		case SDLK_UP: specialKeyPressed[UP] = true; break;
		case SDLK_DOWN: specialKeyPressed[DOWN] = true; break;
		case SDLK_LEFT: specialKeyPressed[LEFT] = true; break;
		case SDLK_RIGHT: specialKeyPressed[RIGHT] = true; break;	
		case SDLK_LSHIFT: specialKeyPressed[5] = true; break;	
		default: break;
    }
	if (key == SDLK_e)	{
		G->action = true;
	}	
}

// Cycle through key releases and set the key event to false
void InputManager::keyUp(SDL_Keycode key){
	// disable directions on lift
	bool halt = true;
	if (key == SDLK_w || key == SDLK_s || key == SDLK_a || key == SDLK_d) {
		off(key); //halt = false; //spinning camera
	}else if (key < 256 && key >= 0) on(key);		//activate regular keys
	else switch (key){		
		case SDLK_UP: specialKeyPressed[UP] = false; break;
		case SDLK_DOWN: specialKeyPressed[DOWN] = false; break;
		case SDLK_LEFT: specialKeyPressed[LEFT] = false; break;
		case SDLK_RIGHT: specialKeyPressed[RIGHT] = false; break;	
		case SDLK_LSHIFT: specialKeyPressed[5] = false; 
			//if (H->speedMode == 2) H->updateSpeedMode(1);			
			break;	
		default: break;
    }
	//for (int i = 0; i < 4; i++) if (specialKeyPressed[i] == true) stop = false;
	//if (halt) H->halt();
}

//********************************* INPUT RESPONSES *********************************

void InputManager::		checkToggles(){
	//toggles
	if (keyPressed[SDLK_ESCAPE])			G->gameActive = false; 
	//tab key
	if (keyPressed[SDLK_TAB]) 			{	
		//G->resetProgram(0);
		//if (G->menuCommand != PLAY) 
			//G->enterMenu(PLAY);
		//else
			//G->enterMenu(MAIN);
		off(SDLK_TAB); 
	}	

	if (keyPressed[SDLK_BACKQUOTE]) 	{	G->toggleConsole();		off(SDLK_BACKQUOTE);}
	if (!G->paused){
	
		if (keyPressed[SDLK_y]) 		{	G->toggleFog();			off(SDLK_y);}	
		if (keyPressed[SDLK_z])			{	}//H->toggleSpeedMode();	off(SDLK_z);}
		if (keyPressed[SDLK_f])			{	}//H->toggleDebug();		off(SDLK_f);}
	
	}
}


void InputManager::		actionInput(){
	if (!G->paused){
		//movement WSAD - > direction keys 
		if (keyPressed[SDLK_w])					;//H->walk(UP);				
		else if (keyPressed[SDLK_s])			;//H->walk(DOWN);	
		else if (keyPressed[SDLK_a])			;//H->walk(LEFT);
		else if (keyPressed[SDLK_d]) 			;//H->walk(RIGHT);
		if (keyPressed[SDLK_w] && keyPressed[SDLK_a])		;//H->walk(UL);				
		else if (keyPressed[SDLK_w] && keyPressed[SDLK_d])	;//->walk(UR);	
		else if (keyPressed[SDLK_s] && keyPressed[SDLK_a])	;//H->walk(DL);
		else if (keyPressed[SDLK_s] && keyPressed[SDLK_d]) 	;//H->walk(DR);
		//action
		//if (specialKeyPressed[5] && H->speedMode == 1) 
				//H->updateSpeedMode(2);
		

	}
}
/*/
void InputManager::		cameraInput(){
	if (!G->paused){
		//UDLR - > camera pan keys
		if (C->mode == 0){
			float f = G->physDelta;
			if (specialKeyPressed[UP])		C->zoom(-f);
			if (specialKeyPressed[DOWN])	C->zoom(f);
			if (specialKeyPressed[LEFT])	C->pan(f);	 	
			if (specialKeyPressed[RIGHT])	C->pan(-f);		
		}
	}
}
//*/