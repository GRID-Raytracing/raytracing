#include "../Ray.h"
 #include "../Observer.h"
 #include "../Scene.h"
 #include "../Sphere.h"
 #include "../Constants.h"
 #include "../PointLightSource.h"
 #include "../drawableObject.h"
 #include "../Observer.h"
 #include <iostream>
 
 
 using namespace raytracing;
 using namespace std;
 
 int main(){
	 Scene* scene = Scene::getInstance();
	 
	 for(i=0; i<10; i++) {
	 	for(j=0; j<10; j++) {
	 		scene->addDrawableObject(new Sphere(Vector3D(-5+i,-5+j,10),0.8, Color(rand(),rand(),rand()), 0.0, 1.0);
	 	}
	 }
	 Observer observer(Vector3D(0,0,0),Vector3D(0,0,1), 1.0, Vector3D(0.001,0,0), Vector3D(0,0.001,0), 1000, 1000);
	 scene->setObserver(observer);
	 PointLightSource* pointLight = new PointLightSource(Vector3D(0,0,0),0.0,Color(1,1,1),0.0);
	 scene->addLightSource(pointLight);
	 if(DEBUG) cout << "starting Rendering" <<endl;
	 scene->getObserver().render();
	 scene->getObserver().exportImage("SphereField.bmp", "bmp");
	 return 0;
 }
