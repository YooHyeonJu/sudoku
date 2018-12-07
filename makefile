exe_sudoku : sudoku.o input_output.o gosudoku.o
	gcc -o exe_sudoku sudoku.o input_output.o gosudoku.o

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm -f input_output exe exe_sudoku
	rm -f *.o 
	rm -f libfuncs.a
