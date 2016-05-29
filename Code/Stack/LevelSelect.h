#ifndef LEVELSELECT_H
#define LEVELSELECT_H

#include "HUDMenu.h"

//********************************* CONSTANTS *********************************
 
//enum ActionType {EXIT, OPTN, STGSLCT, STGINFO, STGCOMP, UPGRADE, PLAY};

//********************************* INITIALIZATION *********************************

class LevelSelect : public Menu  {
	public: 
	LevelSelect::		LevelSelect();
	
	void LevelSelect::	cursorLR(int i);

	void LevelSelect::	drawText();	
	void LevelSelect::	drawCursor();
	void LevelSelect::	drawIcons();

	void LevelSelect:: refresh(int ind);


};
#endif