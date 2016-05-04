#ifndef MENULOADER_H
#define MENULOADER_H
#include "../BaseEngine/lib.h"

//********************************* CONSTANTS *********************************

//********************************* INITIALIZATION *********************************

class StageLoader  {
public: 
	StageLoader::StageLoader();

	void StageLoader::registerRoot(StackCommand * m);


	void StageLoader::loadList();
	void StageLoader::loadStage(int i);

	string StageLoader::getText(char * c);
	int StageLoader::getInt(char * c);
private:
	vector <string> stageFiles;


};
#endif