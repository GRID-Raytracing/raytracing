#ifndef SHADOWEDSPHERE_H
#define SHADOWEDSPHERE_H

#include "Sphere.h"
#include "Color.h"
#include "Vector3D.h"
#include "Ray.h"

namespace raytracing {

	class ShadowedSphere : public Sphere {
	
	public:

		virtual Color getColorAtIntersection(Vector3D i, Ray r) override;
	};

}


#endif //SHADOWEDSPHERE_H
