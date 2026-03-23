// input
// 1 3 2 1 3
#include <stdio.h>
int main()
{
    int hash[12] = {0};
    int element[5]={1,3,2,1,3};

    for(int i=0; i<5; i++){
        hash[element[i]]+=1;   
    }

    for(int j=0; j<5; j++){
        printf("%d ", hash[j]);
    }

    return 0;
}