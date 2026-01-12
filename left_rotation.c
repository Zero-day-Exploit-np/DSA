// Left rotate array by 1
#include <stdio.h>
void rotation(int array[], int size)
{
    int temp;
    temp = array[0];
    for (int i = 0; i < size - 1; i++)
    {
        array[i] = array[i + 1];
    }
    array[size - 1] = temp;
    for (int i = 0; i < size; i++)
    {
        printf("array[%d]=%d\n", i, array[i]);
    }
}
int main()
{
    int array[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    int size = 12;

    rotation(array, size);
    return 0;
}