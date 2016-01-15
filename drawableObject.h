#ifndef DRAWABLE_OBJECT_H
#define DRAWABLE_OBJECT_H

#include "Color.h"
#include "Vector3D.h"
#include "Ray.h"

namespace raytracing {

class drawableObject: public Object {

protected:
	double reflectivity;
	Color color;
	double transparency;
public:
	virtual double intersection (Ray r);
	virtual Color getColorAtIntersection( Vector3D intersection, Ray r);
};}

#endif //DRAWABLE_OBJECT_H
