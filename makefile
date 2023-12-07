battleship: main.o helpers.o player.o ai.o user.o ship.o board.o coor.o arr.h arr.cpp
	g++ -o battleship main.o helpers.o player.o ai.o user.o ship.o board.o coor.o
main.o: main.cpp 
	g++ -c main.cpp
helpers.o: helpers.cpp helpers.h arr.h player.h
	g++ -c helpers.cpp
player.o: player.cpp 
	g++ -c player.cpp
ai.o: ai.cpp ai.h 
	g++ -c ai.cpp
user.o: user.cpp user.h 
	g++ -c user.cpp
ship.o: ship.cpp ship.h 
	g++ -c ship.cpp
board.o: board.cpp board.h
	g++ -c board.cpp
coor.o: coor.cpp coor.h
	g++ -c coor.cpp
clean:
	rm *.o battleship