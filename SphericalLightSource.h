namespace raytracing {
	
	class SphericalLightSource: public LightSource, public Sphere {
	public:
		SphericalLightSource(Vector3D pos, double ref, Color col, double t, double r) :
    		Sphere(pos, ref, col, t, r) {}
		virtual Color getColorAtIntersection( Vector3D i, Ray r) override {
			return (color+getReflectionAtIntersection(i,r));
		};
	};

}
