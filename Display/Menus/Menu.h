#ifndef MENU_H
#define MENU_H

#include "../ModelManager.h"

//********************************* CONSTANTS *********************************
 
//enum ActionType {EXITA, OPTN, STGSLCT, STGINFO, STGCOMP, UPGRADE, PLAY};

//********************************* INITIALIZATION *********************************

class Menu   {
	public: 
	Menu::		Menu();
	virtual void Menu::		init(Menu *screen);
	void Menu::		setBackground(int id);
	void Menu::		addText(string s);
	void Menu::		addCursor(int id, int x, int y);

	void Menu::addFlow(int menuIndex);	
	virtual void Menu::setFlow(int menuIndex);	
	virtual int Menu::getFlow();

	
	virtual void Menu::	cursorLR(int i);	
	virtual void Menu::	cursorUD(int i);
	virtual void Menu::	menuExit(){abort = true;}
		
	virtual void Menu::	enter(){affirm = true;}
	virtual void Menu::	reset();
	virtual void Menu::	quit(){abort = true;}



	
	virtual void Menu::		refresh();
	virtual void Menu::		refresh(int ind);
	void Menu::			rapidUpdate();


//********************************* DRAW *********************************

	
	virtual void Menu::	drawText();	
	virtual void Menu::	drawCursor();
	virtual void Menu::	drawIcons();
	virtual void Menu::	drawBackground ();

/*/ Purpose: 
Side Effects:  
Triggers: 
/*/
//********************************* MEMBERS *********************************
	
	//MenuType type;
	int menuID;
	int parent;
	//MenuType parent;
	//vector <DisplayItem> items;
	vector <string> text;
	vector <int> flows;
	XZI cursor;
	int cursorID;
	int backgroundID;

	bool abort, affirm, update; 
	bool overlay, preview, fixed, backdrop;
	int index, maxIndex;
	int parentIndex;
	int lineH;
	int lineW;
	int timeOut;
	int time;

//********************************* MEMBER FUNCTIONS *********************************
	bool Menu::isDone(){return abort;};
	void Menu::setTimeOut(int to){timeOut = to;};
	virtual int Menu::getCategory(){return 0;}

};
#endif