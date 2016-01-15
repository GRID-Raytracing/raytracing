#include "drawableObject.h"
#include "Sphere.h"
#include <cmath>

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

	//calculate intersection point
	double A,B,C,D;
	//A:
	A = rayDirection * rayDirection;
	//B:
	B = 2*(rayOrigin * rayDirection - spherePosition * rayDirection);
	//C:
	C = rayOrigin * rayOrigin + spherePosition * spherePosition - 2*(rayOrigin * spherePosition) - sphereRadius * sphereRadius;
	//D:
	D = B * B - 4*A*C;

	//
	double direction;
	if(D < 0)
		//no intersection point
		direction = 0.0;
	else if(D <= 0){
		t = (-B + sqrt(D)) / (2*A);
		//intersection point
		Vector3D intersectionPoint;
		intersectionPoint = rayOrigin + t*rayDirection;
		direction = (intersectionPoint - rayOrigin)　* (intersectionPoint - rayOrigin);
	}

	return direction;

}