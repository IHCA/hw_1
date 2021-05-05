#include<stdlib.h>
#include<stdio.h>
int main(){
    char arr[128];
    int i, j;
    srand(1);
    for(i=0;i<1000000;i++){
        for(j=0;j<100;j++){
           arr[j]= rand()%26+'a';
        
        }
        arr[j]='\0';
        printf("%s\n",arr);
    }
}
