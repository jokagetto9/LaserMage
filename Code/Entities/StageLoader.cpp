//********************************* INITIALIZATION *********************************
#include "StageLoader.h"
#include "../Entities/MonsterBook.h"

void StageLoader::load(){
	try {		
		loadList("stagelist.xml", "StageList", "StageFile", stageFiles);
	}catch(...){
		cout << "Stage did not load properly." << endl;
	}
	for (int i = 0; i < stageFiles.size(); i++){
		loadStage(i);
	}
}



void StageLoader::loadStage(ID id){
	try {
		rapidxml::file<> xmlFile(stageFiles[id].c_str()); // Default template is char
		rapidxml::xml_document<> doc;
		doc.parse<0>(xmlFile.data());
		rapidxml::xml_node<> *node; 
		for (node = doc.first_node(); node; node = node->next_sibling()){
			rapidxml::xml_node<> *n;
			rapidxml::xml_attribute<> *a;
			string s = getText(node->name());
			Stage stage;
			bool success = true;
			if (s == "Stage"){ 
				for (a = node->first_attribute(); a; a = a->next_attribute()){
					s = getText(a->name());
					if (s == "name")
						stage.name = getText(a->value());
					else if (s == "tile")
						stage.baseTile = getInt(a->value());
				}
				for (n = node->first_node(); n; n = n->next_sibling()){
					s = getText(n->name());
					if (s == "Map"){
						//s = getText(n->value());
						//loadMap(s, stage);
					} else if (s == "SpawnPoint"){
						stage.addSpawnPoint(buildSpawnpoint(n));
					}
				}
				if (success) stages.push_back(stage);
			}
		}
	}catch(...){
		cout << "Stage [" << id << "] did not load properly."<< endl;
	}
}


SpawnPoint StageLoader::buildSpawnpoint(rapidxml::xml_node<> * node){
	rapidxml::xml_attribute<> *a;
	rapidxml::xml_node<> *n;
	SpawnPoint spawn;
	//wave.clear();
	for (a = node->first_attribute(); a; a = a->next_attribute()){
		string s = getText(a->name());
		if (s == "x"){
			spawn.x_ = getInt(a->value());
		}if (s == "y" || s == "z"){
			spawn.z_ = getInt(a->value());
		}
	}
	for (n = node->first_node(); n; n = n->next_sibling()){
		if (getText(n->name()) == "Wave"){
			spawn.addWave(buildWave(n));
		}
	}	
	return spawn;
}

EnemyWave StageLoader::buildWave(rapidxml::xml_node<> * node){
	rapidxml::xml_attribute<> *a;
	EnemyWave wave;
	wave.quantity = getInt(node->value());
	for (a = node->first_attribute(); a; a = a->next_attribute()){
		string s = getText(a->name());
		if (s == "type"){
			string type = getText(a->value());
			wave.type = Dictionary::getIndex(type, MonsterBook::getID());
		}else if (s == "dist"){
			wave.dist = getInt(a->value());
		}else if (s == "mirror"){ 
			wave.mirrored = getInt(a->value());
		}else if (s == "ctheta"){
			wave.centerTheta = getInt(a->value());
		}else if (s == "cluster"){
			wave.clustering = getInt(a->value());
		}
	}
	return wave;
}


Stage * StageLoader::getStage(ID id){
	if (id < stages.size()){
		return &stages[id];
	}
	return NULL;
}


