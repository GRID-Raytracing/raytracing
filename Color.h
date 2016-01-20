#ifndef COLOR_H
#define COLOR_H

#include "Serializable.h"

namespace raytracing {
 class Color : public Serializable {
  private:
    double r, g, b;
  public:
    Color(double r=0, double g=0, double b=0){
      SetR(r); SetG(g); SetB(b);
    }
    double R(){ return r; }
    double G(){ return g; }
    double B(){ return b; }
    void SetR(double h){ r = (h>1?1:(h<0?0:h)); }
    void SetG(double h){ g = (h>1?1:(h<0?0:h)); }
    void SetB(double h){ b = (h>1?1:(h<0?0:h)); }
    unsigned char getCharR(){ return r*255; }
    unsigned char getCharG(){ return g*255; }
    unsigned char getCharB(){ return b*255; }
    unsigned int RGB(double r, double g, double b){return (r*65536)+(g*256)+b;}
    
    Color operator+(Color c2) { return Color(r+c2.R(),g+c2.G(),b+c2.B());}
    Color operator*(Color c2) { return Color(r*c2.R(),g*c2.G(),b*c2.B());}
    Color operator*(double d) { return Color(r*d,g*d,b*d);}
    Color operator+=(Color c2) {r+=c2.R(); g+=c2.G(); b+=c2.B(); return *this};


    virtual void serialize(const string &indent = ""){
      string i=indent+"  ";
      beginObject();
      writePair("R", R(), i);
      writePair("G", G(), i);
      writePair("B", B(), i, true);
      endObject(indent);
    }

    virtual void deserialize(){
      cerr << "Deserialize Color" << endl;
      string nextId;
      expectObjectBegin();
      do {
        nextId =readIdentifier();
//        cerr << "Deserialize Color<" << nextId << ">" << nextId.compare("}") << endl;
      if (nextId.compare("R") == 0)  SetR(readDouble());
      if (nextId.compare("G") == 0)  SetG(readDouble());
      if (nextId.compare("B") == 0)  SetB(readDouble());
      if (nextId.compare("}") == 0) return;
//      cerr << "Deserialize Vector x " << x << endl;
//      cerr << "Deserialize Vector y " << y << endl;
//      cerr << "Deserialize Vector z " << z << endl;
      } while (true);
    }
  };
  
  inline Color operator*(double d, Color& c) {return c.operator*(d);}
  
}
#endif //COLOR_H
