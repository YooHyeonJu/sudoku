#include <stdio.h>
#include<stdlib.h>

int main(void)
{
int i, j;

printf("\n << Color Code Table >> \n\n");

for(i=40; i <= 47; i++) {
printf("\x1b[0m[%d] ", i);
for(j=30; j <= 37; j++) {
printf("\x1b[%dm\x1b[%dm[%d] ",i ,j ,j);
}
printf("\n");
}

/* 칼라해제 */
printf("\x1b[0m\n");

printf("Example> printf(\"\\x1b[41m\\x1b[33m[BgColor=41, FgColor=33]\\x1b[0m\\n\"); \n");
printf("Result> \x1b[41m\x1b[33m[BgColor=41, FgColor=33]\x1b[0m\n");
printf("\n");
printf("Example> printf(\"\\x1b[44m\\x1b[32m칼라로 나타내고 싶은 메시지\\x1b[0m\\n\"); \n");
printf("Result> \x1b[44m\x1b[32m칼라로 나타내고 싶은 메시지\x1b[0m\n");

printf("\n");

printf("\x1b[31m" "HI\n");
printf("\x1b[0m" "bye\n");

exit(0);
}



