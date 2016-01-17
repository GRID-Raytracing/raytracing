#include "Scene.h" 

namespace raytracing {
    
    Scene* Scene::theScene = nullptr;

    
    Scene::Scene(Observer o, std::vector<drawableObject*> dO, std::vector<LightSource*> l):
		obs(o), drawableObjects(dO), lights(l) {}
		
    Scene* Scene::getInstance() { 
		if(theScene == nullptr) theScene = new Scene(Observer(), std::vector<drawableObject*>(), std::vector<LightSource*>());
		return theScene;
	}
}
