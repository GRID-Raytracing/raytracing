#ifndef SPHERE_H
#define SPHERE_H

#include "drawableObject.h"
#include "Vector3D.h"
#include "Color.h"
#include "Ray.h"


using namespace std;

namespace raytracing {
class Sphere : public drawableObject {
public:
  // constructor
  Sphere(Vector3D pos, double ref, Color col, double t, double r) :
    drawableObject(pos, ref, col, t), radius(r) {}
  
  // setter
  void setRadius(double r) { radius = r; }

  // getter
  double getRadius() { return radius;}
  
  virtual double intersection(Ray r) override;
  virtual Color getColorAtIntersection(Vector3D i, Ray r) override;
  virtual void serialize(const string &indent = "");
  virtual void deserialize();

  
private:
  double radius;  
  
};
} // namespace raytracing

#endif // SPHERE_H
