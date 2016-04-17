//********************************* INITIALIZATION *********************************
#include "BaseStackManager.h"

BaseStackManager::BaseStackManager(){
	menuView = false;
	initMenus();
}

void BaseStackManager::	initMenus(){
	loadingScreen.setBackground(1);
}


//********************************* LOADING *********************************

void BaseStackManager::	loadDefaults(){	
	//stack.push_back(&loadingScreen);
	//stack.push_back(&crabScreen);
	//G->enterMenu(PLAY); //jump start
	setRootMenu();
}


void BaseStackManager::setRootMenu(){}


void BaseStackManager:: updateMenu(){}
void BaseStackManager::	popMenu(){}



//********************************* DRAW *********************************


void BaseStackManager::	draw(){		
	//drawText();
	//drawCursor();
	//drawIcons();
	//drawBackground();
	M->menuBO.use();	 
	loadingScreen.drawBackground();
}

void BaseStackManager::	drawHUD(){		
	//M->fontBO.use();	//hudMenu.drawText();
	//M->cursorBO.use();	//hudMenu.drawCursor();
	//M->menuBO.use();	 //hudMenu.drawIcons();
	//hudMenu.drawBackground();
}

//*********************************


void BaseStackManager :: setUp2DView (int width, int height){
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

void BaseStackManager :: disable2DView ()
{
	if (menuView){
		glMatrixMode(GL_PROJECTION);
		glPopMatrix();

		menuView = false;
		//glMatrixMode(GL_MODELVIEW);
		//glPopMatrix();

	}
}


//*********************************

bool BaseStackManager:: empty(){
	return true;
	//return stack.empty();
}


bool BaseStackManager:: aborting(){
	return false;
	//return stack.back()->abort;
}