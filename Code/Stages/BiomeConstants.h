#ifndef BIOMECONSTANTS_H
#define BIOMECONSTANTS_H


#include "../Legend/h.h"

enum NodeType {_n, _nub, _mininub, _nob, _mininob, _building, _sprite};

enum NUBS {ROCK, TREE, EVERGREEN, GREATTREE, DEADTREE, TALLTREE, TALLDEADTREE, WTFPLANT, CACTUS};
enum MININUBS {WEED, FLOWER, MUSHROOM}; 

enum Biome {TOWN, FIELD1, FIELD2, FOREST1, FOREST2, DARKFOREST1, DARKFOREST2, DARKFOREST3, THEDEEP, THEDARK, KEEP, ARID};
enum BiomeContext {PLANE, TOWN1, TOWN2, TOWN3, CNS, CWE, CNW, CSW, CSE, CNE, WFORK, EFORK, NFORK, SFORK, LAKE,  THEKEEP}; 

//enum _BUILDINGS_ {_TOWN, _LAKE, _WINDMILL, _FARM, _RANCH, _TUNNEL, _EMPTY, _WELL, _BOULDER, _LOGGER, _HUNTER, _FISHER,
			//_MONUMENT, _GRAVEYARD, _DEN, _HOLE, _PIT, _TOWER, _DUNGEON, _ELEMENTAL, _PORTAL};

enum _POI { _EMPTY, _FARM, _RANCH, _LOGGER, _HUNTER, _FISHER, _WELL, _BOULDER, _DEN, _HOLE, _PIT, 
			_TOWN, _LAKE, _WINDMILL, _MONUMENT, _TUNNEL, _GRAVEYARD,  _TOWER};
const string _POI_NAMES [] =  {"Empty Shack", "Farm House", "Ranch", "Logging Shack", "Hunting Shack", "Fishing Shack", "Abandoned Well", "Big...Rock",
	"Animal Den", "Big Scary Hole", "Monster Pit", "Town", "Lake", "Windmill", "Monument", "Tunnel", "Graveyard", "Tower"};
enum _HIDDEN_POI {_NOTHING, _TREASURE, _ELEMENTAL, _PORTAL, _DUNGEON};
enum BUILDINGS {TENT, HUT, HOUSE, BARN, WINDMILL, BOOTH, SHOP, WELL };// TOWER, TAVERN, POND, PIER};
enum NOBS {CHAIR, STOOL, CRATE, /*BARREL,*/TABLE, BED, BAR, CABINET, BOOKSHELF, FIREPLACE, FRAME, SHELF, BEAMS};
enum WALLNOBS {FENCE, WALL, CLIFF};
enum MININOBS {CUP, BOWL, BOTTLE, POT, BOOK, VASE, HAYBAIL};


struct POI {
	XZI xz;
	Drctn d;
	_POI _p;
	_HIDDEN_POI _h;
	int _pRank;
	int _hRank;
};



//move to shader
struct NubProfile {
	float scale;
	XZI i;
};
const NubProfile N_ROCK = {1.4};
const NubProfile N_TREE = {9};
const NubProfile N_PINE = {5};
const NubProfile N_GREAT = {7}; 
const NubProfile N_DEAD = {9, 		G4_0}; 
const NubProfile N_TALL = {9,		G4_1}; 
const NubProfile N_TALLDEAD = {5.5,	G4_2}; 
const NubProfile N_WTF = {9, 		G4_3}; 
const NubProfile N_CACTUS = {2.5}; 
const NubProfile N_[] = {N_ROCK, N_TREE, N_PINE, N_GREAT, N_DEAD, N_TALL, N_TALLDEAD, N_WTF, N_CACTUS}; 

		
#endif