#ifndef NODE_H
#define NODE_H


#include "../Display/Camera.h"
#include "../lib.h"

//********************************* CONSTANTS *********************************

const int rotDirIndex[4][4] = {
	{0, 1, 2, 3},
	{1, 0, 3, 2},
	{2, 3, 0, 1},
	{3, 2, 1, 0}
};


struct BoundingRad {
	glm::vec3 pos;
	float rsq;
	int id;	
};


//********************************* EXTERNAL *********************************

int getCorner(XZI plot);


//********************************* INITIALIZATION *********************************
class Node {
	public: 
	Node::			Node();
	

//************************************************** MEMBERS ***************************************************
	

	int id;
	float xPos, yPos, zPos;
	float scale, theta;
	Drctn dir;	
	XZI plot;


//********************************* MEMBER FUNCTIONS *********************************

	void Node::setID(int i){ id = i; }
	
	void Node::	pos(float x, float z){	xPos = x; 	zPos = z;  }
	void Node::	copyPos(Node &n){	xPos = n.xPos; 	zPos = n.zPos;  }		
	glm::vec3 Node::pos(){	return glm::vec3(xPos, yPos, zPos);}
	
	void Node::	push(int x, int z){	xPos += x; 	zPos += z; yPos += 0; }
	void Node::	setPlot(int x, int z);
	void Node::	setPlot(XZI xz){setPlot(xz.x, xz.z);}
	void Node::	setStage(int x, int z);
	void Node::	setStage(XZI xz){setStage(xz.x, xz.z);}
	void Node::place(XZI zo, int px, int pz){ setStage(zo); setPlot(px, pz); }
	void Node::place(XZI zo, XZI p){ place(zo, p.x, p.z); }


	void Node::translate(){ glPushMatrix(); glTranslatef(xPos, 0, zPos);}

	
	XZI Node::find();
	void Node::adjustPos(Drctn d, int dist);
	void Node::offset(float x, float z);



};
#endif