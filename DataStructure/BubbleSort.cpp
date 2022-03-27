#include <stdio.h>

void swap(int* a, int* b);
void bubblesortA( int A[], int n);

int main()
{
    int A[] = {5, 2, 7, 4, 6, 3, 1};
    bubblesortA(A, 7);
    for(int i=0; i<7; ++i)
        printf("%d\n", A[i]);
    return 0;
}

void bubblesortA( int A[], int n)
{
    bool sorted =false;
    while( !sorted )
    {
        sorted = true;
        for( int i=0; i<n; ++i)
        {
            if ( A[i-1] > A[i])
            {
                swap(&A[i-1], &A[i]);
                sorted = false;
            }
        }
        n--;
    }
}

void swap(int* a, int* b)
{
    int temp;
    temp = *a;
    *a = *b; 
    *b = temp; 
}