#ifndef MODELMANAGER_H
#define MODELMANAGER_H

#include "../System/lib.h"
//#include "MenuShader.h"
//********************************* CONSTANTS *********************************
//********************************* EXTERNAL *********************************
//********************************* INITIALIZATION *********************************
class ModelManager {
public:
	//singleton
	static ModelManager* ModelManager::I(){
		if(instance == 0){
			instance = new ModelManager();
			return instance;
		}return instance;	}
	void ModelManager::quit();

//************************************************** MEMBERS ***************************************************
		
	//MenuShader menuShader;

private:
	ModelManager::ModelManager(){}
	static ModelManager* instance ;
};

extern ModelManager* M;

#endif