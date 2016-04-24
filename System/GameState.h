#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "./BaseEngine/BaseGameState.h"
//********************************* CONSTANTS *********************************


//********************************* INITIALIZATION *********************************



class GameState : public BaseGameState{
public:
	void GameState::		init();	
/*/ Purpose: init members
Side Effects:  set prevTime, startTime
Triggers: loadState
/*/
	void GameState::		quit(){delete instance; instance = NULL;}
/*/ Purpose: close game state 
Side Effects:  deletes instance
/*/
	
//********************************* LOADING *********************************

	void GameState::	loadState();
/*/ Purpose: load game state data from gs.txt
Precondition(s): gs.txt has valid data
Side Effects: loads days, minutes
/*/

//********************************* SAVING *********************************

	void GameState::	saveState();
/*/ Purpose: save game state data to gs.txt
Precondition(s): file exists
Side Effects:  Saves days, minutes
/*/
	void GameState:: addFeature();
	void GameState:: saveProgramEntry();
	void GameState:: cycleFeatDir(int i);
	void GameState:: resetProgram(int i);

//********************************* UPDATES *********************************

	void GameState::		trackTime();
/*/ Purpose: track passage of time
Side Effects:	milli += frameDelta (loop 250)
	slowtick++		every 250 ms
	minutes++		every 2 seconds
	days++			every 1440 minutes -> daily = true
	hourly = true	every 60 minutes	(120 seconds)
	frequently		every 5 minutes		(10 seconds)
/*/
	
	void GameState::		trackMinutes(int inc);
	
	
	void GameState::        checkForUpdates();

	void GameState::		trackTicker();
	void GameState::		trackCalendar();


	void GameState::		skipTime(int min);

//************************************************** MEMBERS ***************************************************

	
		int slowTick, slowCount;	//counts to determine timing

		int	milli, minutes, hours;
		int days, months;	

		bool hourly, daily, frequently;
		
		bool saveMap, saveFeature;
		bool inside;	
	
		bool cons;	
		//int program; 
		int skip;
		//MapFeature feat;

		//ACTIONTYPE actionType;
		//int menuIndex;
		//MenuCommand menuCommand;

	//	int menuLevel;
		//NPC * activeNPC;



		//Nub * activeNub;
		//Nub * activeNob;


//********************************* MEMBER FUNCTIONS *********************************
	
	stringstream GameState::printClock();


//********************************* DEBUG *********************************
	
	void GameState::		toggleFog();	

	void GameState::		toggleConsole();	
/*/ Purpose: toggle debug text
Side Effects:  cons -> false, !cons -> true
/*/


	void GameState::		togglePrograms(int i);
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