#include "ShadowedSphere.h"
#include "Scene.h"
#include "LightSource.h"
#include <iostream>

using namespace raytracing;

Color ShadowedSphere::getColorAtIntersection(Vector3D i, Ray r) {
	Scene* scene = Scene::getInstance();
	vector<LightSource*>& lights = scene->getLightSources();
	
	Color diffuse = Color();
	
	for(LightSource* light : lights){
		if(!isShadowed(Ray(i,(light->getPosition()-i).normalise(),1), light)){
			if(DEBUG) cout<< "Not in Shadow."<<endl;
			double cosAngle = (i-position).normalise()*(light->getPosition()-i).normalise();
			if(DEBUG) cout<< "cos(Angle): " <<cosAngle<<endl;
			cosAngle = (cosAngle>0)?cosAngle:0;
			diffuse += cosAngle*color*light->getColor();
		}
		
	}
	if(DEBUG) cout << "Color: " << diffuse.R()<<","<<diffuse.G()<<","<<diffuse.B()<<endl;
	return diffuse;
	
}

bool ShadowedSphere::isShadowed(Ray r, LightSource* light) {
	//TODO: IMPLEMENT THIS
	return false;
}
