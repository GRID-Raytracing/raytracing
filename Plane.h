#ifndef PLANE_H
#define PLANE_H

/*
 * Plane.h
 * pos     vertex1
 *   +-------+
 *   |       |
 *   |       |
 *   +-------+
 * vertex2  vertex3
 */

#include "Color.h"
#include "drawableObject.h"
#include "Vector3D.h"

using namespace std;

namespace raytracing {
class Plane : public drawableObject {
public:
  // constructor
  Plane(Vector3D pos, double ref, Color col, double t, Vector3D vec1, Vector3D vec2, Vector3D vec3) :
    drawableObject(pos, ref, col, t) {
    vertex[0] = pos;
    vertex[1] = vec1;
    vertex[2] = vec2;
    vertex[3] = vec3;
  }
  
  // setter
  void setVector(Vector3D pos, Vector3D vec1, Vector3D vec2, Vector3D vec3) {
    vertex[0] = pos;
    vertex[1] = vec1;
    vertex[2] = vec2;
    vertex[3] = vec3;
  }

  // getter
  Vector3D* getVertex() {
    return vertex;
  }
  
  virtual double intersection(Ray r);
  virtual Color getColorAtIntersection(Vector3D i, Ray r);
  
private:
  Vector3D* vertex;
  
//  void calculatePlaneFormula(double* ar, Vector3D A, Vector3D B, Vector3D C);
};
} // namespace raytracing

#endif // PLANE_H
