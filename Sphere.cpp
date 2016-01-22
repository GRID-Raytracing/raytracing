#include "drawableObject.h"
#include "Sphere.h"
#include "Constants.h"
#include <cmath>
#include <iostream>


//http://www.vcl.jp/~kanazawa/raytracing/?page_id=78

namespace raytracing {

    double Sphere::intersection(Ray r){
            //Ray: o(vec.origin) + d(vec.direction) * t = p
            //Sphere: ( p - s(vec.position) )^2 = r(radius)^2
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
            //r(radius)
            double rad = getRadius();

            //calculate intersection point
            double A,B,C,D;
            //A:
            A = d*d;
            //B:
            B = 2*( o*d - s*d );
            //C:
            C = o*o + s*s - 2*( o*s ) - rad*rad;
            //D:
            D = B * B - 4*A*C;

            //
            double t=-5;
            if(D < 0) {
                    //no intersection point
                    t = -3.0;
                    //if(DEBUG) cout << "Ray has missed!" <<endl;
            }
            else if(D >= 0){
                    double t1 = (-B + sqrt(D)) / (2*A);
                    double t2 = (-B - sqrt(D)) / (2*A);
                    t = (t1>t2)?t1:t2;
                    if(DEBUG) cout << "Ray has hit!" << endl;
            }

            return t;

    }
    
    Color Sphere::getColorAtIntersection(Vector3D i, Ray r) {
        return color;
    }

  void Sphere::serialize(const string &indent){
    string i=indent + "  ";
    beginObject();
    writeIdentifier("drawableObject", i); drawableObject::serialize(i);
    writePair("radius", radius, i, true);
    endObject(indent);

  }
  void Sphere::deserialize(){
    string nextId;
    expectObjectBegin();
    do {
      nextId =readIdentifier();
      if(DEBUG) cout<<"Sphere::deserialize: "<<nextId<<endl;
      if (nextId.compare("drawableObject") == 0) drawableObject::deserialize();
      if (nextId.compare("}") == 0) return;
      if (nextId.compare("radius") == 0)  radius=readDouble();
    } while (true);
  }

    
}
