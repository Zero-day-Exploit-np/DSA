#include<stdio.h>
int main(){
char str1[]="hello world";
for(int i=0; str1[i]!='\0'; i++){
    printf("%c\n",str1[i]);
}
return 0;
}