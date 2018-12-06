exe_sudoku : sudoku.o
	gcc -o exe_sudoku -L. sudoku.o -lfuncs

sudoku.o : sudoku.c
	gcc -c -I. sudoku.c -o sudoku.o

libfuncs.a : input_output.o
	ar rv libfuncs.a input_output.o

input_output.o : input_output.c
	gcc -c -I. input_output.c -o input_output.o

clean:
	rm -f input_output
	rm -f *.o 
	rm -f libfuncs.a
