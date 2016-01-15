namespace raytracing{
class cuboid: public drawableObject
{
private:
	double xSize;
	double ySize;
	double zSize;
public:
	void setxSize(double x):xSize(x){};
	void setySize(double y):ySize(y){};
	void setzSize(double z):zSize(z){};

	Vector3D intersection (Ray r);
	Color getColorAtIntersection( Vector3D intersection, Ray r);
};
}
