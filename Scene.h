#ifndef SCENE_H
#define SCENE_H

#include<vector>
#include "Serializable.h"
#include "Vector3D.h"
#include "Ray.h"
#include "Observer.h"
#include "drawableObject.h"
#include "LightSource.h"

namespace raytracing{
    
class Scene : public Serializable {

private:
	Observer obs;
	static Scene* theScene;
	std::vector<drawableObject*> drawableObjects;
	std::vector<LightSource*> lights;
	Scene(Observer o, std::vector<drawableObject*> dO, std::vector<LightSource*> l);


public:
	~Scene() {
            theScene = nullptr;            
        };
	static Scene* getInstance();
	std::vector<drawableObject*>& getDrawableObjects() {return drawableObjects;}
	std::vector<LightSource*>& getLightSources() {return lights;}
        Observer& getObserver() {return obs;};
        
        void setObserver(Observer& o) {obs = o;};
        void addDrawableObject(drawableObject* d) {drawableObjects.push_back(d);};
	virtual void serialize(const string &indent = "");
	virtual void deserialize();
	virtual const string type(){ return "Scene"; };
};


}

#endif //SCENE_H
