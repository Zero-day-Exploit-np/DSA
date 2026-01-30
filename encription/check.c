#include <stdio.h>
int main()
{

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