#include "../Ray.h"
#include "../Observer.h"
#include "../Scene.h"


using namespace raytracing;

int main(){
    Scene& scene = Scene::getInstance();
    scene.getObserver().render();
    scene.getObserver().exportImage("emptySceneTest.bmp", "bmp");
    return 0;
}