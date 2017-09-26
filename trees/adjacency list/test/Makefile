CC=gcc
FLAGS= -I ../include -g
EXECPATH= ../
OBJPATH= ../src/

default: main clean

main: main.o func.o
	$(CC) -o $(EXECPATH)main main.o func.o  -g

main.o: main.c
	$(CC) $(FLAGS) -c main.c
 
func.o: $(OBJPATH)func.c
	$(CC) $(FLAGS) -c $(OBJPATH)func.c

clean:
	rm -rf main.o func.o




