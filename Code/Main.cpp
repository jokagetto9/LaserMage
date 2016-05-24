#include "BaseEngine/BaseEngine.h"
#include "BaseEngine/Stack/BaseStackManager.h"
#include "Display/Environment.h"
#include "Stages/StageLoader.h" 
#include "Entities/EntityLoader.h"
#include "InputManager.h"
//********************************* MODULES *********************************

	BaseEngine eng;						// handle for managing the passage of time

	InputManager input ;			// handle for managing input
	EntityLoader entities ;
	BaseStackManager stack;
	MenuLoader menuLoader;
	Environment env;
	StageLoader stageLoader;
	Stage testStage;
	Stage * currStage;
	Players P;
	


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
	stack.loadCommand(cmd);

	//input.checkToggles();
	if (!G->paused) {	
		//input.directionInput()->exec(P.getActor(P1));
		input.mouseInput()->exec(P.getActor(P1));
	}

	if (!G->loaded){
		//currStage->init(H);
		currStage->init(P);
		G->loaded = true;
	}

	//DBT->update();
	//if (G->save) save();
	clockCycle();
	
	
	stack.menuInput(input.menuInput());

	if (G->paused) stack.update();
	//input.clearKeys();	
}

void clockCycle(){
	eng.trackAVG(); eng.trackFPS();	
	eng.incLag();
	while (eng.testLag()){	// while phys delta has time lag
		if(eng.lagVSlag())	{		// phys has more lag	
			if (!G->paused) { 
				physicsUpdate();
				//G->action = false;
			}
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
	currStage->physUpdate(eng.physDelta);
}

void rapidUpdate(){
	if (!G->paused){	
		currStage->rapidUpdate(eng.aiDelta);
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
		
		C->update(P.pos());		
		currStage->drawTerrain();  
		P.drawP1(eng.avgFrameDelta);
		currStage->draw(eng.avgFrameDelta); 

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
		BaseGameState::I()->gameActive = false; 
	else {
		eng.displayVersion();
		initGlobals();
		entities.load();
		stageLoader.load();
		currStage = stageLoader.getStage(0);
		if (currStage == NULL) currStage = &testStage;		
		currStage->drawPool.activateTextures();
		//menus
		stack.init(menuLoader);	
		input.init(menuLoader);
		menuLoader.load();


	}  
}

void initGlobals(){
	logfile = ofstream("log.txt");	//init logfile
	
	//displayVersion();

	M = ModelManager::I();
	C = Camera::I(); 
	C->init();		
	//H.init();	

	G = BaseGameState::I();		
	G->init();
	G = G;	
	
	env.init();
	//init quest markers
	//Q = Question::I();	Q->init();
}

//********************************* MAIN *********************************
int main(int argc, char* args[]){
	init();
	//game loop
	while( BaseGameState::I()->gameActive ){	
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

