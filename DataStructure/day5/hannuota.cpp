#include <stdio.h>

int i=1;

void hannuota(int sour, int by, int dest, int cnt);
int main(void)
{
    int n = 3;
    char A = 'A';
    char B = 'B';
    char C = 'C';
    hannuota(A, B, C, n);
    return 0;
}

void hannuota(int sour, int by, int dest, int cnt)
{
    if(cnt >1)
        hannuota(sour, dest, by, cnt-1);
    
    printf("第%d次 : %c --> %c\n", i, sour, dest);
    i++;

    if(cnt > 1)
        hannuota(by, sour, dest, cnt-1);
}