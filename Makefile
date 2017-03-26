CXX=  g++

CFLAGS=-g -Wall -Iinclude/ -std=c++11
LDFLAGS=
LIBS=-lGL -lglfw -lGLEW

O=build

OBJS= \
    $(O)/main.o \
    $(O)/application.o \
    $(O)/scene.o \
    $(O)/staticmesh.o \
    $(O)/shader.o

all: $(O)/octengine

clean:
	rm -rf $(O)

$(O)/octengine: $(OBJS) $(O)
	$(CXX) $(CFLAGS) $(LDFLAGS) $(OBJS) -o $(O)/octengine $(LIBS)

$(O)/%.o: src/%.cpp $(O)
	$(CXX) $(CFLAGS) -c $< -o $@

$(O):
	mkdir $(O)
