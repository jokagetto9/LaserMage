#ifndef MCOMMAND_H
#define MCOMMAND_H
#include "../Display/Menus/Menu.h"
#include "../System/BaseEngine/BaseGameState.h"

//********************************* CONSTANTS *********************************

//********************************* INITIALIZATION *********************************


class PlayCommand  {
public:
  virtual void enter(vector <Menu *>& stack){
	  stack.clear();
	  G0->paused = false;
  }
};

class StackCommand : public PlayCommand{
public:
StackCommand::StackCommand(){ current = -1;}
  virtual void enter(vector <Menu *>& stack){
	  if (!menus.empty()){
		stack.push_back(&menus[0]);
		current = 0;
	  }
  }

  int getFlow(){
	  if (!menus.empty() && current >= 0){
		  return menus[current].getFlow();
	  }
  }

  void addMenu(Menu& menu){
	  menus.push_back(menu);
  }


private:
	int current;
  vector<Menu> menus;
  
};


class MenuCommand  {
public:
	virtual void exec(Menu * m){};
};
class MenuDrctn : public MenuCommand {
public:
	MenuDrctn::MenuDrctn(){reset();}
  void MenuDrctn::exec(Menu * m){
	  if (xz.x != 0)
		 m->cursorLR(xz.x);
	  else if (xz.z != 0)
		 m->cursorUD(xz.z);
	  reset();
  }
  void MenuDrctn::set(int x, int z){xz.x = 0; xz.z = 0;}
  void MenuDrctn::reset(){xz.x = 0; xz.z = 0;}

private: 
	XZI xz;
};

class MenuAccept : public MenuCommand  {
public:
  void exec(Menu * m){
	  m->enter();
  }
};

class MenuQuit : public MenuCommand   {
public:
  void exec(Menu * m){	  
	  m->quit();
  }
};



//class MessageCommand  {
//public:

//};

#endif