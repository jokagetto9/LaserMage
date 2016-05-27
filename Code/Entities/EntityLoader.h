#ifndef ENTITYLOADER_H
#define ENTITYLOADER_H


#include "../BaseEngine/XMLParser.h"
#include "../Display/ModelManager.h"

//********************************* CONSTANTS *********************************

//********************************* INITIALIZATION *********************************

class EntityLoader : public XMLParser {
public: 
	void EntityLoader::load(); 
	void EntityLoader::loadActor(ID id);
	void EntityLoader::loadProp(ID id);
	
	void EntityLoader::buildEntity(rapidxml::xml_node<> * node);

	void EntityLoader::addAnimation(rapidxml::xml_node<> * node);

	
	void EntityLoader::loadAuxillary(rapidxml::xml_node<> * node);

	


private: 
	
	ID count;
	string props;
	vector <string> actorFiles;
	vector <ID> * textures;
	//static vector <TypeObj*> types;
};
#endif