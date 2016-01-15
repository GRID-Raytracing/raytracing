

SRC=GRIDRaytracer.cpp Observer.cpp
OBJ:=$(patsubst %.cpp,%.o, $(SRC))
TARGET=GRIDRaytracer

GRIDRaytracer: $(OBJ)
	c++ $^ -o $@

#%.o: %.c
#	c++ -c $< -o $<.o

clean:
	rm -f *.o $(TARGET)  


 
