#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SZ 9

#define WHITE	"\x1b[0m"	// 0
#define RED	"\x1b[31m"	// 1
#define BLUE	"\x1b[34m"	// 2


int array[SZ][SZ];
int color[SZ][SZ];

int checkHorizontal(int _data, int _row,int _col)
{
	for (int i = 0; i < SZ; i++)
	{
		if (array[_row][i] == _data && i!=_col)
		{
			color[_row][i] = 1;
			printf("Horizontal\n");
			return 1;
		}
	}
	return 0;
}

int checkVertical(int _data, int _row,int _col)
{
	for (int i = 0; i < SZ; i++)
	{
		if (array[i][_col] == _data && i!=_row)
		{
			color[i][_col] = 1;
			printf("Vertical\n");
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
			if (array[3*h + i][3*v + j] == _data)
			{
				color[3*h + i][3*v + j] = 1;
				printf("Square\n");
				return 1;
			}
		}
	}
	return 0;
}


void showSolution()
{
	for (int i = 0; i < SZ; i++)
	{
		if (i % 3 == 0)
		{
			printf(WHITE "+-----------------------+\n");
		}

		for (int j = 0; j < SZ; j++)
		{
			if (j % 3 == 0)
			{
				printf(WHITE "| ");
			}
			if(color[i][j] == 1)
			{	printf(RED "%d ", array[i][j]);}
			else 
			{	printf(WHITE "%d ", array[i][j]);}
		}
		printf("|\n");
	}
	printf(WHITE "+-----------------------+\n\n\n");
}

void putNum2Array(char *buf,int _row)
{
	for(int i = 0;i<SZ;i++)
	{
		array[_row][i] = atoi(&buf[2*i]);
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
			if(array[i][j]==0)
				return 0;
		}
	}
	return 1;
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
		scanf("%d %d %d",&row,&col,&num);
		printf("row=%d, col=%d, num=%d\n",row,col,num);
		row-=1; col-=1;

		if(checkHorizontal(num,row,col)==0 || checkVertical(num,row,col)==0 || checkSquare(num,row,col)==0)
		{
			array[row][col]=num;
		}
		
		showSolution();

	}
}


int main(void)
{
	get_data();
	showSolution();
	getNumber();

	return 0;
}
