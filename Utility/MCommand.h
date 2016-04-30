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
  virtual void enter(vector <Menu *>& stack){
	  if (!menus.empty())
		stack.push_back(&menus[0]);
  }

  void addMenu(Menu& menu){
	  menus.push_back(menu);
  }

protected:
  vector<Menu> menus;  
};

class TrickStack : public StackCommand{
public:
  virtual void enter(vector <Menu *>& stack){
	if (menus.size() >= 2) {
		stack.push_back(&menus[1]);
		stack.push_back(&menus[0]);
	 } 
  }
};


class StackQuit  : public StackCommand{
public:
  void enter(vector <Menu *>& stack){
	  stack.clear();
	  G0->gameActive = false;
  }
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