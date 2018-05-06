## Makefile for CS162 Spring 2018 - Group Project
## Author: Group 1

PROGRAM = Group1_Project
CXX = g++
CXXFLAGS = -c -std=c++0x 
CXXFLAGS += -Wall -pedantic-errors
CXXFLAGS += -g

SRCS = main.cpp 
SRCS += Critter.cpp Ant.cpp Doodlebug.cpp Grid.cpp
SRCS += helpers.cpp Menu.cpp MenuItem.cpp

OBJS = $(SRCS:.cpp=.o)

HEADERS = Critter.hpp Ant.hpp Doodlebug.hpp Grid.hpp
HEADERS += helpers.hpp Menu.hpp MenuItem.hpp
# additional files for make zip
FILES = Makefile

$(PROGRAM): $(OBJS)
	$(CXX) $(OBJS) -o $(PROGRAM)

$(OBJS): $(SRCS) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(@:.o=.cpp)

clean:
	rm $(PROGRAM) $(OBJS)

valgrind: 
	valgrind --leak-check=full ./$(PROGRAM)

## Idea for make zip from student Kelley Reynolds
zip: $(SRCS) $(HEADERS)
	rm -f $(PROGRAM).zip
	zip -D $(PROGRAM).zip $(SRCS) $(HEADERS) $(FILES)