#include "Observer.h"
namespace raytracing {
    
    Observer::Observer(Vector3D pos, Vector3D dir, double dist, Vector3D xDir, Vector3D yDir, unsigned int xRes, unsigned int yRes):
            Object(pos), viewingDirection(dir), displayDistance(dist), xDirection(xDir), yDirection(yDir), xResolution(xRes), yResolution(yRes) {
                image.resize(xResolution);
                for(unsigned int i = 0; i<xResolution; i++) {
                    image[i].resize(yResolution);
                }
            }
    
    
    void Observer::exportImage(string path, string format) {
        
        //there's probably a more efficient way for exporting
        //to bitmap.
        if(format == "bmp") {
            //create new image
            bitmap_image bitmap(xResolution, yResolution);
            //set background to black, probably unneeded
            bitmap.set_all_channels(0,0,0);
            
            //set all pixels according to Color array
            for(unsigned int i = 0; i<xResolution; i++){
                for(unsigned int j = 0; j<yResolution; j++){
                    Color& c = image[i][j];
                    bitmap.set_pixel(i,j,c.R(),c.G(),c.B());
                }
            }
            bitmap.save_image(path);
            return;            
        }
        
        cerr << "Error in Observer::exportImage(): Format not supported!" << endl;
        return;
    }

}