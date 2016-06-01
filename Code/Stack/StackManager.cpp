//********************************* INITIALIZATION *********************************
#include "StackManager.h"

StackManager::StackManager(){
	menuView = false;
	previewMenu = NULL;
}


void StackManager::loadStages(StageLoader* stages){
	ID mID = -1; int s = title.size();
	for (ID i = 0; i < title.size(); i++){
		if (title.getName(i) == "StageSelect");
			mID = i;		
	}
	if (mID >= 0 && mID < title.size()){
		ID s = stages->size();
		title.getMenu(mID)->maxIndex = s-1;
		for (ID i = 0; i < s; i++){
			string name = stages->getStage(i)->name;
			title.getMenu(mID)->addText(name);
		}
	}		

}

void StackManager::setMenu(int flow){
	if (stack.back()->func){

		GameFunctionCode func = (GameFunctionCode)flow;
		if (func == BACK)	{
			int i = stack.back()->index; //save for later?
			stack.back()->quit();
		}else if (func == START){
			index = stack.back()->index;
			PlayCommand play;
			play.enter(stack, 0);
			currRoot = NULL;
		}else if (func == RESTART){	
			G->loaded = false;
		}else if (func == OPTN){	

		}else if (func == MAINMENU){
			stack.clear();
			G->loaded = false;
			G->state = TITLE;
		}else if (func == QUIT){
			G->gameActive = false;
		}else if (func == USE){
			//usageMenu.init(stack.back());
			//stack.push_back(menuList[mt]);
		}
	} else 
		 BaseStackManager::setMenu(flow);
}