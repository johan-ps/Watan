CXX = g++
CXXFLAGS = -std=c++14 -Wall -MMD -g -Werror=vla
OBJECTS = main.o hexagon.o subject.o observer.o textDisplay.o board.o tile.o gameManager.o ./player/student.o ./player/player.o ./developments/criteria/criterion.o ./developments/criteria/assignment.o ./developments/development.o
DEPENDS = ${OBJECTS:.o=.d}
EXEC = watan

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${DEPENDS} ${OBJECTS} ${EXEC}
