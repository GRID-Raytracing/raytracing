#include "../Ray.h"
#include "../Observer.h"
#include "../Scene.h"
#include "../Sphere.h"
#include "../Constants.h"
#include <iostream>


using namespace raytracing;

int main(){
    Scene* scene = Scene::getInstance();
    Sphere* sphere1 = new Sphere(Vector3D(0.5,0,4),0.0, Color(255,0,0), 0.0, 1.0);
    Sphere* sphere2 = new Sphere(Vector3D(-0.5,0,5),0.0, Color(0,0,255), 0.0, 1.0);
    
    scene->addDrawableObject(sphere1);
    scene->addDrawableObject(sphere2);
    
    if(DEBUG) cout << "starting Rendering" <<endl;
    scene->getObserver().render();
    scene->getObserver().exportImage("simpleSphereTest.bmp", "bmp");
    return 0;
}
