#ifndef SCENE_H
#define SCENE_H

#include<vector>
#include "Observer.h"
#include "drawableObject.h"
#include "LightSource.h"

namespace raytracing{
class Scene{

private:
	Observer* obs;
	static Scene* theScene;
	std::vector<drawableObject> drawableObjects;
	std::vector<LightSource> lights;
	Scene(Observer* o, std::vector<drawableObject> dO, std::vector<LightSource> l):
		obs(o), drawableObjects(dO), lights(l) {theScene = this;};


public:
	~Scene() {theScene = nullptr;};
	static Scene& getInstance() { 
		if(theScene != nullptr) theScene= new Scene(nullptr, *new std::vector<drawableObject>, *new std::vector<LightSource>);
		return *theScene;
	}
	std::vector<drawableObject>& getDrawableObjects() {return drawableObjects;}
	std::vector<LightSource>& getLightSources() {return lights;}
};
}

#endif //SCENE_H
