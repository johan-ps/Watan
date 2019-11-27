CXX = g++
CXXFLAGS = -std=c++14 -Wall -MMD -g -Werror=vla
OBJECTS = main.o hexagon.o textDisplay.o board.o tile.o gameManager.o ./assets/developments/criteria/assignment.o ./assets/developments/development.o
DEPENDS = ${OBJECTS:.o=.d}
EXEC = watan

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	del ${DEPENDS} ${OBJECTS} ${EXEC}
