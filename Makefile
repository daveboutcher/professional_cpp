# Assume a C++17 (aka c++1z) compiler
CXXFLAGS = -Wall -std=c++1z -g

# Need to link against the SDL libraries
LDLIBS = -lSDL2 -lSDL2_image

# Because this is a C++ application, tell make to use the C++ linker
LINK.o = $(LINK.cc)

all: cards

cards: cards.o

cards.o: cards.cpp $(wildcard cdl/*.h)
