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

int filledAll()
{
	for (int i = 0; i < SZ; i++)
	{
		for (int j = 0; j < SZ; j++)
		{
			if (array[i][j] == 0)
			{
				return 0;
			}
		}
	}
	return 1;
}

int cnt = 0;

void tracking(int _data)
{
	for (int i = 0; i < SZ; i++)
	{
		for (int j = 0; j < SZ; j++)
		{
			if (array[i][j] == 0)
			{
				if (isThereValue(_data) == 0)
				{
					array[i][j] = _data;

					if (_data == 9)
					{
						cnt += 1;
						showSolution();
					}

					tracking(_data + 1);

					array[i][j] = 0;
				}
				else
				{
					if (_data == 9)
					{
						cnt += 1;
						showSolution();
					}
					tracking(_data + 1);
				}
			}
		}
	}
}

int main(void)
{
	array[0][0] = 1;
	array[0][1] = 2;
	array[0][2] = 3;
	array[1][0] = 4;
	array[1][1] = 5;
	array[1][2] = 6;
	array[2][0] = 7;
	//array[2][1] = 8;
	
	tracking(1);

	printf("%d\n", cnt);

	return 0;
}
