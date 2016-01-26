#include "Color.h"
#include "drawableObject.h"
#include "Vector3D.h"
#include "Plane.h"
#include <cmath>

using namespace std;

namespace raytracing {
double Plane::intersection(Ray r) {
  Vector3D o = r.getOrigin();
  Vector3D d = r.getDirection();

  double ar[4];
  //calculatePlaneFormula(ar, position, vertex[0], vertex[1]);
  Vector3D A = position;
  Vector3D B = vertex[0];
  Vector3D C = vertex[1];
  
  ar[0] = (B.Y()-A.Y())*(C.Z()-A.Z())
            -(C.Y()-A.Y())*(B.Z()-A.Z());
  ar[1] = (B.Z()-A.Z())*(C.X()-A.X())
            -(C.Z()-A.Z())*(B.X()-A.X());
  ar[2] = (B.X()-A.X())*(C.Y()-A.Y())
            -(C.X()-A.X())*(B.Y()-A.Y());
  ar[3] = -(ar[0]*A.X()+ar[1]*A.Y()+ar[2]*A.Z());
  double a = ar[0];
  double b = ar[1];
  double c = ar[2];
  //double d = ar[3];

  double t = -(a*(o.X()-position.X())+b*(o.Y()-position.Y())+c*(o.Z()-position.Z()))/(a*d.X()+b*d.Y()+c*d.Z());
  
  double x = o.X() + d.X()*t;
  double y = o.Y() + d.Y()*t;
  double z = o.Z() + d.Z()*t;
  double xx = (x-o.X()) * (x-o.X());
  double yy = (y-o.Y()) * (y-o.Y());
  double zz = (z-o.Z()) * (z-o.Z());
  double norm = sqrt(xx+yy+zz);

  return norm;
}

Color Plane::getColorAtIntersection(Vector3D i, Ray r) {
  return color;
}

void calculatePlaneFormula(double* ar, Vector3D A, Vector3D B, Vector3D C) {
}
} // namespace raytracing
