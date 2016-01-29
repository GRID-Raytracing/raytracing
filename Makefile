
CC=g++
CFLAGS=-std=c++11 -Wall -pedantic -static-libstdc++

MAIN=GRIDRaytracer.cpp director_1.cpp $(TESTS)
HEADERS=:=$(patsubst %.cpp,%.h, $(SRC)) $(STANDALONEHEADERS)
STANDALONEHEADERS=Color.h drawableObject.h LightSource.h PointLightSource.h SphericalLightSource.h
SRC=$(filter-out $(MAIN),$(wildcard *.cpp))
OBJ:=$(patsubst %.cpp,%.o, $(SRC))
TARGET=GRIDRaytracer
TESTS=emptySceneRenderTest simpleSphereRenderTest readScene ReflectiveSphereTest twoSpheresOcclusionTest ShadowedSphereTest VectorTest

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
	
ShadowedSphereTest: tests/ShadowedSphereTest.o $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

ReflectiveSphereTest: tests/ReflectiveSphereTest.o $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@
	
SphereField: tests/SphereField.o $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

movie_1/director_1: director_1.cpp $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@
	cp GRIDRaytracer movie_1
	
%.o: %.cpp
	$(CC) $(CFLAGS) -c $^ -o $@

test: $(TESTS) $(OBJ)
	
clean:
	rm -rf *.o tests/*.o $(TARGET) $(TESTS) simpleSphereTest.bmp twoSpheresTest.bmp ShadowedSphereTest.bmp emptySceneTest.bmp ReflectiveSphereTest.bmp


 
