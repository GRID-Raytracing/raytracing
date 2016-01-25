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
 
 int main(){
	 Scene* scene = Scene::getInstance();
	 Sphere* sphere = new Sphere(Vector3D(1,0,5),0.0, Color(1,0,0), 0.0, 1.0);
	 Sphere* refSphere = new Sphere(Vector3D(-1,0,5),1.0, Color(0.5,0.5,0.5), 0.0, 1.0);
	 scene->addDrawableObject(sphere);
	 scene->addDrawableObject(refSphere);
	 Observer observer(Vector3D(0,0,0),Vector3D(0,0,1), 1.0, Vector3D(0.001,0,0), Vector3D(0,0.001,0), 1000, 1000);
	 scene->setObserver(observer);
	 PointLightSource* pointLight = new PointLightSource(Vector3D(0,0,0),0.0,Color(1,1,1),0.0);
	 scene->addLightSource(pointLight);
	 if(DEBUG) cout << "starting Rendering" <<endl;
	 scene->getObserver().render();
	 scene->getObserver().exportImage("ReflectiveSphereTest.bmp", "bmp");
	 return 0;
 }
 