#ifndef LIGHTSOURCE_H
#define LIGHTSOURCE_H

#include "Color.h"
#include "Vector3D.h"
#include "drawableObject.h"

namespace raytracing {
	
	class LightSource: public drawableObject {
      // constructor
      LightSource(Vector3D pos, double ref, Color cl, double tr) :
        drawableObject(pos, ref, cl, tr) {}		
	};

}

#endif //LIGHTSOURCE_H
