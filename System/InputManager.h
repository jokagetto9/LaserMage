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

	void InputManager::		pollKeyEvents();
	void InputManager::		keyDown(SDL_Keycode key);
	void InputManager::		keyUp(SDL_Keycode key);

//********************************* INPUT RESPONSES *********************************
	
	void InputManager::		checkToggles();
	void InputManager::		checkProgram();
	void InputManager::		actionInput();
	void InputManager::		cameraInput();

//************************************************** MEMBERS ***************************************************
	
//********************************* MEMBER FUNCTIONS *********************************


};

#endif