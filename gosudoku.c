#include <stdio.h>
#include <string.h>
#define SZ 9

int sudoku[SZ][SZ] =
{
 2,0,5,0,0,7,0,0,6,
 4,0,0,9,6,0,0,2,0,
 0,0,0,0,8,0,0,4,5,
 9,8,0,0,7,4,0,0,0,
 5,7,0,8,0,2,0,6,9,
 0,0,0,6,3,0,0,5,7,
 7,5,0,0,2,0,0,0,0,
 0,6,0,0,5,1,0,0,2,
 3,0,0,4,0,0,5,0,8
};
//after change

int readOnlySudoku[SZ][SZ];

void initReadOnlySudoku(void)
{
 memcpy(&readOnlySudoku, sudoku, SZ*SZ*sizeof(int));
}

int main(void)
{
 printf("you are success!! this is sudoku\n");
 for(int i=0; i<SZ; i++)
 {
  for (int j=0; j<SZ; j++)
  {
   printf("%d ", sudoku[i][j]);
  }printf("\n");
 }
 return 0;
}
