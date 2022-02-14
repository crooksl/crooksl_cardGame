CXX = g++
CXXFLAGS = --std=c++11 -g

game: tests.o ultility.o main.o
	${CXX}  ${CXXFLAGS} tests.o ultility.o main.o -o test

tests: cards.o ultility.o tests.o main.o
	${CXX}  ${CXXFLAGS} cards.o ultility.o tests.o main.o -o test


clean:
	rm -f *.o game
	rm -f *.o tests