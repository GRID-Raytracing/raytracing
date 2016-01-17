#ifndef DRAWABLE_OBJECT_H
#define DRAWABLE_OBJECT_H

#include "Color.h"
#include "Vector3D.h"
#include "Ray.h"
#include "Object.h"

namespace raytracing {
    
class Ray; //forward declaration of Ray

class drawableObject: public Object {

protected:
	double reflectivity;
	Color color;
	double transparency;
public:
	drawableObject(Vector3D& pos, double& ref, Color& c, double& t): Object(pos), reflectivity(ref), color(c), transparency(t) {};
	virtual double intersection (Ray r) {return -1;};
	virtual Color getColorAtIntersection( Vector3D intersection, Ray r) {return -1;};
};}

#endif //DRAWABLE_OBJECT_H
