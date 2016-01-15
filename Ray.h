namespace raytracing {
	
	class Ray {
	private:
		Vector3D origin;
		Vector3D direction;
		unsigned int step;
		
	public:
		Color trace();
	}
}

