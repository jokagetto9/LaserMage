#ifndef StackManager_H
#define StackManager_H

#include "ControllerInput.h"


//********************************* CONSTANTS *********************************

//********************************* INITIALIZATION *********************************

class StackManager {
public:
	StackManager::StackManager();
	// Constructor
	void StackManager::	initMenus();
/*/ Purpose: 
Side Effects:  
Triggers: 
/*/
	
	void StackManager::		quit();
//********************************* LOADING *********************************

	void StackManager::	enterMenu();
	void StackManager:: loadMenu();

	void StackManager::	loadBiomeMap();
	

	void StackManager::	popMenu();
//********************************* SAVING *********************************
		void StackManager::		save();


//********************************* UPDATES *********************************
	void StackManager::	interactions();
	
	void StackManager::	update(ControllerInput &input);
	void StackManager::	updateMenu();
	
	
	void StackManager::	rapidUpdate();


	// screen setup
	
	void StackManager::setRootMenu();



	void StackManager::	setUp2DView(int width, int height);
	void StackManager::	disable2DView();
	
	void StackManager::unpause();
	
//********************************* DRAW *********************************
	void StackManager::	draw();
	void StackManager::	drawMenus();
	void StackManager::	drawText();
	
	void StackManager::	drawCursor();
	void StackManager::	drawIcons();
	void StackManager::	drawBackground();

	bool StackManager::isOverlay();
	bool StackManager::hasPreview();
	
	/*/ Purpose: 
Side Effects:  
Triggers: 
	/*/
//************************************************** MEMBERS ***************************************************
		bool abort, menuView;
		bool loading, updating; 

		int physSkip;
		// class controlling environment specific effects (lighting, fog, plant growth)
		Menu loadingScreen;

		int menuIndex;


//********************************* MEMBER FUNCTIONS *********************************


		bool StackManager:: backdrop();
};
#endif
