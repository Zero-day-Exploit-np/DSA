#include<stdio.h>
void oddeven(int n){
    int odd=0, even=0;
    for(int i=1; i<=n; i++){
        if(i%2==0){
            even++;
        }else{
            odd++;
        }
    }
    printf("odd= %d and even = %d",odd,even);
}

int main(){
int n;
printf("enter the n number:");
scanf("%d",&n);
oddeven(n);
return 0;
}