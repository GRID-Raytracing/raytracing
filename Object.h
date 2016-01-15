namespace raytracing {
	
	class Object {
	protected:
		Vector3D position;
		
	public:
		Object(Vector3D p): position(p) {};
		Vector3D getPosition() { return position;};
	}
}
