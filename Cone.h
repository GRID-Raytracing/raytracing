#ifndef CONE_H
#define CONE_H

#include "drawableObject.h"
#include "Vector3D.h"
#include "Color.h"
#include "Ray.h"

using namespace std;

namespace raytracing {
class Cone : public drawableObject {
public:
    // constructor
    Cone(Vector3D pos, double ref, Color col, double t, double r, double h) : drawableObject(pos, ref, col, t), radius(r) , height(h){}
    Cone() {} //Defaultobject
    
    // setter
    void setRadius(double r) { radius = r; }
    void setHeight(double h) { height = h; }
    
    // getter
    double getRadius() { return radius;}
    double getHeight() { return height;}
  
    virtual double intersection(Ray r) override;
    virtual Vector3D getNormalVectorAtPoint(Vector3D i) override {return (i-position).normalise();}
    
    virtual void serialize(const string &indent = "");
    virtual void deserialize();
    virtual const string type(){ return "Cone"; }

private:
    double radius;
    double height;

};
} // namespace raytracing

#endif // CONE_H