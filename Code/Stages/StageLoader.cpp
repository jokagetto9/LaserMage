//********************************* INITIALIZATION *********************************
#include "StageLoader.h"

StageLoader::StageLoader(){
	cursorFile = "";
	
}

void StageLoader::registerRoot(StackCommand * m){
	if (m)
		rMenus.push_back(m);
}

string XMLLoader::loadList(char*, listFile, char * listTag, char * fileTag, vector <string>& files){
    rapidxml::file<> xmlFile(listFile); // Default template is char
    rapidxml::xml_document<> doc;
	try {
		doc.parse<0>(xmlFile.data());
		rapidxml::xml_node<> *list = doc.first_node();
		rapidxml::xml_node<> *n;
		rapidxml::xml_attribute<> *a;
		string s = getText(list->name());
		if (s == listTag){ 
			for (n = list->first_node(); n; n = n->next_sibling()){
				s = getText(n->name());		
				a = n->first_attribute();
				if (s == fileTag && a) 
					s = getText(a->value());
					files.push_back(s);
				}
				else 
					loadAuxillary();
			}
		}
	}catch(...){
		cout << listTag << " did not load properly." << endl;
	}
}

void StageLoader::loadList(){
    rapidxml::file<> xmlFile("stagelist.xml"); // Default template is char
    rapidxml::xml_document<> doc;
	try {
		doc.parse<0>(xmlFile.data());
		rapidxml::xml_node<> *list = doc.first_node();
		rapidxml::xml_node<> *n;
		rapidxml::xml_attribute<> *a;
		string s = getText(list->name());
		if (s == "StageList"){ 
			for (n = list->first_node(); n; n = n->next_sibling()){
				s = getText(n->name());		
				a = n->first_attribute();
				if (s == "StageFile" && a) {
					s = getText(a->name());
					if (s == "filename"){
						s = getText(a->value());
						stageFiles.push_back(s);
					}
				}
			}
		}
	}catch(...){
		cout << "Stages did not load properly." << endl;
	}
}

Stage & StageLoader::loadStage(int i){
	try {
		rapidxml::file<> xmlFile(stageFiles[i].c_str()); // Default template is char
		rapidxml::xml_document<> doc;
		doc.parse<0>(xmlFile.data());
		rapidxml::xml_node<> *list = doc.first_node();
		for (list = list->first_node(); list; list = list->next_sibling()){
			rapidxml::xml_node<> *n;
			rapidxml::xml_node<> *n2;
			rapidxml::xml_attribute<> *a;
			string s = getText(node->name());
			Stage stage;
			SpawnPoint spawn;
			EnemyWave wave;
			bool success = false;
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
						loadMap(s, stage);
					}
					else if (getText(n->name()) == "SpawnPoint"){
						spawn.clear();
						wave.clear();
						for (a = n->first_attribute(); a; a = a->next_attribute()){
							s = getText(a->name());
							if (s == "x"){
								spawn.x = getInt(a->value());
							}if (s == "y" || s == "z"){
								spawn.z = getInt(a->value());
							}
						}
						for (n2 = n->first_node(); n2; n2 = n2->next_sibling()){
							if (getText(n2->name()) == "Wave"){
								for (a = n->first_attribute(); a; a = a->next_attribute()){
									wave.q = getInt(n->value());
									s = getText(a->name());
									if (s == "type"){
										//wave.type == getInt(a->value());
										//dist="60" mirror="0" ctheta="0" cluster="10"
									}else if (s == "dist"){
										wave.dist = getInt(a->value());
									}else if (s == "mirror"){
										wave.mirror = getInt(a->value());
									}else if (s == "ctheta"){
										wave.centerTheta = getInt(a->value());
									}else if (s == "cluster"){
										wave.clustering = getInt(a->value());
									}
								}
								if (wave.validate())  spawn.addWave(spawn);
							}
						}	
						if (spawn.validate())  stage.addSpawnPoint(spawn);
					}
				}
				if (success) return stage;
			}
		}
	}catch(...){
		cout << "Stage [" << i << "] did not load properly."<< endl;
	}
}

void StageLoader::loadMenu(int i, rapidxml::xml_node<> * node){

	
}

void StageLoader::loadCursors(){	
	if (cursorFile != ""){
		try {
			rapidxml::file<> xmlFile(cursorFile.c_str()); // Default template is char
			rapidxml::xml_document<> doc;	
			rapidxml::xml_node<> *n;
			rapidxml::xml_attribute<> *a;
			string s;

			doc.parse<0>(xmlFile.data());
			rapidxml::xml_node<> *list = doc.first_node();
			for (n = list->first_node(); n; n = n->next_sibling()){
				s = getText(n->name());
				if(s == "Cursor"){
					int index = 0; GLuint tex = 0;
					for (a = n->first_attribute(); a; a = a->next_attribute()){
						s = getText(a->name());
						if(s == "id"){
							index = getInt(a->value());
						}			
						else if(s == "filename"){
							tex = loadTexture(a->value(), false);
							Menu::createCursor(tex, index);
						}		
					}
				}
			}
		}catch(...){
			cout << "Cursors did not load properly." << endl;
		}
	}
}

void StageLoader::printList(){
	for (int i = 0; i < menuFiles.size(); i++){
		cout << menuFiles[i] << endl;
	}
}

void StageLoader::printMenu(int i){
	if (i < menuFiles.size()){


	}
}

string StageLoader::getText(char * c){	
	stringstream ss; string s;
	ss << c;	 ss >> s;
	return s;
}


int StageLoader::getInt(char * c){	
	stringstream ss; int i;
	ss << c;	 ss >> i;
	if (i < -10000)
		return 0;
	else 
		return i;
}