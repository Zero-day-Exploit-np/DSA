#include <stdio.h>
#include <ctype.h>
#include<string.h>

int main()
{
    char plaintext[100], key[100];
    int i, j = 0;

    printf("Enter plaintext: ");
    scanf("%s", plaintext);

    printf("Enter key: ");
    scanf("%s", key);

    for (i = 0; plaintext[i] != '\0'; i++)
    {
        if (isalpha(plaintext[i]))
        {
            char p = toupper(plaintext[i]) - 'A';
            char k = toupper(key[j % strlen(key)]) - 'A';
            char cipher = (p + k) % 26 + 'A';

            printf("%c", cipher);
            j++;
        }
    }

    return 0;
}
