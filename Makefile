
CC=g++
CFLAGS=-std=c++11 -Wall -pedantic

SRC=Observer.cpp Ray.cpp Scene.cpp Object.cpp Serializable.cpp Vector3D.cpp
OBJ:=$(patsubst %.cpp,%.o, $(SRC))
TARGET=GRIDRaytracer
TESTS=emptySceneRenderTest simpleSphereRenderTest readScene twoSpheresOcclusionTest

GRIDRaytracer: $(TARGET).o $(OBJ)
	$(CC) $^ -o $@


emptySceneRenderTest: tests/emptySceneRenderTest.o $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@
	
readScene: tests/readScene.o $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@
	
simpleSphereRenderTest: tests/simpleSphereRenderTest.o Ray.o Scene.o Observer.o drawableObject.h Vector3D.o Sphere.o
	$(CC) $(CFLAGS) $^ -o $@
	
twoSpheresOcclusionTest: tests/twoSpheresOcclusionTest.o Ray.o Scene.o Observer.o drawableObject.h Vector3D.o Sphere.o
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.cpp
	$(CC) $(CFLAGS) -c $^ -o $@

test: $(TESTS) $(OBJ)
	
clean:
	rm -rf *.o $(EXECS) simpleSphereTest.bmp twoSpheresTest.bmp


 
