#ifndef OBJECT_H
#define OBJECT_H

#include "Vector3D.h"

using namespace std;

namespace raytracing {
	
	class Object : public Serializable {
	protected:
        Vector3D position;
        
	public:
        //constructor
        Object(Vector3D& p): position(p) {}
        //get
        Vector3D getPosition() { return position;}
        virtual void serialize(const string &indent = "");
        virtual void deserialize();
    };
}

#endif // OBJECT_H
