#include <stdio.h>

void quicksort(int* a, int low, int high);
int findpos(int* a, int low, int high);
int main(void)
{
    int a[] = {5, 4, 6, 9 ,2, 1, 3};
    quicksort(a, 0, 6);

    for(int i=0; i<7; ++i)
        printf("%d\n", a[i]);
    return 0;
}

void quicksort(int* a, int low, int high)
{
    int pos;

    if(low < high)
    {
        pos = findpos(a, low, high);
        quicksort(a, low, pos-1);
        quicksort(a, pos+1, high);
    }
}

int findpos(int* a, int low, int high)
{
    int val = a[low];

    while(low < high)
    {
        while(low < high && a[high] >= val)
            --high;
        a[low] = a[high];

        while(low < high && a[low] <= val)
            low++;
        a[high] = a[low];
    }

    a[low] = val;

    return high;       //high可以改为low
}