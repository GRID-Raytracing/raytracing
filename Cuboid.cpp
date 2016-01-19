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
	x=getxSize();
	y=getySize();
	z=getzSize();

	//Ray coordinates
	Vector3D o=r.getOrigin();
	Vector3D d=r.getDirection();

	// Intersection with coordinates x,y,z
	double xmin= X(pos)-0.5*x;
	double xmax= X(pos)+0.5*x;
	double ymin= Y(pos)-0.5*y;
	double ymax= Y(pos)+0.5*y;
	double zmin= Z(pos)-0.5*z;
	double zmax= Z(pos)+0.5*z;

	// t from intersection with coordinates x,y,z
	double txmin=(xmin-X(o))/X(d);
	double txmax=(xmax-X(o))/X(d);
	double tymin=(ymin-Y(o))/Y(d);
	double tymax=(ymax-Z(o))/Y(d);
	double tzmin=(zmin-Z(o))/Z(d);
	double tzmax=(zmax-Z(o))/Z(d);
	
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
