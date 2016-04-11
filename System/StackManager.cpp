//********************************* INITIALIZATION *********************************
#include "StackManager.h"

StackManager::StackManager(){
	abort = false;
	menuView = false;
	loading = false;
	updating = false; 
	initMenus();
	physSkip = 0;
}

void StackManager::	initMenus(){
	previewMenu = NULL;
	owlMenu.setBackground(EXIT);
	//owlMenu.setTimeOut(10);
		
//enum MenuCommand {PLAY, EXIT, TITLE, MAIN, SYS, STORE, DLG, DBG }; //when not exit
//enum MenuType {QUIT, STAT, EQP, INV, LOOT, RELIC, SKLS, JRNL, ACTIVEEQP, ACTIVEITM, USE, SHOPEQP, SHOPLOOT, CNFM, NUMSLCT, PASS};
	menuList.push_back(&owlMenu);
	menuList.push_back(&statusMenu);
	menuList.push_back(&equipMenu);
	menuList.push_back(&invMenu);
	menuList.push_back(&lootMenu); 
	menuList.push_back(&relicMenu);
	menuList.push_back(&skillMenu);
	menuList.push_back(&logMenu);
	menuList.push_back(&activeEqpMenu);
	menuList.push_back(&activeItmMenu);
	menuList.push_back(&usageMenu);
	menuList.push_back(&shopEquipMenu);
	menuList.push_back(&shopLootMenu);
	menuList.push_back(&confMenu);
	menuList.push_back(&numberMenu);



	mainMenu.addFlow(STAT);
	mainMenu.addFlow(EQP);
	mainMenu.addFlow(INV);
	mainMenu.addFlow(SKLS);
	mainMenu.addFlow(RELIC);
	mainMenu.addFlow(JRNL);
	mainMenu.preview = true;
	
	mainMenu.setBackground(MAIN);
	mainMenu.maxIndex = 5;
	mainMenu.addCursor(2, 262, 290);
	mainMenu.lineW = 80;

	statusMenu.setBackground(DBG + STAT);

	equipMenu.setBackground(DBG + EQP);

	invMenu.setBackground(DBG + INV);
	invMenu.setFlow(LOOT);
	invMenu.preview = true;		
	invMenu.maxIndex = 5;
	invMenu.addCursor(1, 63, 50);
	invMenu.lineW = 40;
	
	lootMenu.setBackground(DBG + INV);
	//lootMenu.overlay = true;
	lootMenu.setFlow(USE);

	skillMenu.setBackground(DBG + SKLS);	

	logMenu.setBackground(DBG + JRNL);

	dialogMenu.setBackground(DLG);
	dialogMenu.backdrop = false;
	debugMenu.setBackground(DBG);
	debugMenu.backdrop = false;

	activeEqpMenu.overlay = true;
	activeItmMenu.overlay = true;
	usageMenu.overlay = true;
	
	shopMenu.setBackground(STORE);
	shopMenu.backdrop = false;
	shopMenu.addFlow(SHOPEQP);
	shopMenu.addFlow(SHOPLOOT);
	shopMenu.maxIndex = 3;
	shopMenu.addCursor(4, 60, 138);
	shopMenu.lineH = 25;
	
	shopEquipMenu.setBackground(DBG + SHOPEQP);
	shopLootMenu.setBackground(DBG + SHOPLOOT);
	//confMenu;
	///numberMenu;
}


//********************************* LOADING *********************************

void StackManager::setRootMenu(){
	if (G->menuCommand == PLAY)
		stack.clear();		
	else if (G->menuCommand == MAIN)	
		stack.push_back(&mainMenu);	
	else if (G->menuCommand == DLG)	
		stack.push_back(&dialogMenu);	
	else if (G->menuCommand == STORE)	
		stack.push_back(&shopMenu);	
	else if (G->menuCommand == DBG)	
		stack.push_back(&debugMenu );	
		
	G->initMenu = false;
}

