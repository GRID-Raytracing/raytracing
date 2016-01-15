namespace raytracing{
class drawableObject: public Object, public Scene{

protected:
	double reflectivity;
	Color color;
	double transparency;
public:
    virtual double intersection(Ray r) {return 0.0;};
	virtual Color getColorAtIntersection( Vector3D intersection, Ray r);
};}
