//********************************* INITIALIZATION *********************************
#include "GameState.h"
GameState* GameState::instance = 0;
GameState* G;



void GameState::init(){

	state = TITLE;
	gameActive = true;  action = false;
	paused = true;	

	actionString = "";
}
