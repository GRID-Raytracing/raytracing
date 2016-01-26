namespace raytracing {
	
	class SphericalLightSource: public LightSource, public Sphere {
	public:
		virtual Color getColorAtIntersection( Vector3D i, Ray r) override {return color+getReflectionAtIntersection(i,r);};
	}

}
