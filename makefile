CC = gcc
CFLAGS = -W -Wall
OBJECTS = sudoku.o
TARGET = exe_sudoku
SUB_DIR = lib 
.PHONY : all clean

SUB_DIR :
	cd lib; make

exe_sudoku : sudoku.o
	gcc -o -W -Wall -L./lib sudoku.o -lsource

sudoku.o : sudoku.c
	gcc -W -Wall -c -I./header sudoku.c -o sudoku.o

clean:
	cd lib; make clean	
	rm *.o exe_sudoku
	
