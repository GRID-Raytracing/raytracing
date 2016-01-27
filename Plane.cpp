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
  Vector3D D = vertex[2];

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
  
  // calculate intersection
  double x = o.X() + d.X()*t;
  double y = o.Y() + d.Y()*t;
  double z = o.Z() + d.Z()*t;

  // for norm
  double xx = (x-o.X()) * (x-o.X());
  double yy = (y-o.Y()) * (y-o.Y());
  double zz = (z-o.Z()) * (z-o.Z());
  
  // calculate distance between ray origin and intersection
  double norm = sqrt(xx+yy+zz);

  // check whether object include the point
  /*double AB = (B.X()-A.X())*(yy-A.Y())-(xx-A.X())*(B.Y()-A.Y());
  double BC = (C.X()-B.X())*(yy-B.Y())-(xx-B.X())*(C.Y()-B.Y());
  double CD = (D.X()-C.X())*(yy-C.Y())-(xx-C.X())*(D.Y()-C.Y());
  double DA = (A.X()-D.X())*(yy-D.Y())-(xx-D.X())*(A.Y()-D.Y());
  if (AB > 0 || BC > 0 || CD > 0 || DA > 0) {
    norm = 0.0;
  }*/
  Vector3D normal(a, b, c);
  Vector3D intersect(x, y, z);
  double d1 = abs(normal * o) / norm;
  double d2 = abs(normal * intersect) / norm;
  double ratio = d2 / (d1+d2);
  if (ratio != 0) {
    norm = 0.0;
  }

  return norm;
}

Color Plane::getColorAtIntersection(Vector3D i, Ray r) {
  return color;
}

void calculatePlaneFormula(double* ar, Vector3D A, Vector3D B, Vector3D C) {
}
} // namespace raytracing
