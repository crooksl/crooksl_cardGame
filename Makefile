CXX = g++
CXXFLAGS = --std=c++11 -g

game: cards.o utility.o main.o
	${CXX}  ${CXXFLAGS} cards.o utility.o main.o -o game

test: cards.o utility.o tests.o
	${CXX}  ${CXXFLAGS} cards.o utility.o tests.o  -o test

cards.o:
	${CXX}  ${CXXFLAGS} -c cards.cpp

utility.o:
	${CXX}  ${CXXFLAGS} -c utility.cpp

main.o:
	${CXX}  ${CXXFLAGS} -c main.cpp

tests.o:
	${CXX}  ${CXXFLAGS} -c tests.cpp

clean:
	rm -f *.o game
	rm -f *.o tests
	rm -f *.o main