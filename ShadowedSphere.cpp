#include "ShadowedSphere.h"
#include "Scene.h"
#include "LightSource.h"

using namespace raytracing;

Color ShadowedSphere::getColorAtIntersection(Vector3D i, Ray r) {
	Scene* scene = Scene::getInstance();
	vector<LightSource*>& lights = scene->getLightSources();
	
	Color diffuse = Color();
	
	for(LightSource* light : lights){
		if !isShadowed(Ray(i,(light->getPosition()-i).normalize()), light){
			double cosAngle = (i-position).normalise()*(light->getPosition()-i).normalise();
			cosAngle = (cosAngle>0)?cosAngle:0;
			diffuse += cosAngle*color*light->getColor();
		}
	}
	
	return diffuse;
	
}
