#ifndef SCENE_H
#define SCENE_H

#include<vector>
#include "Vector3D.h"
#include "Ray.h"
#include "Observer.h"
#include "drawableObject.h"
#include "LightSource.h"

namespace raytracing{
    
class Scene{

private:
	Observer obs;
	static Scene* theScene;
	std::vector<drawableObject> drawableObjects;
	std::vector<LightSource> lights;
	Scene(Observer o, std::vector<drawableObject> dO, std::vector<LightSource> l);


public:
	~Scene() {theScene = nullptr;};
	static Scene* getInstance();
	std::vector<drawableObject>& getDrawableObjects() {return drawableObjects;}
	std::vector<LightSource>& getLightSources() {return lights;}
        Observer& getObserver() {return obs;};
        
        void setObserver(Observer& o) {obs = o;};
};


}

#endif //SCENE_H
