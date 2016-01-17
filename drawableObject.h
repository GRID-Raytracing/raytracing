#ifndef DRAWABLE_OBJECT_H
#define DRAWABLE_OBJECT_H

#include "Color.h"
#include "Vector3D.h"
#include "Ray.h"
#include "Object.h"
#include <iostream>
#include "Constants.h"

namespace raytracing {
    
class Ray; //forward declaration of Ray

class drawableObject: public Object {

protected:
	double reflectivity;
	Color color;
	double transparency;
public:
	drawableObject(Vector3D& pos, double& ref, Color& c, double& t): Object(pos), reflectivity(ref), color(c), transparency(t) {};
	virtual double intersection (Ray r) {
            if(DEBUG) cout<<"drawableObject called."<<endl;
            return -2;
            
        };
	virtual Color getColorAtIntersection( Vector3D intersection, Ray r) {return Color(0,0,0);};
};}

#endif //DRAWABLE_OBJECT_H
