#include <stdio.h>
int main()
{
    int arr[5] = {1 ,4 ,5,3 ,2};

    for (int i = 0; i < 5; i++)
    {
        int isshorted = 0;
        printf("pass %d.\n",i+1);
        for (int j = 1; j < 5 - i; j++)
        {
            isshorted = 1;
            if (arr[j - 1] > arr[j])
            {
                isshorted = 0;
                int value = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = value;
            }
        }
        if (isshorted)
        {
            break;
        }
    }
    for (int i = 0; i < 5; i++)
    {
        printf(" %d", arr[i]);
    }

    return 0;
}