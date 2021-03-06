

#include "drawableObject.h"
#include "LightSource.h"
#include "Scene.h"

namespace raytracing {

  void drawableObject::serialize(const string &indent){
    string i=indent + "  ";
    beginObject();
    writeIdentifier("Object", i); Object::serialize(i);
    writeIdentifier("Color", i); color.serialize(i);
    writePair("reflectivity", reflectivity, i);
    writePair("transparency", transparency, i);
    endObject(indent);

  }
  void drawableObject::deserialize(){
    cerr << "Deserialize drawableObject" << endl;
    string nextId;
    expectObjectBegin();
    do {
      nextId =readIdentifier();
      cerr << "Deserialize drawableObject<" << nextId << ">" << nextId.compare("Object") << endl;
      if (nextId.compare("}") == 0) return;
      if (nextId.compare("Object") == 0) Object::deserialize();
      if (nextId.compare("Color") == 0) color.deserialize();
      if (nextId.compare("reflectivity") == 0)  reflectivity=readDouble();
      if (nextId.compare("transparency") == 0)  transparency=readDouble();
    } while (true);
  }
  
  Color drawableObject::getColorAtIntersection(Vector3D i, Ray r) {
	  Scene* scene = Scene::getInstance();
	  vector<LightSource*>& lights = scene->getLightSources();
	  if(DEBUG) cout << "Intersection: "<<i<<endl;
	  //diffuse color
	  Color diffuse = Color();
	  for(LightSource* light : lights){
		  if(!isShadowed(Ray(i,(light->getPosition()-i).normalise(),1), light)){
			  //if(DEBUG) cout<< "Not in Shadow."<<endl;
			  Vector3D normal = getNormalVectorAtPoint(i);
			  double cosAngle = (normal*(light->getPosition()-i).normalise());
			  cosAngle = (cosAngle>0)?cosAngle:0;
			  //if(DEBUG) cout<< "cos(Angle): " <<cosAngle<<endl;
			  //if(DEBUG) cout << "Color: " << color.R()<<","<<color.G()<<","<<color.B()<<endl;
			  //if(DEBUG) cout << "Light: " << light->getColor().R()<<","<<light->getColor().G()<<","<<light->getColor().B()<<endl;
			  Color temp = cosAngle*color*light->getColor();
			  //if(DEBUG) cout << "illumination: " << temp.R()<<","<<temp.G()<<","<<temp.B()<<endl;
			  diffuse += temp;
		  }
		  
	  }
	  //if(DEBUG) cout << "Result: " << diffuse.R()<<","<<diffuse.G()<<","<<diffuse.B()<<endl;
	  
	    
	  
	  return diffuse+getReflectionAtIntersection(i,r);
	  
  }
  
  bool drawableObject::isShadowed(Ray r, LightSource* light) {
	  
	  double lightIntersect = light->intersection(r);
	  //if(DEBUG) cout << "light intersetion: "<<lightIntersect<<endl;
	  if(lightIntersect == -2) {
		  cerr<<"Warning: intersection() not implemented for this class! Falling back to drawableObject..."<<endl;
		  
	  }
	  if(lightIntersect < 0) {
		  cerr<<"Warning: nonsensical value for intersection with light source. Assuming no shadow."<<endl;
		  return false;
	  }
	  Scene* scene = Scene::getInstance();
	  vector<drawableObject*>& objects = scene->getDrawableObjects();
	  for(drawableObject* object : objects) {
		  if(object->intersection(r) > lightIntersect) return true;
	  }
	  return false;
  }
  
  Color drawableObject::getReflectionAtIntersection(Vector3D i, Ray r) {
  	 Color reflectedColor(0,0,0);
	  if(reflectivity>0 && r.getStep()>0){
	      Vector3D normal = getNormalVectorAtPoint(i);
		  if(DEBUG) cout <<"Normal Vector:"<< normal.X()<<", "<<normal.Y()<<", "<<normal.Z()<<endl;
	      Vector3D incident = r.getDirection().normalise();
		  if (DEBUG) cout <<"Incident Vector:"<<incident.X()<<", "<<incident.Y()<<", "<<incident.Z()<<endl;
	      Vector3D reflected = incident-2*(normal*incident)*normal;
	      Ray reflectionRay(i,reflected,r.getStep()-1);
	      reflectedColor = reflectionRay.trace();
	  }
	  return reflectivity*reflectedColor;
  }

}

