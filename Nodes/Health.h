#ifndef HEALTH_H
#define HEALTH_H
#include "../lib.h"
/*/
instant boost
healtholism
digestion rate
//*/

//********************************* CONSTANTS *********************************
struct BuffProfile{
	int statID;
	int bufDur;
	int bonus;
	bool active;
};
//const Health BASEHEALTH = {200, 200, 4, 20, 20, 	200, 200, 0, 20, 20}; 

//********************************* INITIALIZATION *********************************

class Health  {
	public: 
	Health::		Health();

	void Health::	update();
	void Health::	slowUpdate();

	void Health::	digest();
	void Health::	digest(int id);
	void Health::	activateBuff();
	void Health::	updateBuff();
/*/ Purpose: 
/*/
//************************************************** MEMBERS ***************************************************
		int ms125;
		// fatigue over time -> restored by sleep
		float sleepiness;
		float fullness, maxFull;
		//Level hunger;

		int maxLife, maxStamina, maxPain, maxAction, maxMana;
		float life, stamina, pain, action, mana;
	
		vector <int> digestion;
		vector <BuffProfile> buffs;

//********************************* MEMBER FUNCTIONS *********************************
	


};
#endif