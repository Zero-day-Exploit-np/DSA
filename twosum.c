#include <stdio.h>
void sumcheck(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (i != j - 1)
            {
                if (arr[i] + arr[j - 1] == arr[j])
                {
                    printf("check %d+%d=%d\n", arr[i], arr[j - 1], arr[j]);
                }
                
            }
        }
    }
}
int main()
{
    int arr[7] = {1, 2, 3, 6, 8, 7, 9};
    sumcheck(arr, 7);

    return 0;
}