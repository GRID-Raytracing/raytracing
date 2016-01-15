#ifndef OBJECT_H
#define OBJECT_H

using namespace std;

namespace raytracing {
	
	class Object {
	protected:
		Vector3D position;
		
	public:
        //constructor
        Object(){}
        Object(Vector3D p): position(p) {}
        Vector3D getPosition() { return position;}
    };
}

#endif // OBJECT_H