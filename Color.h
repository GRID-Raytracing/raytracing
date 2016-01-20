#ifndef COLOR_H
#define COLOR_H
namespace raytracing {
 class Color {
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
    
    Color operator+(Color& c2) { return Color(r+c2.R(),g+c2.G(),b+c2.B());}
    Color operator*(Color& c2) { return Color(r*c2.R(),g*c2.G(),b*c2.B());}
    Color operator*(double d) { return Color(r*d,g*d,b*d);}
  };


}
#endif //COLOR_H
