#include "Engine.h"

//********************************* SDL CONTEXT *********************************
Engine eng;

SDL_Window* gWindow = NULL;			//The window we'll be rendering to
SDL_Renderer* gRenderer = NULL;		//The window renderer
SDL_GLContext gContext;				//OpenGL context

bool initW, initC, initE;


//********************************* DECLARATIONS *********************************
 
bool initGLAttrib(); /*/
Purpose: Load SDL_GL attributes 
Returns: true if nothing fails
Side Effects:  Initializes framebuffer, enables, depthbuffer, version, linear filtering 
/*/
 
bool initGLEW(); /*/
Purpose: init GLEW  
Returns: true if nothing fails
Side Effects:  Initializes GL extensions
/*/

bool initSDL(); /*/
Purpose: Load SDL window using OpenGL 
Parameter(s): N/A
Precondition(s): N/A
Returns: true if nothing fails
Side Effects:  Initializes SDL_Window, SDL_GL Context, SDL_image
Triggers: initGLAttrib, initGLEW, displayVersion
/*/

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

void displayVersion(); /*/
Side Effects: display opengl and graphics card versions  
/*/

void loadingMenu();

//********************************* MAIN *********************************
int main(int argc, char* args[]){
	//init
	if (initSDL()){
		initGlobals();
		eng.init();		
		initE = true;
	} else { gameActive = false; }
	displayVersion();
	//game loop
	while( gameActive ){	
		eng.update();	
		eng.display();
		glFlush(); SDL_GL_SwapWindow(gWindow); 
	}
	//game close
	close(); return 0; //Free resources and close SDL	
}//*/

void loadingMenu(){
		glClearColor(1, 1, 1, 1);	
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glMatrixMode(GL_MODELVIEW);	
		glLoadIdentity();	// initialize the selected matrix
		//C->update(H->pos());
	glFlush(); SDL_GL_SwapWindow(gWindow);		
}
//********************************* INIT *********************************
bool initGLAttrib(){
	//framebuffer
	SDL_GL_SetAttribute( SDL_GL_DOUBLEBUFFER, 1 );
	SDL_GL_SetAttribute( SDL_GL_DEPTH_SIZE, 24); 
	//enable framebuffer modes
	SDL_GL_SetAttribute( SDL_GL_ALPHA_SIZE, 1);
	//version
	SDL_GL_SetAttribute( SDL_GL_CONTEXT_MAJOR_VERSION, 3 );
	SDL_GL_SetAttribute( SDL_GL_CONTEXT_MINOR_VERSION, 3 );
	SDL_GL_SetAttribute( SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_COMPATIBILITY );

	//linear filtering
	if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) ) {printf( "Warning: Linear texture filtering not enabled!" );}
	return true;
}

bool initGLEW(){
	glewExperimental = GL_TRUE;
	GLenum status = glewInit(); 
	if (status != GLEW_OK) {cout << "GLEW Error: " << glewGetErrorString(status) << "\n"; exit(1);}
	return true;
	//GLenum error = glGetError(); if (error != GL_NO_ERROR){ 		cout << "OpenGL Error: " << error << " " << gluErrorString(error) << endl;}	
}

bool initSDL(){
	initW = false; initC = false; initE = false;
	//init video
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 ) {	 printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() ); return false;	}
		
	if(_DEBUG) cout << "Initializing SDL_GL" << endl;
	initGLAttrib(); // init attributes

	//init window
	////**CONFLICT** hardcoded the values
	gWindow = SDL_CreateWindow( "Stay out of the Forest", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, RES.x, RES.z, SDL_WINDOW_SHOWN|SDL_WINDOW_OPENGL );
	if( gWindow == NULL ) {	printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() ); 	return false;	}
	initW = true;

	//init context
	gContext = SDL_GL_CreateContext(gWindow);
	if ( gContext == NULL ){printf( "Context could not be created! SDL Error: %s\n", SDL_GetError() );	return false;	}	
	initC = true;
	
	// init SDL_image
	int imgFlags = IMG_INIT_PNG;
	if( !( IMG_Init( imgFlags ) & imgFlags ) ){	printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() ); 	return false;	}
	
	//init renderer
	/*/Create vsynced renderer for window
	gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED );
	if( gRenderer == NULL )	{printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );	return false;	}
	SDL_SetRenderDrawColor( gRenderer, 0x00, 0x0, 0x00, 0xFF ); //*///Initialize renderer color
	
	//if(_DEBUG) cout << "Loading GLEW" << endl;
	initGLEW();

	return true;
}

void initGlobals(){
	
	//**CONFLICT** create global logfile
	logfile = ofstream("log.txt");	//init logfile
	
	//displayVersion();

	//init model manager
	//if(_DEBUG) cout << "Loading Shaders" << endl;
	M = ModelManager::I();
	//engine stack loading screen
	loadingMenu();

	//init camera
	//if(_DEBUG) cout << "Matrixes..." ;
	//C = Camera::I(); C->init();

	//init hero
	//if(_DEBUG) cout << "Hero..." ;
	//H = Hero::I();	
	//H->init();	

	//init game state
	//if(_DEBUG) cout << "Game State" << endl;
	//G = GameState::I();		G->init();


	//init quest markers
	//Q = Question::I();	Q->init();
}

//********************************* CLOSE *********************************

void closeGlobals(){	
	//H->quit(); C->quit(); G->quit(); M->quit(); Q->quit();
	logfile.close();
}

void close(){
	if(_DEBUG) cout << "Quitting" << endl;	
	if (initC) SDL_GL_DeleteContext(gContext);		gRenderer = NULL;
	if (initW) SDL_DestroyWindow( gWindow );		gWindow = NULL;	
	if (initE) {
		eng.quit();
		closeGlobals();
	}
	SDL_Quit(); //Quit SDL subsystems 
}


//********************************* OTHER *********************************
void displayVersion(){
	if (_DEBUG){
		cout << glGetString(GL_VERSION) << endl;
		cout <<  glGetString(GL_RENDERER) << "  " << glGetString(GL_VENDOR ) << endl << endl;
	}
	logfile << glGetString(GL_VERSION) << endl;
	logfile <<  glGetString(GL_RENDERER) << "  " << glGetString(GL_VENDOR ) << endl << endl;
}
