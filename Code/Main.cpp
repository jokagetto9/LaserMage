#include "BaseEngine/BaseEngine.h"
#include "Stack/StackManager.h"
#include "Display/Environment.h"
#include "Entities/EntityLoader.h"
#include "InputManager.h"
#include "DebugTool.h"
#include "Laser/Laser.h"

//********************************* MODULES *********************************

	BaseEngine eng;						// handle for managing the passage of time

	InputManager input ;			// handle for managing input
	EntityLoader entities ;
	StackManager stack;
	BaseMenuLoader menuLoader;
	Environment env;
	StageLoader stageLoader;
	Stage testStage;
	Stage * currStage;
	DebugTool debug;
	

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
	
	C->setCursorPos(input.mX, input.mY);
	PlayCommand * cmd = input.checkPause();
	stack.loadCommand(cmd);

	input.debugToggles();
	if (!G->paused) {	
		if (input.controls){
			//input.directionInput()->exec(P.getActor(P1));
		}
		if (input.mouseL){
			glm::vec3 c = C->corner();
			XZI m = {(input.mX+0.5)*0.25+c.x, (input.mY+1)*0.25+c.z };	
			currStage->addParticle(1, m);
			input.mouseL = false;
		}
	}

	clockCycle();

	stack.menuInput(input.menuInput());

	if (G->paused) stack.update();

	if(G->state == TITLE)
		currStage = NULL;
	else if (!G->loaded && G->state == PLAY){
		if (!currStage){
			currStage = stageLoader.getStage(stack.index);
		}
		currStage->init();		
		G->loaded = true;
	}
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
		currStage->draw(eng.avgFrameDelta); 
	}//*/
		
	stack.setUp2DView(RES.x, RES.z);
	//debug.drawDebugConsole(eng.avgFPS);
	if(G->paused) 
		stack.draw();
	else
		stack.drawHUD();
	stack.disable2DView();
} 


//********************************* INIT *********************************
void init(){

	RES.x = PIXELSCALE*pWIDTH; RES.z = PIXELSCALE*pHEIGHT; 
	if (!eng.initSDL()) 
		BaseGameState::I()->gameActive = false; 
	else {
		eng.displayVersion();
		initGlobals();
		entities.load();
		stageLoader.load();  
		//menus
		stack.init(menuLoader);	
		input.init(menuLoader);
		menuLoader.load();
		stack.loadStages(&stageLoader);
		
		Size size(3.2, 7, 8);
		heroBook.addSize(size);
		EntityList::addDict(&propList);
		EntityList::addDict(&propList);
		EntityList::addDict(&particleList);
		EntityList::addDict(&monBook);
		EntityList::addDict(&heroBook);
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
	G = G;	//??????
	
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

