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
	PlayCommand * cmd = input.checkPause();
	if (cmd) cmd->enter(stack.stack);

	//input.checkToggles();
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
	eng.trackAVG(); eng.trackFPS();	
	eng.incLag();
	while (eng.testLag()){	// while phys delta has time lag
		if(eng.lagVSlag())	{		// phys has more lag	
			if (!G->paused) physicsUpdate();
			G->action = false;
			eng.decPhysLag();	
		} else {			// if ai has equal or more lag	
			rapidUpdate();	
			eng.decAILag();
		}
	}		
	eng.prevTime = eng.curTime;	// reset cycle
	 //else G->action = false;
}

void physicsUpdate(){	
	input.cameraInput();
	testStage.init(H);
	testStage.physUpdate(eng.physDelta);
	H.physUpdate(144, eng.physDelta);
	//world.interactions();
	//DBT->physUpdate(); //?
}

void rapidUpdate(){
	if (!G->paused){	
		testStage.rapidUpdate(eng.aiDelta);
	}
	stack.rapidUpdate();
}

//********************************* DRAW *********************************
void display(){
	float c = 0/255;
	glClearColor(c, c, c, 1);	
	eng.clearDisplay();
	//
	if(!G->paused || !stack.backdrop()){
		
		C->update(H.pos());		
		testStage.drawTerrain(); 
		H.drawHero(eng.avgFrameDelta);
		M->gridBO.prepNPC();
		testStage.draw(eng.avgFrameDelta); 

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
		initGlobals();
		//menus
		stack.init(menuLoader);	
		input.init(menuLoader);
		menuLoader.loadList();


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

