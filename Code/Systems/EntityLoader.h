#ifndef ENTITYLOADER_H
#define ENTITYLOADER_H


#include "../BaseEngine/XMLParser.h"
#include "../Display/ModelManager.h"
#include "../Entities/Book.h"

//********************************* CONSTANTS *********************************

//********************************* INITIALIZATION *********************************

class EntityLoader : public XMLParser {
public: 
	void EntityLoader::load(); 

	void EntityLoader::loadProp(ID id);
	void EntityLoader::buildProp(rapidxml::xml_node<> * node);
	void EntityLoader::buildProps(rapidxml::xml_node<> * node);

	void EntityLoader::loadActor(ID id);	
	void EntityLoader::buildActor(rapidxml::xml_node<> * node);
	void EntityLoader::loadParticle(ID id);	
	void EntityLoader::buildParticle(rapidxml::xml_node<> * node);
	
	void EntityLoader::addAnimation(rapidxml::xml_node<> * node, ParticleList * dict);
	bool EntityLoader::loadShaderProfile(rapidxml::xml_attribute<> *a, ShaderProfile &sp);
		
	void EntityLoader::loadAuxillary(rapidxml::xml_node<> * node);


private: 
	
	ID propCount;
	ID enemyCount;
	ID particleCount;
	vector <string> propFiles;
	vector <string> actorFiles;
	vector <string> particleFiles;
	vector <ID> * textures;
	//static vector <TypeObj*> types;


};
#endif