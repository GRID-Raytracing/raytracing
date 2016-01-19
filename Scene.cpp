#include "Scene.h" 

namespace raytracing {
    
    Scene* Scene::theScene = nullptr;

    
    Scene::Scene(Observer o, std::vector<drawableObject*> dO, std::vector<LightSource*> l):
		obs(o), drawableObjects(dO), lights(l) {}
		
    Scene* Scene::getInstance() { 
		if(theScene == nullptr) theScene = new Scene(Observer(), std::vector<drawableObject*>(), std::vector<LightSource*>());
		return theScene;
	}

  void Scene::serialize(const string &indent){
    beginObject();
    writeIdentifier("Observer", indent+"  ");    obs.serialize(indent + "  ");
    endObject(indent);
    //os << indent << "}" << endl;
  }
  void Scene::deserialize(){
    cerr << "Deserialize scene" << endl;
    string nextId;
    expectObjectBegin();
    do {
      nextId =readIdentifier();
      if (nextId.compare("}") == 0) return;
      if (nextId.compare(string("Observer")) == 0) obs.deserialize();
    } while (true);
  }
}
