CXX = g++
CXXFLAGS = -std=c++14 -Wall -MMD -g -Werror=vla
OBJECTS = fake_main.o player.o student.o ../resources.o ../developments/development.o ../developments/criteria/criterion.o ../developments/goal/goal.o ../developments/criteria/assignment.o ../developments/goal/achievement.o  ../observer.o
DEPENDS = ${OBJECTS:.o=.d}
EXEC = player_exec

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${DEPENDS} ${EXEC}






