#ifndef ENTITYLOADER_H
#define ENTITYLOADER_H


#include "../BaseEngine/XMLParser.h"
#include "../Display/ModelManager.h"

//********************************* CONSTANTS *********************************

//********************************* INITIALIZATION *********************************

class EntityLoader : public XMLParser {
public: 
	void EntityLoader::load(); 

	void EntityLoader::loadProp(ID id);
	void EntityLoader::buildProp(rapidxml::xml_node<> * node);

	void EntityLoader::loadActor(ID id);	
	void EntityLoader::buildActor(rapidxml::xml_node<> * node);

	void EntityLoader::addAnimation(rapidxml::xml_node<> * node);

	
	void EntityLoader::loadAuxillary(rapidxml::xml_node<> * node);

	


private: 
	
	ID count;
	vector <string> propFiles;
	vector <string> actorFiles;
	vector <ID> * textures;
	//static vector <TypeObj*> types;
};
#endif