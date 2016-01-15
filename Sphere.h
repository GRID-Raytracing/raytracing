#ifndef SPHERE_H
#define SPHERE_H

using namespace std;

namespace raytracing {
class Sphere : public drawableObject {
public:
  // constructor
  Sphere() {}
  Sphere(double ref, Color col, double t, double r) :
    drawableObject(rev, col, t), radius(r) {}
  
  // setter
  void setRadius(double r) { radius = r; }

  // getter
  double getRadius() { return radius;}

private:
  double radius;
};
} // namespace raytracing

#endif // SPHERE_H
