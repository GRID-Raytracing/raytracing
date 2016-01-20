#include "Ray.h"
#include "Scene.h"
#include "drawableObject.h"
#include <iostream>
#include "Constants.h"

using std::vector;

namespace raytracing {
    
    Color Ray::trace() {
        //if(DEBUG) cout<<"tracing..."<<endl;
        Scene* scene = Scene::getInstance();
        vector<drawableObject*>& objects = scene->getDrawableObjects();
        unsigned int closestObjectID;
        double closestDistance = -1;
        for(unsigned int i=0; i<objects.size(); i++) {
            //if(DEBUG) cout<<"Checking object "<<i<<endl;
            double currentDistance = objects[i]->intersection(*this);
            //if(DEBUG) cout<<"Intersection at t="<<currentDistance<<endl;
            if(currentDistance > 0 && (currentDistance < closestDistance || closestDistance < 0)) {
                closestDistance = currentDistance;
                closestObjectID = i;
            }
        }
        //if intersection found, closestDistance is larger than 0
        if(closestDistance > 0) {
            return objects[closestObjectID]->getColorAtIntersection(origin+closestDistance*direction, *this);
        }
        else {
            //if no intersection is found, return black.
            return Color(0,0,0);
        }
        
        
    }
    
}
