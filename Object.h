#ifndef OBJECT_H
#define OBJECT_H

#include "Vector3D.h"

using namespace std;

namespace raytracing {
	
	class Object {
	protected:
        Vector3D position;
        
	public:
        //constructor
        Object(){}
        Object(Vector3D p): position(p) {}
        //get
        Vector3D getPosition() { return position;}
    };
}

#endif // OBJECT_H
