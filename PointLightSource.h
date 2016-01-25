#ifndef POINTLIGHTSOURCE_H
#define POINTLIGHTSOURCE_H

#include "LightSource.h"

namespace raytracing {
	
	class PointLightSource: public LightSource {
	public:
		PointLightSource(Vector3D pos, double ref, Color cl, double tr) : LightSource(pos,ref,cl,tr) {};
		PointLightSource(){};
	

    virtual void serialize(const string &indent){
      string i=indent + "  ";
      beginObject();
      writeIdentifier("LightSource", i); LightSource::serialize(i);
      endObject(indent);
    }
    virtual void deserialize(){
      string nextId;
      expectObjectBegin();
      do {
        nextId =readIdentifier();
        cerr << "Deserialize PointLightsource<" << nextId << ">" << nextId.compare("LightSource") << endl;
        if (nextId.compare("}") == 0) return;
        if (nextId.compare("LightSource") == 0) LightSource::deserialize();
      } while (true);
    }
    virtual const string type(){ return "PointLightSource"; };

  };

}

#endif