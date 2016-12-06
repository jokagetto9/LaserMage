#ifndef STACKMANAGER_H
#define STACKMANAGER_H

//#include "MenuLoader.h"
#include "../BaseEngine/Stack/BaseStackManager.h"
#include "../Entities/StageLoader.h"
#include "../Stack/HUDMenu.h"


//********************************* CONSTANTS *********************************

//********************************* INITIALIZATION *********************************

class StackManager : public BaseStackManager{
public:
	StackManager::StackManager();
	void StackManager::loadStages(StageLoader* stages);
	void StackManager::setMenu(int flow);
	void StackManager::	drawHUD();

	HUDMenu hud;

};
#endif
