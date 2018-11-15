#include<stdio.h>

#define SZ 3

int array[SZ][SZ];

void showSolution()
{
	for (int i = 0; i < SZ; i++)
	{
		if (i % 3 == 0)
		{
			printf("+-------+\n");
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
	printf("+-------+\n\n\n");
}

int isThereValue(int _data)
{
	for (int i = 0; i < SZ; i++)
	{
		for (int j = 0; j < SZ; j++)
		{
			if (array[i][j] == _data)
			{
				return 1;
			}
		}
	}
	return 0;
}

void fillArray()
{
	int data = 1;
	for (int i = 0; i < SZ; i++)
	{
		for (int j = 0; j < SZ; j++)
		{
			if (array[i][j] == 0)
			{
				if (isThereValue(data) == 0)
				{
					array[i][j] = data;
				}
				else
				{
					data += 1;
					array[i][j] = data;
				}
				data += 1;
			}
		}
	}
}

int main(void)
{
	array[0][0] = 9;
	array[1][1] = 2;


	fillArray();
	showSolution();

	return 0;
}
