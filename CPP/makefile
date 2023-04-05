CC=g++

test: main.o Game.o Car.o Lemon.o PingPong.o Spinner.o
	$(CC) main.o Game.o Car.o Lemon.o PingPong.o Spinner.o -o test

main.o: main.cpp
	$(CC) -c main.cpp

Game.o: Game.cpp Game.h
	$(CC) -c Game.cpp

Car.o: Car.cpp Car.h
	$(CC) -c Car.cpp

Lemon.o: Lemon.cpp Lemon.h
	$(CC) -c Lemon.cpp

PingPong.o: PingPong.cpp PingPong.h
	$(CC) -c PingPong.cpp

Spinner.o: Spinner.cpp Spinner.h
	$(CC) -c Spinner.cpp

clean:
	rm *.o test