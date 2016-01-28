#include "drawableObject.h"
#include "Cone.h"
#include "Constants.h"
#include <cmath>
#include <iostream>

//http://www.vcl.jp/~kanazawa/raytracing/?page_id=19#toc-03476ddd7e79e9c8fa7d759966a93ba4-10

//    /\
//   /  \
//  /    \
//  --++--
// ++ : s(vec.position)


namespace raytracing {

    double Cone::intersection(Ray r){
        //Ray:x=sx+tdx,y=sy+tdy,z=sz+tdz
        ////sx,sz,sz = o(vec.origin).X(),Y(),Z()
        ////dx,dy,dz = d(vec.direction).X(),Y(),Z()
        //Cone:(x−cx)^2+(z−cz)^2=(r/h)^2(y−h−cy)^2
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
        double A,B,C,D,rh,iy;
        //r*r / h*h
        rh = ( rad*rad ) / ( h*h );
        //A:
        A = d.X()*d.X() + d.Z()*d.Z() - rh*d.Y()*d.Y();
        //B:
        B = -2*( s.X()*d.X() + s.Z()*d.Z() - rh*( h+s.Y() )*d.Y() );
        //C:
        C = s.X()*s.X() + s.Z()*s.Z() - rh*( h+s.Y() )*( h+s.Y() ) + o.X()*o.X() + o.Z()*o.Z() - rh*o.Y()*o.Y() -2*( s.X()*o.X() + s.Z()*o.Z() - rh*( h+s.Y() )*o.Y() );
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
            
            if( s.Y() <= iy && iy <= ( s.Y()+h )){
                if(DEBUG) cout << "Ray has hit!" << endl;
            }
            //ADD INTERSECTION CONDITION
            //intersection is out of the height of the cone
            else{
                //no intersection point
                t = -3.0;
                //if(DEBUG) cout << "Ray has missed!" <<endl;
            }
        }
        
        return t;
        
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
            if (nextId.compare("radius") == 0)  radius=readDouble();
            if (nextId.compare("height") == 0)  height=readDouble();
        } while (true);
    }
    
}
