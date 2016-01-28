#include "drawableObject.h"
#include "Cylinder.h"
#include "Constants.h"
#include <cmath>
#include <iostream>

//http://www.vcl.jp/~kanazawa/raytracing/?page_id=19#toc-03476ddd7e79e9c8fa7d759966a93ba4-10

//  -----
//  |   |
//  | + |
//  |   |
//  -----
// ++ : s(vec.position)

namespace raytracing {

    double Cylinder::intersection(Ray r){
        //Ray:x=sx+tdx,y=sy+tdy,z=sz+tdz
        ////sx,sz,sz = o(vec.origin).X(),Y(),Z()
        ////dx,dy,dz = d(vec.direction).X(),Y(),Z()
        //Cylinder:(x−cx)^2+(z−cz)^2=r^2
        ////cx,cy,cz = s(vec.position).X(),Y(),Z()

        //Simultaneous equations with x,y,z
        //A * t^2 + B * t + C = 0
        //t = [ -B±√(B^2 - 4AC) ] / 2A
        
        //o(vec.origin)
        Vector3D o = r.getOrigin();
        //d(vec.direction)
        Vector3D d = r.getDirection();
        //s(vec.position)
        Vector3D s = getPosition();
        //rad(radius)
        double rad = getRadius();
        //h(height)
        double h = getHeight();
        
        //calculate intersection point
        double A,B,C,D,iy;
 
        //A:
        A = d.X()*d.X() + d.Z()*d.Z();
        //B:
        B = 2*d.X()*( o.X() - s.X() ) + 2*d.Z()*( o.Z() - s.Z() );
        //C:
        C = s.X() * s.X() + s.Z() * s.Z() - rad*rad + o.X()*( o.X() - 2*s.X() ) + o.Z()*( o.Z() - 2*s.Z() );
        //D:
        D = B * B - 4*A*C;
        //y distance between intersection and position
        
        double t=-5;
        if(D < 0) {
            //no intersection point
            t = -3.0;
            //if(DEBUG) cout << "Ray has missed!" <<endl;
        }
        else if(D >= 0){
            double t1 = (-B + sqrt(D)) / (2*A);
            double t2 = (-B - sqrt(D)) / (2*A);
            t = (t1<t2)?t1:t2;
            
            //intersection Y
            iy = o.Y() + t*d.Y();
            
            if( ( s.Y()-( h/2 ) ) <= iy && iy <= ( s.Y()+( h/2 ) )){
                if(DEBUG) cout << "Ray has hit!" << endl;
            }
            //ADD INTERSECTION CONDITION
            //intersection is out of the height of the Cylinder
            else{
                //no intersection point
                t = -3.0;
                //if(DEBUG) cout << "Ray has missed!" <<endl;
            }
        }
        
        return t;
        
    }
    
    void Cylinder::serialize(const string &indent){
        string i=indent + "  ";
        beginObject();
        writeIdentifier("drawableObject", i); drawableObject::serialize(i);
        endObject(indent);
        
    }
    void Cylinder::deserialize(){
        string nextId;
        expectObjectBegin();
        do {
            nextId =readIdentifier();
            if(DEBUG) cout<<"Cylinder::deserialize: "<<nextId<<endl;
            if (nextId.compare("drawableObject") == 0) drawableObject::deserialize();
            if (nextId.compare("}") == 0) return;
            if (nextId.compare("radius") == 0)  radius=readDouble();
            if (nextId.compare("height") == 0)  height=readDouble();
        } while (true);
    }
    
}
