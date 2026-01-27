#include <stdio.h>
int main()
{
    int s[3] = {1, 2, 3};
    int size = 3*2;
    int a[size];
    int n=0;

    for (int j = 0; j < 2; j++)
    {
        for (int i = 0; i < 3; i++)
        {
            a[n++] = s[i];
        }
    }

    for (int i = 0; i < size; i++)
    {
        printf(" %d ", a[i]);
    }
    return 0;
}