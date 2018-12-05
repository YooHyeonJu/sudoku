

exe_sudoku : 

input_output : input_output.c
	gcc -o input_output input_output.c

clean:
	rm -f input_output
