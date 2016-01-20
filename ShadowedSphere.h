#ifndef SHADOWEDSPHERE_H
#define SHADOWEDSPHERE_H

namespace raytracing {

	class ShadowedSphere : public Sphere {
	
	public:

		virtual Color getColorAtIntersection(Vector3D i, Ray r) override;
	};

}


#endif //SHADOWEDSPHERE_H
