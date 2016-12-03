#ifndef WAVETRACKER_H
#define WAVETRACKER_H

#include "../BaseEngine/Template/SubObj.h"


class WaveTracker: public Observer{
public:
	WaveTracker::WaveTracker(){}
	void WaveTracker::onNotify(GridData& data){ 
		ID g = data.group;
		if( g <  waves.size()){
			ID s = waves[g].size();
			vector <ID> & enemies = waves[g].members;
			for (ID i = 0; i < s; i++){
				if (enemies[i] == data.index){
					enemies.erase(enemies.begin()+i);
					i = s;
				}
			}
		}
	}



  void update() {



  }

  vector <EnemyWave> waves;

};

#endif