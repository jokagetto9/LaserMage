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
						loadMap(n, stage);
					} else if (s == "SpawnPoint"){
						buildSpawnpoint(n, stage);
					}
				}
				if (success) stages.push_back(stage);
			}
		}
	}catch(...){
		cout << "Stage [" << id << "] did not load properly."<< endl;
	}
}


void StageLoader::loadMap(rapidxml::xml_node<> * node, Stage &stage){
	rapidxml::xml_attribute<> *a;
	rapidxml::xml_node<> *n;
	EntityXZ e = {0, 0, 0};
	for (n = node->first_node(); n; n = n->next_sibling()){
		bool success = false;
		for (a = n->first_attribute(); a; a = a->next_attribute()){			
			string s = getText(a->name());
			if (s== "type"){		
				string type = getText(a->value());
				e.id = Book::props.getIndex(type);
				success = true;
			}else if (s == "x"){
				e.x = getInt(a->value());
			}else if (s == "y" || s == "z"){
				e.z = getInt(a->value());
			}
		}
		if (success) stage.add(e);
	}
}


void StageLoader::buildSpawnpoint(rapidxml::xml_node<> * node, Stage &stage){
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
			spawn.addWave(buildWave(n, stage));
		}
	}	
	stage.addSpawnPoint(spawn);
}

ID StageLoader::buildWave(rapidxml::xml_node<> * node, Stage &stage){
	rapidxml::xml_attribute<> *a;
	EnemyWave wave;
	wave.quantity = getInt(node->value());
	for (a = node->first_attribute(); a; a = a->next_attribute()){
		string s = getText(a->name());
		if (s == "type"){
			string type = getText(a->value());
			wave.type = Book::enemies.getIndex(type);
		}else if (s == "dist"){
			wave.dist = getInt(a->value());
		}else if (s == "mirror"){ 
			wave.mirrored = getInt(a->value());
		}else if (s == "ctheta"){
			wave.centerTheta = getInt(a->value());
		}else if (s == "spacing"){
			wave.spacing = getInt(a->value());
		}else if (s == "index"){
			wave.trigInd = getInt(a->value());
		}else if (s == "timer"){
			wave.trigTime = getFloat(a->value());
		}else if (s == "ratio"){
			wave.trigRat = getFloat(a->value());
		}
	}
	return stage.addWave(wave);
}


Stage * StageLoader::getStage(ID id){
	if (id < stages.size()){
		return &stages[id];
	}
	return NULL;
}


