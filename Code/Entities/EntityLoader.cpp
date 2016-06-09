//********************************* INITIALIZATION *********************************
#include "EntityLoader.h"
#include "MonsterBook.h"

void EntityLoader::load(){
	enemyCount = 0;
	propCount = 0;
	try {		
		loadList("entitylist.xml", "EntityList", "ActorFile", actorFiles);
		loadList("entitylist.xml", "EntityList", "PropFile", propFiles);
	}catch(...){
		cout << "Entities did not load properly." << endl;
	}
	loadActor(0);
	loadProp(0);
	for (int i = 0; i < actorFiles.size(); i++){
		//loadStage(i);
		//loadProp(i);
	}
}


void EntityLoader::loadProp(ID id){
	try {
		rapidxml::file<> xmlFile(propFiles[id].c_str()); // Default template is char
		rapidxml::xml_document<> doc;
		doc.parse<0>(xmlFile.data());
		rapidxml::xml_node<> *node = doc.first_node(); 
		for (node = node->first_node(); node; node = node->next_sibling()){
			rapidxml::xml_node<> *n;
			rapidxml::xml_attribute<> *a;
			string s = getText(node->name());
			bool success = true;
			if (s == "Prop"){ 
				buildProp(node);
			}else if (s == "Props"){				
				buildProps(node);
			}
		}
	}catch(...){
		cout << "Enemy [" << id << "] did not load properly."<< endl;
	}
}


void EntityLoader::buildProp(rapidxml::xml_node<> * node){
	rapidxml::xml_attribute<> *a;
	Identity identity = {"", 0};
	ID tex = 0;
	SizeProfile size = {3, 10, 1, 0};
	Rendering r;
	ShaderProfile sp = {0, 1, G1x1};
	for (a = node->first_attribute(); a; a = a->next_attribute()){
		string s = getText(a->name());
		if (s == "name"){
			identity.name = getText(a->value());
			identity.id = propCount; propCount++;
		}else if (s == "size")
			size.rad = getFloat(a->value());		
		else
			loadShaderProfile(a, sp);
	}
	propList.addIdentity(identity);
	//propList.addProfileIndex(propList.size()); 
	propList.addProfile(sp); 

	r.tex = sp.tex;
	propList.addRendering(r); 
}

void EntityLoader::buildProps(rapidxml::xml_node<> * node){
	rapidxml::xml_attribute<> *a;
	rapidxml::xml_node<> * n;
	Identity identity = {"", 0};
	ID tex = 0;
	float size;
	ShaderProfile sp = {0, 1, G1x1};
	Rendering r;
	for (a = node->first_attribute(); a; a = a->next_attribute())
		loadShaderProfile(a, sp);
		propList.addProfile(sp); 
		for (n = node->first_node(); n; n = n->next_sibling()){		
			string s = getText(n->name());
			if (s == "Prop"){
				for (a = n->first_attribute(); a; a = a->next_attribute()){
					s = getText(a->name());
					if (s == "name"){
						identity.name = getText(a->value());
						identity.id = propCount; propCount++;
					}else if (s == "size")
						size = getFloat(a->value());		
					else if (s == "index")
						r.texIndex = getInt(a->value());
				}
				r.tex = sp.tex;
				propList.addIdentity(identity);
				propList.addProfileIndex(propList.profileCount()-1); 
				propList.addRendering(r);
			} 
		}
}

void EntityLoader::loadActor(ID id){ 
	try {
		rapidxml::file<> xmlFile(actorFiles[id].c_str()); // Default template is char
		rapidxml::xml_document<> doc;
		doc.parse<0>(xmlFile.data());
		rapidxml::xml_node<> *node = doc.first_node(); 
		for (node = node->first_node(); node; node = node->next_sibling()){
			rapidxml::xml_node<> *n;
			rapidxml::xml_attribute<> *a;
			string s = getText(node->name());
			bool success = true;
			if (s == "Enemy"){ 
				buildActor(node);
				for (n = node->first_node(); n; n = n->next_sibling()){
					if (getText(n->name()) == "Animation"){
						addAnimation(n);
					}
				}
			} //else if (s == "NPC"){
		}
	}catch(...){
		cout << "Enemy [" << id << "] did not load properly."<< endl;
	}
}

void EntityLoader::buildActor(rapidxml::xml_node<> * node){
	rapidxml::xml_attribute<> *a;
	Identity identity = {"", 0};
	MotionMax mm = {1, 1};
	for (a = node->first_attribute(); a; a = a->next_attribute()){
		string s = getText(a->name());
		if (s == "name"){
			identity.name = getText(a->value());
			identity.id = enemyCount; enemyCount++;
		}else if (s == "speed"){
			mm.speed = getFloat(a->value());
		}else if (s == "accel"){
			mm.accel = getInt(a->value());
		}
	}
	if (true) {
		monBook.addIdentity(identity);
		monBook.addMotion(mm); 
	}
}

bool EntityLoader::loadShaderProfile(rapidxml::xml_attribute<> *a, ShaderProfile &sp){
	bool input = false;;
	string s = getText(a->name());
	if (s == "texture"){
		input = true;
		sp.tex = loadTexture(a->value(), false);
	}else if (s == "scale"){
		input = true;
		sp.scale = getFloat(a->value());
	}else if (s == "grid"){
		input = true;
		string grid = getText(a->value());
		if (grid == "2x2")
			sp.g = G2x2;
		else if (grid == "4x4")
			sp.g = G4x4;
		else
			sp.g = G1x1;
	}
	return input;
}


void EntityLoader::addAnimation(rapidxml::xml_node<> * node){
	rapidxml::xml_attribute<> *a;
	ID tex = 0;
	ID min = 0; ID max = 3;
	ID frames = 20;
	ShaderProfile sp = {0, 1, G4x4};
	bool cyclic = false;
	for (a = node->first_attribute(); a; a = a->next_attribute()){	
		string s = getText(a->name());
		if (s == "start")
			min = getInt(a->value());
		else if (s == "end"){
			cyclic = true;
			max = getInt(a->value());
		} else if (s == "frames")
			frames = getInt(a->value());
		else
			loadShaderProfile(a, sp);
	}
	monBook.addProfile(sp); 

	Animation anim;
	if (cyclic)
		anim.setCyclic(min, max, frames);

	monBook.anim.push_back(anim);
}

void EntityLoader::loadAuxillary(rapidxml::xml_node<> * node){


}
