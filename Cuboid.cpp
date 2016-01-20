#include "drawableObject.h"
#include "Cuboid.h"
#include "Constants.h"
#include <cmath>
#include <iostream>

namespace raytracing {

double Cuboid::intersection(Ray r)
{

	//getposition of the center of the cubiod
	Vector3D pos=getPosition();

	//get length directions
	double x=getxSize();
	double y=getySize();
	double z=getzSize();

	//Ray coordinates
	Vector3D o=r.getOrigin();
	Vector3D d=r.getDirection();

	// Intersection with coordinates x,y,z
	double xmin= pos.X()-0.5*x;
	double xmax= pos.X()+0.5*x;
	double ymin= pos.Y()-0.5*y;
	double ymax= pos.Y()+0.5*y;
	double zmin= pos.Z()-0.5*z;
	double zmax= pos.Z()+0.5*z;

	// t from intersection with coordinates x,y,z
	double txmin=(xmin-o.X())/d.X();
	double txmax=(xmax-o.X())/d.X();
	double tymin=(ymin-o.Y())/d.Y();
	double tymax=(ymax-o.Z())/d.Y();
	double tzmin=(zmin-o.Z())/d.Z();
	double tzmax=(zmax-o.Z())/d.Z();
	
	//first intersection
	double tx=min(txmin,txmax);
	double ty=min(tymax,tymin);
	double tz=min(tzmax,tzmin);
	
	//max of the first intersection
	double t=max(max(tx,ty),tz);

	return t;
}


Color Cuboid::getColorAtIntersection(Vector3D i, Ray r)
{
return color;
}


}
