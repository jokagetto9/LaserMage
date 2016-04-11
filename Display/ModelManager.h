#ifndef MODELMANAGER_H
#define MODELMANAGER_H

#include "./Shaders/MenuShader.h"
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
		
	MenuShader menuBO;

private:
	ModelManager::ModelManager(){}
	static ModelManager* instance ;
};

extern ModelManager* M;

#endif