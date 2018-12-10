#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<memory.h>

#include "input_output.h"
#include "alheader.h"

#define SZ 9


#define WHITE	"\x1b[0m"	// 0
#define RED	"\x1b[31m"	// 1


int main(void)
{
	system("clear");

	get_data();

	initReadOnlySudoku();
	solveSudoku(0, 0);

	showSolution();

	getNumber();

	return 0;
}
