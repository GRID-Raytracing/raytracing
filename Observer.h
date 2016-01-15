namespace raytracing{
class Observer: public Object{
private:
	Vector3D viewingDirection;
	double displayDistance;
	Vector3D xDirection;
	Vector3D yDirection;
	Vector3D xResolution;
	Vector3D yResolution;
	Color image[][];
public:
	void render();
	void exportImage(string path, string format);
};}
