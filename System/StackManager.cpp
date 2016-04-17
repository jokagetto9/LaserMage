//********************************* INITIALIZATION *********************************
#include "StackManager.h"

StackManager::StackManager(){
	BaseStackManager::BaseStackManager();
}


//********************************* LOADING *********************************



//void StackManager::setRootMenu(){}




void StackManager::	update(InputManager &input){

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


