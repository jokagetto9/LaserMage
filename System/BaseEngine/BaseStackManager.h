#ifndef BaseBaseStackManager_H
#define BaseBaseStackManager_H

#include "../../Display/Menus/Menu.h"


//********************************* CONSTANTS *********************************

//********************************* INITIALIZATION *********************************

class BaseStackManager {
public:
	BaseStackManager::BaseStackManager();
	// Constructor
	void BaseStackManager::	initMenus();	
	void BaseStackManager::	loadDefaults();


	// screen setup
	
	void BaseStackManager::setRootMenu();
	void BaseStackManager::	updateMenu();
	
	void BaseStackManager::	popMenu();


	
	void BaseStackManager::	rapidUpdate();
	
//********************************* DRAW *********************************
	void BaseStackManager::	draw();
	void BaseStackManager::	drawHUD();
	void BaseStackManager::	drawMenus();
	void BaseStackManager::	drawText();
	
	void BaseStackManager::	drawCursor();
	void BaseStackManager::	drawIcons();
	void BaseStackManager::	drawBackground();



	void BaseStackManager::	setUp2DView(int width, int height);
	void BaseStackManager::	disable2DView();
	/*/ Purpose: 
Side Effects:  
Triggers: 
	/*/
//************************************************** MEMBERS ***************************************************
		bool menuView;
		Menu loadingScreen;

		vector <Menu *> stack;
		
//********************************* MEMBER FUNCTIONS *********************************
		
		bool BaseStackManager:: empty();
		bool BaseStackManager:: aborting();

};
#endif
