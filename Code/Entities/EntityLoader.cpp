//********************************* INITIALIZATION *********************************
#include "EntityLoader.h"

#include "MonsterBook.h"

void EntityLoader::load(){
	count = 0;
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
			} //else if (s == "NPC"){
		}
	}catch(...){
		cout << "Enemy [" << id << "] did not load properly."<< endl;
	}
}
void EntityLoader::buildProp(rapidxml::xml_node<> * node){
	rapidxml::xml_attribute<> *a;
	Identity identity = {"", 0};
	MotionMax mm = {1, 1};
	for (a = node->first_attribute(); a; a = a->next_attribute()){
		string s = getText(a->name());
		if (s == "name"){
			identity.name = getText(a->value());
			identity.id = count; count++;
		}else if (s == "speed"){
			mm.speed = getFloat(a->value());
		}else if (s == "accel"){
			mm.accel = getInt(a->value());
		}
	}
	if (true) {
		MonsterBook::names.push_back(identity);
//TODO replace with Rendering
		MonsterBook::max.push_back(mm); 
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
			identity.id = count; count++;
		}else if (s == "speed"){
			mm.speed = getFloat(a->value());
		}else if (s == "accel"){
			mm.accel = getInt(a->value());
		}
	}
	if (true) {
		MonsterBook::names.push_back(identity);
//TODO replace with Rendering
		MonsterBook::max.push_back(mm); 
	}
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
		string type = "walk";
		if (s == "name")
			type = getText(a->value());
		else if (s == "texture")
			sp.tex = loadTexture(a->value(), false);
		else if (s == "start")
			min = getInt(a->value());
		else if (s == "end"){
			cyclic = true;
			max = getInt(a->value());
		} else if (s == "frames")
			frames = getInt(a->value());		
		else if (s == "scale")
			sp.scale = getFloat(a->value());
		else if (s == "grid"){
			string grid = getText(a->value());
			if (grid == "2x2")
				sp.g = G2x2;
			else
				sp.g = G1x1;		
		}
	}

	monBook.addProfile(sp); 

	Animation anim;
	if (cyclic)
		anim.setCyclic(min, max, frames);

	MonsterBook::anim.push_back(anim);
}

void EntityLoader::loadAuxillary(rapidxml::xml_node<> * node){


}
