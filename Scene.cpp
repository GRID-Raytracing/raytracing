#include "Scene.h"
#include "Sphere.h"

namespace raytracing {
    
    Scene* Scene::theScene = nullptr;

    
    Scene::Scene(Observer o, std::vector<drawableObject*> dO, std::vector<LightSource*> l):
		obs(o), drawableObjects(dO), lights(l) {}
		
    Scene* Scene::getInstance() { 
		if(theScene == nullptr) theScene = new Scene(Observer(), std::vector<drawableObject*>(), std::vector<LightSource*>());
		return theScene;
	}

   void Scene::serialize(const string &indent){
    string i=indent+"  ";
    beginObject();
    writeIdentifier("Observer", i);    obs.serialize(i);
    writeIdentifier("drawableObjects", i); beginList();
    i=i+"  ";
    for (unsigned int k=0; k < drawableObjects.size(); k++){
      //cerr << "Scene::serialize(): " << drawableObjects[k]->type() << endl;;
      //if (k>0) writeListDelimiter();
      writeIdentifier(drawableObjects[k]->type(), i);
      drawableObjects[k]->serialize(i);
    }
    endList(indent+"  ");
    endObject(indent);
  }
  void Scene::deserialize(){
    string nextId;
    expectObjectBegin();
    do {
      nextId =readIdentifier();
      if(DEBUG) cout<<"Scene::deserialize: "<<nextId<<endl;
      if (nextId.compare("}") == 0) return;
      if (nextId.compare(string("Observer")) == 0) obs.deserialize();
      if (nextId.compare(string("drawableObjects")) == 0) expectListBegin();
      if (nextId.compare(string("Sphere")) == 0){
	Sphere *s=new Sphere();
	s->deserialize();
	addDrawableObject(s);
      if (nextId.compare("]") == 0) ; // array end, nothing to be done
      }
    } while (true);
  }
}
