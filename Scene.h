#include <iostream>

using namespace std;


class Scene{

private:
	int numberofObjects;
	int numberofLightsources;
	Observer obs;
	drawableObjects drawableObjects[numberofObjects];
	Scene theScene;
	LightSource lights[numberofLightsources];

public:
	getInstance(); 




};
