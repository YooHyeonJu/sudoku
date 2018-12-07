#ifdef ALHEADER_H
#define ALHEADER_H

void solveSudoku(int _r, int _c);
int readOnlySudoku[SZ][SZ];
void initReadOnlySudoku(void);
int isOKUD(int _r, int _c, int _value);
int isOKLR(int _r, int _c, int _value);
int isOKregion(int _r, int _c, int _value);
void printSolution(void);
void checkNext(int _r, int _c);

#endif
