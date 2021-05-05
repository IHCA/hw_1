#include"heapsort.h"
#include<stdio.h>
#include <sys/time.h>
void myheap(int arr[1000000], int number);
void heapadjust(int arr[1000000], int root, int number);	
void swap(int *a, int *b){
    int tmp;
    tmp=*a;
    *a=*b;
    *b=tmp;
}
int main(){
    unsigned  long diff;
    struct  timeval start;
    struct  timeval end;
    int arr[1000000];
    int input, j, i=0;
    while(scanf("%d",&input)!=EOF){
        arr[i]=input;
        i++;
    }
    gettimeofday(&start, NULL);
    myheap(arr, i);
    gettimeofday(&end, NULL);
    diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec; 
    printf("Sorting performance %ld us (equal %f sec)\n", diff, diff / 1000000.0);
    /*for(j=0;j<i-1;j++){
        printf("%d ",arr[j]);
    }
    printf("%d\n",arr[j]);*/
}
void myheap(int arr[1000000], int number){
    int i;
    for(i=number/2-1;i>=0;i--){
        heapadjust(arr, i, number);
    }
    for(i=number-1;i>1;i--){
        swap(&arr[0],&arr[i]);
        heapadjust(arr, 0, i-1);
    }
    swap(&arr[0],&arr[1]);
}
void heapadjust(int arr[1000000], int root, int number){
    int left=root*2+1;
    int right=root*2+2;
    int key;
    if(left<=number&&arr[left]>arr[root])key=left;
    else key=root;
    if(right<=number&&arr[right]>arr[key])key=right;
    if(key!=root){
        swap(&arr[root],&arr[key]);
        heapadjust(arr,key,number);
    }
}
