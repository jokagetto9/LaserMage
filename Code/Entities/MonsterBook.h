#ifndef MONSTERBOOK_H
#define MONSTERBOOK_H

#include "../BaseEngine/Entities/Dictionaries.h"

//********************************* CONSTANTS *********************************


//********************************* INITIALIZATION *********************************

class MonsterBook : public Dictionary { 
public:

	void addProfile(ShaderProfile profile){profiles.push_back(profile);}

	static vector <Identity> & getID(){return names;}
	static vector <Identity> names; 		
	static vector <ID> auxTex;
	static vector <float> scale;
	static vector <Animation> anim;
	static vector <MotionMax> max; 		
		
	//static vector <string> actionType; 
	//static vector <string> aAnim; 
};


extern MonsterBook monBook;

#endif