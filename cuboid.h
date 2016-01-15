#ifndef CUBIOD_H
#define CUBIOD_H

namespace raytracing{
class Cuboid: public drawableObject
{
private:
	double xSize;
	double ySize;
	double zSize;
public:
	//constructor
	Cuboid(){}
	Cuboid(double ref, Color col, double t, double x, double y, double z): drawableObject(rev,col,t),xSize(x), ySize(y), zSize(z) {}	

	//setter
	void setxSize(double x):xSize(x){};
	void setySize(double y):ySize(y){};
	void setzSize(double z):zSize(z){};
	
	//getter
	void getxSize() {return x;}
	void getySize() {return y;}
	void getzSize() {return z;}

	
	Vector3D intersection (Ray r);
	Color getColorAtIntersection( Vector3D intersection, Ray r);
};
}
#endif // CUBIOD_H
