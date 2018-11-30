#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SZ 9

#define WHITE	"\x1b[0m"	// 0
#define RED	"\x1b[31m"	// 1
#define BLUE	"\x1b[34m"	// 2

int array[SZ][SZ];

int color[SZ][SZ];

void showSolution()
{
	for (int i = 0; i < SZ; i++)
	{
		if (i % 3 == 0)
		{
			printf("+-----------------------+\n");
		}

		for (int j = 0; j < SZ; j++)
		{
			if (j % 3 == 0)
			{
				printf("| ");
			}
			printf(WHITE "%d ", array[i][j]);
		}
		printf("|\n");
	}
	printf("+-----------------------+\n\n\n");
}

void putNum2Array(char *buf,int _row)
{
	for(int i = 0;i<SZ;i++)
	{
		array[_row][i] = atoi(&buf[2*i]);
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

int main(void)
{
	get_data();
	showSolution();

	return 0;
}
