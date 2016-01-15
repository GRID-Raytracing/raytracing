namespace raytracing {
	
	class Ray {
	private:
		Vector3D origin;
		Vector3D direction;
		unsigned int step;
		
	public:
		Color trace();
		Vector3D getOrigin() { return origin;};
		Vector3D getDirection() { return direction;};
		unsigned int getStep() { return step;};
	}
}

