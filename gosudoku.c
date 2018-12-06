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

int isOK(int _r, int _c, int _value)
{
 for (int i=0; i<SZ; i++)
 {
	if (sudoku[i][_c] == _value && i != _r)
	{
	 return 0;
	}
 }
 for (int i=0; i<SZ; i++)
 {
	if(sudoku[_r][i] == _value && i != _c)
	{
	 return 0;
	}
 }
 
}

void solveSudoku(int _r, int _c)
{
 if(sudoku[_r][_c] > 0)
 {
  //checkNextNum function
 // return 0;
 }
 else
 {
  for(int i=1; i<=9; i++)
  {
   memcpy(&sudoku[_r][_c], &readOnlySudoku[_r][_c], sizeof(int)*SZ*SZ - sizeof(int)*(_r*SZ+_c));
   if (isOk(_r, _c, i) == 1)
   {
	sudoku[_r][_c] =i;
   }
  }
 }
}

void checkNext(int _r, int _c)
{
 if(_r == (SZ-1) && _c == (SZ-1))
 {
  printSoultion();
  return;
 } _c++;

 if(_c == SZ)
 {
  _c = 0;
  r++;
 }
 solveSudoku(_r, _c);
}

int main(void)
{
 initReadOnlySudoku();
 printf("you are success!! this is sudoku\n");
 for(int i=0; i<SZ; i++)
 {
  for (int j=0; j<SZ; j++)
  {
   printf("%d ", sudoku[i][j]);
  }printf("\n");
 } // check operation
 return 0;
}
