#ifndef CONTROLLERINPUT_H
#define CONTROLLERINPUT_H

#include "GameState.h"

//********************************* CONSTANTS *********************************


//********************************* INITIALIZATION *********************************

class ControllerInput {
public:
	
	ControllerInput::ControllerInput(){} 
/*/ Purpose: default constructor 
Parameter(s): N/A
Precondition(s): N/A
Returns: N/A
Side Effects:  N/A
Triggers: N/A
/*/
	
	void ControllerInput ::	init();	
/*/ Purpose: init members 
Side Effects:  init status, speedMode
Triggers: spriteInit, loadHero
/*/


//********************************* LOADING *********************************

	//load options


//********************************* KEY CYCLE *********************************

	void ControllerInput::		pollKeyEvents();
	void ControllerInput::		keyDown(SDL_Keycode key);
	void ControllerInput::		keyUp(SDL_Keycode key);
	void ControllerInput::		clearKeys();

//********************************* INPUT RESPONSES *********************************
	
	void ControllerInput::		checkToggles();
	void ControllerInput::		checkProgram();
	void ControllerInput::		actionInput();
	void ControllerInput::		cameraInput();
	//void ControllerInput::		menuInput(Menu *screen);



//************************************************** MEMBERS ***************************************************
	

		bool keyPressed[256];		//keyboard state array
		bool specialKeyPressed[20];	//special key state array
		
		SDL_Event ev;

//********************************* MEMBER FUNCTIONS *********************************

	void ControllerInput::		on(SDL_Keycode key);
	void ControllerInput::		off(SDL_Keycode key);

};

#endif