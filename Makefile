CXXFLAGS = -Wall -std=c++1z -g
LDLIBS = -lSDL2 -lSDL2_image

all: cards

main: cards.cpp
