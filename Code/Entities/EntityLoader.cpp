//********************************* INITIALIZATION *********************************
#include "EntityLoader.h"

#include "../BaseEngine/Entities/Dictionaries.h"

void EntityLoader::load(){
	count = 0;
	try {		
		loadList("entitylist.xml", "EntityList", "ActorFile", actorFiles);
		//loadList("entitylist.xml", "EntityList", "PropFile", actorFiles);
	}catch(...){
		cout << "Entities did not load properly." << endl;
	}
	loadActor(0);
	for (int i = 0; i < actorFiles.size(); i++){
		//loadStage(i);
	}
}


void EntityLoader::loadProp(ID id){}


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
				buildEntity(node);
				for (n = node->first_node(); n; n = n->next_sibling()){
					if (getText(n->name()) == "Anim"){
						//addAnimation(n);
					}
				}
			} //else if (s == "NPC"){
		}
	}catch(...){
		cout << "Enemy [" << id << "] did not load properly."<< endl;
	}
}


void EntityLoader::buildEntity(rapidxml::xml_node<> * node){
	rapidxml::xml_attribute<> *a;
	Identity identity = {"", 0};
	ID tex = 0;
	MotionMax mm = {1, 1};
	for (a = node->first_attribute(); a; a = a->next_attribute()){
		string s = getText(a->name());
		if (s == "name"){
			identity.name = getText(a->value());
			identity.id = count; count++;
		}else if (s == "texture"){
			tex = loadTexture(a->value(), false);
		}else if (s == "speed"){
			mm.speed = getInt(a->value());
		}else if (s == "accel"){
			mm.accel = getInt(a->value());
		}
	}
	if (true) {
		ParticleList::profiles.push_back(identity);
		ParticleList::textures.push_back(tex); //TODO replace with Rendering
		ParticleList::max.push_back(mm); 
	}
}


void EntityLoader::addAnimation(rapidxml::xml_node<> * node){
	rapidxml::xml_attribute<> *a;
	for (a = node->first_attribute(); a; a = a->next_attribute()){
		string s = getText(a->name());
		string type = "walk";
		if (s == "name")
			type = getText(a->value());
		else if (type == "walk"){								
			//if (s == "filename"){
				//profile.walkTex = loadTexture(a->value(), false);
				//textures->push_back(profile.walkTex);
			//} else if (s == "type")
				//profile.walkAnim.type = 0;
		}else if (type == "die"){


		}
	}
}

void EntityLoader::loadAuxillary(rapidxml::xml_node<> * node){


}
