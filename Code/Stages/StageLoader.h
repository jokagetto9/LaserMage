#ifndef STAGELOADER_H
#define STAGELOADER_H
#include "Stage.h"
#include "../BaseEngine/Utility/XMLParser.h"

//********************************* CONSTANTS *********************************

//********************************* INITIALIZATION *********************************

class StageLoader : public XMLParser {
public: 
	void StageLoader::load();
	void StageLoader::loadStage(int i);
	Stage * StageLoader::getStage(int i);

private:
	vector <string> stageFiles;
	vector <Stage> stages;
	int stageCount;

};
#endif