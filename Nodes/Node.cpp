//********************************* INITIALIZATION *********************************
#include "Node.h"
Node::Node(){		
	id = -1;
	xPos = 0; 	zPos = 0;
	yPos = 0;
	scale = 1; theta = 0;
	dir = DUNNO;
	type = _n;
}


//********************************* MEMBER FUNCTIONS *********************************

void Node::	setPlot(int x, int z){ 
	xPos += PLOT * x;  zPos += PLOT * z;
	plot.x = x; plot.z =z;
}

void Node::	setStage(int x, int z){ 	xPos = ZONE * x;  zPos = ZONE * z;	}

XZI Node::find(){ 
	XZI zone;//why return zone?
	zone.x = floor(xPos/ZONE);				zone.z = floor(zPos/ZONE);
	float x = xPos - zone.x*ZONE;			float z = zPos - zone.z*ZONE;
	plot.x = floor(x/PLOT);					plot.z = floor(z/PLOT);
	return zone;
}

void Node::adjustPos(Drctn d, int dist){	
	xPos += ADJ_[d].x * dist;	
	zPos += ADJ_[d].z * dist; 
}


void Node::offset(float x, float z){	
	if (dir == NORTH) {
		xPos += x; zPos += z;
	} else if (dir == SOUTH){
		xPos += 50-x; zPos += 50-z;
	} else if (dir == WEST){
		xPos += z; zPos += 50-x;
	} else if (dir == EAST){
		xPos += 50-z; zPos += 50-x;
	} 
}



//********************************* EXTERNAL *********************************



int getCorner(XZI plot){
	if (plot.x < 5){
		if (plot.z < 5) return 0; 
		else return 2;
	} else {
		if (plot.z < 5) return 1; 
		else return 3;
	}
}