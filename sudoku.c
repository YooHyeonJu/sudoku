#include<stdio.h>

#define SZ 9

int array[SZ][SZ]=
{ {5,3,0,0,7,0,0,0,0},{6,0,0,1,9,5,0,0,0},{0,9,8,0,0,0,0,6,0},
  {8,0,0,0,6,0,0,0,3},{4,0,0,8,0,3,0,0,1},{7,0,0,0,2,0,0,0,6},
  {0,6,0,0,0,0,2,8,0},{0,0,0,4,1,9,0,0,5},{0,0,0,0,8,0,0,7,9} };

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
			printf("%d ", array[i][j]);
		}
		printf("|\n");
	}
	printf("+-----------------------+\n\n\n");
}


int checkHorizontal(int _data,int _row)
{
	for(int i = 0;i<SZ;i++)
	{
		if(array[_row][i] == _data)
		{
			return 1;
		}
	}
	return 0;
}

int checkVertical(int _data, int _col)
{
	for(int i = 0;i<SZ;i++)
	{
		if(array[i][_col] == _data)
		{
			return 1;
		}
	}
	return 0;
}

int checkSquare(int _data, int _row, int _col)
{
	int h = _row/3;
	int v = _col/3;

	for(int i = 0;i<3;i++)
	{
		for(int j = 0;j<3;j++)
		{
			if(array[h + i][v+j] == _data)
			{
				return 1;
			}
		}
	}
	return 0;
}

int filledAll()
{
	for(int i = 0;i<SZ;i++)
	{
		for(int j = 0;j<SZ;j++)
		{
			if(array[i][j] == 0)
			{
				return 0;
			}
		}
	}
	return 1;
}

void doSudoku(int _data)
{
	for(int i = 0;i<SZ;i++)	// row
	{
		for(int j = 0;j<SZ;j++) // col
		{
			if(array[i][j] == 0)
			{
				if(checkHorizontal(_data,i) == 0 &&
				   checkVertical(_data,j) == 0 &&
				   checkSquare(_data,i,j) == 0)
				   {
				   		array[i][j] = _data;

						if(filledAll() == 1)
						{
							showSolution();
						}
						
						doSudoku(_data+1);
						
						array[i][j] = 0;
				   }
			}
		}
	}
}

int main(void)
{
	printf("first game\n");
	showSolution();
	
	printf("play game\n");
	doSudoku(1);
	return 0;
}
