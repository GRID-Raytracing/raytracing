#ifndef VECTOR3D_H
#define VECTOR3D_H

#include<cmath>

using namespace std;

namespace raytracing {
class Vector3D {
public:
  // constructor
  Vector3D() {}
  Vector3D(double argx, double argy, double argz) :
   x(argx), y(argy), z(argz) {}

  // setter
  void setX(double argx) { x = argx; }
  void setY(double argy) { y = argy; }
  void setZ(double argz) { z = argz; }

  // getter
  double X() { return x; }
  double Y() { return y; }
  double Z() { return z; }

  Vector3D normalise() {
  	double length = this->getLength();
  	Vector3D temp(x/length,y/length,z/length);
  	return temp; }
  double getLength() { return sqrt(x*x+y*y+z*z);}
  
  Vector3D operator+(Vector3D other) {
  	Vector3D temp(x+other.X(),y+other.Y(), z+other.Z());
  	return temp;
  }

private:
  double x;
  double y;
  double z;
};
} // namespace raytracing

#endif // VECTOR3D_H
