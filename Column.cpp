#include "drawableObject.h"
#include "Column.h"
#include "Constants.h"
#include <cmath>
#include <iostream>

namespace raytracing {

    double Column::intersection(Ray r){
        //Ray: o(vec.origin) + d(vec.direction) * t = p
        //input the formula

            //
            double t=-5;
            if(D < 0) {
                    //no intersection point
                    t = -3.0;
                    if(DEBUG) cout << "Ray has missed!" <<endl;
            }
            else if(D >= 0){
                    double t1 = (-B + sqrt(D)) / (2*A);
                    double t2 = (-B - sqrt(D)) / (2*A);
                    t = (t1>t2)?t1:t2;
                    if(DEBUG) cout << "Ray has hit!" << endl;
            }

            return t;

    }
    
    Color Column::getColorAtIntersection(Vector3D i, Ray r) {
        return color;
    }
    
}