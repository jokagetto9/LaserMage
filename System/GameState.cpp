//********************************* INITIALIZATION *********************************
#include "GameState.h"
GameState* GameState::instance = 0;
GameState* G;



void GameState::init(){
	prevTime = glutGet(GLUT_ELAPSED_TIME);	// init start time
	startTime = prevTime;

	frameDelta = 0;	 avgFrameDelta = 0;

	avgFPS = 0;	frameCount = -1;
		
	physLag = 0;		physDelta = 1000/PHYSICS_PERSEC;	// ms per update
	aiLag = 0;			aiDelta = 1000/AI_PERSEC;			// ms per update

	gameActive = true;  action = false;
	paused = true;	initMenu = false; updateMenu = false;
	blackDrop = true;

	fog = true; 
	actionString = "";
}
