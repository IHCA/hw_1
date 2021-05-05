#include"quicksort.h"
#include<stdio.h>
#include <sys/time.h>
void swap(int *a, int *b){
    int tmp;
    tmp=*a;
    *a=*b;
    *b=tmp;
}
int main(){
    int arr[1000000];
    int input, j, i=0;
    while(scanf("%d",&input)!=EOF){
        arr[i]=input;
        i++;
    }
    i--;
    struct  timeval start;
    struct  timeval end;
    unsigned  long diff;
    gettimeofday(&start, NULL);
    quicksort(arr, 0, i);
    gettimeofday(&end, NULL);
    diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;     printf("Sorting performance %ld us (equal %f sec)\n", diff, diff / 1000000.0);
    /*for(j=0; j<=i-1; j++){
        printf("%d ",arr[j]);
    }
    printf("%d\n",arr[i]);*/
}
int partition(int arr[], int left, int right){
    int i=left+1, j=right;
    while(i<j){
        while(arr[j]>=arr[left]&&i<j){
            j--;
        }
        while(arr[i]<arr[left]&&i<j){
            i++;
        }
        swap(&arr[i], &arr[j]);
    }
    if(arr[left]>arr[i]){
        swap(&arr[left],&arr[i]);
    }
    return i;
}
void quicksort(int arr[], int left, int right){
    if(left<right){
        int div;
        div = partition(arr, left, right);
        quicksort(arr, left, div-1);
        quicksort(arr, div, right);
    }
}
