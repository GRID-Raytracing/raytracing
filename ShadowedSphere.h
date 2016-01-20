#ifndef SHADOWEDSPHERE_H
#define SHADOWEDSPHERE_H

#include "Sphere.h"
#include "Color.h"
#include "Vector3D.h"
#include "Ray.h"
#include "LightSource.h"

namespace raytracing {

	class ShadowedSphere : public Sphere {
	
	public:
		ShadowedSphere(Vector3D pos, double ref, Color col, double t, double r) : Sphere(pos, ref, col, t, r) {};
		virtual Color getColorAtIntersection(Vector3D i, Ray r) override;
		virtual bool isShadowed(Ray r, LightSource* light);
	};

}


#endif //SHADOWEDSPHERE_H
