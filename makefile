exe_sudoku : sudoku.o
	gcc -o exe_sudoku sudoku.o input_output.o

input_output.o : input_output.c
	gcc -c -o input_output.o input_output.c

sudoku.o : sudoku.c
	gcc -c sudoku.c -o sudoku.o



clean:
	rm -f input_output exe exe
	rm -f *.o 
	rm -f libfuncs.a
