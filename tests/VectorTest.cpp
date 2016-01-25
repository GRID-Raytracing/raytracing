#include "../Vector3D.h"
#include <iostream>

using namespace raytracing;
using namespace std;


int main(){

	Vector3D v1(1,0,0);
	Vector3D v2(0,1,0);
	
	cout << "scalar product, orthogonal vectors: " << v1*v2 <<endl;
	cout << "scalar product, parallel vectors: " << v1*v1 <<endl;
	cout << "scalar product, antiparallel vectors: " << v1*(-1*v1) <<endl;
	cout << "normalisation: " << (5*v1).normalise()*(2*v1).normalise() <<endl;
	cout << "scalar product, composite vectors: " << (v1+v2).normalise()*(v1+v2).normalise() <<endl;
	cout << "subtraction: "<<(v1-v2)<<endl;
	
}