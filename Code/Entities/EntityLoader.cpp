//********************************* INITIALIZATION *********************************
#include "EntityLoader.h"


SizeProfile buildSizeProfile(float base, float crash, float sep, float sepR, float coh, float cohR){
	SizeProfile sp;// = {col, sep, avo, ali, coh};
	return sp;
}

void EntityLoader::load(){
	enemyCount = 0;
	particleCount = 0;
	propCount = 0;
	

	try {		
		loadList("entitylist.xml", "EntityList", "ActorFile", actorFiles);
		loadList("entitylist.xml", "EntityList", "PropFile", propFiles);
		loadList("entitylist.xml", "EntityList", "ParticleFile", particleFiles);
	}catch(...){
		cout << "Entities did not load properly." << endl;
	}
	loadActor(0);
	loadProp(0);
	loadParticle(0);
	//Obstacles::sizeProfiles.push_back(Obstacles::ignore);
	//SizeProfile sp;
	//sp = buildSizeProfile(0, 0.5, 2, 9, 10, 0.001);
	//sp = {0, 0.2, 2, 9, 8, 0.0005};
	//sp = buildSizeProfile(0, 0.2, 2, 9, 10, 0.001); //gnome
	//Obstacles::sizeProfiles.push_back(sp);
	//sp = buildSizeProfile(0.5, 0, 3.5, 16, 12, 0.0001);
	//Obstacles::sizeProfiles.push_back(sp);
	//sp = buildSizeProfile(0, 1, 4, 10, 0, 0);
	//Obstacles::sizeProfiles.push_back(sp);
	//sp = buildSizeProfile(1, 1, 5, 16, 0, 0);
	//Obstacles::sizeProfiles.push_back(sp);
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
	rapidxml::xml_attribute<> *a;;
	Identity identity = {"", 255, -1, 1};
	ID tex = 0;
	Rendering r;
	Size size;
	ShaderProfile sp = {0, 1, G1x1};
	for (a = node->first_attribute(); a; a = a->next_attribute()){
		string s = getText(a->name());
		if (s == "name"){
			identity.name = getText(a->value());
			identity.type = propCount; propCount++;
		}else if (s == "scale")
			sp.scale = getFloat(a->value());		
		else if (s == "col")
			size.colR = getFloat(a->value());
		else if (s == "sep")
			size.sepR = getFloat(a->value());	
		else if (s == "avo")
			size.avoR = getFloat(a->value());	
		else
			loadShaderProfile(a, sp);
	}
	propList.addIdentity(identity);
	//propList.addProfileIndex(propList.profileCount()); 
	propList.addProfile(sp); 
	propList.addSize(size); 

	r.tex = sp.tex;
	propList.addRendering(r); 
}

void EntityLoader::buildProps(rapidxml::xml_node<> * node){
	rapidxml::xml_attribute<> *a;
	rapidxml::xml_node<> * n;
	Identity identity = {"", 255, -1, 1};
	ID tex = 0;
	Rendering r;
	Size size;
	ShaderProfile sp = {0, 1, G2x2};
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
						identity.type = propCount; propCount++;
					}else if (s == "col")
						size.colR = getFloat(a->value());
					else if (s == "sep")
						size.sepR = getFloat(a->value());	
					else if (s == "avo")
						size.avoR = getFloat(a->value());							
					else if (s == "index")
						r.texIndex = getInt(a->value());
				}
				r.tex = sp.tex;
				propList.addIdentity(identity);
				propList.addProfileIndex(propList.profileCount()-1); 
				propList.addSize(size); 
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
						addAnimation(n, &monBook);
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
	Identity identity = {"", 255, -1, 3};
	MotionMax mm = {1, 1};	
	Size size;
	for (a = node->first_attribute(); a; a = a->next_attribute()){
		string s = getText(a->name());
		if (s == "name"){
			identity.name = getText(a->value());
			identity.type = enemyCount; enemyCount++;
		}else if (s == "speed"){
			mm.speed = getFloat(a->value());
		}else if (s == "accel"){
			mm.accel = getInt(a->value());
		}else if (s == "col")
			size.colR = getFloat(a->value());
		else if (s == "sep")
			size.sepR = getFloat(a->value());	
		else if (s == "avo")
			size.avoR = getFloat(a->value());				
	}
	if (true) {			
		monBook.addSize(size); 
		monBook.addIdentity(identity);
		monBook.addMotion(mm); 
	}
}


void EntityLoader::loadParticle(ID id){ 
	try {
		rapidxml::file<> xmlFile(particleFiles[id].c_str()); // Default template is char
		rapidxml::xml_document<> doc;
		doc.parse<0>(xmlFile.data());
		rapidxml::xml_node<> *node = doc.first_node(); 
		for (node = node->first_node(); node; node = node->next_sibling()){
			rapidxml::xml_node<> *n;
			rapidxml::xml_attribute<> *a;
			string s = getText(node->name());
			bool success = true;
			if (s == "Particle"){ 
				buildParticle(node);
				for (n = node->first_node(); n; n = n->next_sibling()){
					if (getText(n->name()) == "Animation"){
						addAnimation(n, &particleList);
					}
				}
			} //else if (s == "NPC"){
		}
	}catch(...){
		cout << "Particle [" << id << "] did not load properly."<< endl;
	}
}

void EntityLoader::buildParticle(rapidxml::xml_node<> * node){
	rapidxml::xml_attribute<> *a;;
	Identity identity = {"", 255, -1, 2};
	MotionMax mm = {1, 1};	
	Size size;
	for (a = node->first_attribute(); a; a = a->next_attribute()){
		string s = getText(a->name());
		if (s == "name"){
			identity.name = getText(a->value());
			identity.type = particleCount; particleCount++;
		}else if (s == "speed"){
			mm.speed = getFloat(a->value());
		}else if (s == "accel"){
			mm.accel = getInt(a->value());
		}else if (s == "col")
			size.colR = getFloat(a->value());
		else if (s == "sep")
			size.sepR = getFloat(a->value());	
		else if (s == "avo")
			size.avoR = getFloat(a->value());
	}
	if (true) {			
		particleList.addSize(size); 
		particleList.addIdentity(identity);
		particleList.addMotion(mm); 
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
		else if (grid == "5x5")
			sp.g = G5x5;
		else
			sp.g = G1x1;
	}
	return input;
}


void EntityLoader::addAnimation(rapidxml::xml_node<> * node, ParticleList * dict){
	rapidxml::xml_attribute<> *a;
	ID tex = 0;
	ID min = 0; ID max = 3;
	ID frames = 20;
	Animation anim;
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
		else if (s == "type"){
			s = getText(a->value());
			if (s == "Walk20"){
				anim.type = WALK20;
				anim.setFrameRate(frames);
			}
		}else
			loadShaderProfile(a, sp);
	}
	dict->addProfile(sp); 

	if (cyclic)
		anim.setCyclic(min, max, frames);

	dict->anim.push_back(anim);
}

void EntityLoader::loadAuxillary(rapidxml::xml_node<> * node){


}
