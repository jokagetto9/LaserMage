#ifndef STACKMANAGER_H
#define STACKMANAGER_H

//#include "MenuLoader.h"
#include "../BaseEngine/Stack/BaseStackManager.h"
#include "../Stages/StageLoader.h"


//********************************* CONSTANTS *********************************

//********************************* INITIALIZATION *********************************

class StackManager : public BaseStackManager{
public:
	StackManager::StackManager();
	void StackManager::loadStages(StageLoader* stages);
	void StackManager::setMenu(int flow);
};
#endif
