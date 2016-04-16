//********************************* INITIALIZATION *********************************
#include "Engine.h"

Engine::	Engine(){	
	BaseEngine::BaseEngine();
}

void Engine::init(){
	
}

void Engine::quit(){
	BaseEngine::quit();
}
//********************************* PRIMARY CYCLES *********************************


void Engine::		physicsUpdate(){
	//input.cameraInput();
	//world.physUpdate();
	//world.interactions();
	//DBT->physUpdate(); //?
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
}







