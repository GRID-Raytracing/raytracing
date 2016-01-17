#ifndef OBSERVER_H
#define OBSERVER_H

#include <string>
#include <vector>
#include "Vector3D.h"
#include "Color.h"
#include "Object.h"
#include "Ray.h"
#include "Constants.h"

#include "lib/bitmap_image.hpp"

using std::vector;

namespace raytracing {
  class Observer : public Object {
  private:
	Vector3D viewingDirection;
	double displayDistance;
	Vector3D xDirection;
	Vector3D yDirection;
	unsigned int xResolution;
	unsigned int yResolution;
	vector<vector<Color> > image; //implemented with vector because dynamic arrays are not part of C++11.
  public:
        Observer(Vector3D pos, Vector3D dir, double dist, Vector3D xDir, Vector3D yDir, unsigned int xRes, unsigned int yRes);
        Observer(): Observer(Vector3D(0,0,0), Vector3D(0,0,1), 1.0, Vector3D(0.01,0,0), Vector3D(0,0.01,0), 100, 100) {};
	void render();
	void exportImage(string path, string format);
  };
}

#endif //OBSERVER_H
