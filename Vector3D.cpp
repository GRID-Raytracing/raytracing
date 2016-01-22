#include "Vector3D.h"

namespace raytracing {
//    Vector3D operator*(double c, Vector3D& v) { return v.operator*(c);}
  void Vector3D::serialize(const string &indent){
    string i=indent+"  ";
    beginObject();
    writePair("X", x, i);
    writePair("Y", y, i);
    writePair("Z", z, i, true);
    endObject(indent);
  }
  void Vector3D::deserialize(){
    cerr << "Deserialize Vector" << endl;
    string nextId;
    expectObjectBegin();
    do {
      nextId =readIdentifier();
      cerr << "Deserialize Vector<" << nextId << ">" << nextId.compare("}") << endl;
//      cerr << "Deserialize Vector<" << nextId << ">" << nextId.compare("Y") << endl;
//      cerr << "Deserialize Vector<" << nextId << ">" << nextId.compare("Z") << endl;
      if (nextId.compare("X") == 0)  x=readDouble();
      if (nextId.compare("Y") == 0)  y=readDouble();
      if (nextId.compare("Z") == 0)  z=readDouble();
      if (nextId.compare("}") == 0) return;
//      cerr << "Deserialize Vector x " << x << endl;
//      cerr << "Deserialize Vector y " << y << endl;
//      cerr << "Deserialize Vector z " << z << endl;
    } while (true);
  }

  
}
