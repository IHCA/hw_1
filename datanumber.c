#include<stdlib.h>
#include<stdio.h>
int main(){
    int i;
    int data[1000000];
    srand(1);
    for(i=0;i<1000000;i++){
    data[i]=rand();
    printf("%d\n",data[i]);
    }
}
