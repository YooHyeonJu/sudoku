#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "input_output.h"
#include "alheader.h"

#define SZ 9

extern int array[SZ][SZ];



#define WHITE	"\x1b[0m"	// 0
#define RED	"\x1b[31m"	// 1
#define BLUE	"\x1b[34m"	// 2



int main(void)
{
	printf("%d !!",array[0][0]);
	get_data();
	showSolution();
	getNumber();
	showSolution();


	return 0;
}
