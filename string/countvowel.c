// 3️⃣ Count vowels and consonants
#include<stdio.h>
int main(){
    char str1[]="Hello this is string";
    int vowel=0,i;
    for(i=0; str1[i]!='\0'; i++){
        if(str1[i]=='a' || str1[i]=='e' ||str1[i]=='i' || str1[i]=='o' || str1[i]=='u'){
            vowel++;
        }
    }
    printf("Vowel=%d and consonant=%d",vowel,i-vowel);
    return 0;
}