#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

#include "GameState.h"

#include "BaseEngine/BaseInputManager.h"

//********************************* CONSTANTS *********************************
//********************************* INITIALIZATION *********************************

class InputManager : public BaseInputManager{
public:
	
	InputManager::InputManager(){} 
	
//********************************* KEY CYCLE *********************************

//********************************* INPUT RESPONSES *********************************
	
	void InputManager::		checkToggles();
	void InputManager::		cameraInput();

//************************************************** MEMBERS ***************************************************
	
//********************************* MEMBER FUNCTIONS *********************************


};

#endif