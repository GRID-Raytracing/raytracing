namespace raytracing {
	
	class PointLightSource: public LightSource {
	public:
		PointLightSource(Vector3D pos, double ref, Color cl, double tr) : LightSource(pos,ref,cl,tr) {};
	
	};

}
