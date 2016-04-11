//********************************* INITIALIZATION *********************************
#include "Engine.h"

//**TEMP**
bool gameActive;

Engine::	Engine(){
	
		menuView = false;
}

void Engine::init(){

	//stack.init();
	//input.init();	
	//world.init();
	//onspawner.setWorld(&world);
	//DBT = DebugTool::I(); 
	//DBT->init(&world);
	gameActive = true;
}

void Engine::		loadingMenu(){
	//load null
}

void Engine::quit(){

	//world.quit();
	//if(_DEBUG) cout << "Zones Deleted" << endl;
}

//********************************* PRIMARY CYCLES *********************************
void Engine::update(){		
	pollKeyEvents(); //input.pollKeyEvents();
	//input.checkToggles();	
	//input.actionInput();
	//menu.update();
	//DBT->update();
	//if (G->save) save();
	//if (G->skip == 0){ 
	//	clockCycle();
	//} else skipTime();
	
	//stack.update(input);
	//input.clearKeys();	
}

void Engine::pollKeyEvents(){
	SDL_Keycode key;
	SDL_Event ev;
	while(SDL_PollEvent(&ev))
	{	key = ev.key.keysym.sym;
		switch (ev.type)
		{	case SDL_QUIT: 
			gameActive = false; break;
			case SDL_KEYDOWN: 	break;     
			case SDL_KEYUP: //keyUp(key); 				
				if (key == SDLK_ESCAPE)  
					gameActive = false; 				
				break;
		}	
	}	
}


//*/
//********************************* DRAW *********************************

void Engine::display(){			
		glClearColor(1, 1, 1, 1);	
		clearDisplay();
		setUp2DView(RES.x, RES.z);
		M->menuBO.use();
		//M->menuBO.prep();
		M->menuBO.draw(0);
		disable2DView();
}
 
void Engine::clearDisplay(){

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glMatrixMode(GL_MODELVIEW);	
		glLoadIdentity();	// initialize the selected matrix

}


void Engine :: setUp2DView (int width, int height){
	if (!menuView){
		if(width < 1)  width = 1;
		if(height < 1) height = 1;

		glMatrixMode(GL_PROJECTION);
		glPushMatrix();
		glLoadIdentity();
		//gluOrtho2D(0.0, width, 0.0, width);
		glOrtho(0.0, width, 0.0, height, 0, 1);



		menuView = true;
	}
}

void Engine :: disable2DView ()
{
	if (menuView){
		glMatrixMode(GL_PROJECTION);
		glPopMatrix();

		menuView = false;
		//glMatrixMode(GL_MODELVIEW);
		//glPopMatrix();

	}
}

