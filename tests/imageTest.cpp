#include "../Observer.h" 

using namespace raytracing;

int main(){
    Observer obs(Vector3D(0,0,0), Vector3D(0,0,1), 1.0, Vector3D(1,0,0), Vector3D(0,1,0), 100, 100);
    obs.exportImage("testImage.bmp", "bmp");
}