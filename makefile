exe_sudoku : sudoku.o input_output.o
	gcc -o exe_sudoku sudoku.o input_output.o

input_output.o : input_output.c
	gcc -c -o input_output.o input_output.c

gosudoku.o : gosudoku.c
	gcc -c -o gosudoku.o gosudoku.c

sudoku.o : sudoku.c
	gcc -c sudoku.c -o sudoku.o


clean:
	rm -f input_output exe exe
	rm -f *.o 
	rm -f libfuncs.a
