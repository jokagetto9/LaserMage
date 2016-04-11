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

	slowCount = 0; slowTick = 0;	

	
	gameActive = true; 
	hourly = false; 	daily = false; frequently = false;
	
	save = false;	load = false; //gload
	saveMap = false; saveFeature = false;

	inside = false; action = false;
	paused = true;	initMenu = false; updateMenu = false;
	blackDrop = true;

	fog = true; cons = false; 
	//program = 0; skip = 0;
	//feat.i = 0; feat.d = DUNNO; 

	actionString = "";
	//actionType = NO_a;
	//enterMenu(PLAY);

	//if (load) 
		//loadState();
}

//********************************* LOADING *********************************


void GameState::	loadState(){
	//default
	days = 0;	minutes = 360;
	milli = 0;
	months = 0;

	string gsl; 
	int gsv; int cntr = 0;
	ifstream gsf ("gs.txt");
	if (gsf.is_open())  {
		while ( getline (gsf, gsl) ) {
			if (gsl != "datetime_stop" && cntr < 2){					
				stringstream ss(gsl);
				ss >> gsv; 
				if  (cntr == 0) days = gsv;
				else if  (cntr == 1) minutes = gsv;
				cntr++;
			}
		} 
	}else{
		cout << "Failed to load inventory." << endl;
	}
	gsf.close();

	hours = minutes/60;
}

//********************************* SAVING *********************************

void GameState::	saveState(){
	ofstream gsf ("gs.txt");
	if (gsf.is_open())  {
		//for ( int i = 0 ; i < 8 ; i++)
		gsf << days << endl;
		
		gsf << minutes << endl;
		gsf << "datetime_stop";
	}else		cout << "Failed to save Game State." << endl;
    gsf.close();
}



//********************************* UPDATES *********************************

void GameState::	trackAVG(){
	float a = frameDelta;
	
		getCurrentTime();
		getFrameDelta(); 
		/*/
		if (frameDelta < 16){
			SDL_Delay(16-frameDelta);	
			getCurrentTime();	
			getFrameDelta(); 
		}//*/

	if (avgFrameDelta != 0){
		avgFrameDelta = (avgFrameDelta + a )/2;  
		//avgFrameDelta = (avgFrameDelta + a + frameDelta)/3;  
		avgFrameDelta += frameDelta/2;
	}
	else avgFrameDelta = frameDelta; 
}

void GameState::	trackFPS(){
	if (frameCount >= 1000){
		frameCount = 0;
		startTime = curTime;
	}else {
		frameCount++;
		avgFPS = frameCount / ( (curTime-startTime)  / 1000.f );
	}
}


void GameState::	trackTime(){
	if (milli >= 250 )	{
		
		slowTick ++;	
		milli -= 250;
		if (slowTick == 8){
			slowTick = 0;
			trackMinutes(1);
		}
	}else {
		milli += frameDelta;
	}
}

void GameState::		trackMinutes(int inc){
	minutes += inc; 
	if (minutes == 1440) {
		minutes = 0;
		days++;
		daily = true;
		//logfile << "Day " << days << endl;
	}			
	hours = minutes/60;
	checkForUpdates();
}


void GameState::        checkForUpdates(){
	if (minutes % 60 == 0)	hourly = true;
	if (minutes % 5 == 0)	frequently = true;
}


void GameState::		skipTime(int min){	
	skip = min;
}

//********************************* MEMBER FUNCTIONS *********************************


stringstream GameState::printClock(){
	stringstream ss;
	int m = minutes%60;
	ss << hours << ":";
	if (m < 10) ss << "0"; 
	ss << m;			
	return ss;
}

/*/
void GameState::enterMenu(MenuCommand mt){
	menuCommand = mt; 
	initMenu = true;
	updateMenu = true;
	if (mt == PLAY) {
		paused = false; 
	} else	
		paused = true;	
}//*/

void GameState::togglePause(){
	if (paused) {
		paused = false; initMenu = false;
	} else
		paused = true;	
}
/*/
void GameState::		togglePrograms(int i){
	if (i > 0){
		program = i;
	}else 	
		program = 0;
}
//*/

//********************************* DEBUG *********************************

void GameState::toggleConsole(){
	if (cons) cons = false; 
	else cons = true;
}
void GameState::toggleFog(){
	if (fog) fog = false;
	else fog = true;	
}
