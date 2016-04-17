#include "Engine.h"
#include "InputManager.h"
#include "StackManager.h"
//********************************* MODULES *********************************

	Engine eng;						// handle for managing the passage of time
	InputManager input;			// handle for managing input
	StackManager stack;

//********************************* DECLARATIONS *********************************
 
void initGlobals(); /*/
Purpose: init global aliases
Precondition(s): initSDL
Side Effects:  Initializes Hero, Camera, ModelManager, GameState, Question
/*/

void update(); 
void menuUpdate();
void display(); 


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

void update(){
	input.pollKeyEvents();
	input.checkToggles();	
	//input.actionInput();
	//DBT->update();
	//if (G->save) save();
	//if (G->skip == 0){ 
		eng.clockCycle();
	//} else skipTime();
	
	//stack.update(input);
	//input.clearKeys();	
}



void menuUpdate(){

	if (G->initMenu);// stack.setRootMenu();
	if (G->paused){
		if (stack.empty())	
			stack.loadDefaults();			//pop production bumpers!
		else {
		//	input.menuInput(currentMenu());
			if (stack.aborting()) stack.popMenu();
			else stack.updateMenu();
		}
	}
}

void display(){
	glClearColor(1, 1, 1, 1);	
	eng.clearDisplay();
	stack.setUp2DView(RES.x, RES.z);
	if(G->paused) 
		stack.draw();
	else
		stack.drawHUD();
	stack.disable2DView();
} 



//********************************* MAIN *********************************
int main(int argc, char* args[]){
	//eng.init();	  	//init
	if (eng.initSDL()){
		eng.displayVersion();
		initGlobals();
		input.init();
		//world.init();
		//onspawner.setWorld(&world);
		//DBT = DebugTool::I(); 
		//DBT->init(&world);
	} else { 
		GameState::I()->gameActive = false; 
		//***display failure message
	}
	//game loop
	while( GameState::I()->gameActive ){	
		update();	
		display();
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
	G0 = G;	


	//init quest markers
	//Q = Question::I();	Q->init();
}

//********************************* CLOSE *********************************

void closeGlobals(){	
	//H->quit(); C->quit(); 
	G->quit(); //M->quit(); 
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

