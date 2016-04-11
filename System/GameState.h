#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "lib.h"

//********************************* CONSTANTS *********************************


const float PHYSICS_PERSEC = 30.0f;		// per second
const float AI_PERSEC =  4.0f;			// per second
const float MAXFPS = 60.0f;				// phys + ai are limited to 60 fps

//********************************* INITIALIZATION *********************************



class GameState {
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
	
	void GameState::		trackAVG();
/*/ Purpose: track avgFrameDelta from animations
Precondition(s): avgFrameDelta must be initialized
Side Effects: avgFrameDelta = (avgFrameDelta + prevFrameDelta + curFrameDelta)/3
/*/

	void GameState::		trackFPS();
/*/ Purpose: track avgFPS for display
Precondition(s): game has been running a few seconds
Side Effects: frameCount++
/*/

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

		long prevTime;			//cpu time at the start of the prev frame
		long curTime;			//cpu time at the start of the current frame
		GLuint startTime;		//arbitrary start time for measuring fps

		float frameDelta;			//ms per frame
		float avgFrameDelta;		//avg ms per frame !!!number is halved!!!
	
		float avgFPS;				//approximate fps for display
		int frameCount;				//frame count for fps calc
			
		long physLag, aiLag;		//remaining ms for physics updates
		float physDelta, aiDelta;	// CONST ms per update
		
		int slowTick, slowCount;	//counts to determine timing

		int	milli, minutes, hours;
		int days, months;	

		bool gameActive;//??
		bool hourly, daily, frequently;
		
		bool save, saveMap, load, saveFeature;
		bool inside, action;	
		bool paused, initMenu, updateMenu; 
		bool blackDrop;
	
		bool fog, cons;	
		//int program; 
		int skip;
		//MapFeature feat;

		string actionString;
		//ACTIONTYPE actionType;
		//int menuIndex;
		//MenuCommand menuCommand;

	//	int menuLevel;
		//NPC * activeNPC;



		//Nub * activeNub;
		//Nub * activeNob;


//********************************* MEMBER FUNCTIONS *********************************
	
	void GameState::		getCurrentTime(){curTime = glutGet(GLUT_ELAPSED_TIME);}
/*/ Purpose: update current time
Side Effects: curTime = system time
/*/

	void GameState::		getFrameDelta(){frameDelta = curTime - prevTime;}
/*/ Purpose: get new frame delta
Precondition(s): curTime and prevTime are initialized
Side Effects: frameDelta = ms from prev to cur frame
/*/

	void GameState::		incLag(){ physLag += frameDelta; aiLag += frameDelta; }
/*/ Purpose: increase phys and ai lag
Side Effects: physLag and aiLag increase by frameDelta
/*/

	void GameState::		decPhysLag(){ physLag -= physDelta;	}
/*/ Purpose: decrease physlag by phys cycle time
Precondition(s): phys cycle has just completed
Side Effects: physLag is decreased by (30/1000)ms
/*/

	void GameState::		decAILag(){	aiLag -= aiDelta; }
/*/ Purpose: decrease ailag by ai cycle time
Precondition(s): ai cycle has just completed
Side Effects: aiLag is decreased by 250ms
/*/

	bool GameState::		testLag(){ return physLag > physDelta || aiLag > aiDelta; }
/*/ Purpose: determine if phys or ai lag is large enough to run cycle
Returns: true is flag is > then cycle delta
/*/

	bool GameState::		lagVSlag(){	return physLag - physDelta > aiLag - aiDelta; }
/*/ Purpose: determine which lag is larger
Returns: true if physLag > aiLag
/*/

	void GameState::		togglePause();	
/*/ Purpose: toggle debug text
Side Effects:  cons -> false, !cons -> true
/*/
	//void GameState::		enterMenu(MenuCommand mt);	
/*/ Purpose: toggle debug text
Side Effects:  cons -> false, !cons -> true
/*/

	stringstream GameState::printClock();


//********************************* DEBUG *********************************

	void GameState::		toggleConsole();	
/*/ Purpose: toggle debug text
Side Effects:  cons -> false, !cons -> true
/*/


	void GameState::		toggleFog();
/*/ Purpose: toggle fog distance
Side Effects:  fog -> fogD=1000, !fog -> fogD<500
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