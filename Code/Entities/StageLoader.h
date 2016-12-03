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

	void StageLoader::loadMap(rapidxml::xml_node<> * node, Stage &stage);
	void StageLoader::buildSpawnpoint(rapidxml::xml_node<> * node, Stage &stage);
	ID StageLoader::buildWave(rapidxml::xml_node<> * node, Stage &stage);



	ID StageLoader::size(){return stages.size();}

private:
	vector <string> stageFiles;
	vector <Stage> stages;
	

};
#endif