CC = g++
CFLAGS = -std=c++0x
EXEC = planning.exe
OBJ = obj/

all: $(EXEC)

planning.exe : main.o date.o rdv.o
	$(CC) -o planning.exe $(OBJ)main.o $(OBJ)date.o $(OBJ)rdv.o

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp -o $(OBJ)main.o

date.o: date.cpp
	$(CC) $(CFLAGS) -c date.cpp -o $(OBJ)date.o

rdv.o: rdv.cpp
	$(CC) $(CFLAGS) -c rdv.cpp -o $(OBJ)rdv.o

clean:
	rm -rf $(OBJ)*.o

mrproper: clean
	rm -rf $(EXEC)
