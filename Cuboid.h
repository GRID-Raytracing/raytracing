#ifndef CUBIOD_H
#define CUBIOD_H

using namespace std;

namespace raytracing{
class Cuboid: public drawableObject{

private:
	double xSize;
	double ySize;
	double zSize;
public:
	//constructor
	Cuboid(Vector3D pos, double ref, Color col, double t, double x, double y, double z): 
		drawableObject(pos, ref, col, t), xSize(x), ySize(y), zSize(z) {}	

	//setter
	void setxSize(double x){xSize=x;}
	void setySize(double y){ySize=y;}
	void setzSize(double z){zSize=z;}
	
	//getter
	double getxSize() {return xSize;}
	double getySize() {return ySize;}
	double getzSize() {return zSize;}

	
	virtual double intersection (Ray r) override;
	virtual Color getColorAtIntersection( Vector3D intersection, Ray r) override;
};
}
#endif // CUBIOD_H
