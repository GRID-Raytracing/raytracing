#include "Color.h"

namespace raytracing {
	
	class LightSource: public drawableObject {
      // constructor
      LightSource() {}
      LightSource(double ref, Color cl, double tr) :
        drawableObject(ref, cl, tr) {}		
	};

}
