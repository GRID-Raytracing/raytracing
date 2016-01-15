#include "drawableObjects.h"
#include "LightSource.h"
#include "Observer.h"

namespace raytracing{
class Scene{

private:
	int numberofObjects;
	int numberofLightsources;
	Observer obs;
	drawableObjects drawableObjects[numberofObjects];
	Scene theScene;
	LightSource lights[numberofLightsources];

public:
	Scene getInstance() { return this; }
};
}
