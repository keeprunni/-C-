#include <stdio.h>

void reverse(int A[], int n);
void reverse(int A[], int lo, int hi);
void swap(int* a, int* b);

int main()
{
    int A[] = {1, 2, 3, 4, 5, 6, 7};
    reverse(A, 7);
    for(int i=0; i<7; ++i)
        printf("%d\n", A[i]);
    return 0;
}

void reverse(int A[], int n)
{
    reverse(A, 0, n-1);
}

void reverse(int A[], int lo, int hi)
{
    if(lo < hi)
    {
        swap(&A[lo], &A[hi]);
        reverse(A, lo+1, hi-1);
    }
}

void swap(int* a, int* b)
{
    int temp;
    temp = *a;
    *a = *b; 
    *b = temp; 
}