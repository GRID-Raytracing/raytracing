namespace raytracing {
	
	class Ray {
	private:
		Vector3D origin;
		Vector3D direction;
		unsigned int step;
		
	public:
		Ray(Vector3D o, Vector3D d, unsigned int s): origin(o), direction(d), step(s) {};
		Color trace();
		Vector3D getOrigin() { return origin;};
		Vector3D getDirection() { return direction;};
		unsigned int getStep() { return step;};
	};
}

