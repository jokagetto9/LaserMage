#include "Engine.h"
#include "InputManager.h"
#include "StackManager.h"
#include "../Display/Camera.h"
#include "../Display/Environment.h"
#include "../Stages/Stage.h"
//********************************* MODULES *********************************

	Engine eng;						// handle for managing the passage of time

	InputManager input ;			// handle for managing input
	StackManager stack;
	MenuLoader menuLoader;
	Environment env;
	Stage testStage;
	Hero H;
	


//********************************* DECLARATIONS *********************************
void init();
void initGlobals(); /*/
Purpose: init global aliases
Precondition(s): initSDL
Side Effects:  Initializes Hero, Camera, ModelManager, GameState, Question
/*/

void update(); 
void clockCycle();
void physicsUpdate();
void rapidUpdate();

void display(); 


void deleteGlobals(); 
void close();	

//********************************* UPDATES *********************************

void update(){

	input.pollKeyEvents();
	input.checkToggles();
	if (!G0->paused) {	
		input.directionInput()->exec(H);
		input.mouseInput()->exec(H);
	}
	//DBT->update();
	//if (G->save) save();
	clockCycle();
	
	
	stack.menuInput(input.menuInput());

	if (G0->paused) stack.update();
	//input.clearKeys();	
}

void clockCycle(){
	G->trackAVG(); G->trackFPS();	
	G->incLag();
	while (G->testLag()){	// while phys delta has time lag
		if(G->lagVSlag())	{		// phys has more lag	
			if (!G->paused) physicsUpdate();
			G->action = false;
			G->decPhysLag();	
		} else {			// if ai has equal or more lag	
			rapidUpdate();	
			G->decAILag();
		}
	}		
	G->prevTime = G->curTime;	// reset cycle
	 //else G->action = false;
}

void physicsUpdate(){

	input.cameraInput();
	testStage.physUpdate();
	H.physUpdate(144, G->physDelta);
	//world.interactions();
	//DBT->physUpdate(); //?
}

void rapidUpdate(){
	if (!G->paused){	
		testStage.rapidUpdate();
	}
	stack.rapidUpdate();
}

//********************************* DRAW *********************************
void display(){
	float c = 0/255;
	glClearColor(c, c, c, 1);	
	eng.clearDisplay();
	C->update(H.pos());
	//
	if(!G->paused){
		glDisable(GL_DEPTH_TEST);
		M->tileBO.use();	
		glBindTexture(GL_TEXTURE_2D, M->tileBO.terrainT1[0]);
		M->tileBO.draw(16, 36, 64, 144);
		glEnable(GL_DEPTH_TEST);

		H.drawHero();
		M->gridBO.prepNPC();
		testStage.draw(); 

	}//*/

	stack.setUp2DView(RES.x, RES.z);
	if(G->paused) 
		stack.draw();
	else
		stack.drawHUD();
	stack.disable2DView();
} 
//********************************* INIT *********************************
void init(){	
	RES.x = dfWIDTH; RES.z = dfHEIGHT; 
	if (!eng.initSDL()) 
		GameState::I()->gameActive = false; 
	else {
		eng.displayVersion();
		stack.init(menuLoader);

		initGlobals();
		menuLoader.loadList();


		testStage.init(H);
	}  
}

void initGlobals(){
	logfile = ofstream("log.txt");	//init logfile
	
	//displayVersion();

	M = ModelManager::I();
	C = Camera::I(); 
	C->init();		
	H.init();	

	G = GameState::I();		
	G->init();
	G0 = G;	
	
	input.init();
	env.init();
	//init quest markers
	//Q = Question::I();	Q->init();
}

//********************************* MAIN *********************************
int main(int argc, char* args[]){
	init();
	//game loop
	while( GameState::I()->gameActive ){	
		update();	
		display();
		eng.flush();
	}
	//game close
	close(); return 0; //Free resources and close SDL	
}//*/

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

