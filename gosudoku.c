#include <stdio.h>
#include <string.h>
#define SZ 9
#include "alheader.h"
#include "input_output.h"

extern int sudoku[SZ][SZ];
extern int color[SZ][SZ];
void solveSudoku(int _r, int _c);
int readOnlySudoku[SZ][SZ];
int solutionCnt = 0;

void initReadOnlySudoku(void)
{
 memcpy(&readOnlySudoku, sudoku, SZ*SZ*sizeof(int));
}
void printSolution(void)
{
 solutionCnt++;
 printf("----This is Solution # %d ---\n", solutionCnt);
 for(int i=0; i<SZ; i++)
 {
  for(int j=0; j<SZ; j++)
  {
   printf("%d ", sudoku[i][j]);
  } printf("\n");
 }
}
int isOKUD (int _r, int _c, int _value)
{
 for (int i=0; i<SZ; i++)
 {
   if (sudoku[i][_c] == _value && i != _r)
   {
    return 0;
   }
 }return 1;
}
int isOKLR(int _r, int _c, int _value)
{
 for (int i=0; i<SZ; i++)
 {
   if(sudoku[_r][i] == _value && i != _c)
   {
    return 0;
   }
 }return 1;
}
int isOKregion(int _r, int _c, int _value)
{
 int region_row = _r/3;
 int region_col = _c/3;
 for (int i = region_row*3; i<= region_row*3+2; i++)
 {
   for(int j = region_col*3; j<=region_col*3+2; j++)
   {
    if(sudoku[i][j] == _value && i != _r && j != _c)
    {
      return 0;
    }
   }
 }return 1;
}
void checkNext(int _r, int _c)
{
 if(_r == (SZ-1) && _c == (SZ-1))
 {
  printSolution();
  return;
 } _c++;
 if(_c == SZ)
 {
  _c = 0;
  _r++;
 }
 solveSudoku(_r, _c);
}
void solveSudoku(int _r, int _c)
{
 if(sudoku[_r][_c] > 0)
 {
  checkNext(_r, _c);
 }
 else
 {
  for(int i=1; i<=9; i++)
  {
   memcpy(&sudoku[_r][_c], &readOnlySudoku[_r][_c], sizeof(int)*SZ*SZ - sizeof(int)*(_r*SZ+_c));
   if ( isOKUD(_r, _c, i) == 1 && isOKLR(_r, _c, i) == 1 && isOKregion(_r, _c, i))
   {
   sudoku[_r][_c] = i;
   checkNext(_r, _c);
   }
  }
 }
}
#include <stdio.h>
#include <string.h>
#define SZ 9
#include "alheader.h"
void solveSudoku(int _r, int _c);
extern int sudoku[SZ][SZ];
int readOnlySudoku[SZ][SZ];
int solutionCnt = 0;
void initReadOnlySudoku(void)
{
 memcpy(&readOnlySudoku, sudoku, SZ*SZ*sizeof(int));
}
void printSolution(void)
{
 solutionCnt++;
 printf("----This is Solution # %d ---\n", solutionCnt);
 for(int i=0; i<SZ; i++)
 {
  for(int j=0; j<SZ; j++)
  {
   printf("%d ", sudoku[i][j]);
  } printf("\n");
 }
}
int isOKUD (int _r, int _c, int _value)
{
 for (int i=0; i<SZ; i++)
 {
   if (sudoku[i][_c] == _value && i != _r)
   {
    return 0;
   }
 }return 1;
}
int isOKLR(int _r, int _c, int _value)
{
 for (int i=0; i<SZ; i++)
 {
   if(sudoku[_r][i] == _value && i != _c)
   {
    return 0;
   }
 }return 1;
}
int isOKregion(int _r, int _c, int _value)
{
 int region_row = _r/3;
 int region_col = _c/3;
 for (int i = region_row*3; i<= region_row*3+2; i++)
 {
   for(int j = region_col*3; j<=region_col*3+2; j++)
   {
    if(sudoku[i][j] == _value && i != _r && j != _c)
    {
      return 0;
    }
   }
 }return 1;
}
void checkNext(int _r, int _c)
{
 if(_r == (SZ-1) && _c == (SZ-1))
 {
  printSolution();
  return;
 } _c++;
 if(_c == SZ)
 {
  _c = 0;
  _r++;
 }
 solveSudoku(_r, _c);
}
void solveSudoku(int _r, int _c)
{
 if(sudoku[_r][_c] > 0)
 {
  checkNext(_r, _c);
 }
 else
 {
  for(int i=1; i<=9; i++)
  {
   memcpy(&sudoku[_r][_c], &readOnlySudoku[_r][_c], sizeof(int)*SZ*SZ - sizeof(int)*(_r*SZ+_c));
   if ( isOKUD(_r, _c, i) == 1 && isOKLR(_r, _c, i) == 1 && isOKregion(_r, _c, i))
   {
   sudoku[_r][_c] = i;
   checkNext(_r, _c);
   }
  }
 }
}
