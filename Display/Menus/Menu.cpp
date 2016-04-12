#include "Menu.h"

Menu ::Menu (){
	affirm = false;	abort = false;
	update = true;
	overlay = false;
	preview = false;
	fixed = false;
	backdrop = true;
	menuID = (int)PASS;
	parent = (int)PASS;
	timeOut = 0;	time = 0;
	cursor.x = 0; cursor.z = 0;
	cursorID = -1;
	index = 0; 	maxIndex = 0; 
	backgroundID = -1;
	lineH = 0; lineW = 0;
}



void Menu::		init(Menu *screen){
	parent = screen->menuID;
	parentIndex = index;
}



void Menu::	setBackground(int id){
	backgroundID = id;
}


void Menu::		addText(string s){	
	text.push_back(s);
}

void Menu::		addCursor(int id, int x, int y){
	cursorID = id;
	cursor.x = x;
	cursor.z = y;
}

void Menu::addFlow(int menuIndex){
	flows.push_back(menuID);
	maxIndex = flows.size()-1;
}

void Menu::setFlow(int menuIndex){	
	flows.push_back(menuID);
	fixed = true;

}
//void Menu::addFlow(ActionType action, int index){} 

int Menu::getFlow(){
	if (fixed){
		return flows.front();
	} else if (flows.size() >= index+1){
		return flows[index];
	}
	return (int)QUIT;
}


void Menu::	cursorLR(int i){
	index += i;
	if (index > maxIndex) index = 0;
	else if (index < 0) index = maxIndex;	
	update = true;
}
void Menu::	cursorUD(int i){
	index += i;
	if (index > maxIndex) index = 0;
	else if (index < 0) index = maxIndex;	
	update = true;
}



void Menu::	reset(){
	abort = false;
	affirm = false;
	update = true;
	time = 0;
}


//********************************* updates *********************************
void Menu::		refresh(){
}

void Menu::		refresh(int ind){
	refresh();
}


void Menu::		rapidUpdate(){
	if (timeOut > 0){
		time++;
		if (time == timeOut) {
			time = 0;
			abort = true;
		}
	}
}



//********************************* draw *********************************


	
void Menu::	drawText(){}	
void Menu::	drawCursor(){
	if (cursorID >= 0){
		//M->cursorBO.drawCursor(cursorID, cursor.x + lineW * index, cursor.z + lineH * index); 
	}
}
void Menu::	drawIcons(){	
	//int s = items.size();
	//for (int i = 0; i < s; i++){
	//	items[i].draw();
	//}
}
void Menu::	drawBackground(){
	if (backgroundID > -1)
		M->menuBO.draw(backgroundID);	
}