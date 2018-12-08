CC = gcc
CFLAGS = -W -WALL
OBJECTS = gosudoku.o input_output.o
TARGET = libsource.a

$(TARGET) : $(OBJECTS)
	ar rscv $(TARGET) $(OBJECTS)

gosudoku.o : gosudoku.c
	$(CC) -c -I../header gosudoku.c -o gosudoku.o

input_output.o : input_output.c
	$(CC) -c -I../header input_output.c -o input_output.o

clean:
	rm -f $(TARGET) $(OBJECTS)
