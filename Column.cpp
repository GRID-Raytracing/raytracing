#include "drawableObject.h"
#include "Column.h"
#include "Constants.h"
#include <cmath>
#include <iostream>

namespace raytracing {

    double Column::intersection(Ray r){
		return 0.0;
    }
    
    Color Column::getColorAtIntersection(Vector3D i, Ray r) {
        return color;
    }
    
}
