//********************************* INITIALIZATION *********************************
#include "StackManager.h"

StackManager::StackManager(){
	abort = false;
	menuView = false;
	loading = false;
	updating = false; 

	initMenus();
	physSkip = 0;
}

void StackManager::	initMenus(){

//	previewMenu = NULL;
	loadingScreen.setBackground(EXIT);
}


//********************************* LOADING *********************************



void StackManager::setRootMenu(){}


//void StackManager::setMenu(MenuType mt){}


void StackManager::	update(ControllerInput &input){

	if (G->initMenu);// setRootMenu();
	if (G->paused){
		//if (stack.empty()){	
				//pop production bumpers!
				//stack.push_back(&titleScreen);
				//stack.push_back(&crabScreen);
				//loadStack();		
			//G->enterMenu(PLAY);
			//setRootMenu();
		//} else {
		//	input.menuInput(stack.back());

		//	if (!stack.back()->abort) updateMenu();
		//	else	popMenu();
		//}
	}
}


//********************************* DRAW *********************************


void StackManager::	draw(){		
	setUp2DView(RES.x, RES.z);	//2D pixel coordinates
	//for (each screen with >displayOnly)
	if (G->paused){
		//M->fontBO.use();	hudMenu.drawText();
		//M->cursorBO.use();	hudMenu.drawCursor();
		M->menuBO.use();	loadingScreen.drawBackground(); //hudMenu.drawIcons();
	} else {//if (!stack.empty()){ 
		//drawText();
		//drawCursor();
		//drawIcons();
	}
	
	disable2DView();
}


//*********************************


void StackManager :: setUp2DView (int width, int height){
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

void StackManager :: disable2DView ()
{
	if (menuView){
		glMatrixMode(GL_PROJECTION);
		glPopMatrix();

		menuView = false;
		//glMatrixMode(GL_MODELVIEW);
		//glPopMatrix();

	}
}
