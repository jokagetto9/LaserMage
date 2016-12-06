#ifndef HUDMENU_H
#define HUDMENU_H
#include "../BaseEngine/Stack/Menu.h"
#include "../BaseEngine/Entities/EntityList.h"
//#include "../Laser.h"

//********************************* CONSTANTS *********************************


//********************************* INITIALIZATION *********************************
class HUDMenu : public Menu{
	public: 
	HUDMenu::HUDMenu();
	void HUDMenu::init();


	void HUDMenu::update(ID p1, EntityList& entities){
		gData = entities.gData[p1];
		health = entities.health[p1];
	}






	void HUDMenu::	draw();

	void HUDMenu::	drawHealth();


	void HUDMenu::	drawDebugConsole();

	
	GridData gData;
	Health health;
	//laser
	GLuint redT, greenT; 	

//************************************************** MEMBERS ***************************************************
	
		
};
#endif