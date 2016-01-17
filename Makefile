
CC=g++
CFLAGS=-std=c++11 -Wall -pedantic

SRC=GRIDRaytracer.cpp Observer.cpp
OBJ:=$(patsubst %.cpp,%.o, $(SRC))
TARGET=GRIDRaytracer

GRIDRaytracer: $(OBJ)
	c++ $^ -o $@


emptySceneRenderTest: tests/emptySceneRenderTest.o Ray.o Scene.o  Observer.o  drawableObject.h Vector3D.o
	$(CC) $(CFLAGS) $^ -o $@
	
simpleSphereRenderTest: tests/simpleSphereRenderTest.o Ray.o Scene.o Observer.o drawableObject.h Vector3D.o Sphere.o
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.cpp
	$(CC) $(CFLAGS) -c $^ -o $@


clean:
	rm -f *.o $(TARGET)  


 
