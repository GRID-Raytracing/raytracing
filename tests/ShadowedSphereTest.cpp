#include "../Ray.h"
#include "../Observer.h"
#include "../Scene.h"
#include "../Sphere.h"
#include "../Constants.h"
#include "../PointLightSource.h"
#include "../drawableObject.h"
#include <iostream>


using namespace raytracing;

int main(){
    Scene* scene = Scene::getInstance();
    Sphere* sphere = new Sphere(Vector3D(0,0,4),0.0, Color(255,0,0), 0.0, 1.0);
    scene->addDrawableObject(sphere);
    PointLightSource* pointLight = new PointLightSource(Vector3D(0,0,0),0.0,Color(1,1,1),0.0);
    scene->addLightSource(pointLight);
    if(DEBUG) cout << "starting Rendering" <<endl;
    scene->getObserver().render();
    scene->getObserver().exportImage("ShadowedSphereTest.bmp", "bmp");
    return 0;
}
