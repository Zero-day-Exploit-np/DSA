#include <stdio.h>
int main()
{
    // char arr[26]={"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"};
    // char arr[26]={"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"};

    char plain[]="bikram";
    char key[] = "KEY";
    char chipher[100];
    // printf("Enter the plain text:");
    // scanf("%s", &plain);
    printf(" %s ", plain);

    for (int i = 0; plain[i] != '\0'; i++)
    {
        int value = i % 3;
        chipher[i] = key[value];
    }

    printf(" %s ", chipher);
    return 0;
}