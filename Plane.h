#ifndef PLANE_H
#define PLANE_H

/*
 * Plane.h
 * pos     vertex1
 *   +-------+
 *   |       |
 *   |       |
 *   +-------+
 * vertex2
 */

using namespace std;

namespace raytracing {
class Plane : public drawableObject {
public:
  // constructor
  Plane(Vector3D pos, double ref, Color col, double t, Vector3D vec1, Vector3D vec2) :
    drawableObject(pos, ref, col, t), vertex1(vec1), vertex2(vec2) {}
  
  // setter
  void setVertex(Vector3D vec1, Vector3D vec2) {
    vertex1 = vec1;
    vertex2 = vec2;
  }

  // getter
  Vertex3D[] getVertex() {
    Vertex3D vertexArray[] = {vertex1, vertex2};
    return vertexArray;
  }
  
  virtual double intersection(Ray r) override;
  virtual Color getColorAtIntersection(Vector3D i, Ray r) override;
  
private:
  Vector3D vertex1;
  Vector3D vertex2;
};
} // namespace raytracing

#endif // PLANE_H
