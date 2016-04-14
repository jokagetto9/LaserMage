#include "Engine.h"

//********************************* MODULES *********************************
Engine eng;


//********************************* DECLARATIONS *********************************
 
void initGlobals(); /*/
Purpose: init global aliases
Precondition(s): initSDL
Side Effects:  Initializes Hero, Camera, ModelManager, GameState, Question
/*/

void deleteGlobals(); /*/
Purpose: delete global aliases
Precondition(s): initE
Side Effects:  closes and deletes Hero, Camera, ModelManager, GameState, Question
/*/

void close();	 /*/
Purpose: close entire project 
Side Effects:  closes engine and deletes SDL_Window, SDL_GL Context
Triggers: eng.quit()
/*/



//********************************* MAIN *********************************
int main(int argc, char* args[]){
	//init
	if (eng.initSDL()){
		initGlobals();
		eng.init();	
	} else { 
		GameState::I()->gameActive = false; 
		//***display failure message
	}
	//game loop
	while( GameState::I()->gameActive ){	
		eng.update();	
		eng.display();
		eng.flush();
	}
	//game close
	close(); return 0; //Free resources and close SDL	
}//*/


void initGlobals(){
	logfile = ofstream("log.txt");	//init logfile
	
	//displayVersion();

	//init model manager
	//if(_DEBUG) cout << "Loading Shaders" << endl;
	M = ModelManager::I();
	//engine stack loading screen

	//init camera
	//if(_DEBUG) cout << "Matrixes..." ;
	//C = Camera::I(); C->init();

	//init hero
	//if(_DEBUG) cout << "Hero..." ;
	//H = Hero::I();	
	//H->init();	

	//init game state
	//if(_DEBUG) cout << "Game State" << endl;
	G = GameState::I();		G->init();


	//init quest markers
	//Q = Question::I();	Q->init();
}

//********************************* CLOSE *********************************

void closeGlobals(){	
	//H->quit(); C->quit(); 
	G->quit(); M->quit(); 
	//Q->quit();
	logfile.close();
}

void close(){
	if(_DEBUG) cout << "Quitting" << endl;	
	eng.quit();
	closeGlobals();
	SDL_Quit(); //Quit SDL subsystems 
}


//********************************* OTHER *********************************
