#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

#include "BaseEngine/BaseGameState.h"

#include "BaseEngine/BaseInputManager.h"
#include "Laser/LaserCommand.h"
//********************************* CONSTANTS *********************************
//********************************* INITIALIZATION *********************************

class InputManager : public BaseInputManager{
public:
	
	InputManager::InputManager(){zoomOut = false;} 
	
//********************************* KEY CYCLE *********************************

//********************************* INPUT RESPONSES *********************************
	
	Command * InputManager::		mouseInput();
	void InputManager::		cameraInput();
	void InputManager::		debugToggles();

//************************************************** MEMBERS ***************************************************
	
//********************************* MEMBER FUNCTIONS *********************************
private:
	LaserCommand lasercmd;
	bool zoomOut;
};

#endif