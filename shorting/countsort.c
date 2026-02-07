#include <stdio.h>
int max(int *arr, int size)
{
    int max = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (max < arr[i])
        {
            max = arr[i];
        }
    }
    return max;
}
void countsort(int *arr, int size)
{
    int i, j;
    int maxvalue = max(arr, size);
    int temp[maxvalue + 1];
    for (i = 0; i < maxvalue + 1; i++)
    {
        temp[i] = 0;
    }
    for (i = 0; i < size; i++)
    {

        temp[arr[i]] = temp[arr[i]] + 1;
    }
    i = j = 0;
    while (i <= maxvalue)
    {
        if (temp[i] > 0)
        {
            arr[j] = i;
            temp[i] = temp[i] - 1;
            j++;
        }
        else
        {
            i++;
        }
    }

    for (i = 0; i < size; i++)
    {
        printf(" %d", arr[i]);
    }
}

int main()
{

    int arr[] = {1, 4, 2, 8, 5, 3, 6, 1};
    countsort(arr, 8);

    return 0;
}