CXX = g++
CXXFLAGS = -std=c++14 -Wall -MMD -g -Werror=vla
OBJECTS = assignment.o criterion.o ../development.o fakeMain.o ../../player/player.o ../../player/student.o ../../observer.o
DEPENDS = ${OBJECTS:.o=.d}
EXEC = criteria_exec

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${DEPENDS} ${EXEC}