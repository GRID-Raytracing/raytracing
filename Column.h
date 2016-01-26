#ifndef COLUMN_H
#define COLUMN_H

#include "drawableObject.h"
#include "Vector3D.h"
#include "Color.h"
#include "Ray.h"

using namespace std;

namespace raytracing {
class Column : public drawableObject {
private:
  double radius;
  double height;
public:
    // constructor
    Column(Vector3D pos, double ref, Color col, double t, double r, double h) : drawableObject(pos, ref, col, t), radius(r), height(h) {}
    Sphere() {} //Defaultobject
  
  // setter
  void setRadius(double r) {
    radius = r;
  }
  void setHeight(double h) {
    height = h;
  }

  // getter
  double getRadius() {
    return radius;
  }
  double getHeight() {
    return height;
  }
  
    virtual double intersection(Ray r) override;
    virtual Vector3D getNormalVectorAtPoint(Vector3D i) override {return (i-position).normalise();}
    
    virtual void serialize(const string &indent = "");
    virtual void deserialize();
    virtual const string type(){ return "Column"; }

};
} // namespace raytracing

#endif // COLUMN_H