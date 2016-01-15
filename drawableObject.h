#include <iostream>

using namespace std;

class drawableObject: public Object, public Scene{

protected:
	double reflectivity;
	Color color;
	double transparency;
public:
	virtual Vector3D intersection (Ray r);
	virtual Color getColorAtIntersection( Vector3D intersection, Ray r);
};
