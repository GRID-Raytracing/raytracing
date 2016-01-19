#ifndef COLUMN_H
#define COLUMN_H

// Column.h

using namespace std;

namespace raytracing {
class Column : public drawableObject {
private:
  double radius;
  double height;
public:
  // constructor
  Column(Vector3D pos, double ref, Color col, double t, double r, double h) :
    drawableObject(pos, ref, col, t), radius(r), height(h) {}
  
  // setter
  void setRadius(double r) {
    radius = r;
  }
  void setHeight(double h) {
    height = h;
  }

  // getter
  double getRadius() {
    return radius;
  }
  double getHeight() {
    return height;
  }
  
  virtual double intersection(Ray r) override;
  virtual Color getColorAtIntersection(Vector3D i, Ray r) override;

};
} // namespace raytracing

#endif // COLUMN_H