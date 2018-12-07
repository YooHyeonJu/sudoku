#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "input_output.h"
#include "alheader.h"

#define SZ 9

#define WHITE	"\x1b[0m"	// 0
#define RED	"\x1b[31m"	// 1
#define BLUE	"\x1b[34m"	// 2


extern int readOnlySudoku[SZ][SZ];

int sudoku[SZ][SZ];
int color[SZ][SZ];

int checkHorizontal(int _data, int _row,int _col)
{
	for (int i = 0; i < SZ; i++)
	{
		if (sudoku[_row][i] == _data)
		{
			color[_row][i] = 1;
			return 1;
		}
	}
	return 0;
}

int checkVertical(int _data, int _row,int _col)
{
	for (int i = 0; i < SZ; i++)
	{
		if (sudoku[i][_col] == _data)
		{
			color[i][_col] = 1;
			return 1;
		}
	}
	return 0;
}

int checkSquare(int _data, int _row, int _col)
{
	int h = _row / 3;
	int v = _col / 3;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (sudoku[3*h + i][3*v + j] == _data)
			{
				color[3*h + i][3*v + j] = 1;
				return 1;
			}
		}
	}
	return 0;
}

void showSolution()
{
	printf(WHITE "    1 2 3   4 5 6   7 8 9  \n");
	for (int i = 0; i < SZ; i++)
	{
		if (i % 3 == 0)
		{
			printf(WHITE "  +-----------------------+\n");
		}
		printf(WHITE "%d ",i+1);
		for (int j = 0; j < SZ; j++)
		{
			if (j % 3 == 0)
			{
				printf(WHITE "| ");
			}
			if(color[i][j] == 1)
			{
				printf(RED "%d ", sudoku[i][j]);
			}
			else 
			{	
				printf(WHITE "%d ", sudoku[i][j]);
			}
		}
		printf(WHITE "|\n");
	}
	printf(WHITE "  +-----------------------+\n\n\n");
}

void putNum2Array(char *buf,int _row)
{
	for(int i = 0;i<SZ;i++)
	{
		sudoku[_row][i] = atoi(&buf[2*i]);
		color[_row][i] = 0;
	}
}

void get_data()
{
	int row = 0;
	int level = 0;
	printf("Choice the Level(1,2,3)\n");
	scanf("%d",&level);
	FILE *f = 0;
	if(level == 1)
	{
		f = fopen("level1.txt","rt");
	}
	else if(level == 2)
	{
		f = fopen("level2.txt","rt");
	}
	else
	{
		f = fopen("level3.txt","rt");
	}
	char buf[100] = {0};
	while(!feof(f))
	{
		fgets(buf,99,f);
		putNum2Array(buf,row);
		row+=1;
		
	}
}

int full()
{
	for(int i = 0;i<SZ;i++)
	{
		for(int j = 0;j<SZ;j++)
		{
			if(sudoku[i][j]==0)
				return 0;
		}
	}
	return 1;
}

int checkRange(int row, int col, int num)
{
	if(row<1 || row>9)
	{
		printf(RED "ROW" WHITE" is out of range!!\n\n");
		return 1;
	}
	if(col<1 || col>9)
	{
		printf(RED "COL" WHITE" is out of range!!\n\n");
		return 1;
	}
	if(num<1 || num>9)
	{
		printf(RED "NUMBER" WHITE" is out of range!!\n\n");
		return 1;
	}
	
	return 0;
}

void getNumber()
{
	int num=0,col=0,row=0;
	while(1)
	{
		if(full() == 1)
		{
			showSolution();
			return;
		}
		printf("row, column, num : ");
		scanf("%d %d %d",&row,&col,&num);
		int ret = checkRange(row,col,num);
		if(ret == 1)
		{
			continue;
		}
		row-=1; col-=1;
		if(sudoku[row][col] !=0)
		{
			printf(RED "Number is already exist!!\n");
			continue;
		}
		else
		{
			int ret1 = checkHorizontal(num,row,col);
			int ret2 = checkVertical(num,row,col);
			int ret3 = checkSquare(num,row,col);
			
			if(ret1 == 0 && ret2 == 0 && ret3 == 0)
			{
				sudoku[row][col]=num;
			}
		}
		
		
		showSolution();
		memset(color,0,sizeof(int)*SZ*SZ);
	}
}

