#include "drawableObject.h"
#include "Column.h"
#include "Constants.h"
#include <cmath>
#include <iostream>

namespace raytracing {

    double Column::intersection(Ray r){
		return 0.0;
    }
    
    void Column::serialize(const string &indent){
        string i=indent + "  ";
        beginObject();
        writeIdentifier("drawableObject", i); drawableObject::serialize(i);
        writePair("radius", radius, i, true);
        writePair("height", height, i, true);
        endObject(indent);
        
    }
    void Column::deserialize(){
        string nextId;
        expectObjectBegin();
        do {
            nextId =readIdentifier();
            if(DEBUG) cout<<"Column::deserialize: "<<nextId<<endl;
            if (nextId.compare("drawableObject") == 0) drawableObject::deserialize();
            if (nextId.compare("}") == 0) return;
            if (nextId.compare("radius") == 0)  radius=readDouble();
            if (nextId.compare("height") == 0)  height=readDouble();
        } while (true);
    }
    
}
