// Reverse a string 
#include<stdio.h>
#include<string.h>
int main(){
char str[]="Hello world";
int size=strlen(str);
for(int i=0; i<size/2; i++){
    char temp=str[i];
    str[i]=str[size-i-1];
    str[size-i-1]=temp;

}


    printf("%s",str);



return 0;
}