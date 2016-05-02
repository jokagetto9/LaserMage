#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

#include "BaseEngine/BaseGameState.h"

#include "BaseEngine/BaseInputManager.h"
#include "Nodes/Laser/LaserCommand.h"
//********************************* CONSTANTS *********************************
//********************************* INITIALIZATION *********************************

class InputManager : public BaseInputManager{
public:
	
	InputManager::InputManager(){} 
	
//********************************* KEY CYCLE *********************************

//********************************* INPUT RESPONSES *********************************
	
	void InputManager::		checkToggles();
	Command * InputManager::		mouseInput();
	void InputManager::		cameraInput();

//************************************************** MEMBERS ***************************************************
	
//********************************* MEMBER FUNCTIONS *********************************
private:
	LaserCommand lasercmd;

};

#endif