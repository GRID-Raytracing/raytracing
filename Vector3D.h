#ifndef VECTOR3D_H
#define VECTOR3D_H

using namespace std;

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

  Vector3D normalise() {}
  double getLength() {}

private:
  double x;
  double y;
  double z;
};

#endif // VECTOR3D_H
