//********************************* INITIALIZATION *********************************
#include "Enemy.h"
Enemy::Enemy(){	
	dead = false;	
}


void Enemy::init(EnemyType t){
	speed = glm::vec3(0.0); prevPos = glm::vec3(0.0);	
	maxS = RUN_MAX_ACCEL;
	
	prevTheta = 0;
	
	targetV = glm::vec3(0);
	updateSpeedMode(0);
	if (t == MIMIC)
		walkAnim.init(CYCLIC);
	else 
		walkAnim.init(WALK12);

}

void Enemy::radialOffset(float theta, float dist, glm::vec3 p){
	//setTarget(p);
	glm::vec3 v = calcThetaV(theta);
	v *= dist; v += p;
	place(v.x, v.z);
}



void Enemy::	setTarget(const glm::vec3 pos){
	targetP = pos;
}


void Enemy::aiUpdate(float aiDelta){
	health.update()	;
	targetV = targetP - pos();	
	float maxChange = RUN_MAX_ACCEL * aiDelta;
	truncate (targetV, maxChange);
	crash();
}


void Enemy:: crash (){
	float d = getDistSQ(targetP);
	if (d < 3*3){
		dead = true;
	}
}