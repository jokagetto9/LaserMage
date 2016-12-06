//********************************* INITIALIZATION *********************************
#include "HUDMenu.h"

HUDMenu::HUDMenu(){}

void HUDMenu::init(){
	setBackground(loadTexture("MENU/hud.png", false));
	
	redT = loadTexture("MENU/healthred.png", false);
	greenT = loadTexture("MENU/healthgreen.png", false); 	

}

//********************************* STATUS BARS *********************************




void HUDMenu::	draw(){	
	
	
	drawHealth();

	M->menuBO.use();
	if (backgroundT > 0)
		M->menuBO.draw(backgroundT);	


}	



void HUDMenu::	drawHealth(){
	M->cursorBO.use();
		int x = 30 * PIXELSCALE;
		int z = 10 * PIXELSCALE;
		float mx = health.maxHealth;	mx /= 100;
	if (health.health > 0){
		float h = health.health;		h /= health.maxHealth;	h *= mx;
		M->cursorBO.drawBar(greenT, 6, h, 1, x, z);
	}
	M->cursorBO.drawBar(redT, 6, mx, 1, x, z);

}


void HUDMenu::	drawDebugConsole(){ //recreate as class

	//fontTest();
	M->fontBO.setBuffer(2);

	stringstream ss(""); 
	//ss << C->yPos << "    " << G->avgFPS;
	//M->fontBO.beginText(ss.str()); ss.str("");
	int o1 = 52; int o2 = 75;
	M->fontBO.convertString(ss.str(), o1+o2, 0, 0); ss.str("");
	//ss << H->zone.x << ", " << H->zone.z;		
	M->fontBO.appendText(ss.str(), o1, 0); 
	//M->fontBO.appendText(G->actionString, o2+5, o1); 
	M->fontBO.loadMessage();
	M->fontBO.draw(0, 2);
	
}

