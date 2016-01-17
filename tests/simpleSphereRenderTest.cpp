#include "../Ray.h"
#include "../Observer.h"
#include "../Scene.h"
#include "../Sphere.h"
#include "../Constants.h"
#include <iostream>


using namespace raytracing;

int main(){
    Scene* scene = Scene::getInstance();
    Sphere* sphere = new Sphere(Vector3D(0,0,4),0.0, Color(255,0,0), 0.0, 1.0);
    Ray ray(Vector3D(0,0,0), Vector3D(0,0,1), 1);
    sphere->intersection(ray);
    scene->addDrawableObject(sphere);
    if(DEBUG) cout << "starting Rendering" <<endl;
    scene->getObserver().render();
    scene->getObserver().exportImage("simpleSphereTest.bmp", "bmp");
    return 0;
}