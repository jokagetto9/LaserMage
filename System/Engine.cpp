//********************************* INITIALIZATION *********************************
#include "Engine.h"

//**TEMP**
bool gameActive;

Engine::	Engine(){

}

void Engine::init(){

	//stack.init();
	//input.init();	
	//world.init();
	//onspawner.setWorld(&world);
	//DBT = DebugTool::I(); 
	//DBT->init(&world);
	gameActive = true;
}

void Engine::		loadingMenu(){
	//load null
}

void Engine::quit(){

	//world.quit();
	//if(_DEBUG) cout << "Zones Deleted" << endl;
}

//********************************* SAVING *********************************

void Engine::save(){	
	cout << "Saving..." << endl;	
	//H->saveHero();	
	//G->saveState();
	//world.save();
	//G->save = false;
}


//********************************* PRIMARY CYCLES *********************************
void Engine::update(){		
	pollKeyEvents(); //input.pollKeyEvents();
	//input.checkToggles();	
	//input.actionInput();
	//menu.update();
	//DBT->update();
	//if (G->save) save();
	//if (G->skip == 0){ 
	//	clockCycle();
	//} else skipTime();
	
	//stack.update(input);
	//input.clearKeys();	
}

void Engine::pollKeyEvents(){
	SDL_Keycode key;
	SDL_Event ev;
	while(SDL_PollEvent(&ev))
	{	key = ev.key.keysym.sym;
		switch (ev.type)
		{	case SDL_QUIT: 
			gameActive = false; break;
			case SDL_KEYDOWN: 	break;     
			case SDL_KEYUP: //keyUp(key); 				
				if (key == SDLK_ESCAPE)  
					gameActive = false; 				
				break;
		}	
	}	
}
/*/
void Engine::clockCycle(){
	G->trackAVG(); G->trackFPS();	
	if (!G->paused){
		G->trackTime();
		//world.hourlyUpdate();
	}
	G->incLag();
	while (G->testLag()){	// while phys delta has time lag
		if(G->lagVSlag())	physicsUpdate();	// phys has more lag			
		else				rapidUpdate();		// if ai has equal or more lag			
	}		
	G->prevTime = G->curTime;	// reset cycle
	 //else G->action = false;
}


void Engine::		physicsUpdate(){
	if (!G->paused){	
		//input.cameraInput();
		//world.physUpdate();
		//world.interactions();
		//DBT->physUpdate(); //?
	}
	G->action = false;
	G->decPhysLag();		
}

void Engine::		rapidUpdate(){
	if (!G->paused){	
		//world.rapidUpdate();
		if (G->frequently) {
			//world.freqUpdate();
			G->frequently = false;
		}
	}
	//stack.rapidUpdate();
	//G->decAILag();
}
	//if (G->slowCount == SLOW_AI_FACTOR-1) freqUpdate();// slow ai runs by a factor of ai cycles

	/////////			//if(slowTick == SLOW_AI_FACTOR) 	// SLOW AI UPDATE


void Engine::	skipTime(){
	for (int i = 1; i < G->skip; i++){
		G->trackMinutes(1);
		//if (G->frequently) //world.freqUpdate();
		//world.hourlyUpdate();
	} 
	G->skip=0;
}


//*/
//********************************* DRAW *********************************

void Engine::display(){	
	//if (G->paused && stack.backdrop()){		
		glClearColor(0, 0, 0, 1);	
		clearDisplay();

	/*/} else {
		world.updateEnv();		
		clearDisplay();		
		C->update(H->pos());
		spawner.drawWorld();	
		H->drawHero();
		DBT->draw();
	}/*/
	//stack.drawMenus();
	//menu.draw();
}
 
void Engine::clearDisplay(){

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glMatrixMode(GL_MODELVIEW);	
		glLoadIdentity();	// initialize the selected matrix

}