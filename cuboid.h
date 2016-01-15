#include <iostream>

using namespace std;

class cuboid: public drawableObject
{
private:
	double xSize;
	double ySize;
	double zSize;
public:
	Vector3D intersection (Ray r);
	Color getColorAtIntersection( Vector3D intersection, Ray r);
};
