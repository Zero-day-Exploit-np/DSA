#include <stdio.h>

int main()
{
    int a[] = {5, 9, 3, 2, 1, 0};
    int size = 6;

    for (int i = 0; i < size - 1; i++)
    {
        int minIndex = i;

        for (int j = i + 1; j < size; j++)
        {
            if (a[j] < a[minIndex])
            {
                minIndex = j;
            }
        }

        // swap only once
        if (minIndex != i)
        {
            int temp = a[i];
            a[i] = a[minIndex];
            a[minIndex] = temp;
        }
    }

    for (int i = 0; i < size; i++)
    {
        printf(" %d", a[i]);
    }

    return 0;
}
