#ifdef ALHEADER_H
#define ALHEADER_H
extern void solveSudoku(int _r, int _c);
extern void initReadOnlySudoku(void);

void solveSudoku(int _r, int _c);
void initReadOnlySudoku(void);
int isOKUD(int _r, int _c, int _value);
int isOKLR(int _r, int _c, int _value);
int isOKregion(int _r, int _c, int _value);
void printSolution(void);
void checkNext(int _r, int _c);

#endif
