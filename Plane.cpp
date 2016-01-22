#include "Color.h"
#include "drawableObject.h"
#include "Vertex3D.h"
#include "Plane.h"
#include <cmath>

using namespace std;

namespace raytracing {
virtual double Plane::intersection(Ray r) override {
  Vertex3D o = r.getOrigin();
  Vertex3D d = r.getDirection();

  double t = -(a*(o.X()-position.X())+b*(o.Y()-position.Y())+c*(o.Z()-position.Z()))/(a*d.X()+b*d.Y()+c*d.Z());
  
  double x = o.X() + d.X()*t;
  double y = o.Y() + d.Y()*t;
  double z = o.Z() + d.Z()*t;
  
  double norm = sqrt((x-o.X())^2+(y-o.Y())^2+(z-o.Z())^2);
  return norm;
}

virtual Color Plane::getColorAtIntersection(Vector3D i, Ray r) override {
}
} // namespace raytracing

#endif // PLANE_H
