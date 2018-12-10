CC = gcc
CFLAGS = -W -Wall
OBJECTS = sudoku.o
TARGET = exe_sudoku

$(TARGET) : $(OBJECTS)
	$(CC) -o $(TARGET) -L../lib $(OBJECTS) -lsource

sudoku.o : sudoku.c
	$(CC) $(CFLAGS) -c -I../header sudoku.c -o sudoku.o

clean:
	rm -f $(TARGET) $(OBJECTS)
