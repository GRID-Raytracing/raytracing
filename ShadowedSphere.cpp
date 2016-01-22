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
			double cosAngle = -1*((i-position).normalise()*(light->getPosition()-i).normalise());
			cosAngle = (cosAngle>0)?cosAngle:0;
			if(DEBUG) cout<< "cos(Angle): " <<cosAngle<<endl;
			if(DEBUG) cout << "Color: " << color.R()<<","<<color.G()<<","<<color.B()<<endl;
			if(DEBUG) cout << "Light: " << light->getColor().R()<<","<<light->getColor().G()<<","<<light->getColor().B()<<endl;
			Color temp = cosAngle*color*light->getColor();
			if(DEBUG) cout << "illumination: " << temp.R()<<","<<temp.G()<<","<<temp.B()<<endl;
			diffuse += temp;
		}
		
	}
	if(DEBUG) cout << "Result: " << diffuse.R()<<","<<diffuse.G()<<","<<diffuse.B()<<endl;
	return diffuse;
	
}

bool ShadowedSphere::isShadowed(Ray r, LightSource* light) {
	//TODO: IMPLEMENT THIS
	return false;
    
	double lightIntersect = light->intersection(r);
	if(DEBUG) cout << "light intersetion: "<<lightIntersect<<endl;
	Scene* scene = Scene::getInstance();
	vector<drawableObject*>& objects = scene->getDrawableObjects();
	for(drawableObject* object : objects) {
		if(object->intersection(r) > lightIntersect) return true;
	}
	return false;
}
