#include "SkillMenu.h"

SkillMenu ::SkillMenu (){
	affirm = false;	abort = false;
	update = true;
	overlay = false;
	preview = false;
	backdrop = true;
	timeOut = 0;	time = 0;
	cursor.x = 62; cursor.z = 56;
	cursorID = 4;
	index = 0; 	maxIndex = 23; 
	lineH = 25; lineW = 288;
}



void SkillMenu::	drawText(){
	M->fontBO.beginText("");
	M->fontBO.loadMessage();
	M->fontBO.draw(109, 133);			
}	


void SkillMenu::	drawCursor(){
	int x = index / 12;
	int z = index % 12; 
	if (z < 6)
		M->cursorBO.drawCursor(cursorID, cursor.x+x*lineW, cursor.z+z*lineH);
	else		
		M->cursorBO.drawCursor(cursorID, cursor.x+x*lineW, cursor.z+(z+1)*lineH+6);
}


void SkillMenu::	drawIcons(){
}


void SkillMenu::	refresh(int ind){
}

void SkillMenu::	cursorLR(int i){	
	int temp = index + 12*i;
	if (temp < 0) 
		temp += maxIndex+1;
	else if (temp > maxIndex) 
		temp -= maxIndex+1;
	index = temp;
	update = true;

}