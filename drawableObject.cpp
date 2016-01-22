

#include "drawableObject.h"

namespace raytracing {

  void drawableObject::serialize(const string &indent){
    string i=indent + "  ";
    beginObject();
    writeIdentifier("Object", i); Object::serialize(i);
    writeIdentifier("Color", i); color.serialize(i);
    writePair("reflectivity", reflectivity, i);
    writePair("transparency", transparency, i);
    endObject(indent);

  }
  void drawableObject::deserialize(){
    cerr << "Deserialize drawableObject" << endl;
    string nextId;
    expectObjectBegin();
    do {
      nextId =readIdentifier();
      cerr << "Deserialize drawableObject<" << nextId << ">" << nextId.compare("Object") << endl;
      if (nextId.compare("}") == 0) return;
      if (nextId.compare("Object") == 0) Object::deserialize();
      if (nextId.compare("Color") == 0) color.deserialize();
      if (nextId.compare("reflectivity") == 0)  reflectivity=readDouble();
      if (nextId.compare("transparency") == 0)  transparency=readDouble();
    } while (true);
  }

}

