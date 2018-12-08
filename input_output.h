#ifndef HJ_H
#define HJ_H

int checkHorizontal(int _data, int _row,int _col);
int checkVertical(int _data, int _row,int _col);
int checkSquare(int _data, int _row, int _col);
int isItCorrect();
void showSolution();
void putNum2Array(char *buf,int _row);
void get_data();
int full();
int checkRange(int row, int col, int num);
void getNumber();

#endif
