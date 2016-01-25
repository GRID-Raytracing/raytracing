#ifndef LIGHTSOURCE_H
#define LIGHTSOURCE_H

#include "Color.h"
#include "Vector3D.h"
#include "drawableObject.h"
#include "Serializable.h"

namespace raytracing {
	
	class LightSource: public drawableObject {
      // constructor
	public:
		LightSource(Vector3D pos, double ref, Color cl, double tr) :
        	drawableObject(pos, ref, cl, tr) {}
        	LightSource(){}

  virtual void serialize(const string &indent){
    string i=indent + "  ";
    beginObject();
    writeIdentifier("drawableObject", i); drawableObject::serialize(i);
    endObject(indent);

  }
  virtual void deserialize(){
    cerr << "Deserialize Lightsource" << endl;
    string nextId;
    expectObjectBegin();
    do {
      nextId =readIdentifier();
      cerr << "Deserialize Lightsource<" << nextId << ">" << nextId.compare("drawableObject") << endl;
      if (nextId.compare("}") == 0) return;
      if (nextId.compare("drawableObject") == 0) drawableObject::deserialize();
    } while (true);
  }
	virtual const string type(){ return "LightSource"; };

	  
	};
}

#endif //LIGHTSOURCE_H
