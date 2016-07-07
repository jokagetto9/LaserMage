#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

#include "BaseEngine/BaseGameState.h"

#include "BaseEngine/BaseInputManager.h"
#include "Laser/LaserCommand.h"
//********************************* CONSTANTS *********************************
//********************************* INITIALIZATION *********************************

class InputManager : public BaseInputManager{
public:
	
	InputManager::InputManager();
	
//********************************* KEY CYCLE *********************************

//********************************* INPUT RESPONSES *********************************
	
	LaserCommand * InputManager::		laserInput();
	void InputManager::		cameraInput();
	void InputManager::		debugToggles();

//************************************************** MEMBERS ***************************************************
	
	bool controls;
//********************************* MEMBER FUNCTIONS *********************************
private:
	LaserCommand lasercmd;
	bool zoomOut;
};

#endif