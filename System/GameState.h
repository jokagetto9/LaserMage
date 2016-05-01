#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "BaseEngine/BaseGameState.h"
//********************************* CONSTANTS *********************************


//********************************* INITIALIZATION *********************************



class GameState : public BaseGameState{
public:

	void GameState::		quit(){delete instance; instance = NULL;}

//********************************* SINGLETON *********************************

	static GameState* GameState::I(){
		if(instance == 0){
			instance = new GameState();
			return instance;
		}return instance;	
	}

private:
	GameState::GameState(){}
	static GameState* instance ;
};

extern GameState* G;
#endif