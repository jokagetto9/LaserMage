#ifndef H_H
#define H_H

#include "lib.h"


typedef void (*voidf) ();


enum MenuCommand {PLAY, EXIT, TITLE, MAIN, SYS, STORE, DLG, DBG }; //when not exit
enum MenuType {QUIT, STAT, EQP, INV, LOOT, RELIC, SKLS, JRNL, ACTIVEEQP, ACTIVEITM, USE, SHOPEQP, SHOPLOOT, CNFM, NUMSLCT, PASS};
//********************************* DIMENSIONS AND DIRECTIONS *********************************


const int WIDTH = 1000;		
const int HEIGHT = 700;	

const float pi = 3.1415926535897932384626433832795;

const int PLOT = 50;
const int SECT = 100;
const int ZONE = 500;
const int WORLD = 12500;



struct Level{
	int lv; 	int xp;
};
const Level z3r0 = {1, 0};







#endif
