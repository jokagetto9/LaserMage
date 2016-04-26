#ifndef ENEMY_H
#define ENEMY_H


#include "Hero.h"

//********************************* CONSTANTS *********************************

enum EnemyType {CHUCKY, MOSQUITO, TRUNKLING, LABOMBA, MIMIC };

//********************************* INITIALIZATION *********************************
class Enemy : public Mob {
	public: 
	Enemy::			Enemy();
	void Enemy::	init(EnemyType t);
	void Enemy::	init(float theta, float dist);
	void Enemy::aiUpdate(float aiDelta);

	void Enemy:: crash ();
	EnemyType eType;

};
#endif