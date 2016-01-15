
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
  };

}
