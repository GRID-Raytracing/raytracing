
#include "Scene.h"

using namespace raytracing;

int main(int argc, char **argv){
  Scene *scene = Scene::getInstance();

  string sceneInfilename="scene_in.txt";
  string imageFiletype="bmp";
  string imageFilename=string(argv[0]);
  
  

  for (int i=1; i<argc;i++){
    if (string(argv[i]).compare(string("-s"))==0){
      if (++i >= argc){ cerr << argv[0] << ": Despite option -s no scenefile given" << endl; return 1; }
      
      sceneInfilename=string(argv[i]);
    }
    if (string(argv[i]).compare(string("-o"))==0){
      if (++i >= argc){ cerr << argv[0] << ": Despite option -o no imagefile given" << endl; return 2; }
      
      imageFilename=string(argv[i]);
    }
    if (string(argv[i]).compare(string("-t"))==0){
      if (++i >= argc){ cerr << argv[0] << ": Despite option -t no imagefile given" << endl; return 3; }
      
      imageFiletype=string(argv[i]);
    }
  }

  scene->openInfile(sceneInfilename);
  try {
    scene->deserialize();
  } catch (const char *e){   
    cerr << argv[0] << ": " << e << endl;
    return 101;
  }
  std::vector<drawableObject*> drawables=scene->getDrawableObjects();
  for (int i=1; i<= 10; i++){
    for (unsigned int k=0; k<drawables.size(); k++)
      drawables[k]->move(drawables[k]->getPosition()*0.1);
    scene->getObserver().render();
    scene->getObserver().exportImage(imageFilename+"_"+to_string(i)+"."+imageFiletype, imageFiletype);
  }
  
  return 0;
}
