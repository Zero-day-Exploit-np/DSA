#include <stdio.h>
#include <stdlib.h>
int shuffle(int *nums, int numsSize, int n)
{
    int *a = (int *)malloc(numsSize * sizeof(int));

    for (int i = 0; i < n; i + 2)
    {

        printf("  %d", i);
    }
    for (int i = 1; i < n; i + 2)
    {

        printf("  %d", i);
    }


}
int main()
{

    int arr[6] = {1, 2, 3, 4, 5, 6};
    shuffle(arr, 6, 3);

    return 0;
}