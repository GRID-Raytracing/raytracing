#ifndef VECTOR3D_H
#define VECTOR3D_H

#include<cmath>
#include "Serializable.h"
#include <iostream>


namespace raytracing {
class Vector3D : public Serializable {
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

  Vector3D operator-(Vector3D other) {
  	Vector3D temp(x-other.X(),y-other.Y(), z-other.Z());
  	return temp;
  }
  
  Vector3D operator*(double c) {return Vector3D(x*c,y*c,z*c);}
  double operator*(Vector3D other) {return x*other.X()+y*other.Y()+z*other.Z();}
  
  friend ostream& operator<<(ostream& os, Vector3D v);
  
  virtual void serialize(const string &indent = "");
  void deserialize();


private:
  double x;
  double y;
  double z;
};

inline Vector3D operator*(double c, Vector3D& v) { return v.operator*(c);}
inline   ostream& operator<<(ostream& os, Vector3D v) {
	return os<<v.x<<", "<<v.y<<", "<<v.z;
}

} // namespace raytracing

#endif // VECTOR3D_H
