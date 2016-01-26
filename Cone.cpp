#include "drawableObject.h"
#include "Cone.h"
#include "Constants.h"
#include <cmath>
#include <iostream>

namespace raytracing {

    double Cone::intersection(Ray r){
        //Ray: o(vec.origin) + d(vec.direction) * t = p
        //Column: ( p - s(vec.position) )^2 = r(radius)^2
        //Simultaneous equations with p
        //t = [ -B±√(B^2 - 4AC) ] / 2A
        //A = d^2
        //B = 2*( o*d - s*d )
        //C = o^2 + s^2 - 2*o*s - r^2
        
        //o(vec.origin)
        Vector3D o = r.getOrigin();
        //d(vec.direction)
        Vector3D d = r.getDirection();
        //s(vec.position)
        Vector3D s = getPosition();
        
		return 0.0;
    }
    
    void Cone::serialize(const string &indent){
        string i=indent + "  ";
        beginObject();
        writeIdentifier("drawableObject", i); drawableObject::serialize(i);
        endObject(indent);
        
    }
    void Cone::deserialize(){
        string nextId;
        expectObjectBegin();
        do {
            nextId =readIdentifier();
            if(DEBUG) cout<<"Cone::deserialize: "<<nextId<<endl;
            if (nextId.compare("drawableObject") == 0) drawableObject::deserialize();
            if (nextId.compare("}") == 0) return;
        } while (true);
    }
    
}
