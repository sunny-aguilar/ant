# File: 	makefile
# Author: 	Sandro Aguilar
# Date: 	January 2019
# Description:	Makefile for project 1 Langston's Ant

# Variables to control Makefile operation

CXX = g++

CXXFLAGS = -Wall
CXXFLAGS += -g
CXXFLAGS += -std=c++0x

OBJECTS = main.o
OBJECTS += ant.o
OBJECTS += board.o
OBJECTS += menu.o

HPPs = ant.hpp
HPPs += board.hpp
HPPs += menu.hpp

CPPs = main.cpp
CPPs += ant.cpp
CPPs += board.cpp
CPPs += menu.cpp

# Targets needed to bring the executable up to date

Ant: $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o Ant $(OBJECTS)

main.o: main.cpp $(HPPs)
	$(CXX) $(CXXFLAGS) -c main.cpp

ant.o: ant.hpp

board.o: board.hpp

menu.o: menu.hpp

# Clean up operations
clean:
	rm Ant *.o

debug:
	valgrind -v --leak-check=full --show-leak-kinds=all --track-origins=yes ./Ant

zip :
	zip -D ProjectOne_Aguilar_Sandro.zip $(CPPs) $(HPPs) $(TXTS) makefile *.txt *.pdf