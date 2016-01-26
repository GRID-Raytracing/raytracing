namespace raytracing {
	
	class SphericalLightSource:  public Sphere, public LightSource {
	public:
		SphericalLightSource(Vector3D pos, double ref, Color col, double t, double r) :
    		Sphere(pos, ref, col, t, r), LightSource(pos,ref,col,t) {}
		virtual Color getColorAtIntersection( Vector3D i, Ray r) override {
			return (color+getReflectionAtIntersection(i,r));
		};
	};

}
