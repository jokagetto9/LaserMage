#include "Engine.h"
#include "InputManager.h"
#include "StackManager.h"
#include "../Display/Camera.h"
#include "../Display/Environment.h"
//********************************* MODULES *********************************

	Engine eng;						// handle for managing the passage of time

	InputManager input ;			// handle for managing input
	StackManager stack;
	Environment env;

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
		eng.clockCycle();
	
	stack.update(input);
	input.clearKeys();	
}


void display(){
	float c = 255/255;
	glClearColor(c, c, c, 1);	
	eng.clearDisplay();
	glm::vec3 v = glm::vec3(0.0);
	C->update(v);
	//
	if(!G->paused){
		glDisable(GL_DEPTH_TEST);
		M->tileBO.use();	
		//getHeroStage()->drawTerrain();	// current zone
		glBindTexture(GL_TEXTURE_2D, M->tileBO.terrainT1[0]);
		M->tileBO.draw(16, 36, 64, 144);
		//M->terrainBO.draw(5, 5, 25, 25);

		//drawgardens
		glEnable(GL_DEPTH_TEST);
	}//*/

	stack.setUp2DView(RES.x, RES.z);
	if(G->paused) 
		stack.draw();
	else
		stack.drawHUD();
	stack.disable2DView();
} 



//********************************* MAIN *********************************
int main(int argc, char* args[]){
	
	RES.x = dfWIDTH; RES.z = dfHEIGHT; 
	eng.BaseEngine::init(&input, &stack);	  	//init
	if (eng.initSDL()){
		eng.displayVersion();
		initGlobals();
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
	C = Camera::I(); C->init();	
	

	//init hero
	//if(_DEBUG) cout << "Hero..." ;
	//H = Hero::I();	
	//H->init();	

	//init game state
	//if(_DEBUG) cout << "Game State" << endl;
	G = GameState::I();		G->init();
	G0 = G;	
	
	input.init();
	env.init();
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

