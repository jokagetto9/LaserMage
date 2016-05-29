//********************************* INITIALIZATION *********************************
#include "DebugTool.h"
DebugTool::DebugTool(){


}	



void DebugTool::init(){	
	
}




void DebugTool::	fontTest(){
	M->fontBO.setBuffer(3);
	M->fontBO.changeFont();
	string test; int i = 0;
	test = " !?#$%&()[]*+,-./";
	M->fontBO.beginText(test); i++;
	test = "0123456789";
	M->fontBO.appendText(test, 0, 16*i);  i++;
	test = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	M->fontBO.appendText(test, 0, 16*i);  i++;
	test = "abcdefghijklmnopqrstuvwxyz";
	M->fontBO.appendText(test, 0, 16*i);  
	M->fontBO.loadMessage();
	M->fontBO.draw(0, 2);	
}

void DebugTool::	drawDebugConsole(float fps){ //recreate as class
	M->fontBO.use();
	M->fontBO.setBuffer(2);	
	stringstream ss("");
	ss << fps;
	M->fontBO.convertString(ss.str(), 0, 0, 0); ss.str("");
	M->fontBO.loadMessage();
	M->fontBO.draw(3, 0);
	
}
