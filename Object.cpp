#include "Object.h"
//#include <iostream>
#include "Constants.h"

namespace raytracing {
    
  void Object::serialize(const string &indent){
    string i=indent + "  ";
    beginObject();
    writeIdentifier("Position", i); position.serialize(i);
    endObject(indent);
  }
  void Object::deserialize(){
    cerr << "Deserialize Object" << endl;
    string nextId;
    expectObjectBegin();
    do {
      nextId =readIdentifier();
      cerr << "Deserialize Object<" << nextId << ">" << nextId.compare("}") << endl;
      if (nextId.compare("}") == 0) return;
      if (nextId.compare("Position") == 0)  position.deserialize();
    } while (true);
  }

  
}