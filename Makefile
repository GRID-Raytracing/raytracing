
CC=g++
CFLAGS=-std=c++11 -Wall -pedantic

SRC=Observer.cpp Ray.cpp Scene.cpp Object.cpp Serializable.cpp Vector3D.cpp Sphere.cpp
HEADERS=:=$(patsubst %.cpp,%.h, $(SRC)) Color.h
OBJ:=$(patsubst %.cpp,%.o, $(SRC))
TARGET=GRIDRaytracer
TESTS=emptySceneRenderTest simpleSphereRenderTest readScene twoSpheresOcclusionTest
GITS=$(SRC) $(HEADERS) Makefile

GRIDRaytracer: $(TARGET).o $(OBJ)
	$(CC) $^ -o $@


emptySceneRenderTest: tests/emptySceneRenderTest.o $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@
	
readScene: tests/readScene.o $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@
	
simpleSphereRenderTest: tests/simpleSphereRenderTest.o $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@
	
twoSpheresOcclusionTest: tests/twoSpheresOcclusionTest.o $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.cpp
	$(CC) $(CFLAGS) -c $^ -o $@

test: $(TESTS) $(OBJ)
	
clean:
	rm -rf *.o $(TARGET) $(TESTS) simpleSphereTest.bmp twoSpheresTest.bmp


 
