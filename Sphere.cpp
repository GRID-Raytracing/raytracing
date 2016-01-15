#include "drawableObject.h"
#include "Sphere.h"
#include <cmath>

//http://www.vcl.jp/~kanazawa/raytracing/?page_id=78

double Sphere::intersection(Ray r){
	//Ray: o(vec.origin) + d(vec.direction) * t = p
	//Sphere: ( p - s(vec.position) )^2 = r(radius)^2
	//Simultaneous equations with p
	//t = [ -B±√(B^2 - 4AC) ] / 2A
	//A = d^2
	//B = 2*( o*d - s*d )
	//C = o^2 + s^2 - 2*o*s - r^2

	//o(vec.origin)
	Vector3D o = r.getOrigin();
	//d(vec.direction)
	Vector3D d = r.getDirection();
	//s(vec.position)
	Vector3D s = getPosition();
	//r(radius)
	double r = getRadius();

	//calculate intersection point
	double A,B,C,D;
	//A:
	A = d*d;
	//B:
	B = 2*( o*d - s*d );
	//C:
	C = o*o + s*s - 2*( o*s ) - r*r;
	//D:
	D = B * B - 4*A*C;

	//
	double direction;
	if(D < 0)
		//no intersection point
		direction = 0.0;
	else if(D <= 0){
		t = (-B + sqrt(D)) / (2*A);
		//i(intersection point)
		Vector3D i;
		i = o + t*d;
		direction = (i - o)　* (i - o);
	}

	return direction;

}