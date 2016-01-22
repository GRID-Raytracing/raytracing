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
#include "Vertex3D.h"

using namespace std;

namespace raytracing {
class Plane : public drawableObject {
public:
  // constructor
  Plane(Vector3D pos, double ref, Color col, double t, Vector3D vec1, Vector3D vec2, Vector vec3) :
    drawableObject(pos, ref, col, t), vertex1(vec1), vertex2(vec2), vertex3(vec3) {
    calculatePlaneFormula(pos, vec1, vec2);
  }
  
  // setter
  void setVertex(Vector3D vec1, Vector3D vec2) {
    vertex1 = vec1;
    vertex2 = vec2;
    vertex3 = vec3;
  }

  // getter
  Vertex3D[] getVertex() {
    Vertex3D vertexArray[] = {vertex1, vertex2, vertex3};
    return vertexArray;
  }
  
  virtual double intersection(Ray r) override;
  virtual Color getColorAtIntersection(Vector3D i, Ray r) override;
  
private:
  Vector3D vertex1;
  Vector3D vertex2;
  Vector3D vertex3;
  double a;
  double b;
  double c;
  double d;

  void calculatePlaneFormula(Vector3D A, vector3D B, vector3D C) {
    a = (B.Y()-A.Y())*(C.Z()-A.Z())
        -(C.Y()-A.Y())*(B.Z()-A.Z());
    b = (B.Z()-A.Z())*(C.X()-A.X())
        -(C.Z()-A.Z())*(B.X()-A.X());
    c = (B.X()-A.X())*(C.Y()-A.Y())
        -(C.X()-A.X())*(B.Y()-A.Y());
    d = -(a*A.X()+b*A.Y()+c*A.Z());
  }
};
} // namespace raytracing

#endif // PLANE_H
