#ifndef MCOMMAND_H
#define MCOMMAND_H
#include "HeroCommand.h"

//********************************* CONSTANTS *********************************

//********************************* INITIALIZATION *********************************


//class MessageCommand  {
//public:

//};

class MenuCommand  {
public:
	//MenuCommand::MenuCommand(){menus.reserve(10);}
  void enter(vector <Menu *>& stack){
	  if (!menus.empty()){
		stack.push_back(menus[0]);
	  }
  }

private:
  vector<Menu> menus;
  
};




};
#endif