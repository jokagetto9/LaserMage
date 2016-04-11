//********************************* INITIALIZATION *********************************
#include "ControllerInput.h"

void ControllerInput::init(){
	for (int i = 0; i < 256; i++) keyPressed[i] = false;		
	for (int i = 0; i < 20; i++) specialKeyPressed[i] = false;
}


//********************************* KEY CYCLE *********************************


void ControllerInput::pollKeyEvents(){
	SDL_Keycode key;
	while(SDL_PollEvent(&ev)){
		key = ev.key.keysym.sym;
		switch (ev.type){
			case SDL_QUIT: G->gameActive = false; break;
			case SDL_KEYDOWN: keyDown(key); break; // Handle key presses     
			case SDL_KEYUP: keyUp(key); break;
}	}	}


// Cycle through key presses and set the key event to true
void ControllerInput::keyDown(SDL_Keycode key){
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
	}	else if (key == SDLK_r && G->program == 0)	{
		H->equipAction(2);
	}	else if (key == SDLK_t && G->program == 0)	{
		H->equipAction(3);
	}	
}

// Cycle through key releases and set the key event to false
void ControllerInput::keyUp(SDL_Keycode key){
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
			if (H->speedMode == 2) H->updateSpeedMode(1);			break;	
		default: break;
    }
	//for (int i = 0; i < 4; i++) if (specialKeyPressed[i] == true) stop = false;
	if (halt) H->halt();
}

void ControllerInput::		clearKeys(){
	for (int key = 0; key < 256; key++){
		if (key == SDLK_w || key == SDLK_s || key == SDLK_a || key == SDLK_d || key == SDLK_e) {
			//off(key); //stop = false;
		}else if (key < 256 && key >= 0) off(key);
	}
}



//********************************* INPUT RESPONSES *********************************

void ControllerInput::		checkToggles(){
	//toggles
	if (keyPressed[SDLK_ESCAPE])			G->gameActive = false; 
	//tab key
	if (keyPressed[SDLK_TAB]) 			{	
		G->resetProgram(0);
		if (G->menuCommand != PLAY) 
			G->enterMenu(PLAY);
		else
			G->enterMenu(MAIN);
		off(SDLK_TAB); 
	}	

	if (keyPressed[SDLK_BACKQUOTE]) 	{	G->toggleConsole();		off(SDLK_BACKQUOTE);}
	if (!G->paused){
	
		if (keyPressed[SDLK_y]) 		{	G->toggleFog();			off(SDLK_y);}	
		if (keyPressed[SDLK_z])			{	H->toggleSpeedMode();	off(SDLK_z);}
		if (keyPressed[SDLK_f])			{	H->toggleDebug();		off(SDLK_f);}
		checkProgram();
	}
}

void ControllerInput::		checkProgram(){
	if (G->program == 0){		
		if (keyPressed[SDLK_p]) 		{	
			G->enterMenu(DBG);//G->program++;				
			off(SDLK_p);
		}
	}else if (G->program > 0){	
		if (G->feat.i == 0){	
			if (G->action) 
				G->addFeature();
		}else{
			if (G->action) 
				G->saveProgramEntry();
			if (keyPressed[SDLK_r]) 		{	
				G->cycleFeatDir(1);			
				off(SDLK_r);
			}else if (keyPressed[SDLK_t]) 		{	
				G->cycleFeatDir(-1);			
				off(SDLK_t);
			}
		}
		if (keyPressed[SDLK_q]) 		{	G->resetProgram(0);			off(SDLK_q);}		
		//if (keyPressed[SDLK_p]) 		{	G->program++;				off(SDLK_p);}

	}
}


void ControllerInput::		actionInput(){
	if (!G->paused){
		//movement WSAD - > direction keys 
		if (keyPressed[SDLK_w])					H->walk(UP);				
		else if (keyPressed[SDLK_s])			H->walk(DOWN);	
		else if (keyPressed[SDLK_a])			H->walk(LEFT);
		else if (keyPressed[SDLK_d]) 			H->walk(RIGHT);
		if (keyPressed[SDLK_w] && keyPressed[SDLK_a])		H->walk(UL);				
		else if (keyPressed[SDLK_w] && keyPressed[SDLK_d])	H->walk(UR);	
		else if (keyPressed[SDLK_s] && keyPressed[SDLK_a])	H->walk(DL);
		else if (keyPressed[SDLK_s] && keyPressed[SDLK_d]) 	H->walk(DR);
		//action
		if (specialKeyPressed[5] && H->speedMode == 1) 
				H->updateSpeedMode(2);
		//if (keyPressed[SDLK_e])			{ H->enterPOI(); keyPressed[SDLK_e] = false;}


	}
}

void ControllerInput::		cameraInput(){
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

//********************************* MENU *********************************

void ControllerInput::		menuInput(Menu *screen){
	if (G->paused) {
		// add 1-5, R, T, F, C, V, ESC
		if (keyPressed[SDLK_w] || specialKeyPressed[UP]){ 
			keyPressed[SDLK_w] = false; specialKeyPressed[UP] = false;
			screen->cursorUD(-1);
		}else if (keyPressed[SDLK_s] || specialKeyPressed[DOWN]){ 
			keyPressed[SDLK_s] = false; specialKeyPressed[DOWN] = false;
			screen->cursorUD(1);
		}else if (keyPressed[SDLK_a] || specialKeyPressed[LEFT]){ 
			keyPressed[SDLK_a] = false; specialKeyPressed[LEFT] = false;
			screen->cursorLR(-1);
		}else if (keyPressed[SDLK_d] || specialKeyPressed[RIGHT]){ 
			keyPressed[SDLK_d] = false; specialKeyPressed[RIGHT] = false;
			screen->cursorLR(1);
		}
		if (G->action){//(keyPressed[SDLK_e]) {
			screen->enter();	
			G->action = false;
			//off(SDLK_e);
		} else if (keyPressed[SDLK_q]) {
			screen->quit();	
			off(SDLK_q);
		}
	}
}

//********************************* MEMBER FUNCTIONS *********************************


void ControllerInput::		on(SDL_Keycode key){ keyPressed[key] = true ; }
void ControllerInput::		off(SDL_Keycode key){ keyPressed[key] = false; }
