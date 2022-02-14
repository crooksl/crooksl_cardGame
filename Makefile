CXX = g++
CXXFLAGS = --std=c++11 -g

game: cards.o ultility.o main.o
	${CXX}  ${CXXFLAGS} cards.o ultility.o main.o -o test

tests: cards.o ultility.o tests.o #main.o
	${CXX}  ${CXXFLAGS} cards.o ultility.o tests.o  -o test


clean:
	rm -f *.o game
	rm -f *.o tests