#ifndef SPHERICALLIGHTSOURCE_H
#define SPHERICALLIGHTSOURCE_H

#include "LightSource.h"
#include "Sphere.h"
#include "Color.h"
#include "Vector3D.h"
#include "Ray.h"

namespace raytracing {

	class SphericalLightSource:  public Sphere, public LightSource {
	public:
		SphericalLightSource(Vector3D pos, double ref, Color col, double t, double r) :
    		Sphere(pos, ref, col, t, r), LightSource(pos,ref,col,t) {}
		virtual Color getColorAtIntersection( Vector3D i, Ray r) override {
			return (LightSource::color+Sphere::getReflectionAtIntersection(i,r));
		};
		virtual double intersection (Ray r) {return Sphere::intersection(r);}
		virtual Vector3D getNormalVectorAtPoint(Vector3D i) {return Sphere::getNormalVectorAtPoint(i);}
	};

}

#endif //SPHERICALLIGHTSOURCE_H