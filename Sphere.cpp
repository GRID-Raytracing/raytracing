#include "drawableObject.h"
#include "Sphere.h"

double Sphere::intersection(Ray r){
	//Ray: vec.origin + vec.direction * t = vec.present
	//Sphere: ( vec.present - vec.position )^2 = radius
	//Simultaneous equations with vec.present
	//t = [ -B±√(B^2 - 4AC) ] / 2A
	//A = (vec.direction)^2
	//B = 2*( vec.origin * vec.direction - vec.position * vec.direction)
	//C = (vec.origin)^2 + (vec.position)^2 - 2*(vec.origin*vec.position) - (radius)^2

	//vec.origin
	Vector3D rayOrigin = r.getOrigin();
	//vec.direction
	Vector3D rayDirection = r.getDirection();
	//vec.position
	Vector3D spherePosition = getPosition();
	//radius
	double sphereRadius = getRadius();

	//intersection point : i
	double intersectionPoint;
	double A,B,C;
	//A:
	A = rayDirection * rayDirection;
	//B:
	B = 2*(rayOrigin * rayDirection - spherePosition * rayDirection);
	//C:
	C = rayOrigin * rayOrigin + spherePosition * spherePosition - 2*(rayOrigin * spherePosition) - sphereRadius * sphereRadius;

	//t
	//pattern

	double d;
	d = 2.0;
	return d;
}