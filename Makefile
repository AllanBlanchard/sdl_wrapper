CXX=g++
CXXFLAGS= -Wall -Wextra -Werror -pedantic-errors -Wold-style-cast -Wcast-qual -Wcast-align -Wconversion -Wdouble-promotion -Wfloat-equal -Woverloaded-virtual -Wnon-virtual-dtor -Wshadow -Wredundant-decls -Wundef -Wunused -Wuninitialized -Winit-self -Wwrite-strings -Wpointer-arith -Wswitch-default -Wswitch-enum -Wlogical-op -Winline -Weffc++ -std=c++11 $(shell sdl2-config --cflags)
LDFLAGS= -pthread $(shell sdl2-config --libs)
SRC=$(wildcard *.cpp)
OBJ=$(SRC:.cpp=.o)
EXEC=sdllib

all: ${EXEC}

${EXEC} : ${OBJ}
	@echo -n "Linking $@ ... "
	@${CXX} -o $@ $^ ${CXXFLAGS} ${LDFLAGS}
	@echo "done."

%.o : %.cpp
	@echo -n "Compiling $@ ... "
	@${CXX} -c $< ${CXXFLAGS}
	@echo "done."

clean:
	rm -rf ${OBJ}
