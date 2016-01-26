#include "../Ray.h"
 #include "../Observer.h"
 #include "../Scene.h"
 #include "../Sphere.h"
 #include "../Constants.h"
 #include "../SphericalLightSource.h"
 #include "../drawableObject.h"
 #include "../Observer.h"
 #include <iostream>
 
 
 using namespace raytracing;
 using namespace std;
 
 int main(){
	 Scene* scene = Scene::getInstance();
	 
	 for(int i=0; i<10; i++) {
	 	for(int j=0; j<10; j++) {
	 		scene->addDrawableObject(new Sphere(Vector3D(-4.5+i,-4.5+j,11),0.8, Color(sin(i/10*2*3.141592),cos(j/10*2*3.141592),sin((i+j)/10*3.141592)), 0.0, 0.5));
	 	}
	 }
	 Observer observer(Vector3D(0,0,0),Vector3D(0,0,1), 1.0, Vector3D(0.001,0,0), Vector3D(0,0.001,0), 1000, 1000);
	 scene->setObserver(observer);
	 SphericalLightSource* sLight = new SphericalLightSource(Vector3D(0,0,0),0.0,Color(1,1,1),0.0,1.0);
	 scene->addLightSource(sLight);
	 if(DEBUG) cout << "starting Rendering" <<endl;
	 scene->getObserver().render();
	 scene->getObserver().exportImage("SphereField.bmp", "bmp");
	 return 0;
 }
