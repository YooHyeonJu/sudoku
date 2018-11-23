#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SZ 9

int array[SZ][SZ];

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

int main(void)
{
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
		printf("%s",buf);
	}

	return 0;
}
