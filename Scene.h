#ifndef SCENE_H
#define SCENE_H

#include<vector>
#include "Observer.h"
#include "drawableObject.h"
#include "LightSource.h"

namespace raytracing{
class Scene{

private:
	Observer obs;
	static Scene theScene;
	std::vector<drawableObject> drawableObjects;
	std::vector<LightSource> lights;

public:
	static Scene getInstance();
	std::vector<drawableObject>& getDrawableObjects() {return drawableObjects;}
	std::vector<LightSource>& getLightSources() {return lights;}
};
}

#endif //SCENE_H
