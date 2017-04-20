CXX=  g++

CFLAGS=-g -Wall -Iinclude/ -std=c++11
LDFLAGS=
LIBS=-lGL -lglfw -lGLEW -llua -ldl

O=build

OBJS= \
    $(O)/main.o \
    $(O)/application.o \
    $(O)/file.o \
    $(O)/scene.o \
    $(O)/staticmesh.o \
    $(O)/shader.o \
    $(O)/script.o

SCRIPTS= \
    $(O)/rotate.so

all: $(O)/octengine

clean:
	rm -rf $(O)

$(O)/octengine: $(OBJS) $(SCRIPTS) $(O)
	$(CXX) $(CFLAGS) $(LDFLAGS) $(OBJS) -o $(O)/octengine $(LIBS)

$(O)/%.o: src/%.cpp $(O)
	$(CXX) $(CFLAGS) -c $< -o $@

$(O)/%.so: scripts/%.cpp $(O)
	$(CXX) $(CFLAGS) -shared -fPIC $< -o $@

$(O):
	mkdir $(O)
