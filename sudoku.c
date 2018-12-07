#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<memory.h>

#include "input_output.h"
#include "alheader.h"

#define SZ 9

//extern int sudoku[SZ][SZ];
//extern int color[SZ][SZ];
//extern int readOnlySudoku[SZ][SZ];


#define WHITE	"\x1b[0m"	// 0
#define RED	"\x1b[31m"	// 1
#define BLUE	"\x1b[34m"	// 2



int main(void)
{
	system("clear");

	get_data();

	initReadOnlySudoku();
	solveSudoku(0, 0);

	showSolution();
	getNumber();
	//showSolution();

	return 0;
}
