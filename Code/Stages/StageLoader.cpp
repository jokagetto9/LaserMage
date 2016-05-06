//********************************* INITIALIZATION *********************************
#include "StageLoader.h"


void StageLoader::load(){
	try {		
		loadList("stagelist.xml", "StageList", "StageFile", stageFiles);
	}catch(...){
		cout << "Stage did not load properly." << endl;
	}
	stageCount = stageFiles.size();
	loadStage(0);
	for (int i = 0; i < stageFiles.size(); i++){
		//loadStage(i);
	}
}



void StageLoader::loadStage(int i){
	try {
		rapidxml::file<> xmlFile(stageFiles[i].c_str()); // Default template is char
		rapidxml::xml_document<> doc;
		doc.parse<0>(xmlFile.data());
		rapidxml::xml_node<> *node; 
		for (node = doc.first_node(); node; node = node->next_sibling()){
			rapidxml::xml_node<> *n;
			rapidxml::xml_node<> *n2;
			rapidxml::xml_attribute<> *a;
			string s = getText(node->name());
			Stage stage;
			SpawnPoint spawn;
			EnemyWave wave;
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
					if (getText(n->name()) == "Map"){
						s = getText(n->value());
						//loadMap(s, stage);
					}
					else if (getText(n->name()) == "SpawnPoint"){
						//spawn.clear();
						//wave.clear();
						for (a = n->first_attribute(); a; a = a->next_attribute()){
							s = getText(a->name());
							if (s == "x"){
								spawn.xPos = getInt(a->value());
							}if (s == "y" || s == "z"){
								spawn.zPos = getInt(a->value());
							}
						}
						for (n2 = n->first_node(); n2; n2 = n2->next_sibling()){
							if (getText(n2->name()) == "Wave"){
								wave.quantity = getInt(n2->value());
								for (a = n2->first_attribute(); a; a = a->next_attribute()){
									s = getText(a->name());
									if (s == "type"){
										//wave.type == getInt(a->value());
										//dist="60" mirror="0" ctheta="0" cluster="10"
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
								spawn.addWave(wave);
							}
						}	
						stage.addSpawnPoint(spawn);
					}
				}
				if (success) stages.push_back(stage);
			}
		}
	}catch(...){
		cout << "Stage [" << i << "] did not load properly."<< endl;
	}
}




Stage * StageLoader::getStage(int i){
	if (i < stageCount){
		return &stages[i];
	}
	return NULL;
}


