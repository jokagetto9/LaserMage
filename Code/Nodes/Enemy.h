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
	void Enemy::	radialOffset(float theta, float dist, glm::vec3 p);
	void Enemy::	setTarget(const glm::vec3 pos);
	void Enemy::aiUpdate(float aiDelta);

	void Enemy:: crash ();

private:
	EnemyType eType;
	glm::vec3 targetP;

};
#endif