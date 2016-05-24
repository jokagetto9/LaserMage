#ifndef STAGELOADER_H
#define STAGELOADER_H
#include "Stage.h"
#include "../BaseEngine/XMLParser.h"

//********************************* CONSTANTS *********************************

//********************************* INITIALIZATION *********************************

class StageLoader : public XMLParser {
public: 
	void StageLoader::load();
	void StageLoader::loadStage(ID id);
	Stage * StageLoader::getStage(ID id);

	
	SpawnPoint StageLoader::buildSpawnpoint(rapidxml::xml_node<> * node);
	EnemyWave StageLoader::buildWave(rapidxml::xml_node<> * node);


private:
	vector <string> stageFiles;
	vector <Stage> stages;
	int stageCount;
	

};
#endif