void StackManager::setMenu(MenuType mt){
	if (mt == QUIT)	{
		int i = stack.back()->index; //save for later?
		stack.back()->quit();
	}else if (mt == USE){
		usageMenu.init(stack.back());
		stack.push_back(menuList[mt]);
	}else if (mt == PASS){
	} else{
		if (previewMenu == NULL){
			if (stack.back() != NULL) menuList[mt]->init(stack.back());
			stack.push_back(menuList[mt]);
		}else{
			if (previewMenu->maxIndex >= 0){
				stack.push_back(previewMenu);
				previewMenu = NULL;
			}
		}
	} 		
}

void StackManager::	update(ControllerInput &input){
	if (G->initMenu) setRootMenu();
	if (G->paused){
		if (stack.empty()){	
			G->enterMenu(PLAY);
			setRootMenu();
		} else {
			input.menuInput(stack.back());
			if (!stack.back()->abort) updateMenu();
			else	popMenu();
		}
	}
}

void StackManager::updateMenu(){
	//if (G->initMenu) setRootMenu();
	
	if (G->menuCommand != PLAY){
		Menu *s = stack.back();
		if (s->affirm){
			s->reset();
			setMenu(s->getFlow());
			s = stack.back();
		}
		if (s->update){
			s->refresh();
			if(s->preview){
				MenuType mt = s->getFlow();
				if (mt != QUIT){
					previewMenu = menuList[mt];
					previewMenu->refresh(s->index);
				}else 
					previewMenu = NULL;
			}
			s->update = false;
		} 
	}
}



void StackManager::	pushMenu(Menu * s){
	stack.push_back(s);
}
 
void StackManager::	popMenu(){
	if (!stack.empty()){
		if (stack.back()->abort){
			stack.back()->reset();
			stack.pop_back();
		}
	}
}



void StackManager::	rapidUpdate(){		
	if (!stack.empty()){
		stack.back()->rapidUpdate();
	}
}

//********************************* DRAW *********************************

void StackManager::	drawMenus(){		
	setUp2DView(WIDTH, HEIGHT);	//2D pixel coordinates
	//for (each screen with >displayOnly)
	if (!G->paused){
		M->fontBO.use();	hudMenu.drawText();
		M->cursorBO.use();	hudMenu.drawCursor();
		M->menuBO.use();	hudMenu.drawIcons();
	} else if (!stack.empty()){ 
		drawText();
		drawCursor();
		drawIcons();
		drawBackground();
	}
	
	disable2DView();
}

void StackManager::	drawText(){
	M->fontBO.use();
	
	hudMenu.drawDebugConsole();

	stack.back()->drawText();
	if(isOverlay())
		getNextMenu()->drawText();
	if (hasPreview())
		previewMenu->drawText();
}
void StackManager::	drawCursor(){
	M->cursorBO.use();
	stack.back()->drawCursor();
}
void StackManager::	drawIcons(){
	M->iconBO.use();
	stack.back()->drawIcons();
	if(isOverlay())
		getNextMenu()->drawIcons();
	if (hasPreview())
		previewMenu->drawIcons();
}
void StackManager::	drawBackground(){
	M->menuBO.use();
	stack.back()->drawBackground();
	if(isOverlay())
		getNextMenu()->drawBackground();
	if (hasPreview())
		previewMenu->drawBackground();
}


//*********************************

Menu* StackManager::getNextMenu(){
	int s = stack.size();
	if (s > 1)
		return stack[s-2];
	return NULL;
}

bool StackManager::isOverlay(){
	if (stack.back()->overlay && stack.size() > 1)
		return true;
	return false;
}

bool StackManager::hasPreview(){
	return stack.back()->preview && previewMenu != NULL;
}


//*********************************

void StackManager :: setUp2DView (int width, int height){
	if (!menuView){
		if(width < 1)  width = 1;
		if(height < 1) height = 1;

		glMatrixMode(GL_PROJECTION);
		glPushMatrix();
		glLoadIdentity();
		//gluOrtho2D(0.0, width, 0.0, width);
		glOrtho(0.0, width, 0.0, height, 0, 1);



		menuView = true;
	}
}

void StackManager :: disable2DView ()
{
	if (menuView){
		glMatrixMode(GL_PROJECTION);
		glPopMatrix();

		menuView = false;
		//glMatrixMode(GL_MODELVIEW);
		//glPopMatrix();

	}
}




bool StackManager:: backdrop(){
	if (!stack.empty()){
		return stack.back()->backdrop;
	}
	return false;
}
