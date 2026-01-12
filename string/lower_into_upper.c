// 4️⃣ Convert lowercase to uppercase
#include<stdio.h>
#include<string.h>
int main(){
    char str1[]="hello this is string";
    for(int i=0; str1[i]!='\0'; i++){
        if(str1[i]>='a' && str1[i]<='z'){
            str1[i]=str1[i]-32;
        }
    }
    printf("Uppercase string: %s\n",str1);
return 0;
}