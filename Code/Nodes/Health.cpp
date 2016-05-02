#include "Health.h"

Health ::		Health (){
	ms125 = 0;
	maxLife	= 200;		life = 200;
	maxStamina = 200;	stamina = 200;
	maxPain = 4;		pain = 0;
	maxAction = 20;		action = 20;
	maxMana = 20;		mana = 0;


	sleepiness = 0;
	fullness = 0;
	maxFull = 30;
//	hunger = z3r0;
}

void Health::	update(){
	ms125++; 
	if (ms125 >= 8){
		ms125 -= 8;
		digest();

		updateBuff();
	}
}

void Health::	slowUpdate(){
	sleepiness += 0.5;
}

//struct FoodProfile{
//	DigestionRank dRank;
//	int hunger;
//	int dur;
//};\

void Health::	digest(){
	int s = digestion.size();
	if (s > 0){
		if (digestion[0] == 0){
			activateBuff();
			digestion.erase(digestion.begin());
		} else{
			digestion[0]--;
			cout << digestion[0] << endl;
		}
	}
}

void Health::	digest(int id){
	int s = digestion.size();
	float t1 = 5; int t2 = 20;
	if (s > 0){
		for (int i = 1; i <= s; i++){
			t1 = t1 * 1.15;
		}
	}
	
	digestion.push_back(t1);
	BuffProfile bp = {6, 20, 1, false};
	buffs.push_back(bp);

}

void Health::	activateBuff(){
	
	int s = buffs.size();
	for (int i = 0; i < s; i++){
		if (!buffs[i].active){
			buffs[i].active = true;
			i = s;
		}
	}
}

void Health::	updateBuff(){
	int s = buffs.size();
	for (int i = 0; i < s; i++){
		if (buffs[i].active){
			buffs[i].bufDur--;
			stamina += buffs[i].bonus;
			if (buffs[i].bufDur == 0){
				buffs.erase(buffs.begin()+i);
				i--; s--;
			}
		}
	}



}