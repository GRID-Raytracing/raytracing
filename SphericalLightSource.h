#ifndef SPHERICALLIGHTSOURCE_H
#define SPHERICALLIGHTSOURCE_H

#include LightSource.h
#include Sphere.h
#include Color.h
#include Vector3D.h
#include Ray.h

namespace raytracing {
	
	class SphericalLightSource: public LightSource, public Sphere {
		
	public:
		virtual Color getColorAtIntersection(Vector3D intersection, Ray r) {return color;};
	
	}

}

#endif //SPHERICALLIGHTSOURCE_H